#include <TimerOne.h>

uint8_t segment[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D,0x7D,0x07, 0x7F, 0x6F};
uint8_t number = 0;

void setup(){
    for(int i = 0;i < 12; i++)
      pinMode(i, OUTPUT);
    
    Timer1.initialize(1000000); 
    Timer1.attachInterrupt(timerCallback);
}

void timerCallback(){
    if(number == 100)
      number = 0;
    else
      number++;
}

void show(){
  uint8_t count = number;
  for(int i = 11; i > 7; i--){
    uint8_t temp = (int)count%10;
    count/=10;
    for(int j = 0; j < 8; j++){
      bool isBit = bitRead(segment[temp], j);
      digitalWrite(j, isBit);
    }
    digitalWrite(i, LOW);
    delay(10);
    digitalWrite(i, HIGH);
  }
}

void loop(){
  show();
}

