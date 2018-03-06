/*
    Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleServer.cpp
    Ported to Arduino ESP32 by Evandro Copercini
*/
#include <Nefry.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/

#define SERVICE_UUID        "D5875408-FA51-4763-A75D-7D33CECEBC31"
#define CHARACTERISTIC_UUID "A4F01D8C-A037-43B6-9050-1876A8C23584"

//d5875408-fa51-4763-a75d-7d33cecebc31
//a4f01d8c-a037-43b6-9050-1876a8c23584

bool deviceConnected = false; //BLEデバイスの接続確認用
String deviceName = Nefry.getModuleID(); //NefryのデバイスID
uint8_t value = 0;
BLECharacteristic *pCharacteristic;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  Serial.println(deviceName);

  BLEDevice::init("NefryBT-n0bisuke");
  BLEServer *pServer = BLEDevice::createServer();
//  BLEServer *pServer = new BLEServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setValue("Hello World says Neil");
  pService->start();
  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}

void loop() {
  // put your main code here, to run repeatedly:

  if (deviceConnected) {
    Serial.printf("*** NOTIFY: %d ***\n", value);
    pCharacteristic->setValue(&value,  random(255));
    pCharacteristic->notify();
//    pCharacteristic->indicate();
//    value++;
  }
  
  delay(2000);
}

