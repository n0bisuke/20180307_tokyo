#include <HTTPClient.h>

String BASE_URL = "http://f-io.net/d1/";
String DEVICE_TOKEN = ""; //デバイストークンを指定
String CHANNEL = ""; //利用するチャンネルを指定

//String ENDPOINT = BASE_URL + DEVICE_TOKEN + "/?" + CHANNEL + "=";
String ENDPOINT = "https://qiita.com/n0bisuke/items/26ce42781f00bb43beec.json";
int analog;
  
void setup() {
  Serial.begin(115200);
}

void loop() {
  HTTPClient http;
  
  analog = analogRead(A1);
  http.begin(ENDPOINT);
  int httpCode = http.GET();
  
  if(httpCode > 0) {
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    
    if(httpCode == HTTP_CODE_OK) {
      Serial.println("data:" + (String)analog);
//      String payload = http.getString();
//      Serial.println(payload);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  
  http.end();

  delay(5000);
}
