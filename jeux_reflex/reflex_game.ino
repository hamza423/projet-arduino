#include <LiquidCrystal.h>      //On inclus la bibliotheque LiquidCrystal
LiquidCrystal ecran(12,11,5,4,3,2);


int ledm=12; //Led du milieu
int ledd=11; // Led de droide
int ledg=13; // Led de gauche
int victd=0; // compteur victoire joueur de droite
int victg=0; // compteur victoire joueur de gauche
void setup() {
  
  Serial.begin(9600);
  pinMode(ledm, OUTPUT);
  pinMode(ledd, OUTPUT);   //On définie chasque led en sortie
  pinMode(ledg, OUTPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  //ecran.begin(16, 2);
  
}

void loop() {
  Serial.println("--------------- PRET ? ---------------");
  
  digitalWrite(ledm, LOW);    
  digitalWrite(ledd, LOW); 
  digitalWrite(ledg, LOW);
  int t = random(1,9);
  delay(t*500);     // delai d'attente entre 1 x 500ms et 9 x 500ms
  digitalWrite(ledm, HIGH); 

  int s1 = 0;
  int s2 = 0;
  while (!s1 && !s2) {
  s1=digitalRead(9);  
  s2=digitalRead(10);  
  }

  if(s1 && !s2) {
    digitalWrite(ledd, HIGH);  
    digitalWrite(ledg, LOW); 
    victd++;  // le joueur de droite a appuyer avant le joueur de gauche, on incremente le nbre de victoire
  }
  else if(!s1 && s2) {
    digitalWrite(ledd, LOW);  
    digitalWrite(ledg, HIGH); 
    victg++;
  }else {
    digitalWrite(ledd, HIGH);  
    digitalWrite(ledg, HIGH);  
  }
  delay(200);          

if (victd==3) {
  Serial.println("joueur de droite gagne");
  Serial.print("Joueur Droite");
  Serial.println(victd);
  Serial.print("Joueur Gauche");
  Serial.println(victg);
  victd=0;
  victg=0;
}
if (victg==3) {
  Serial.println("joueur de gauche gagne ");
  Serial.print("Joueur Droite");
  Serial.println(victd);
  Serial.print("Joueur Gauche");
  Serial.println(victg);
  victd=0;
  victg=0;
}
if (victg==3) {
   ecran.print("123");
}
else if (victd==3) {
  ecran.print("321");
}
}
