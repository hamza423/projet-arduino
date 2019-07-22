#include <SoftwareSerial.h>         //On inclus la bibliothèque SoftwareSerial.h 

#define ARDUINO_RX 10 // TX - Arduino RX
#define ARDUINO_TX 11 // RX - Arduino TX

#define BUTTON_PREV 2                   //On défini le bouton précédent
#define BUTTON_PAUSE 3                 //On défini le bouton pause
#define BUTTON_NEXT 4                 //On défini le bouton suivant 
#define BUTTON_VOL_DOWN 8            //On défini le bouton pour augmenter le volume
#define BUTTON_VOL_UP 9œ            //On défini le bouton pour baisser le volume
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

SoftwareSerial mySerial(ARDUINO_RX, ARDUINO_TX);        //On initialise nos PIN RX(10) et TX(11)

char playmode = CMD_PLAY;                              //
char Send_buf[8] = {0};

void setup() 
{
  pinMode(BUTTON_PAUSE, INPUT);
  digitalWrite(BUTTON_PAUSE,HIGH);
  
  pinMode(BUTTON_NEXT, INPUT);
  digitalWrite(BUTTON_NEXT,HIGH);
  
  pinMode(BUTTON_PREV, INPUT);
  digitalWrite(BUTTON_PREV,HIGH);

  Serial.begin(9600);
  mySerial.begin(9600);
  delay(500);

  Send_buf[0] = 0x7e;
  Send_buf[1] = 0xff;
  Send_buf[2] = 0x06; 
  Send_buf[4] = 0x00;
  Send_buf[7] = 0xef;
  
  sendCommand(CMD_SEL_DEV, DEV_TF);    //On séléctionne la carte SD
  delay(200);
  sendCommand(CMD_PLAY_W_VOL, 0X0F01);
}


void loop() 
{ 
  if (digitalRead(BUTTON_PAUSE))
  {
    play_or_pause();  
  }
  if (digitalRead(BUTTON_NEXT))
  {
    play_next();
  }
  if (digitalRead(BUTTON_PREV))
  {
    play_prev();
  }
  /*if (digitalRead(BUTTON_VOL_UP))
  {
    volum_up();
  }
    if (digitalRead(BUTTON_VOL_DOWN))
  {
    volum_down();
  }*/
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
     sendCommand(CMD_PAUSE, 0);
  }
  else 
  {
     sendCommand(CMD_PLAY, 0);
  }
}

void play_next() 
{
  sendCommand(CMD_NEXT_SONG, 0);  
  if (playmode == CMD_PAUSE)
  {
    sendCommand(CMD_PLAY, 0);
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

/*void volum_up()
 {
  sendCommand(CMD_VOLUME_UP, 0);
  if (playmode == CMD_VOLUME_UP)
  {
    sendCommand(CMD_VOLUME_UP, 0);
  }
 }

void volum_down()
 {
  sendCommand(CMD_VOLUME_DOWN, 0);
  if (playmode == CMD_VOLUME_DOWN)
  {
    sendCommand(CMD_VOLUME_DOWN,0 );
  }
 }*/
