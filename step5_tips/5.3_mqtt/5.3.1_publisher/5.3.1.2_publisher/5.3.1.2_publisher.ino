/*
analogRead()値を送信
*/
#include <Nefry.h>
#include <PubSubClient.h>

WiFiClient httpsClient;
PubSubClient mqttClient(httpsClient);

#define TOPIC "n0bisuke"
#define QOS 0
#define URL "mosquitto.org"
#define PORT 1883

char data[10];

void setup() {
  mqttClient.setServer(URL, PORT);
  mqttClient.setCallback(callback);
  Nefry.enableSW();
}

void loop() {
  if(!mqttClient.connected()) {
    if (mqttClient.connect(TOPIC)) {
        Serial.println("MQTT Connected.");
    }
    else {
      errorReport();
    }
  }else{
    sprintf(data, "%d", analogRead(A1));
    mqttClient.publish(TOPIC, data);
    Serial.println("published");
    delay(2000);    
  }
  
  mqttClient.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void errorReport(){
  Serial.print("Failed. Error state = ");
  
  switch (mqttClient.state()) {
    case MQTT_CONNECT_UNAUTHORIZED:
      Serial.println("MQTT_CONNECT_UNAUTHORIZED");
      break;
    case MQTT_CONNECT_BAD_CREDENTIALS:
      Serial.println("MQTT_CONNECT_BAD_CREDENTIALS");
      break;
    case MQTT_CONNECT_UNAVAILABLE:
      Serial.println("MQTT_CONNECT_UNAVAILABLE");
      break;
    case MQTT_CONNECT_BAD_CLIENT_ID:
      Serial.println("MQTT_CONNECT_BAD_CLIENT_ID");
      break;
    case MQTT_CONNECT_BAD_PROTOCOL:
      Serial.println("MQTT_CONNECT_BAD_PROTOCOL");
      break;
    case MQTT_CONNECTED:
      Serial.println("MQTT_CONNECTED");
      break;
    case MQTT_DISCONNECTED:
      Serial.println("MQTT_DISCONNECTED");
      break;
    case MQTT_CONNECT_FAILED:
      Serial.println("MQTT_CONNECT_FAILED");
      break;
    case MQTT_CONNECTION_LOST:
      Serial.println("MQTT_CONNECTION_LOST");
      break;
    case MQTT_CONNECTION_TIMEOUT:
      Serial.println("MQTT_CONNECTION_TIMEOUT");
      break;
  }
      
  delay(5000); // Wait 5 seconds before retrying
}
