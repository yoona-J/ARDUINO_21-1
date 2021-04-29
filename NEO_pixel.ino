#include <Adafruit_NeoPixel.h>   // 네오픽셀 LED 라이브러리 추가
#define PIN 6
#define NUMPIXELS 12   // 네오픽셀 LED 개수를 입력한다

// 네오픽셀 LED 초기 설정
Adafruit_NeoPicel pixels = Adafruit_NeoPixel (NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// delatval은 대기 시간 값을 저장하는 변수로, delay() 함수의 매개변수로 사용된다.
// delay() 함수의 매개변수 단위는 ms를 사용한다.
// delayval 변수에 500이 저장됐기 때문에 delay(delayval);은  500ms = 0.5초 대기한다는 의미이다.
int delayval = 500;

void setup() {
  pixels.begin();    // 핀 모드 설정
}

void loop() {
  for (int i = 0; i < NUMPIXELS; i++) {    // 네오픽셀 수 만큼 반복 실행
    // LED 색을 설정하는 함수, 첫번째 매개변수에는 색 픽셀의 순번을 입력하고 두번째 매개변수에는 색깔의 RGB 값을 pixel,
    // color()의 함수의 매개변수로 작성한다
    pixels.setPixelColor (i, pixels.Color(0, 150, 0));
    pixels.show();    // 해당 픽셀에 색깔을 출력
    delay(delayval);    // 0.5초 대기
  }
}
