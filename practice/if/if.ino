int value = 100;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if(value > 50){
    Serial.println("合格");
  }else{
    Serial.println("不合格");
  }
  delay(10000);
}
