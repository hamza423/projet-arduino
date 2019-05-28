#include "pitches.h"  //On ajoute cet bibliothèque afin d'obtenir les notes
 
//notes in the melody
int melody1[]={261};

int melody2[] = {330};

int melody3[] = {392};

int melody4[] = {523};

int melody5[] = {440};
 
//On définie les boutons
int button1= 16;
int button2= 5;
int button3= 4;
int button4= 13;
int button5= 14;
//int bouton6 = 6; //bouton validation 

//note durations. 4=quarter note / 8=eighth note
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
 
  //On définie les entrée et sortie de chaque bouton + le buzzer (INPUT:entrée | OUTPUT:sortie)
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
}
 
void loop(){
 Serial.begin(9600);

Serial.print("Debut du jeu");
delay(1000);

 //On lit la broche d'entrée
 int buttonEtat = digitalRead(button1);
     buttonEtat = digitalRead(button2);
     buttonEtat = digitalRead(button3);
     buttonEtat = digitalRead(button4);
     buttonEtat = digitalRead(button5);
 
 bool gameOver = true;


    /***************************************************************/
 /*SINON SI ON APPUIE SUR LE BOUTON N°1 , La mélodie 2 se déclenchera*/
  /**************************************************************/

  //Si le bouton est pressé
  while(!gameOver){
  if (buttonEtat = digitalRead(button1)){
      //On parcourt les notes de la mélodie
    for (int niveau=0; niveau <12; niveau++){
 
      int noteDuration = 1500 / noteDurations [niveau];  //On prend une seconde pour calculer la durée de la note
      tone(12, melody3 [niveau], noteDuration);

       //On définit un délais minimum entre les notes
      int pauseEntreNotes = noteDuration * 1.30;      //la durée de la note + 30% semble bien fonctionner
      delay(pauseEntreNotes);
 
      //On stop le morceau
      noTone(12);
      Serial.print("bravo , tu passe au niveau 2");
      delay(1500);
      }
  }
    else if (buttonEtat = digitalRead(button2)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
    else if (buttonEtat = digitalRead(button3)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
    else if (buttonEtat = digitalRead(button4)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
    else if (buttonEtat = digitalRead(button5)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
  
    
   /***************************************************************/
 /*SINON SI ON APPUIE SUR LE BOUTON N°2 , La mélodie 2 se déclenchera*/
  /**************************************************************/
  
   if (buttonEtat = digitalRead(button2)){
      //On parcourt les notes de la mélodie
    for (int niveau=1; niveau <12; niveau++){
 
      int noteDuration = 1500 / noteDurations [niveau];  //On prend une seconde pour calculer la durée de la note
      tone(12, melody3 [niveau], noteDuration);

       //On définit un délais minimum entre les notes
      int pauseEntreNotes = noteDuration * 1.30;      //la durée de la note + 30% semble bien fonctionner
      delay(pauseEntreNotes);
 
      //On stop le morceau
      noTone(12);
      Serial.print("bravo , tu passe au niveau 3");
      delay(1500);
      }
  }
    else if (buttonEtat = digitalRead(button1)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
    else if (buttonEtat = digitalRead(button3)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
    else if (buttonEtat = digitalRead(button4)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
    else if (buttonEtat = digitalRead(button5)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
  
    /***************************************************************/
 /*SINON SI ON APPUIE SUR LE BOUTON N°3 , La mélodie 2 se déclenchera*/
  /**************************************************************/

 if (buttonEtat = digitalRead(button3)){
      //On parcourt les notes de la mélodie
    for (int niveau=2; niveau <12; niveau++){
 
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
    }
    else if (buttonEtat = digitalRead(button1)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
    else if (buttonEtat = digitalRead(button4)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
    else if (buttonEtat = digitalRead(button5)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
  

    /***************************************************************/
 /*SINON SI ON APPUIE SUR LE BOUTON N°4 , La mélodie 2 se déclenchera*/
  /**************************************************************/
 if (buttonEtat = digitalRead(button4)){
      //On parcourt les notes de la mélodie
    for (int niveau=3; niveau <12; niveau++){
 
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
    }
    else if (buttonEtat = digitalRead(button3)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
    else if (buttonEtat = digitalRead(button1)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
    else if (buttonEtat = digitalRead(button5)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }

    /***************************************************************/
 /*SINON SI ON APPUIE SUR LE BOUTON N°5 , La mélodie 2 se déclenchera*/
  /**************************************************************/
 if (buttonEtat = digitalRead(button5)){
      //On parcourt les notes de la mélodie
    for (int niveau=4; niveau <12; niveau++){
 
      int noteDuration = 1500 / noteDurations [niveau];  //On prend une seconde pour calculer la durée de la note
      tone(12, melody3 [niveau], noteDuration);

       //On définit un délais minimum entre les notes
      int pauseEntreNotes = noteDuration * 1.30;      //la durée de la note + 30% semble bien fonctionner
      delay(pauseEntreNotes);
 
      //On stop le morceau
      noTone(12);
      Serial.print("bravo , tu as terminer la musique youpi");
      delay(1500);
      }
  }
    else if (buttonEtat = digitalRead(button5)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
    else if (buttonEtat = digitalRead(button3)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
    else if (buttonEtat = digitalRead(button4)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
    else if (buttonEtat = digitalRead(button1)) {
    gameOver=true;
    Serial.print("Mauvais boutton");
    }
  }
 }
