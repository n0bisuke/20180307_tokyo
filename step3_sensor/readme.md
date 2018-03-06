
## Groveセンサー

* Seeed社が開発した規格
* 初心者でも配線知識なくセンサーを使うことができる

![](https://i.gyazo.com/4fedfbb4ae2abef4dc9d7f546ee5c0ad.png)

## Groveセンサーの使い方

Nefry BTでのGroveセンサーの使い方は簡単で、Grove用のポートに接続するだけです。

センサーによって通信方式が違うので、Seeed社のWikiを確認して仕様を確認しましょう。

* アナログ
* デジタル
* I2C
* SPI
* UART

のどれかとなっています。今回利用するセンサーは以下の二つですが、どちらもアナログの値が取れます。

* [Grove Light Sensor](http://wiki.seeed.cc/Grove-Light_Sensor/)
* [Grove Sound Snesor](http://wiki.seeed.cc/Grove-Sound_Sensor/)

写真のように、Nefry BTの左下のA0表示の部分に差し込みましょう。

![](https://i.gyazo.com/2d0d0015df703b109a2cd54f683dc573.jpg)

## Nefry BTにコードを書き込む

[Light Sensorのコード](3.1_light_sensor/3.1_light_sensor.ino)を書き込んでみましょう。

Arduino IDEのファイル -> 新規ファイルから新規のファイルを作成し、コードを貼り付けて書き込みをしてみましょう。

センサーをA0に刺していて、プログラム的にA1となってますが シルク印刷のミスとなっています。（すみません）

## 値の確認 / シリアルモニタ

ツール -> シリアルモニタを選択しましょう。

![](https://i.gyazo.com/92f5d6b5ad2de451ccece0b1a6a777f1.png)

値が確認できれば成功です。

**手をかざして暗くしたりして確認してみましょう。**

## Nefry BTの再起動

再起動の仕方を紹介します。

左下のResetボタンを押すとNefry BTが再起動します。

調子が悪い時は再起動しましょう。

USBの抜き差しでも再起動できますが、シリアルモニタが切断されてしまうのでResetボタンを利用した方が開発しやすいです。

## チャレンジ

* 暗くなったらLEDがついて、明るくなったらLEDが消えるプログラムを書いてみましょう。

ヒント

```
#include <Nefry.h>
#include <NefryDisplay.h>

#define LIGHT_SIG A1

void setup() {
  Serial.begin(115200);                //Start the Serial connection
  pinMode(LIGHT_SIG, INPUT);
  NefryDisplay.begin();
}

void loop() {
  int sensorValue = analogRead(LIGHT_SIG);
    
  NefryDisplay.print("");
  NefryDisplay.print("");
  NefryDisplay.print((String)sensorValue);
  if(sensorValue > 1000){
    //明るいときの処理を記述
  }else{
    //暗い時の処理を記述
  }

  Serial.println(sensorValue);
  delay(1000);
}
```

LEDの明るさは0~100で指定できます。 

> `Nefry.setLed(赤,緑,青,光);`

* 明るい

```
Nefry.setLed(255,255,255,100);
```

* 暗い

```
Nefry.setLed(255,255,255,0);
```

## チャレンジ2

* Sound Sensorに付け替えて、センサーの値を取得してみよう。
* コードは[こちら](https://github.com/n0bisuke/20180119_tokushima/blob/master/step3_sensor/3.2_sound_sensor/3.1_sound_sensor.ino)になります。

手を叩いたり音を出して確認してみましょう。

### 値の確認 / シリアルプロッタ

ツール -> シリアルプロッタを選択しましょう。

![](https://i.gyazo.com/ee49357222f929387b74305c73fe18ca.png)

このようにブラフで値を見れるため、変化を確認しやすいです。

