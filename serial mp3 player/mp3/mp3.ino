#include <SoftwareSerial.h>         //On inclus la bibliothèque SoftwareSerial.h 
#include <ESP8266WiFi.h>           
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define ARDUINO_RX 4 // TX - Arduino RX
#define ARDUINO_TX 5 // RX - Arduino TX

#define BUTTON_PREV   D5                 //On défini le bouton précédent
#define BUTTON_PAUSE  D6                //On défini le bouton pause
#define BUTTON_NEXT   D7               //On défini le bouton suivant 
#define BUTTON_VOL_DOWN 14          //On défini le bouton pour augmenter le volume
#define BUTTON_VOL_UP 12
/************COMMANDE POUR OCTET**************************/

#define CMD_NEXT_SONG 0X01
#define CMD_PREV_SONG 0X02
#define CMD_PLAY_W_INDEX 0X03
#define CMD_VOLUME_UP 0X04
#define CMD_VOLUME_DOWN 0X05
#define CMD_SET_VOLUME 0X06
#define CMD_SINGLE_CYCLE_PLAY 0X08
#define CMD_SEL_DEV 0X09
#define DEV_TF 0X02
#define CMD_SLEEP_MODE 0X0A
#define CMD_WAKE_UP 0X0B
#define CMD_RESET 0X0C
#define CMD_PLAY 0X0D
#define CMD_PAUSE 0X0E
#define CMD_PLAY_FOLDER_FILE 0X0F
#define CMD_STOP_PLAY 0X16
#define CMD_FOLDER_CYCLE 0X17
#define CMD_SET_SINGLE_CYCLE 0X19
#define SINGLE_CYCLE_ON 0X00
#define SINGLE_CYCLE_OFF 0X01
#define CMD_SET_DAC 0X1A
#define DAC_ON  0X00
#define DAC_OFF 0X01
#define CMD_PLAY_W_VOL 0X22

/*********************************************************/

SoftwareSerial mySerial(ARDUINO_RX, ARDUINO_TX);
const char* ssid = "ZOOMACOM";
const char* password = "z00m@COM";

ESP8266WebServer server(80);

char playmode = CMD_PLAY; 
char Send_buf[8] = {0};           //Contient la partie fixe de la commande(command) + l'emplacement de la partie variable 
String page = "";                 //On défini page avec un String comme type de donner afin de stocker notre page web 

void setup() 
{
  Serial.begin(115200);           // Ouverture du port serie en 115200 baud pour envoyer des messages de debug à l'ide par exemple
  delay(10);
  mySerial.begin(9600);
  
  pinMode(BUTTON_PAUSE, INPUT);
  digitalWrite(BUTTON_PAUSE,HIGH);
  pinMode(BUTTON_NEXT, INPUT);
  digitalWrite(BUTTON_NEXT,HIGH);
  pinMode(BUTTON_PREV, INPUT);
  digitalWrite(BUTTON_PREV,HIGH);

  Serial.print("connexion à ");       // Connexion au réseau WiFi
  Serial.println(ssid);

 String page =  "<DOCTYPE html>";
        page += "<html>";
        page += "<head><link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous"></head>";
        page += "<body><style> body { background-color: #fffff; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }</style>";
        page += "<h1>Serial Mp3 Player</h1>";
        page += "<p><a href=\"precedent">"<button type="button" class="btn btn-primary">Piste Précedent</button></a>";
        page += "<a href=\"play">"<button type="button" class="btn btn-primary">Play</button></a>";
        page += "<a href=\"suivant">"<button type="button" class="btn btn-primary">Piste Suivant</button></a></p>";
        page += "</body>";
        page += "</html>";
  WiFi.begin(ssid, password);         // On se connecte a reseau WiFi avec le SSID et le mot de passe precedemment configure

   while (WiFi.status() == WL_CONNECTED) // On sort de la boucle uniquement lorsque la connexion a ete etablie.
   {            
   delay(500);
   Serial.print(".");
   }
   
   Serial.println("");
   Serial.println("WiFi connecté");

    
  server.begin();         // connexion OK, on demarre le server web 
  Serial.println("Serveur démarré");


  Serial.println(WiFi.localIP());     // On indique sur le port serie l'adresse ip de l'ESP pour le trouver facilement
}
  
  server.on("/precedent", [](){                 //On déclare la route pour le bouton precedent 
  server.send(200, "text/html", page);
  play_prev();
  });
  server.on("/play", [](){                     //On déclare la route pour le bouton play et pause 
  server.send(200, "text/html", page);
  play_or_pause();
  });
  server.on("/suivant", [](){                   //On déclare la route pour le bouton play et suivant 
  server.send(200, "text/html", page);
  play_next();
  });

  server.begin();         // connexion OK, on demarre le server web
  
  Send_buf[0] = 0x7e;
  Send_buf[1] = 0xff;
  Send_buf[2] = 0x06;                     //La partie des variable stocker dans le tableau
  Send_buf[4] = 0x00;
  Send_buf[7] = 0xef;
  
  sendCommand(CMD_SEL_DEV, DEV_TF);    //On séléctionne la carte SD
  delay(200);
  sendCommand(CMD_PLAY_W_VOL, 0X1901); // initialise le volume au départ

  Serial.println("test");
}

void loop(void) 
{ 
  server.handleClient();      
  
  if (digitalRead(BUTTON_PAUSE))                //reconnaissance de l'appuie sur le bouton et activation de la fonction play_or_pause
  {
    play_or_pause(); 
    Serial.println("pause"); 
  }
  if (digitalRead(BUTTON_NEXT))                 //reconnaissance de l'appuie sur le bouton et activation de la fonction play_next
  {
    play_next();
  }
  if (digitalRead(BUTTON_PREV))                 //reconnaissance de l'appuie sur le bouton et activation de la fonction play_prev
  {
    play_prev();
  }
  if (digitalRead(BUTTON_VOL_UP))               //reconnaissance de l'appuie sur le bouton et activation de la fonction volume_up
  {
    volum_up();
  }
  if (digitalRead(BUTTON_VOL_DOWN))             //reconnaissance de l'appuie sur le bouton et activation de la fonction volume_down
  {
    volum_down();
  }
}

void sendCommand(int8_t command, int16_t dat)
{
  if (command == CMD_PLAY)            
  {
    playmode = CMD_PLAY;                
  } 
  if (command == CMD_PAUSE)
  {
    playmode = CMD_PAUSE;
  }
   
  Send_buf[3] = command;
  Send_buf[5] = (int8_t)(dat >> 8);
  Send_buf[6] = (int8_t)(dat);
 
  for(uint8_t i=0; i<8; i++)
     mySerial.write(Send_buf[i]);  
}

void play_or_pause()
{
  if(playmode == CMD_PLAY)
  {
     sendCommand(CMD_PAUSE, 0);               //si on appuie sur le bouton cela active pause, sinon on fait play
  }
  else 
  {
     sendCommand(CMD_PLAY, 0);
  }
}

void play_next()                            //Cette fonction permet de changer de piste au déclenchement du bouton 
{
  sendCommand(CMD_NEXT_SONG, 0);  
  if (playmode == CMD_PAUSE)                //Si on mes la musique en pause et que l'on change de piste , le pause s'annulera et on envoie la commande play
  {
    sendCommand(CMD_PLAY, 0);               //Et on envoie la commande play
  }
}

void play_prev()
{
  sendCommand(CMD_PREV_SONG, 0);  
  if (playmode == CMD_PAUSE)
  {
    sendCommand(CMD_PLAY, 0);
  }
}

void volum_up()
 {
    sendCommand(CMD_VOLUME_UP , 0);               //Fonction qui permet d'envoyer la commande volume augmenté
 }

void volum_down()
 {
    sendCommand(CMD_VOLUME_DOWN , 0);            //Fonction qui permet d'envoyer la commande volume diminué
 }
