# Nefry BTからAmbientにデータをあげて可視化しよう

## Ambient

https://ambidata.io/

![](https://i.gyazo.com/0627e9980becca68b8d74c018f14eac0.png)

```
AmbientはIoTデーターの可視化サービスです。

マイコンなどから送られるセンサーデーターを受信し、蓄積し、可視化(グラフ化)します。
```

様々なマイコンボードに対応しています。

![](https://ambidata.io/wp/wp-content/uploads/2016/08/chart2.jpg)

## ユーザー登録

メールアドレスとパスワードを入力して登録しましょう。

## ログインしてチャンネルを作る

![](https://i.gyazo.com/d88631e273d2ebb8312d0a313077dbc4.png)

![](https://i.gyazo.com/ec26b7309bf4d0472f863f3740f6703e.png)

## ログインできない人

### 1個目 8人まで

* id: rkv43994@pdold.com
* pass: hogehoge

### 2コメ 8人まで

* id: m2067647512@dqnwara.com
* pass: 123456

## Nefry BTにプログラムを書き込む

[Ambient利用のコード(4.1_ambient.ino)](4.1_ambient.ino)を書き込んでみましょう。

```4.1.ino
#include <NefryAmbient.h>

NefryAmbient nefryAmbient;

void setup() {
  nefryAmbient.begin();//ambientを使えるように初期設定をします。
  Nefry.setProgramName("AmbientSimpleAnalog");//プログラム名を指定します。
}

void loop() {
  int analog;
  analog = analogRead(A1);//A1ピンの状態を取得します。
  Nefry.print("Analog:");
  Nefry.println(analog);//アナログの値を表示します。
  nefryAmbient.set(1, analog); //field,dataの順にセットします。
  nefryAmbient.send();//ambientにデータを送信します。
  Nefry.ndelay(1000);//1秒待つ
}
```

### ちなみにサンプルスケッチもあります。

![](https://i.gyazo.com/cd415ad4c3c07e988788b94556c1c27d.png)

`ファイル > スケッチ例 > Nefry Ambient library`

## 配線

GroveのA0(A1)ピンにSound SenserもしくはLight Sensorを差し込みましょう。

> 今回の研修の場合は(Nefry BT R2ではA0)

![](https://i.gyazo.com/c67a34a72d8b01b1f3b6b2797c08737d.jpg)

## Nefry BTのWebコンソールでキーを設定

* PCなどからWebコンソールにアクセスし、`Data Store`を選択

![](https://i.gyazo.com/d7499928a193e688742d58dbf4cec1b3.png)


* Ambientで登録した`ライトキー(Write Key)`と`Channel ID`を入力して`Save`

![](https://i.gyazo.com/2f063d19b534feb4089b7c4027e81a5d.png)

するとNefry BTが再起動します。

## 確認

Ambientでチャネル名のリンクをクリックすると、そのチャネルのグラフページになります。

![](https://i.gyazo.com/4bde98b6cdf3ebebe2f9ed9580f35461.gif)

このような形でNefry BTからデータが送信され、外出先などからでもWeb上でデータを監視することが可能です。