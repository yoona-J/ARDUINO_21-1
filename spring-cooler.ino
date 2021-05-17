// 토양 수분 센서를 통해 흙 속의 수분을 파악해 일정 값보다 커지게 되면
// 스프링클러 물 공급 모터를 작동시킨다.

int soilPin = A0;  //토양 수분 센서


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    int value = analogRead(soilPin); // 토양 수분 센서 값 불러오기

  // 토양이 완전히 마른 상태 -> 1023
  // 토양이 완전히 젖은 상태 -> 200 미만
  
    if (value > 800)
    {
      analogWrite(9, 128);
      digitalWrite(10, LOW);
    }else{
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
    
    }
    
    Serial.print("read sensor value : ");
    Serial.println(value);

    delay(600000); // 10분에 한번 체크하는 것으로 수정하였습니다.
}
