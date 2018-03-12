#include <NefryAmbient.h>

#define LIGHT_SIG A1
NefryAmbient nefryAmbient;

void setup() {
    Serial.begin(115200);
    pinMode(LIGHT_SIG, INPUT);
    nefryAmbient.begin(); //ambientを使えるように初期設定をします。
    Nefry.setProgramName("AmbientSimpleAnalog"); //プログラム名を指定します。
}

void loop() {
    int lightValue = analogRead(LIGHT_SIG); //LIGHT_SIG(A1)の状態を取得します。
    Serial.print("Light:");
    Serial.println(lightValue); //値を表示します。
    nefryAmbient.set(1, lightValue); //field,dataの順にセットします。
    nefryAmbient.send(); //ambientにデータを送信します。
    delay(1000); //1秒待つ
}
