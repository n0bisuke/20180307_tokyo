
## Azure IoT Hub (Tips紹介のみ)

https://azure.microsoft.com/ja-jp/services/iot-hub/

![](https://i.gyazo.com/e3bfdfd8664c4ee5a3486ec7b4d1fbf1.jpg)

* IoTデバイスとの双方向通信
* デバイス認証とセキュリティ向上
* 大量のデバイスをクラウド管理

などを行えるMicrosoftのサービスです。

## Nefry BTにAzure IoT Hub向けのライブラリがあります。

このような形で利用できます。

```5.5.ino
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
    a.setValue("EspAnalog", analogRead(A0));
    Azure.push(&a);
    Nefry.println("pushed");
    delay(2000);
  } else {
    Nefry.println("Not connected to the Internet");
    delay(250);
  }
}
```

## Nefry BTのWebコンソールでキーを設定

* PCなどからWebコンソールにアクセスし、`Data Store`を選択

![](https://i.gyazo.com/d7499928a193e688742d58dbf4cec1b3.png)

* Azure IoT Hubの接続キーを設定します。

![](https://i.gyazo.com/16c1bc05e595080e8fcadac8becc759f.png)

するとNefry BTが再起動します。

## 確認

![](https://i.gyazo.com/db219fb64db5d90b2c27f88adfe07a34.png)

定期的にデータがAzure IoT Hubに送信されます。