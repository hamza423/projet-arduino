#include "pitches.h"

int melody1[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,         //On définie première partie de la musique 
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0};

int melody2[] = {NOTE_G6, NOTE_E7, NOTE_G7,         //On définie deuxième partie de la musique 
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0};

int melody3[] = {NOTE_C7, 0, 0, NOTE_G6,            //On définie troisième partie de la musique 
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0};


int melody4[] = {NOTE_G6, NOTE_E7, NOTE_G7,          //On définie quatrième partie de la musique
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0};


int melody5[] = {NOTE_C7, 0, 0, NOTE_G6,            //On définie cinquième partie de la musique
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
};

int noteDurations[]= {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

//int sequence[5]; //on ne dépasse pas la partie 5 : quelle utilité ?

//On définie les boutons
int button1 = 16;
int button2 = 5; 
int button3 = 4; 
int button4 = 0; 
int button5 = 2; 
//int bouton6 = 6; //bouton validation 

void setup() {
  //On définie les entrée et sortie de chaque bouton + le buzzer (INPUT:entrée | OUTPUT:sortie)
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  //pinMode(button6, INPUT);
  //pinMode(buzz, OUTPUT);
}

void loop(){
 
  //On lit la broche d'entrée
  int buttonEtat = digitalRead(button1);
 
  //Si le bouton est pressé
  if (buttonEtat == 0){
 
    //On parcourt les notes de la mélodie
    for (int thisNote=0; thisNote <12; thisNote++){
 
      int noteDuration = 1500 / noteDurations [thisNote];       //On prend une seconde pour calculer la durée de la note
      tone(12, melody1 [thisNote], noteDuration);
 
       //On définit un délais minimum entre les notes
      int pauseEntreNotes = noteDuration * 1.30;   //la durée de la note + 30% semble bien fonctionner
      delay(pauseEntreNotes);
 
      //stop music
      noTone(12);
    }
  }
  /***************************************************************/
 /*ON DONNE LES MEMES CONDITIONS AU BOUTON 2 COMME POUR LE BOUTON 1*/
  /**************************************************************/
  // buttonEtat = digitalRead(button2);
 
  if (buttonEtat == 1){
 
    for (int thisNote=0; thisNote <12; thisNote++){
 
      int noteDuration = 1500 / noteDurations [thisNote];      
      tone(12, melody2 [thisNote], noteDuration);
 
      int pauseEntreNotes = noteDuration * 1.30;  
      delay(pauseEntreNotes);
 
      noTone(12);
    }
  }
  /***************************************************************/
 /*ON DONNE LES MEMES CONDITIONS AU BOUTON 3 COMME POUR LE BOUTON 1*/
  /**************************************************************/
   //buttonEtat = digitalRead(button3);
 
  if (buttonEtat == 1){
 
    for (int thisNote=0; thisNote <12; thisNote++){
 
      int noteDuration = 1500 / noteDurations [thisNote];      
      tone(12, melody3 [thisNote], noteDuration);
  
      int pauseEntreNotes = noteDuration * 1.30; 
      delay(pauseEntreNotes);
 
      //stop music
      noTone(12);
    }
  }
  /***************************************************************/
 /*ON DONNE LES MEMES CONDITIONS AU BOUTON 4 COMME POUR LE BOUTON 1*/
  /**************************************************************/
  // buttonEtat = digitalRead(button4);
 
  
  if (buttonEtat == 1){
 
  
    for (int thisNote=0; thisNote <12; thisNote++){
 
      int noteDuration = 1500 / noteDurations [thisNote];      
      tone(12, melody4 [thisNote], noteDuration);
 
       
      int pauseEntreNotes = noteDuration * 1.30;   
      delay(pauseEntreNotes);
 
      //stop music
      noTone(12);
    }
  }
  /***************************************************************/
 /*ON DONNE LES MEMES CONDITIONS AU BOUTON 5 COMME POUR LE BOUTON 1*/
  /**************************************************************/
// buttonEtat = digitalRead(button5);
 

  if (buttonEtat == 1){
 
   
    for (int thisNote=0; thisNote <12; thisNote++){
 
      int noteDuration = 1500 / noteDurations [thisNote];      
      tone(12, melody5 [thisNote], noteDuration);
 
       //On défini un délai minimal entre elles
      int pauseEntreNotes = noteDuration * 1.30;   
      delay(pauseEntreNotes);
 
      noTone(12);
    }
  }
  
}
