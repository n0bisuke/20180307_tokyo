#include <NefryAzureIoTHub.h>
#include <Nefry.h>

void setup() {
  while(!Azure.begin()){//YourKey Example:"HostName=YourHost.azure-devices.net;DeviceId=YourDevice;SharedAccessKey=" をConfigで入力します
    Nefry.println("Azure begin Fault");
    delay(1000);
  }
  Azure.setCallback(azureCallback);
}

void azureCallback(String s) {
  Nefry.print("Azure Message arrived [");
  Nefry.print(s);
  Nefry.println("] ");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    Azure.connect();
    DataElement a = DataElement();
    a.setValue("message", analogRead(A1));
    Azure.push(&a);
    Nefry.println("pushed");
    delay(5000);
  } else {
    Nefry.println("Not connected to the Internet");
    delay(250);
  }
}
