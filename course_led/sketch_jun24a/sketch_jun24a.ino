#include <Adafruit_NeoPixel.h>
#define led_rouge 6  
#define BT_PIN_ROUGE 8 

#define nombre_rouge 30 

#define rouge 0xFF0000

int dernierButtonStateRouge = 0;
int buttonStateRouge =0;
int button_compteur=0;


Adafruit_NeoPixel strip = Adafruit_NeoPixel(nombre_rouge, rouge, NEO_GRB + NEO_KHZ800);

void lectureBouton(){
   buttonStateRouge = digitalRead(BT_PIN_ROUGE);
}


void setup()
{
  strip.begin();
  pinMode(BT_PIN_ROUGE,INPUT);
  strip.show();
}

void reset_compteur(){
 button_compteur=0;
   
}

void loop()
{
   lectureBouton();   
   
   dernierButtonStateRouge,buttonStateRouge,&button_compteur,rouge; 

  if(button_compteur >28){
        reset_compteur(); 
   }
}
