#include <Servo.h>       //bibliothèque pour le servo-motor s90
  
Servo servo1;                  //On déclare nos deux servo moteur , un pour horizontale et l'autre pour le vertical
Servo servo2;

#define pin_X A0                   //pin du joystick horizontal "VRx"
#define pin_Y A1                   //pin joystick vertical "VRy"



int val;
int pos = 0;  
void setup() 
{
  servo1.attach(8);           //On "attache" le servo n°1 a la broche 8 
  servo2.attach(9);          //On "attache" le servo n°2 a la broche 9
}
  
void loop() {
 for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
}
