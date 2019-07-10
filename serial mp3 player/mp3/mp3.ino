#include <SoftwareSerial.h>
 
#define ARDUINO_RX 5  
#define ARDUINO_TX 6  
 
SoftwareSerial mp3(ARDUINO_RX, ARDUINO_TX);
 
static int8_t Send_buf[8] = {0}; 
static uint8_t ansbuf[10] = {0}; 

String mp3Answer;

boolean autoResume = true;


void setup() {
  Serial.begin(9600;
  mp3.begin(9600);
  delay(500);
}

void loop() {
  char c = ' ';

  if ( Serial .available() )
    {
      c = Serial.read();
      sendMP3Command(c);
    }
}
