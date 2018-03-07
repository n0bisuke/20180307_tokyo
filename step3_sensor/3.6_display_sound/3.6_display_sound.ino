
#define SOUND_SIG A1

void setup() {
  Serial.begin(115200);                //Start the Serial connection
  pinMode(SOUND_SIG, INPUT);
}

void loop() {
  long sum = 0;
  for(int i=0; i<32; i++){
    sum += analogRead(SOUND_SIG);
  }
  sum >>= 5;

  if(sum > 1000){
    //音が大きい場合の処理
  }else{
    //音が小さい場合の処理
  }
  
  Serial.println(sum);
  delay(10);
}
