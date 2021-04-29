#include <SoftwareSerial.h>

SoftwareSerial ESPserial (2, 3);    // TX, RX

void setup() {
  Serial.begin (9600);    // 시리얼 통신 속도 초기화
  ESPserial.begin (9600);    // 소프트웨어 시리얼 통신 속도 초기화 + 시작
  
  Serial.println("");
  Serial.println("AT Command for ESP8266 ESP-01 module");
  Serial.println("");
}

void loop() {
  if (ESPserial.available ()) {     //ESP 모듈에서 데이터가 송신되면,
    Serial.write (ESPserial.read ());    // 수신된 모듈 데이터를 읽어 시리얼 모니터에 출력
  } if (Serial.available ()) {   // 사용자의 시리얼 입력 데이터가 수신되면,
    ESPserial.write (Serial.read ());   // 수신된 데이터를 읽어 시리얼 모니터에 출력
  }
}
