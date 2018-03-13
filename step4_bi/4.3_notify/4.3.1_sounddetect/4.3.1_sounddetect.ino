#define SOUND_SIG A1
#define THRESHOLD 200 //閾値 (変化量)
#define SAMPLINGRATE 100 //サンプリング回数

void setup() {
  Serial.begin(115200);
  pinMode(SOUND_SIG, INPUT);
}

void loop() {
    if(isSoundDetected()){
        Serial.println("反応あり");
    }else{
        //Serial.println("反応なし");
    }
    delay(100);
}

bool isSoundDetected(){
  static unsigned int sum = 0; // 積算用変数
  unsigned int avg = sum; // 前回の積算値をコピー
  bool detected = false;
  
  sum = 0;  
  // SAMPLINGRATE回数だけサンプルをとって平均値を出す
  for(int i=0; i<SAMPLINGRATE; i++) {
    int a = analogRead(SOUND_SIG);
    sum += a;
    
    // 前回の平均値よりTHRESHOLD以上大きい値がとれたらdetected
    if (a >= ((avg/SAMPLINGRATE)+THRESHOLD)) detected = true;
  }
  
  Serial.println(sum/SAMPLINGRATE); // デバッグ用シリアル出力
  return detected;
}