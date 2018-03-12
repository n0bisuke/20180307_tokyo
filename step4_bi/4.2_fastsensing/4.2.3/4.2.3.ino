#include <WiFiClientSecure.h> // HTTPS通信のために必要

#define LIGHT_SIG A1

String TARGET_HOST = "f-io.net"; //ファストセンシングのホスト名
String DEVICE_TOKEN = "metjeb44meqxgz6d"; //デバイストークンを指定
String CHANNEL = "5o2bc524"; //利用するチャンネルを指定

void setup() {
  Serial.begin(115200);
}

void loop() {
  int analog = analogRead(LIGHT_SIG);
  String response = postFastsensing(analog);   // JSONを取得する
  Serial.print(response);
  delay(5000);
}

String postFastsensing(int postData) {
  WiFiClientSecure client; // 変数を宣言
  // サーバーにHTTPSのデフォルトポート（443）でアクセスしてみる
  if (!client.connect(TARGET_HOST.c_str(), 443) ) {
    Serial.println("接続失敗");
    return "";
  }
  
  Serial.print("data: ");
  Serial.println(postData);
  // String data = "{\"api_version\": \"2016-05-02\", \"resource_type\": \"channel_data\", \"action\": \"update\", \"device_token\": \""+DEVICE_TOKEN+"\", \"resource\": [ { \"token\": \""+CHANNEL+"\", \"value\": "+ postData +" } ] }";
//  String data = "api_version=2016-05-02&resource_type=channel_data&action=update&device_token="+DEVICE_TOKEN+"&resource=[{\"token\":\""+CHANNEL+"\",\"value\":"+postData+"}]";
  String data = "{\"api_version\":\"2016-05-02\",\"resource_type\":\"channel_data\",\"action\":\"update\",\"device_token\":\""+DEVICE_TOKEN+"\",\"resource\":[\"{\"token\":\""+CHANNEL+"\",\"value\":"+postData+"}\"]}";
  Serial.println(data);
  
  client.println("POST /api HTTP/1.1");
  client.println("Content-Type: application/json");
  client.println("Host: " + TARGET_HOST);
  client.println("User-Agent: NefryBT/1.0");
  client.print("Content-Length: ");
  client.println(data.length());
  client.println("Connection: close");
  client.println();
  client.println(data);
  
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
