#include <Servo.h>

Servo servoX;
Servo servoY;
int joyX = A0;
int joyY = A1;
int val1 = 0;
int val2 = 0;

void setup() {
  servoX.attach(9);
  servoY.attach(10);
  pinMode (joyX, INPUT);
  pinMode (joyY, INPUT);
  Serial.begin(9600);
}

void loop() {
  val1 = analogRead(joyX);
  if (val1 <= 513) {
    val1 = map(val1, 0, 1023, 70, 110);
  }
  else {
    val1 = map(val1, 0, 1023, 60, 120);
  }
  servoX.write(val1);
  val2 = analogRead(joyY);
  val2 = map(val2, 0, 1023, 75, 105);
  servoY.write(val2);
  delay(15);

}
