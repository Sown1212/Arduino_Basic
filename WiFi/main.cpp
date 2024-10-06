#include <WiFi.h>
#include <HTTPClient.h>
// #include <ArduinoJson.h>

HTTPClient http;

const char* ssid = "Wokwi-GUEST";
const char* pass = "";

String URL = "https://api.openweathermap.org/data/2.5/weather?";
String APIKEY = "9e0ed03f0af44de06083f6e6d7b8e9e9";

String lat = "21.02858967870085";
String lon = "105.80346869078116";

void setup() {
  Serial.begin(9600);
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, pass, 6);
  while(WiFi.status() != WL_CONNECTED){
    delay(100);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
  Serial.println("IP : " + String(WiFi.localIP()));
}

void loop() {
  delay(100);
  http.begin(URL+"lat="+lat+"&lon="+lon+"&units=metric&appid="+APIKEY);
  int httpCode = http.GET();
  if(httpCode > 0){
    String JSON_DATA = http.getString();
    Serial.println(JSON_DATA);
  }
  delay(60000);
}
