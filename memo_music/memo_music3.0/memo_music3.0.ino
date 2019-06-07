#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#include "pitches.h"  //On ajoute cet bibliothèque afin d'obtenir les notes

int mario[] = 
  {
   NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

int noteDurations[]={
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

/*melody lancement*/
int son[] = {261, 330, 392 ,466 ,523};

/*Mélody game over*/
int son1[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,};
  
int sequence[5] = {1, 2, 3, 4, 5};
 
//On définie les boutons
int button1 = 16;
int button2 = 0;
int button3 = 2;
int button4 = 14;
int button5 = 13;
int speaker = 12;
int presseornot=0;
//Durée des notes

int gameOver = 0;
  int presse;
  int i =0;

//---------------------------------------------------------
//Fonction de lecture des boutons.
  //L'arduino vérifie les boutons un par un, mais comme la vitesse d'une vérification
  //est de l'ordre de la nanoseconde, l'ensemble est presque instantané.
int lectureBouton()
{
  int boutonPresse = -1;

  if(boutonPresse=-1)
  {
    if(!digitalRead(button1))
    {
      boutonPresse = 2;
    }
    if(!digitalRead(button2))
    {
      boutonPresse = 4;
    }
    if(!digitalRead(button3))
    {
      boutonPresse = 1;
    }
    if(!digitalRead(button4))
    {
      boutonPresse = 5;
    }
    if(!digitalRead(button5))
    {
      boutonPresse = 3;
    }
  }
  return boutonPresse;
}
 
//---------------------------------------------------------
//Fonction de son
void jouerNote(int numero)
{
  switch(numero)
  {
    case 1:
      son[1];
      break;
    case 2:
      son[2];
      break;
    case 3:
      son[3];
      break;
    case 4:
      son[4];
      break;
    case 5:
      son[5];
      break;
  }
  tone(speaker, son[numero-1]); //Le tableau commence à 0 (non à 1)
  delay(800);

  noTone(speaker);

  delay(200);
}

//---------------------------------------------------------
//Témoin lancement (petite séquence lumineuse)
void melodieLancement()
{
 
   tone(speaker,son[0]);
  delay(300);
  tone(speaker, son[1]);
  delay(300);
  tone(speaker, son[2]);
  delay(300);
  tone(speaker, son[3]);
  delay(300);
  tone(speaker, son[4]);
  delay(300);
  noTone(speaker);
}

//---------------------------------------------------------
//Témoin Game Over
void melodieGameOver()
{
  tone(speaker, son[4]);
  delay(150);
  tone(speaker, son[3]);
  delay(150);
  delay(150);
  tone(speaker, son[2]);
  delay(150);
  tone(speaker, son[1]);
  delay(150);
  tone(speaker, son[0]);
  delay(150);
  delay(500);
  noTone(speaker);
}

void setup()
{
  lcd.init(); 
  lcd.backlight();
  
  Serial.begin(9600);
 
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(speaker, OUTPUT);
  
}

//---------------------------------------------------------
// Boucle principale.
// La loop tournera jusqu'à extinction ou reset.

void loop(){
       
    if(!digitalRead(button1))
    {
      presse = 2;
      presseornot=1;
    }
    if(!digitalRead(button2))
    {
      presse = 4;
      presseornot=1;
    }
    if(!digitalRead(button3))
    {
      presse = 1;
      presseornot=1;
    }
    if(!digitalRead(button4))
    {
      presse = 5;
      presseornot=1;
    }
    if(!digitalRead(button5))
    {
      presse = 3;
      presseornot=1;
    }
   
  if(gameOver==0){
    lcd.print("ALLEZ-Y");
    melodieLancement();
    gameOver = 1   ;
    
    }

  if(gameOver==1)
    {
      if (presse!=-1){
      gameOver=2;
      delay(1000);
      presseornot=0;
     }
    }
    
  //Début du jeu
  
  if(gameOver==2)
  {
    
    if (presseornot==1){
      jouerNote(presse);
    
    if (i<4){
      
      if(presse!=sequence[i]) //Si la note est bonne, on continue, sinon GameOver
      {
        gameOver = 0;
        lcd.print("GAME OVER");
        melodieGameOver();
        i=0;
      }
      else{
        i++;
        }
      }
      else
      {
 for (int thisNote=0; thisNote <12; thisNote++){

      int noteDuration = 1500 / noteDurations [thisNote];
      tone(12, mario [thisNote], noteDuration);

      int pauseEntreNotes = noteDuration * 1.30;
      delay(pauseEntreNotes);
      noTone(12);
    }
     lcd.print("BRAVO , VOUS AVEZ RÉUSSI !!");
     delay(1000); 
     lcd.clear();
     gameOver= 0;
     i=0;
    }
      delay(500);
      presseornot=0;
    }
  }
}
