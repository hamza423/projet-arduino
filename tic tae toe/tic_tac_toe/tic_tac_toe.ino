#include <Keypad.h>
#include <LedControl.h>
#include <avr/io.h>
#include <avr/wdt.h>

#define Reset_AVR() wdt_enable(WDTO_30MS); while(1) {} 

LedControl lc=LedControl(12,10,11,1);

bool player1=true,q1=false,q2=false,q3=false,q4=false,q5=false,q6=false,q7=false,q8=false,q9=false;
int row,col,rowPlays,colPlays,result,player,winner;
char hexaKeys[4][3] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
int plays[3][3] = {
  {0,0,0},
  {0,0,0},
  {0,0,0}
};
byte rowPins[4] = {8, 7, 6, 5};
byte colPins[3] = {4, 3, 2};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, 4, 3); 

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,0);
  lc.clearDisplay(0);
}

void loop() { 
  int customKey = customKeypad.getKey();
  painting(customKey);
  win(result);
  if (winner==1) {
    lc.clearDisplay(0);
    while (winner==1) {
      char customKey = customKeypad.getKey();
      if (customKey=='0') {
        Reset_AVR();
      }
      lc.setLed(0,1,4,true);
      lc.setLed(0,2,5,true);
      lc.setLed(0,3,6,true);
      lc.setLed(0,4,7,true);
      lc.setLed(0,4,6,true);
      lc.setLed(0,4,5,true);
      lc.setLed(0,4,4,true);
      lc.setLed(0,4,3,true);
      lc.setLed(0,4,2,true);
      lc.setLed(0,4,1,true);
      lc.setLed(0,4,0,true);
      lc.setLed(0,5,0,true);
      lc.setLed(0,6,0,true);
      lc.setLed(0,3,0,true);
      lc.setLed(0,2,0,true);
    }
  }
  else if (winner==2) {
    lc.clearDisplay(0);
    while (winner==2) {
      char customKey = customKeypad.getKey();
      if (customKey=='0') {
        Reset_AVR();
      }
      lc.setLed(0,2,0,true);
      lc.setLed(0,3,0,true);
      lc.setLed(0,4,0,true);
      lc.setLed(0,5,0,true);
      lc.setLed(0,2,1,true);
      lc.setLed(0,2,2,true);
      lc.setLed(0,2,3,true);
      lc.setLed(0,2,4,true);
      lc.setLed(0,3,4,true);
      lc.setLed(0,4,4,true);
      lc.setLed(0,5,4,true);
      lc.setLed(0,5,5,true);
      lc.setLed(0,5,6,true);
      lc.setLed(0,5,7,true);
      lc.setLed(0,4,7,true);
      lc.setLed(0,3,7,true);
      lc.setLed(0,2,7,true);
    }
  }
}

int round_player() {
  if (player1) {
    player1=false;
    result=1;
  }
  else {
    player1=true;
    result=2;
  }
  return result;
}

void win(int player) {
  if (plays[0][0]==player && plays[0][1]==player && plays[0][2]==player) {
    winner=player;
  }
  else if (plays[1][0]==player && plays[1][1]==player && plays[1][2]==player) {
    winner=player;
  }
  else if (plays[2][0]==player && plays[2][1]==player && plays[2][2]==player) {
    winner=player;
  }
  else if (plays[0][0]==player && plays[1][0]==player && plays[2][0]==player) {
    winner=player;
  }
  else if (plays[0][1]==player && plays[1][1]==player && plays[2][1]==player) {
    winner=player;
  }
  else if (plays[0][2]==player && plays[1][2]==player && plays[2][2]==player) {
    winner=player;
  }
  else if (plays[0][0]==player && plays[1][1]==player && plays[2][2]==player) {
    winner=player;
  }
  else if (plays[0][2]==player && plays[1][1]==player && plays[2][0]==player) {
    winner=player;
  }
}

void switch_on_led(int col, int row, int colPlays, int rowPlays) {
  if (player1) {
    lc.setLed(0,col,row,true);
    lc.setLed(0,col+1,row-1,true);
  }
  else {
    lc.setLed(0,col,row-1,true);
    lc.setLed(0,col+1,row,true);
  }
  plays[rowPlays][colPlays]=round_player();
}

void painting(int bottone) {
  switch (bottone) {    
  case 49:
    if (!q1){
      switch_on_led(0,7,0,0);
      q1=true;
    }
    break; 
  case 50:
    if (!q2) {
      switch_on_led(3,7,0,1);
      q2=true;
    }    
    break;    
  case 51:
    if (!q3) {
      switch_on_led(6,7,0,2);
      q3=true;
    }    
    break;    
  case 52:
    if (!q4) {
      switch_on_led(0,4,1,0);
      q4=true;
    }
    break;    
  case 53:
    if (!q5) {
      switch_on_led(3,4,1,1);
      q5=true;
    }
    break;    
  case 54:
    if (!q6) {
      switch_on_led(6,4,1,2);
      q6=true;
    }    
    break;    
  case 55:
    if (!q7) {
      switch_on_led(0,1,2,0);
      q7=true;
    }    
    break;
  case 56:
    if (!q8) {
      switch_on_led(3,1,2,1);
      q8=true;
    }    
    break;    
  case 57: 
    if (!q9) {
      switch_on_led(6,1,2,2); 
      q9=true;
    } 
    break;    
  case 48:
    Reset_AVR();
    break;
  }
}
