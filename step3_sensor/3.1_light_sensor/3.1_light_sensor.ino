#include <Nefry.h>

#define LIGHT_SIG A1

void setup() {
  Serial.begin(115200);                //Start the Serial connection
  pinMode(LIGHT_SIG, INPUT);
}

void loop() {
  int sensorValue = analogRead(LIGHT_SIG);
  Serial.println(sensorValue);
  delay(1000);
}
