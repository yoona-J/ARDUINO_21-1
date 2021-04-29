#include <Servo.h>  // Servo 헤더 파일 추가

Servo myservo;  // 서보 제어를 위한 오브젝트 생성

int pos = 0;  // 서보 위피 저장 변수 초기화

void setup() {
  myservo.attach (9);  // 9번 판에 서보모터 신호선을 연결

}

void loop() {
  // put your main code here, to run repeatedly:

  for (pos = 0; pos <= 180; pos += 1) {  // 0 -> 180
   myservo.write (pos);  // 0부터 1도씩 증가
   delay (15);      // 15 ms 지연
  }

  for (pos = 180; pos >= 0; pos -= 1) {  // 180 -> 0
    myservo.write (pos);    // 180부터 1씩 감소
    delay (15);       // 15 ms 지연
  }
}
