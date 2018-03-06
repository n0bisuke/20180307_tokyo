#include <WiFi.h>

int count = 0;

void setup() {
    Serial.begin(115200);
}

void loop() {
    Serial.println("light_sleep_enter");
    esp_sleep_enable_timer_wakeup(10000000); //10 seconds
    int ret = esp_light_sleep_start();
    Serial.printf("light_sleep: %d %d\n", ret, ++count);
}
