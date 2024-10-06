void setup() {
  pinMode(10, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), ham_xu_li_ngat, FALLING);
}

bool status_led = true;

void ham_xu_li_ngat(){
  digitalWrite(10, status_led);
  status_led = !status_led;
  delayMicroseconds(20000);
}

void loop() {
  // if(digitalRead(2) == 0){
  //   digitalWrite(10, status_led);
  //   status_led = !status_led;
  // }
}