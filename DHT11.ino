#include <DHT.h>   //라이브러리로 DHT 헤더파일 추가
#include <DHT_U.h>

#define DHTPIN 2 // DHT11 2번 핀, 오렌지 보드 2번 판 연결

DHT dht (DHTPIN, DHT11); //DHT11 센서 초기화

void setup() {
  Serial.begin (9600);
  Serial.println ("DHT11 measure start");
  Serial.println();
  dht.begin();
}

void loop() {
  float humiValue = dht.readHumidity();   // 습도를 읽어서 변수에 저장
  float tempValue = dht.readTemperature();   // 섭씨온도를 읽어 변수에 저장

  if (isnan (humiValue) || isnan (tempValue) {   // 만약 센서 값을 읽지 못하면
    Serial.println("Failed to read from DHT sensor");
    return;
  }

  Serial.print("Humidity : ");
  Serial.print(humiValue);
  Serial.println(" &RH");
  Serial.print("Temperature : ");
  Serial.print(tempValue);
  Serial.println(" C";
  Serial.println();

  delay (2000);

}
