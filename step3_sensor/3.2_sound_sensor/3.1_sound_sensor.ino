#include <Nefry.h>
#include <NefryDisplay.h>

#define SOUND_SIG A1

void setup() {
  Serial.begin(115200);                //Start the Serial connection
  pinMode(SOUND_SIG, INPUT);
  NefryDisplay.begin();
}

void loop() {
  int sensorValue = analogRead(SOUND_SIG);
  
  long sum = 0;
  for(int i=0; i<32; i++){
    sum += analogRead(SOUND_SIG);
  }
  sum >>= 5;
  
  NefryDisplay.print("");
  NefryDisplay.print("");
  NefryDisplay.print((String)sum);
  if(sum > 1000){
    Nefry.setLed(255,255,255,0);
  }else{
    Nefry.setLed(255,255,255,100);
  }
  Serial.println(sum);
  delay(10);
}
