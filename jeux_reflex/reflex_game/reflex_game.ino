#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int buttonG = 12;
int buttonD = 14;
int led_milieu = 2;           // Broche de la LED du milieu
int led_droite = 13;          // Broche de la LED de droite
int led_gauche = 15;        // Broche de la LED de gauche
int equipe_droite = 0;     // Variable => On stocke la valeur (Read) du Score à 0 pour l'équipe de droite
int equipe_gauche = 0;    // Variable => On stocke la valeur (Read) du Score à 0 pour l'équipe  de gauche

void setup() {
  // On initilaise le LCD pour .....
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  //On définit les LED comme des sorties
  pinMode(led_milieu, OUTPUT);
  pinMode(led_droite, OUTPUT);
  pinMode(led_gauche, OUTPUT);
  //On définit les boutons comme des entrées
  pinMode(12, INPUT);
  pinMode(14,  INPUT);;
}

void loop() {
  lcd.print("Preparez-vous ");
  // On déclare les LED éteintes à l'état LOW
  delay(3000);
  digitalWrite(led_milieu, LOW);
  digitalWrite(led_droite, LOW);
  digitalWrite(led_gauche, LOW);
  // delais aléatoire pour allumer la LED du milieu (entre 500ms 4 500ms)
  int t = random(1, 9);
  delay(t * 500);
  digitalWrite(led_milieu, HIGH);
  //Déclaration de nos variables : equipe_1 et equipe2 (lecture de l'etat des boutons ?)
  int equipe1 = 0;
  int equipe2 = 0;
  // Détection du premier signal impulsé par le bouton de droite ou de gauche
  while (!equipe1 && !equipe2) {
    equipe1 = digitalRead(12);
    equipe2 = digitalRead(14);
  }
  // le joueur de droite a appuyer avant le joueur de gauche, on incremente le nbre de victoire  (equipe2 different de 1 et equipe1=1 : etat bouton)
  if (equipe1 && !equipe2) {
    digitalWrite(led_droite, HIGH);
    digitalWrite(led_gauche, LOW);
    equipe_droite++;
    equipe_gauche;
    //Affiche le score pour l'équipe de droite à chaque tour dans l'afficheur LCD
    lcd.setCursor(0, 0);
    lcd.print("Le joueur D a ");
    lcd.setCursor(0, 1);                              //On définit l'emplacement du texte écrit au moment oú l'écran LCD sera affiché , donc ("Le joueur D a") sera afficher en haut et (String(equipe_droite)+" points") sera afficher en bas
    lcd.print(String(equipe_droite) + " points");
    delay(3000);
    lcd.setCursor(0, 0);
    lcd.print("Equipe droite ");
    lcd.print(equipe_droite);
    lcd.setCursor(0, 1);
    lcd.print("Equipe gauche ");
    lcd.print(equipe_gauche);
    delay(2000);
    lcd.clear();                                     //On efface l'affichage LCD
  }
  // le joueur de gauche a appuyer avant le joueur de droite, on incremente le nbre de victoire (equipe1 different de 1 et equipe2=1 : etat bouton)
  else if (!equipe1 && equipe2) {
    digitalWrite(led_droite, LOW);
    digitalWrite(led_gauche, HIGH);
    equipe_gauche++;
    equipe_droite;
    //Affiche le nouveau score pour les 2 équipes à chaque tour dans le moniteur de série
    lcd.setCursor(0, 0);
    lcd.print("Le joueur G a ");
    lcd.setCursor(0, 1);
    lcd.print(String(equipe_gauche) + " points");
    delay(3000);
    lcd.setCursor(0, 0);
    lcd.print("Equipe droite ");
    lcd.print(equipe_droite);
    lcd.setCursor(0, 1);
    lcd.print("Equipe gauche ");
    lcd.print(equipe_gauche);
    delay(2000);
    lcd.clear();
  }
  delay(200);
  //On vérifie si le joueur de droite ateint le score de 3, on affiche dans le moniteur de série qu'il a gagné et son score
  if (equipe_droite == 3) {
    lcd.print("Joueur Droite :");
    lcd.print(equipe_droite);                        //Si le joueur de droite ateint le score de 3 cela va afficher dans le moniteur de série
    lcd.print("Joueur Gauche :");
    lcd.print(equipe_gauche);
    lcd.clear();
    lcd.print("equipe D gagne ! ");
    lcd.scrollDisplayRight();                       //On va faire défiler "equipe D gagne !" vers la droite
    equipe_droite = 0;
    equipe_gauche = 0;
  }
  //On vérifie si le joueur de gauche ateint le score de 3, on affiche dans le moniteur de série qu'il a gagné et son score
  if (equipe_gauche == 3) {
    lcd.setCursor(0, 0);
    lcd.print("Joueur Droite :");
    lcd.print(equipe_droite);
    lcd.setCursor(0, 1);
    lcd.print("Joueur Gauche :");
    lcd.print(equipe_gauche);
    lcd.clear();                                   //On efface l'affichage
    lcd.print("equipe G gagne ! ");
    lcd.scrollDisplayRight();                     //On va faire défiler "equipe D gagne !" vers la gauche
    equipe_droite = 0;
    equipe_gauche = 0;
  }
}
