#include "pitches.h"  //On ajoute cet bibliothèque afin d'obtenir les notes
 
int melody1[]={NOTE_C7, 0, 0, NOTE_G6,            //On définie troisième partie de la musique 
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0};

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

int sequence[5] = {1, 2, 3, 4, 5};
 
//On définie les boutons
int button1= 16;
int button2= 5;
int button3= 4;
int button4= 13;
int button5= 14;
//int bouton6 = 6; //bouton validation 

//Durée des notes
int noteDurations[]={12, 12, 12, 12,
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
 
 
void setup(){
  
  Serial.begin(9600);
  
  //On définie les entrée et sortie de chaque bouton + le buzzer (INPUT:entrée | OUTPUT:sortie)
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
}
 
void loop(){

Serial.print("Debut du jeu");
delay(5000);

 //On lit la broche d'entrée
 int buttonEtat = digitalRead(button1);
 
 bool gameOver = false;
 int niveau = 0; 

    /**************************************************************/
   /*SI ON APPUIE SUR LE BOUTON N°1 , La mélodie 2 se déclenchera*/
  /**************************************************************/

  //Si le bouton est pressé
  if (buttonEtat = digitalRead(button1)){
      //On parcourt les notes de la mélodie
    for (int niveau=0; niveau<=5; niveau++){
 
      int noteDuration = 1500 / noteDurations [niveau];  //On prend une seconde pour calculer la durée de la note
      tone(12, melody3 [niveau], noteDuration);

       //On définit un délais minimum entre les notes
      int pauseEntreNotes = noteDuration * 1.30;      //la durée de la note + 30% semble bien fonctionner
      delay(pauseEntreNotes);
 
      //On stop le morceau
      noTone(12);
      Serial.print("bravo , tu passe au niveau 2");
      delay(3000);
      }
  }
    else if (buttonEtat = digitalRead(button2)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
     delay(2000);
    }
    else if (buttonEtat = digitalRead(button3)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
    else if (buttonEtat = digitalRead(button4)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
    else if (buttonEtat = digitalRead(button5)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
}
  
    
   /***************************************************************/
 /*SINON SI ON APPUIE SUR LE BOUTON N°2 , La mélodie 2 se déclenchera*/
  /**************************************************************/
  
   if (buttonEtat = digitalRead(button2)){
      //On parcourt les notes de la mélodie
    for (int niveau=1; niveau<=1; niveau++){
 
      int noteDuration = 1500 / noteDurations [niveau];  //On prend une seconde pour calculer la durée de la note
      tone(12, melody3 [niveau], noteDuration);

       //On définit un délais minimum entre les notes
      int pauseEntreNotes = noteDuration * 1.30;      //la durée de la note + 30% semble bien fonctionner
      delay(pauseEntreNotes);
 
      //On stop le morceau
      noTone(12);
      Serial.print("bravo , tu passe au niveau 3");
      delay(3000);
      }
  }
    else if (buttonEtat = digitalRead(button1)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
    else if (buttonEtat = digitalRead(button3)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
    else if (buttonEtat = digitalRead(button4)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
    else if (buttonEtat = digitalRead(button5)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
  
    /***************************************************************/
 /*SINON SI ON APPUIE SUR LE BOUTON N°3 , La mélodie 2 se déclenchera*/
  /**************************************************************/

 if (buttonEtat = digitalRead(button3)){
      //On parcourt les notes de la mélodie
    for (int niveau=0; niveau<=2; niveau++){
 
      int noteDuration = 1500 / noteDurations [niveau];  //On prend une seconde pour calculer la durée de la note
      tone(12, melody3 [niveau], noteDuration);

       //On définit un délais minimum entre les notes
      int pauseEntreNotes = noteDuration * 1.30;      //la durée de la note + 30% semble bien fonctionner
      delay(pauseEntreNotes);
 
      //On stop le morceau
      noTone(12);
      Serial.print("bravo , tu passe au niveau 4");
      delay(1500);
      }
  }
    else if (buttonEtat = digitalRead(button2)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
    else if (buttonEtat = digitalRead(button1)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
    else if (buttonEtat = digitalRead(button4)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
    else if (buttonEtat = digitalRead(button5)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
  

    /***************************************************************/
 /*SINON SI ON APPUIE SUR LE BOUTON N°4 , La mélodie 2 se déclenchera*/
  /**************************************************************/
 if (buttonEtat = digitalRead(button4)){
      //On parcourt les notes de la mélodie
    for (int niveau=0; niveau<=3; niveau++){
 
      int noteDuration = 1500 / noteDurations [niveau];  //On prend une seconde pour calculer la durée de la note
      tone(12, melody4 [niveau], noteDuration);

       //On définit un délais minimum entre les notes
      int pauseEntreNotes = noteDuration * 1.30;      //la durée de la note + 30% semble bien fonctionner
      delay(pauseEntreNotes);
 
      //On stop le morceau
      noTone(12);
      Serial.print("bravo , tu passe au niveau suivant");
      delay(1500);
      }
  }
    else if (buttonEtat = digitalRead(button4)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
    else if (buttonEtat = digitalRead(button3)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
    else if (buttonEtat = digitalRead(button1)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
    else if (buttonEtat = digitalRead(button5)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }

    /***************************************************************/
 /*SINON SI ON APPUIE SUR LE BOUTON N°5 , La mélodie 2 se déclenchera*/
  /**************************************************************/

 if (buttonEtat = digitalRead(button5)){
      //On parcourt les notes de la mélodie
    for (int niveau=0; niveau<=4; niveau++){
 
      int noteDuration = 1500 / noteDurations [niveau];  //On prend une seconde pour calculer la durée de la note
      tone(12, melody3 [niveau], noteDuration);

       //On définit un délais minimum entre les notes
      int pauseEntreNotes = noteDuration * 1.30;      //la durée de la note + 30% semble bien fonctionner
      delay(pauseEntreNotes);
 
      //On stop le morceau
      noTone(12);
      Serial.print("bravo , tu as terminer la musique youpi");
      delay(1500);
      niveau+1;
      }
  }
  
    else if (buttonEtat = digitalRead(button5)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }  
    else if (buttonEtat = digitalRead(button3)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
    else if (buttonEtat = digitalRead(button4)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }   
    else if (buttonEtat = digitalRead(button1)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    delay(2000);
    }
 }
