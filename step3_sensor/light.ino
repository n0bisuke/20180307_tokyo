#include <Nefry.h>
#include <NefryDisplay.h>

#define LIGHT_SIG A1

void setup() {
  Serial.begin(115200);                //Start the Serial connection
  pinMode(LIGHT_SIG, INPUT);
  NefryDisplay.begin();
}

void loop() {
  int sensorValue = analogRead(LIGHT_SIG);
    
  NefryDisplay.print("");
  NefryDisplay.print("");
  NefryDisplay.print((String)sensorValue);
  
  if(sensorValue > 1000){
    //明るいときの処理を記述
    Nefry.setLed(255,255,255,0);
  }else{
    //暗い時の処理を記述
    Nefry.setLed(255,255,255,100);
  }

  Serial.println(sensorValue);
  delay(1000);
}