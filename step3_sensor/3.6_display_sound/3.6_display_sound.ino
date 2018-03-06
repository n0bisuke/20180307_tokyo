#include <Nefry.h>
#include <NefryDisplay.h>

#define SOUND_SIG A1

void setup() {
  Serial.begin(115200); //Start the Serial connection
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
  
  if(sum > 1000){
    Nefry.setLed(255,255,255,100);
    NefryDisplay.print("");
    NefryDisplay.print("ON!");
    NefryDisplay.print((String)sum);
    
    delay(1000);
  }else{
    Nefry.setLed(255,255,255,0);
    
    NefryDisplay.print("");
    NefryDisplay.print("OFF");
    NefryDisplay.print((String)sum);
  }
  
  Serial.println(sum);
  delay(10);
}
