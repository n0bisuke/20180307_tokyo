#define SOUND_SIG A1

void setup() {
  Serial.begin(115200);                //Start the Serial connection
  pinMode(SOUND_SIG, INPUT);
}

void loop() {
  int sensorValue = analogRead(SOUND_SIG);
  
  long sum = 0;
  for(int i=0; i<32; i++){
    sum += analogRead(SOUND_SIG);
  }
  sum >>= 5;
  
  Serial.println(sum);
  delay(10);
}
