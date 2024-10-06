#define X A2
#define Y A3
#define NTC A4
#define LDR A5

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), button_ISR, FALLING);
}

void button_ISR(){
  detachInterrupt(digitalPinToInterrupt(2));
  Serial.println("button has been pressed");

}

void loop() {
  Serial.println("Value :" + String(analogRead(X)) + " " + String(analogRead(Y)) + " " + String(analogRead(NTC)) + " " + String(analogRead(LDR)));
  delay(500);
}