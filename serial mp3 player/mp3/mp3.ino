#include <SoftwareSerial.h>

#define ARDUINO_RX 5
#define ARDUINO_TX 6
SoftwareSerial mySerial(ARDUINO_RX, ARDUINO_TX);


static int8_t Send_buf[8] = {0} ;
                                 
#define NEXT_SONG 0X01 
#define PREV_SONG 0X02 

#define CMD_PLAY_W_INDEX 0X03 
#define VOLUME_UP_ONE 0X04
#define VOLUME_DOWN_ONE 0X05
#define CMD_SET_VOLUME 0X06
#define SET_DAC 0X17
#define CMD_PLAY_WITHVOLUME 0X22 
#define CMD_SEL_DEV 0X09 
#define DEV_TF 0X02         
#define SLEEP_MODE_START 0X0A
#define SLEEP_MODE_WAKEUP 0X0B
#define CMD_RESET 0X0C
#define CMD_PLAY 0X0D 
#define CMD_PAUSE 0X0E 
#define CMD_PLAY_WITHFOLDER 0X0F
#define STOP_PLAY 0X1
#define PLAY_FOLDER 0X17
#define SET_CYCLEPLAY 0X19
#define SET_DAC 0X17


void setup()
{
  Serial.begin(9600);
mySerial.begin(9600);
delay(500);
   sendCommand(CMD_SEL_DEV, DEV_TF);
delay(200);

}
void loop()
{
sendCommand(CMD_PLAY_WITHVOLUME, 0X0F01);
delay(1000);
}

void sendCommand(int8_t command, int16_t dat)
{
 delay(20);
 Send_buf[0] = 0x7e; //starting byte
 Send_buf[1] = 0xff; //version
 Send_buf[2] = 0x06; //the number of bytes of the command without starting byte and ending byte
 Send_buf[3] = command; //
 Send_buf[4] = 0x00;//0x00 = no feedback, 0x01 = feedback
 Send_buf[5] = (int8_t)(dat >> 8);//datah
 Send_buf[6] = (int8_t)(dat); //datal
 Send_buf[7] = 0xef; //ending byte
 for(uint8_t i=0; i<8; i++)//
 {
   mySerial.write(Send_buf[i]) ;//send bit to serial mp3
   Serial.print(Send_buf[i],HEX);//send bit to serial monitor in pc
 }
 Serial.println();
}
