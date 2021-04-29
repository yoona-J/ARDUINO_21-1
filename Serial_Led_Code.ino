const int ledpin = 13; //led 핀 번호

void setup() {
  // put your setup code here, to run once:
  
  pinMode (ledPin, OUTPUT); //led 핀 출력 설정
  Serial.begin (9600);  //시리얼 통신 속도를 9600 bps으로 초기화한다
  }

void loop() {
  // put your main code here, to run repeatedly:
  if (serial.available () > 0) {    //(시리얼 포트에서 수신된 바이트 값을 가져오는 함수)데이터가 수신 되면 ->
    int button_cmd = Serial.read(); //수신 버퍼 값을 변수에 저장 -> 버퍼에 저장된 데이터 1byte를 읽는다.
  
    if (button_cmd == '1'){        //데이터가 1이면 ->
      digitalWrite (ledPin, HIGH); //LED ON
      Serial.println ("LED ON");   //print 'LED ON'
      }
    else if (button_cmd == '0') {  //데이터가 0이면 ->
      digitalWrite (ledPin, LOW);  //LED OFF
      Serial.println ("LED OFF");  //print 'LED OFF'
      }
    else {                         //1이나 0의 데이터가 입력이 되지 않았을 때 ->
      Serial.println ("Unknown command!");   //오류 커멘드를 송신한다
      Serial.println ("PushButton command input : ");
      }
  }
}
