#include <Adafruit_NeoPixel.h> //utilisation de la bibliothèque pour l'anneau du neopixel
#include <LiquidCrystal_I2C.h>
  
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define RING_PIN D7      //PIN qui permet de controler le l'anneau du neopixel
#define button0_PIN D6 //permet de controler le bouton de gauche
#define button1_PIN D5   //permet de controler le bouton de droite
#define num_LED 24      //nombre de led sur l'anneau


Adafruit_NeoPixel ring = Adafruit_NeoPixel(num_LED, RING_PIN, NEO_GRB + NEO_KHZ800);      // num_LED : On va déclarer nos objet connécter à l'anneau
                                                                                         // RING_PIN : Nombre de pin sur l'anneau
                                                                                         //NEO_GRB : Les pixels sont câblés pour le flux binaire GRB (la plupart des produits NeoPixel)
                                                                                         //NEO_KHZ800 : Flux binaire 800 KHz (la plupart des produits NeoPixel avec LEDs WS2812)
                                                                                        

uint32_t color; //On configure la couleur à 32 bits

bool game_ON = 0;          //On indique si le jeu est activé ou non
bool player = 0;           //On sélectionne le joueur actuel
int point_playerG = 0;     //Score du début pour le joueur de gauche (0 points)
int point_playerD = 0;     //Score du début pour le joueur de droite (0 points)
bool dir = 0;              //On séléctionne la direction du jeu
int k=4;                   //Position de la balle 
int game_speed = 100;      //Rapidité de la balle 
int normal = 100;          //Rapididé normale 
unsigned long timer;       //Timer utilisée pour accélérer le jeu

/**************************************************************************
 * SETUP
 *************************************************************************/
 
void setup() {

  lcd.init(); 
  lcd.backlight(); 
  Serial.begin(9600);

     lcd.print("ALLEZ Y");
    lcd.setCursor(0, 0);
  
  pinMode(button0_PIN, INPUT_PULLUP); //Utilisation de l'option pullup 
  pinMode(button1_PIN, INPUT_PULLUP);
    
  ring.begin();

  randomSeed(analogRead(A0));   //Création d'une couleur aléatoire 
  color = ring.Color(random(922277), random(922277), random(922277));
  
  ring_blink(color, 500, 2);  //Début de l'animation
}

/**************************************************************************
 * LOOP
 *************************************************************************/
 
void loop() {

  
 if(!game_ON && player == 0){                    //Initialisation du jeu si le joueur de Gauche est sélectionné
    k=4;
 
    ring.setPixelColor(3,0,100,0);                     // Lumière sur la bordure (vert)
    ring.setPixelColor(ring.numPixels()-4,0,100,0);   // La balle (bleu)
    ring.setPixelColor(4,0,50,75);                   // Les points (rouge)  
    for(int i=0;i<point_playerG;i++){
      ring.setPixelColor(i,100,0,0);
    }
    for(int i=ring.numPixels()-1;i>ring.numPixels()-point_playerD-1;i--){
      ring.setPixelColor(i,100,0,0);
    }
    ring.show();

//Démarre le jeu quand le joueur de gauche appuie
    if(!digitalRead(button0_PIN)){
      game_ON = 1;
      player = !player;
      normal = 50;
      game_speed = normal;
      delay(1000);
      timer = millis();
    }
  }
  
//Sinon si le joueur 1 est sélectionné on initialise le jeu
  else if(!game_ON && player == 1){
    k=ring.numPixels()-5;
    
    ring.setPixelColor(3,0,100,0);                      // LED pour les bordures (vert)
    ring.setPixelColor(ring.numPixels()-4,0,100,0);    //LED de la balle(bleu)
    ring.setPixelColor(ring.numPixels()-5,0,50,75);   //LEDS pour les points (rouge)
    for(int i=0;i<point_playerG;i++){
      ring.setPixelColor(i,100,0,0);
    }
    for(int i=ring.numPixels()-1;i>ring.numPixels()-point_playerD-1;i--){
      ring.setPixelColor(i,100,0,0);
    }
    ring.show();

//Actions si le joueur de gauche appuie
    if(!digitalRead(button1_PIN)){
      game_ON = 1;
      player = !player;
      normal = 50;
      game_speed = normal;
      delay(1000);
      timer = millis();
    }
  }

//On met à jour l'anneau
  else{
      comete(k,0,50,75); 
    
    ring.setPixelColor(3,0,100,0);
    ring.setPixelColor(ring.numPixels()-4,0,100,0);

/****************************************************/
//PARAMÈTRE JOUEUR DROITE
/***************************************************/
//Si le joueur de droite joue
    if(player == 1){

//quand le joueur de droite appuie su le bouton
      if(!digitalRead(button1_PIN)){ 
        
//Donne un super speed si il appuie au bon moment      
        if(k == ring.numPixels()-5){                         
          dir = !dir; //direction inversée
          game_speed = normal*0.5;// super speed
          player = !player; //changement de joueur
        }
        
//Sinon si le joueur appuie sur le bon bouton
        else if(k > ring.numPixels()-8 && k < ring.numPixels()-5){ 
          dir = !dir; //direction inversée
          game_speed = normal;  //rapidité : normal
          player = !player; //changement de joueur
        }
        
//si le joueur appuie au mauvais moment        
        else{ 
          game_ON = 0;                   //Game OFF
          point_playerG ++;             // + 1pt pour le joueur de gauche
          player = !player;            // Changement de joueur
          game_speed = normal*0.75;   //vitesse de l'engagement
          ring_blink(color,150,2);   //clignotement de l'anneau
          show_none();              // anneau éteint
                   
          lcd.setCursor(0, 0);
          lcd.print("Joueur gauche :");
          lcd.print(String(point_playerG)+" points");
          
          lcd.setCursor(0, 1);
          lcd.print("Joueur droite :");
          lcd.print(String(point_playerD)+" points");
        }
      }
    }

/****************************************************/
//PARAMÈTRE JOUEUR GAUCHE
/***************************************************/
//Si le joueur de gauche à appuyer
    if(player == 0){ //Si c est au joureur 1

//Quand le joueur de gauche à appuyer
      if(!digitalRead(button0_PIN)){
//
        if(k == 4){ 
          dir = !dir;                 //direction inversée
          game_speed = normal*0.5;   // grande vitesse
          player = !player;         //changement de joueur
        }

        else if(k < 8 && k > 4){          //Sinon si le joueur de gauche appuie au bon moment
          dir = !dir;                    //Direction inversée
          game_speed = normal;          //Vitesse normal
          player = !player;            //Changement de joueur
        }

//Sinon le joueur de droite gagne      
        else{ 
          game_ON = 0;                   //Game OFF
          point_playerD ++;             //+ 1pt pour le joueur de droite
          player = !player;            //Changement de joueur
          game_speed = normal*2.00;   //Vitesse de l'engagement
          ring_blink(color,150,2);   //Clignotement de l'anneau
          show_none();              //Anneau éteint

          lcd.setCursor(0, 0);
          lcd.print("Joueur gauche :");
          lcd.print(String(point_playerG)+" points");
          
          
          lcd.setCursor(0, 1);
          lcd.print("Joueur droite :");
          lcd.print(String(point_playerD)+" points");
        }
      }
    }


 //Mouvement de la balle 
    if(!dir){
      k++;
      delay(game_speed);
      
//La partie est échoué pour le joueur de droite s'il laisse la balle aller trop loin
      if(k>ring.numPixels()-5){
        game_ON = 0; 
        point_playerG ++;        //point en plus pour le joueur de droite;
        player = !player;       // changement de joueur ;
        k=4;
        ring_blink(color,150,2);
        show_none();

                lcd.setCursor(0, 0);
        lcd.print("Joueur gauche :");
        lcd.print(String(point_playerG)+" points");
        
        lcd.setCursor(0, 1);
        lcd.print("Joueur droite :");
        lcd.print(String(point_playerD)+" points");
      }
    }
    else {
      k--;
      delay(game_speed);

//La partie est échoué pour le joueur de gauche s'il laisse la balle aller trop loin
      if(k<4){
        game_ON = 0;
        point_playerD ++;       //point en plus pour le joueur de droite;
        player = !player;      // changement de joueur ;
        k=ring.numPixels()-5;
        ring_blink(color,150,2);
        show_none();

        lcd.setCursor(0, 0);
        lcd.print("Joueur gauche :");
        lcd.print(String(point_playerG)+" points");
        
        lcd.setCursor(0, 1);
        lcd.print("Joueur droite :");
        lcd.print(String(point_playerD)+" points");
      }
    }
  }

// Fin du jeu si l'un des joueurs à plus de 3 points
  if (point_playerG>3 ){
    ring_blink(color,150,5);
    game_ON = 0;
    player = 0;
    point_playerG=0;
    point_playerD=0;
    game_speed = 100;
    k=4;
    dir = 0;
   lcd.clear(); 
   lcd.print("Joueur G gagne");
 }

 else if (point_playerD>3){
    ring_blink(color,150,5);
    game_ON = 0;
    player = 0;
    point_playerG=0;
    point_playerD=0;
    game_speed = 100;
    k=4;
    dir = 0;
    
    lcd.clear();
    lcd.print("Joueur D gagne");
 }

//Accélération du jeu
  if(millis()-timer > 5000){
    normal = normal*0.8;
    timer=millis();
  }
}



/**************************************************************************
 * FUNCTIONS
 *************************************************************************/
void show_all(uint32_t color) {
  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, color);
  }
  ring.show();
}

void show_none() {
  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, 0, 0, 0);
  }
  ring.show();
}

void ring_blink(uint32_t color, int wait, int num_repet){
  for(int i = 0 ; i<num_repet ; i++){
    show_all(color);
    delay(wait);
    show_none();
    delay(wait);
  }
}

void comete(int pos, byte r, byte g, byte b){
  for(int i=0; i < ring.numPixels(); i++){
    ring.setPixelColor(i,int32bittoRGB(ring.getPixelColor(i),'r')/3,int32bittoRGB(ring.getPixelColor(i),'g')/3,int32bittoRGB(ring.getPixelColor(i),'b')/3);
    ring.setPixelColor(pos,r,g,b);
    }
  ring.show();
}

uint8_t int32bittoRGB ( uint32_t color, char value )
{
  switch ( value ) {
    case 'r': return (uint8_t)(color >> 16);
    case 'g': return (uint8_t)(color >>  8);
    case 'b': return (uint8_t)(color >>  0);
    default:  return 0;
  }
}
