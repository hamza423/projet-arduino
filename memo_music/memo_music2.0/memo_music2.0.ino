#include "pitches.h"  //On ajoute cet bibliothèque afin d'obtenir les notes

int melody[] = {
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


/*melody lancement*/
int son[] = {261, 330, 392 ,466 ,523};

/*Mélody game over*/
int son1[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,};
  
int sequence[5];
 
//On définie les boutons
int button1 = 16;
int button2 = 5;
int button3 = 4;
int button4 = 14;
int button5 = 13;
int speaker = 12;
 
 
void setup()
{
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

void loop()
{
  Serial.print("APPUYER SUR UN BOUTON POUR COMMENCER");
 
  //Attente de pression sur une touche.
  lectureBouton();

  //Témoin de lancement du jeu.
  melodieLancement();
  delay(2000);

  //Début du jeu
  boolean gameOver = false;
  int presse;
  int niveau = 0;
  while(!gameOver)
  {
    nouvelleNote(niveau); //Rajoute une note à la séquence.
    jouerSequence(niveau); //Joue la séquence

    for(int i=0; i<=niveau; i++) //Attend que le joueur tape chaque note de la séquence
    {
      presse = lectureBouton(); //Lecture du bouton appuyé par le joueur
      jouerNote(presse); //Joue la note du joueur
      if(presse!=sequence[i]) //Si la note est bonne, on continue, sinon GameOver
      {
        gameOver = true;
        Serial.print("GAME OVER");
        melodieGameOver();
      }
      if(gameOver) {break;}
    }
    Serial.print("NIVEAU SUIVANT");
    niveau++;
    delay(1000);
  }
if (niveau<=5) {
 
      int noteDuration = 1000 / noteDurations [niveau];
      tone(8, melody [niveau], noteDuration);
      noTone(speaker);
    Serial.print("BRAVO , VOUS AVEZ RÉUSSI !!"); 
  }
}
//---------------------------------------------------------
//Fonction de lecture des boutons.
  //L'arduino vérifie les boutons un par un, mais comme la vitesse d'une vérification
  //est de l'ordre de la nanoseconde, l'ensemble est presque instantané.
int lectureBouton()
{
  int boutonPresse = 0;

  while(!boutonPresse)
  {
    if(digitalRead(button1))
    {
      boutonPresse = 1;
    }
    if(digitalRead(button2))
    {
      boutonPresse = 2;
    }
    if(digitalRead(button3))
    {
      boutonPresse = 3;
    }
    if(digitalRead(button4))
    {
      boutonPresse = 4;
    }
    if(digitalRead(button5))
    {
      boutonPresse = 5;
    }
  }
  return boutonPresse;
}
//---------------------------------------------------------
//Fonction de lumière qet de son
void jouerNote(int numero)
{
  switch(numero)
  {
    case 1:
      digitalRead(button1);
      break;
    case 2:
      digitalRead(button2);
      break;
    case 3:
      digitalRead(button3);
      break;
    case 4:
      digitalRead(button4);
      break;
      case 5:
      digitalRead(button5);
      break;
  }
  tone(speaker, son[numero-1]); //Le tableau commence à 0 (non à 1)
  delay(800);

  noTone(speaker);

  delay(200);
}

//---------------------------------------------------------
//Joue toute la séquence
void jouerSequence(int niveau)
{
  for(int i=0; i<=niveau; i++)
  {
    jouerNote(sequence[5]);
  }
}
//---------------------------------------------------------
//Nouvelle note aléatoire
void nouvelleNote(int niveau)
{
  sequence[niveau] = (int)random(1,5);
}

//---------------------------------------------------------
//Témoin lancement (petite séquence)
void melodieLancement()
{
  tone(speaker, son[0]);
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
