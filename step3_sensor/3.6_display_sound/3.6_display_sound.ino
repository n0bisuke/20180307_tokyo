#include <Nefry.h>
//フルカラーLED　ランダムにカラーが変わります。
#define SEED_PIN A0

void setup() {
  randomSeed(analogRead(SEED_PIN));
}

int red,green,blue;
void loop() {
  red=random(255);//random関数は0-255の数値をランダムに返します。
  green=random(255);
  blue=random(255);
  Nefry.setLed(red,green,blue);//LEDがランダムに点灯します。
  String color="Red:";color+=red;
  color+=" Green:";color+=green;
  color+=" Blue:";color+=blue;
  Nefry.ndelay(3000);//1秒待つ
}
