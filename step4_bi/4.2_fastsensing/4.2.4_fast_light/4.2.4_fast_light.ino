#include <NefryFastSensing.h>
NefryFastSensing fastSensing;

#define LIGHT_SIG A1

void setup() {
    Serial.begin(115200);                //Start the Serial connection
    pinMode(LIGHT_SIG, INPUT);
    fastSensing.begin("qxw7sc6a5j4szy2q", "aadengbq", "jnvkphjs", "wempgxld");
}

void loop() {
    int sensorValue = analogRead(LIGHT_SIG);
    fastSensing.setValue(2, sensorValue); //channel3
    fastSensing.push();
    Serial.println(sensorValue);
    
    delay(5000);
}
