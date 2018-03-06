#include <Nefry.h>
#include <NefryDisplay.h>

#define LIGHT_SIG A1

void setup() {
  Serial.begin(115200); //Start the Serial connection
  pinMode(LIGHT_SIG, INPUT);
  NefryDisplay.begin();
}

void loop() {
  int sensorValue = analogRead(LIGHT_SIG);
    
  NefryDisplay.print("");
  NefryDisplay.print("");
  NefryDisplay.print((String)sensorValue);
  
  Serial.println(sensorValue);
  delay(1000);
}
