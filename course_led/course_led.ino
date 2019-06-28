#include <Adafruit_NeoPixel.h>        //bibliothèque adafruit pour le neopixel ws2812
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
                   
#define BT_PIN_ROUGE D5 
#define BT_PIN_VERT D6
#define BT_PIN_BLEU D7

#define led_PIN D3  
#define NB_LED 50

#define ROUGE 0xFF0000uL
#define VERT  0x00FF00uL
#define BLEU  0x0000FFuL

int compteur_rouge, compteur_vert, compteur_bleu;

int buttonStateRouge, buttonStateVert, buttonStateBleu;

Adafruit_NeoPixel strip(NB_LED, led_PIN, NEO_GRB + NEO_KHZ800);



void setup()
{
  pinMode(BT_PIN_ROUGE,INPUT);
  pinMode(BT_PIN_VERT,INPUT);
  pinMode(BT_PIN_BLEU,INPUT);
  
  Serial.begin(9600);
  lcd.init(); 
  lcd.backlight(); 
    
  strip.begin();
  strip.clear();

  lcd.print("3");
  delay(1500);
  lcd.setCursor(0, 0);
  lcd.scrollDisplayRight();   
  strip.setPixelColor(0, BLEU);
  strip.show();

      
  lcd.print("2");
  lcd.setCursor(0, 0);
  lcd.scrollDisplayRight();   
  delay(1500);
  strip.setPixelColor(0, ROUGE);
  strip.show();

  lcd.print("1");
  lcd.setCursor(0, 0);
  lcd.scrollDisplayRight();   
  delay(1500);
  strip.setPixelColor(0, VERT);
  strip.show();
  
  lcd.print("GO !!");
  lcd.setCursor(0, 0);
  lcd.scrollDisplayRight();   
  strip.setPixelColor(0, ROUGE|VERT|BLEU);
  strip.show();
  
  compteur_rouge = compteur_vert = compteur_bleu = 0;
}

void loop()
{
  unsigned long color;
  int button_rouge, button_vert, button_bleu;

     /******ROUGE******/
  button_rouge = !digitalRead(BT_PIN_ROUGE);
  
  if (button_rouge){  
    if (!buttonStateRouge){
      buttonStateRouge = 1;               //si on appuis sur le bouton , on rajouter +1 
      compteur_rouge++;
    }
  }                                                                                      
  else {
    if (buttonStateRouge)                          // sinon on reste a 0
      buttonStateRouge = 0;     
  } 

     /*********BLEU*********/
     button_bleu = !digitalRead(BT_PIN_BLEU);
      if(button_bleu){  
     if(!buttonStateBleu){
         buttonStateBleu = 1; 
         compteur_bleu++;
     }
   }                                                                                      
     else {
      if (buttonStateBleu == 1)
      buttonStateBleu = 0;
     } 

     /**********VERT**********/
     button_vert = !digitalRead(BT_PIN_VERT);
      if(button_vert){  
     if(!buttonStateVert){
         buttonStateVert = 1; 
         compteur_vert++;
     }
   }                                                                                      
     else {
      if (buttonStateVert == 1)
      buttonStateVert = 0;
     }
         
     color = ROUGE;
     if (compteur_rouge == compteur_vert)
        color |= VERT;                                                    //si la couleur rouge et au meme niveau que le vert et le bleu , ca ne effacera pas la couleur 
     if (compteur_rouge == compteur_bleu)
        color |= BLEU;
     strip.setPixelColor(compteur_rouge, color);
         
     color = VERT;
     if (compteur_vert == compteur_rouge)
        color |= ROUGE;
     if (compteur_vert == compteur_bleu)
        color |= BLEU;
     strip.setPixelColor(compteur_vert, color);
         
     color = BLEU;
     if (compteur_bleu == compteur_rouge)
        color |= ROUGE;
     if (compteur_bleu == compteur_vert)
        color |= VERT;
     strip.setPixelColor(compteur_bleu, color);
     
 
     if(compteur_rouge-1 > 0) {
       color = strip.getPixelColor(compteur_rouge-1);
        color &= ~ROUGE;                                                            //on fait -1 pour chaque appuis , ce qui enleve la trace de la couleur
        strip.setPixelColor(compteur_rouge-1, color);
     }
     if(compteur_vert-1> 0) {
       color = strip.getPixelColor(compteur_vert-1);
        color &= ~VERT;
        strip.setPixelColor(compteur_vert-1, color);
     }
     if(compteur_bleu-1> 0) {
       color = strip.getPixelColor(compteur_bleu-1);
        color &= ~BLEU;
        strip.setPixelColor(compteur_bleu-1, color);
     }
 strip.show();

 if(compteur_rouge > NB_LED){
    lcd.print("rouge gagne");                                           // le joueur rouge depasse 50 led , ca affiche "joueur rouge gagne" et ca rememe les compteur a 0
    compteur_rouge = compteur_vert = compteur_bleu = 0; 
   }

 if(compteur_vert > NB_LED){
  lcd.print("vert gagne");
  compteur_vert = compteur_rouge = compteur_bleu = 0;
   }

 if(compteur_bleu > NB_LED){
  lcd.print("bleu gagne");
    compteur_bleu = compteur_rouge = compteur_vert = 0; 
 }
}
