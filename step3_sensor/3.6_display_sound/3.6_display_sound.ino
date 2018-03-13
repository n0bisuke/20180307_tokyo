#include <Nefry.h>
#include <NefryDisplay.h>

#define SOUND_SIG A1

void setup() {
  Serial.begin(115200); //Start the Serial connection
  pinMode(SOUND_SIG, INPUT);
  NefryDisplay.begin(); //ディスプレイを使いますよ宣言
}

void loop() {
  long sum = 0;
  for(int i=0; i<32; i++){
    sum += analogRead(SOUND_SIG);
  }
  sum >>= 5;

  if(sum > 1000){
    //音が大きい場合の処理
    Nefry.setLed(255,255,255,100);
    
    NefryDisplay.print("");
    NefryDisplay.print("on!");
    NefryDisplay.print((String)sensorValue);
    delay(1000);
  }else{
    //音が小さい場合の処理
    Nefry.setLed(255,255,255,0);

    NefryDisplay.print("");
    NefryDisplay.print("off");
    NefryDisplay.print((String)sensorValue);
  }
  
  Serial.println(sum);
  delay(10);
}
