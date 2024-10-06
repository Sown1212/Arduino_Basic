#define LED1 = 8;
#define LED2 = 9;
#define LED3 = 10;
#define LED4 = 11;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void bai1(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW);
  delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, HIGH);
  delay(1000);
}

void bai2(){
  for(int i = 8; i < 12; i++){
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
    delay(1000);
  }
}

void bai3(){
  for(int i = 8; i < 11; i++){
    digitalWrite(i, HIGH);
    digitalWrite(i+1, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
    digitalWrite(i+1, LOW);
    delay(1000);
  }
}

void bai4(){
  for(int i = 8; i <12; i++){
    digitalWrite(i, HIGH);
    delay(1000);
  }
  for(int i = 11; i > 7; i--){
    digitalWrite(i, LOW);
    delay(1000);
  }
}

void loop() {
  //bai1();
  //bai2();
  //bai3();
  //bai4();
}
