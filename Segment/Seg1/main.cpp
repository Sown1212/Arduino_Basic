int arr_pin[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int number[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void setup() {
  for(int i = 0; i < 7; i++){
    pinMode(i, OUTPUT);
  }

  for(int j = 0; j < 10; j++){
    for(int i = 0; i < 8; i++){
      bool isBit = bitRead(number[j], i); // đọc bit thư i trong number[j]
      digitalWrite(arr_pin[i], isBit); // bật tắt chân thư i theo isBit
    }
    delay(1000);
  }
}

void loop() {
 
}