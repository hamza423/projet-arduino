//#include <LiquidCrystal.h>
//LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

int led_milieu=5;             //Led du milieu
int led_droite=4;            // Led de droite
int led_gauche=16;          // Led de gauche
int equipe_droite=0;       // compteur de victoire pour l'équipe de droite
int equipe_gauche=0;      // compteur de victoire pour l'équipe  de gauche

void setup() {
  
  Serial.begin(9600);
  pinMode(led_milieu, OUTPUT);
  pinMode(led_droite, OUTPUT);         //On définie chaque led en sortie
  pinMode(led_gauche, OUTPUT);

  pinMode(12, INPUT);                  //On définie l'entrer des boutons
  pinMode(14,  INPUT);
}

void loop() {
  Serial.println("---------------Préparer vous !---------------");
  digitalWrite(led_milieu, LOW);    
  digitalWrite(led_droite, LOW);            //Masse à 0 pour chaque led
  digitalWrite(led_gauche, LOW);
  int t = random(1,9);                      
  delay(t*500);                            // delai d'attente entre 1 x 500ms et 9 x 500ms
  digitalWrite(led_milieu, HIGH);          
  int equipe1 = 0;                        //Déclaration de nos variable : equipe_1 et equipe2
  int equipe2 = 0;                        
  while (!equipe1 && !equipe2) {
  equipe1=digitalRead(12);                //Déclenchement du bouton de droite et de gauche 
  equipe2=digitalRead(14);                
  }

  if(equipe1 && !equipe2) {
    digitalWrite(led_droite, HIGH);  
    digitalWrite(led_gauche, LOW);
    equipe_droite++;                // le joueur de droite a appuyer avant le joueur de gauche, on incremente le nbre de victoire
    equipe_gauche;
    Serial.println("Le joueur de droite marque un point ");
    Serial.print("Équipe droite = ");
    Serial.println(equipe_droite);                            //Affiche le score pour l'équipe de droite à chaque tour dans le moniteur de série 
    Serial.print("Équipe gauche = ");
    Serial.println(equipe_gauche);
  }
  
  else if(!equipe1 && equipe2) {
    digitalWrite(led_droite, LOW);  
    digitalWrite(led_gauche, HIGH);
    equipe_gauche++;
    equipe_droite; 
    Serial.println("Le joueur de gauche marque un point");   
    Serial.print("Équipe droite");
    Serial.println(equipe_droite);
    Serial.print("Équipe gauche");
    Serial.println(equipe_gauche);
  }
  else {
    digitalWrite(led_droite, HIGH);         //Sinon nos led sont éteint
    digitalWrite(led_gauche, HIGH);  
  }
  delay(200);          

if (equipe_droite==3) {
  Serial.println("joueur de droite gagne");
  Serial.print("Joueur Droite");
  Serial.println(equipe_droite);                        //Si le joueur de droite ateint le score de 3 cela va afficher dans le moniteur de série 
  Serial.print("Joueur Gauche");
  Serial.println(equipe_gauche);
  equipe_droite=0;
  equipe_gauche=0;
}
if (equipe_gauche==3) {
  Serial.println("joueur de gauche gagne ");
  Serial.print("Joueur Droite");
  Serial.println(equipe_droite);
  Serial.print("Joueur Gauche");
  Serial.println(equipe_gauche);
  equipe_droite=0;
  equipe_gauche=0;
  }
}
