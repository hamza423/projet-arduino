#include <Adafruit_NeoPixel.h>        //bibliothèque adafruit pour le neopixel ws2812

#define led_PIN 4                     //

#define BT_PIN_ROUGE 8 
#define BT_PIN_VERT 7 
//#define BT_PIN_JAUNE 6 
//#define BT_PIN_BLEU 5

#define NB_LED 50

#define rouge 0xFF0000

int button_compteur;
int buttonStateRouge;
//int buttonStateVert;
//int buttonStateJaune;
//int buttonStateBleu;


Adafruit_NeoPixel strip(NB_LED, led_PIN, NEO_GRB + NEO_KHZ800);


void setup()
{
  pinMode(BT_PIN_ROUGE,INPUT);
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  buttonStateRouge = 0;
  //buttonStateVert = 0;
}

void loop()
{
 int button_rouge = !digitalRead(BT_PIN_ROUGE);
  Serial.println(button_compteur,DEC);
   if(button_rouge){  
     if(!buttonStateRouge){
         buttonStateRouge = 1; 
         button_compteur++;
     }
   }
     else {
      if (buttonStateRouge == 1)
      buttonStateRouge = 0;
     }    
     strip.setPixelColor(button_compteur, strip.Color(255, 0, 0));
    if(button_compteur>0)
     strip.setPixelColor(button_compteur-1, strip.Color(0, 0, 0));
 strip.show();

  if(button_compteur > NB_LED){
     button_compteur = 0; 
   
   }
}
