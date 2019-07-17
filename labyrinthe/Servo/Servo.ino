#include <Servo.h>                //On inclue la bibliothèque afin de controlé le servomoteur

Servo servoX;            //On déclare le premier servomoteur qui va controler l'axe horizontal
Servo servoY;           //On déclare le deuxieme servomoteur qui va controler l'axe vertical
int joyX = A0;         //On connecte la broche X du joystick au PIN A0 de notre Arduino Uno
int joyY = A1;        //On connecte la broche Y du joystick au PIN A1 de notre Arduino Uno
int val1 = 0;
int val2 = 0;

void setup() {
  servoX.attach(9);                //On connecte le servomoteur X au pin 9 de notre arduino  
  servoY.attach(10);              //On connecte le servomoteur Y au pin 10 de notre arduino
  pinMode (joyX, INPUT);         //On déclare l'entrée X de notre arduino   
  pinMode (joyY, INPUT);        //On déclare l'entrée Y de notre arduino   
  Serial.begin(9600);
}

void loop() {
  val1 = analogRead(joyX);                    //On lis la valeur de X sur le joystick
  if (val1 <= 513) {                         //Si le l'axe vertical et inférieur ou égal à 513
    val1 = map(val1, 0, 1023, 70, 110);     //On lui donne les limites inférieur et supérieur pour le départ et la déstination, syntaxe : val1 = map(valeur inférieux de départ, valeur supérieur de départ, valeur inférieur à la déstination, valeur supérieur à la déstination);
  }
  servoX.write(val1);                     // prend comme argument la valeur du servo-moteur
  
  val2 = analogRead(joyY);                    //On lis la valeur de X sur le joystick
    if (val1 <= 513) {                       //Si le l'axe vertical et inférieur ou égal à 513
  val2 = map(val2, 0, 1023, 75, 105);       //On lui donne les limites inférieur et supérieur pour le départ et la déstination, syntaxe : val1 = map(valeur inférieux de départ, valeur supérieur de départ, valeur inférieur à la déstination, valeur supérieur à la déstination);
  }
  servoY.write(val2);                     // prend comme argument la valeur du servo-moteur
  delay(15);
  
}
