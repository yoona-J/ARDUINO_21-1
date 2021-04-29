int motorPin = 9;   //트랜지스터 베이스 (B)에 연결할 핀

void setup() {
  pinMode (motorPin, OUTPUT);   // 9번 핀 출력으로 설정

}

void loop() {
  for (int duty = 0; duty < 256; duty++) {
    analogWrite (motorPin, duty);  // 9번 핀에 duty 변수 값 1씩 설정
    delay (50);    // 해당 듀티비를 50 ms 지연
  }

  // 정지 상태에서 최대 속도까지 가속한 뒤에 다시 최대 속도에서 서서히 감속을 하면서 정지되는 것을 반복한다.
  for (int duty = 255; duty >= 0; duty--) {
    analogWrite (motorPin, duty);
    delay (50);
  }
}
