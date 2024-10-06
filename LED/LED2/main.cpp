void setup() {
  for(int i = 0; i < 8;i++){
    pinMode(i, OUTPUT);
  }
}
int n = 0;
void bai5(){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      digitalWrite(j, HIGH); // bật bóng thứ j

      // bật n bóng sau bóng j
      for(int k = j - n; k < j; k++){
        digitalWrite(k, HIGH);
      }

      delay(500);

      digitalWrite(j, LOW);// tắt bóng j 

      // tắt n bóng sau bóng j
      for(int k = j - n; k < j; k++){
        digitalWrite(k, LOW);
      }

    }
    n++; // mỗi 1 vòng số bỏng theo sau tăng 1
    if(n == 8){
      n = 0; //khi tất cả đèn đều sáng thì lặp lại từ đầu
    }
  }
}


void bai6(){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8-i; j++){
      digitalWrite(j, HIGH);
      delay(500);
      digitalWrite(j, LOW);
      }
      digitalWrite(7-i, HIGH);
    }
}

void loop() {
  //bai5();
  //bai6();
}

