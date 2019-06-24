#include <Adafruit_NeoPixel.h>
#define led_rouge 6  
#define BT_PIN_ROUGE 8 

#define NB_ROUGE 50

#define rouge 0xFF0000

int button_compteur;
int buttonStateRouge;

Adafruit_NeoPixel strip(NB_ROUGE, led_rouge, NEO_GRB + NEO_KHZ800);


void setup()
{
  pinMode(BT_PIN_ROUGE,INPUT);
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  buttonStateRouge = 0;
}

void loop()
{
 int v = !digitalRead(BT_PIN_ROUGE);
  Serial.println(button_compteur,DEC);
   if(v){  
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

  if(button_compteur > NB_ROUGE){
     button_compteur = 0; 
   }
}
