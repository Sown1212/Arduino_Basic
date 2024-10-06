#define BLYNK_TEMPLATE_ID "TMPL6Mh5Gkv56"
#define BLYNK_TEMPLATE_NAME "ESP32 Test"
#define BLYNK_AUTH_TOKEN "TceZRbI2O1gWV0j4nOh5hpByn5fzLRQJ"

#define LED 17
#define NTC 34
#define PWM 21

const float BETA = 3950.0;
float celsius = 0;
int analogValue = 0;

#include <WiFi.h>
#include <HTTPClient.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

BlynkTimer timer;
Servo servo;

void setup() {
    servo.attach(PWM);
    pinMode(LED, OUTPUT);
    Blynk.begin(BLYNK_AUTH_TOKEN, "Wokwi-GUEST", "");
    timer.setInterval(1000, sendUptime);
}

void temper(){
  analogValue = analogRead(NTC);
  celsius = 1 / (log(1 / (4095. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
}

void sendUptime(){
  temper();
  Blynk.virtualWrite(V2, celsius);
}

void loop() {
    Blynk.run();
    timer.run();
}

BLYNK_WRITE(V0){
    int ledState = param.asInt();
    digitalWrite(LED, ledState);
}

BLYNK_WRITE(V1){
    int value = param.asInt();
    servo.write(value);
}
