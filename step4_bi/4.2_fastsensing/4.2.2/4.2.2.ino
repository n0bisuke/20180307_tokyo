#include <WiFiClientSecure.h> // HTTPS通信のために必要

String TARGET_HOST = "f-io.net"; //ファストセンシングのホスト名
String DEVICE_TOKEN = "metjeb44meqxgz6d"; //デバイストークンを指定
String CHANNEL = "5o2bc524"; //利用するチャンネルを指定

int analog;

void setup() {
  Serial.begin(115200);
}

void loop() {
  analog = analogRead(A1);
  String trainDelayJson = getTrainDelayJson(analog);   // JSONを取得する
  Serial.print(trainDelayJson);
  delay(5000);
}

String getTrainDelayJson(int sendData) {
  WiFiClientSecure client; // 変数を宣言

  // サーバーにHTTPSのデフォルトポート（443）でアクセスしてみる
  if ( !client.connect(TARGET_HOST.c_str(), 443) ) {
    Serial.println("接続失敗");
    return "";
  }
  
  Serial.print("data: ");
  Serial.println(sendData);
  
  client.print(String("GET /d1/"+DEVICE_TOKEN+"/?"+CHANNEL+"="+(String)sendData+" HTTP/1.1\r\n") +
               "Content-type: application/json \r\n" +
               "Host: "+TARGET_HOST.c_str()+"\r\n" +
               "Connection: close\r\n\r\n"); // HTTP-GETのリクエストメッセージを書く

  // レスポンスが来るまでちょっと待つ
  delay(1000);

  // HTTP-GETのレスポンスを保存しておく変数
  String response = "";

  // レスポンスを変数に格納する
  while (client.available()) {
    response += client.readStringUntil('\r');
  }

  Serial.println("接続成功");
  Serial.println(response);

  return response;
}
