#include <Adafruit_NeoPixel.h>        //bibliothèque adafruit pour le neopixel ws2812

#define led_PIN 4                     

#define BT_PIN_ROUGE 8 
#define BT_PIN_VERT 7 
#define BT_PIN_BLEU 5

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
  strip.begin();
  strip.clear();
  strip.setPixelColor(0, ROUGE|VERT|BLEU);
  strip.show();
  delay(1000);
  strip.setPixelColor(0, ROUGE|VERT);
  strip.show();
  delay(1000);
  strip.setPixelColor(0, ROUGE);
  strip.show();
  delay(1000);
  strip.setPixelColor(0, VERT);
  strip.show();
  delay(1000);
  strip.setPixelColor(0, BLEU);
  strip.show();
  delay(1000);
  strip.setPixelColor(0, ROUGE|VERT|BLEU);
  strip.show();
  
  compteur_rouge = compteur_vert = compteur_bleu = 0;
}

void loop()
{
  unsigned long color;
  int button_rouge, button_vert, button_bleu;
  
  /****************************************************/
              /******BOUTON ROUGE******/
/****************************************************/
  button_rouge = !digitalRead(BT_PIN_ROUGE);
  
  if (button_rouge){  
    if (!buttonStateRouge){
      buttonStateRouge = 1; 
      compteur_rouge++;
    }
  }                                                                                      
  else {
    if (buttonStateRouge)
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
        color |= VERT;
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
        color &= ~ROUGE;
        strip.setPixelColor(compteur_rouge-1, color);
     }
     if(compteur_vert-1>0) {
       color = strip.getPixelColor(compteur_vert-1);
       Serial.print(color, HEX);
       Serial.print(" ");
        color &= ~VERT;
       Serial.println(color, HEX);
        strip.setPixelColor(compteur_vert-1, color);
     }
     if(compteur_bleu-1>0) {
       color = strip.getPixelColor(compteur_bleu-1);
        color &= ~BLEU;
        strip.setPixelColor(compteur_bleu-1, color);
     }
 strip.show();

 if(compteur_rouge > NB_LED){
    Serial.println("rouge a gagne");
    compteur_rouge = compteur_vert = compteur_bleu = 0; 
   }

 if(compteur_vert > NB_LED){
    compteur_vert = 0; 
   }

 if(compteur_bleu > NB_LED){
    compteur_bleu = 0; 
   }    
}
