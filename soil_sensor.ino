int ledPin = 13;   // 오렌지 보드 13번 연결
int solidsensorPinA = A0;  // 아날로그 출력 핀 (AO).A0 핀에 연결
int solidsensorPinD = 2;   // 디지털 출력 핀 (DO).2 번 핀에 연결

void setup() {
  // put your setup code here, to run once:
  pinMode (ledPin, OUTPUT);    //13번 핀 출력으로 선택
  pinMode (solidsensorPinD, INPUT);    //2번 핀 출력으로 선택

  Serial.begin (9600);
  Serial.println("YL-69 sensor measure start");
  Serial.println();

}

void loop() {
  // 센서 모듈의 아날로그 출력 (AO)에 연결된 오렌지 보드의 A0핀을 읽어 analogValue 변수에 저장하고
  // 디지털 입력 (DO)에 연결된 오렌지 보드의 2번 핀을 읽어 digitalValue 변수에 저장한다.
  int analogValue = analogRead (solidsensorPinA);
  int digitalValue = digitalRead (solidsensorPinD);

  // 아날로그 출력 핀 값이 800보다 크면 수분이 부족한 것으로 판단하고
  // 오렌지 보드의 13번 led가 켜지고 수분이 검출되면 LED는 꺼진다.
  if (analogValue > 800) {
    digitalWrite (ledPin, HIGH);
  } else {
    digitalWrite (ledPin, LOW);
  }

  Serial.print("Analog value : ");
  Serial.println(analogValue);

  Serial.print("Digital value : ");
  Serial.println(digitalValue);
  Serial.println();

  delay (2000);

}
