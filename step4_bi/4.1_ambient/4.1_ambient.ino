#include <NefryAmbient.h>

NefryAmbient nefryAmbient;

void setup() {
  nefryAmbient.begin();//ambientを使えるように初期設定をします。
  Nefry.setProgramName("AmbientSimpleAnalog");//プログラム名を指定します。
}

void loop() {
  int analog;
  analog = analogRead(A1);// A1ピンの状態を取得します。
  Nefry.print("Analog:");
  Nefry.println(analog);//アナログの値を表示します。
  nefryAmbient.set(1, analog); //field,dataの順にセットします。
  nefryAmbient.send();//ambientにデータを送信します。
  Nefry.ndelay(1000);//1秒待つ
}
