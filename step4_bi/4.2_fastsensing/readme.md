# Nefry BTからFASTSENSINGにデータをあげて可視化しよう

## ファストセンシング (FASTSENSING)

https://fastsensing.com/ja/author/fastsensing-webmaster/

![](https://i.gyazo.com/4b29f568d0a0ed215d8f89816710f779.png)

```
センサデバイスのための汎用クラウドAPI

ファストセンシングはセンサの監視・記録のための汎用的な機能をAPIで提供するクラウドサービスです。クラウド側の開発をすることなく、ネットワークとセンサを組み合わせたデータモニタリングシステムを構築できます。ファストセンシングは完全な従量課金により提供されますので、小規模かつ短期間のシステムから、大規模なスケールが必要なシステムまで、幅広い用途でご利用いただけます。
```

![](https://i.gyazo.com/137b247b9ac08086ecf4a1b735dbcff8.png)

## ユーザー登録

メールアドレスとパスワードを入力して登録しましょう。

![](https://i.gyazo.com/192210aa46f1f577172b4779d1702a94.png)

メールアドレスに確認メールが送られてくるのでリンクをクリックしましょう。

## ログインできない人

* rsksound+test@gmail.com / hogehoge
* rsksound+test1@gmail.com / hogehoge

## ログインしてホーム画面へ

![](https://i.gyazo.com/bfbc485167fa3000963bf6b67e36285e.png)

![](https://i.gyazo.com/25ee2ea61ec62743e4fe433dc0d5cbbd.png)

最初はメニュー表示だけの画面が表示されます。

## スタブデバイスを追加する

こちらのリンクからスタブデバイスを追加します。

https://console.fastsensing.com/stub_devices

現状だと、ログイン後のページから遷移できない様子なので注意しましょう。

![](https://i.gyazo.com/249cd591feb954309a14bf55e2e00e03.png)

ボタンをクリックすると登録が完了して画面が切り替わります。

![](https://i.gyazo.com/32400e4cd249c3ac08da0ac59285dd4f.png)

* デバイス
* チャンネル1
* チャンネル2
* チャンネル3

の値を確認しましょう。後ほど利用します。

## Nefry BTにプログラムを書き込む

以下のプログラムを用意します。

```4.2.ino
#include <NefryFastSensing.h>
//インスタンスを作成します
NefryFastSensing fastSensing;
float floatData = 0;
float intData = 0;

void setup() {
  //FastSensingで必要な情報を入力し、初期化をします
  //https://console.fastsensing.com/devicesからデバイスとチャンネル
  //begin(デバイス、チャンネル1、チャンネル2、チャンネル3)
  fastSensing.begin("device", "channel1", "channel2", "channel3");
}

void loop() {
  //FastSensingに送るデータを作成します
  //setValue(チャンネル、データ)
  fastSensing.setValue(0, floatData);
  fastSensing.setValue(1, intData);

  //setValueで入れた値をFastSensingに送信します
  //push()
  fastSensing.push();
  
  floatData += 0.1;
  intData++;
  delay(10000);

}
```

* デバイス
* チャンネル1
* チャンネル2
* チャンネル3

の4つの値を自身のものにしてください。

![](https://i.gyazo.com/cd691d180b850257d3a2514f74f77643.png)

変更出来たら書き込みをしてください。

## チャンネル

ファストセンシングではデータの種類によって送信先を変更できるようにチャンネルという概念があります。

先ほどのNefry BTに書き込んだコードで

```
fastSensing.setValue(0, floatData);
```

と指定している箇所がありますが、

チャンネル1の場合は`fastSensing.setValue(0, データ)`とし、チャンネル2の場合は`fastSensing.setValue(1, floatData)`、チャンネル3の場合は`fastSensing.setValue(2, floatData)`となります。

管理画面側でもチャンネル毎にデータを確認しましょう。

## 配線

GroveのA0(A1)ピンにSound SenserもしくはLight Sensorを差し込みましょう。

> 今回の研修の場合は(Nefry BT R2ではA0)

![](https://i.gyazo.com/c67a34a72d8b01b1f3b6b2797c08737d.jpg)

## チャレンジ

- Lignt Sensorの値を取得してFastsensingにあげてみましょう。

ヒント - [Light Sensorのコード](https://github.com/n0bisuke/20180307_tokyo/blob/master/step3_sensor/3.1_light_sensor/3.1_light_sensor.ino)との組み合わせです。

### 解答例

[解答例コード](4.2.4_fast_light/4.2.4_fast_light.ino)

## 確認

チャンネルを指定します。

![](https://i.gyazo.com/a36962a2ff2dfc8138613b65123fae50.png)

作成ボタンを押すと、グラフが表示されました。

![](https://i.gyazo.com/f57d655a1aa487951b31b202f0fa0310.png)

このように簡単にデータをクラウドに送信してグラフ化が出来ました。

他にも

* リアルタイムグラフ
* パネル
* イメージマップ
* 表

など色々なビューがあるので試してみましょう。

![](https://i.gyazo.com/0055cb1c1d1526e1aced563a36b4dfca.png)

## 2018/1/19現在 不安定です。

Fastsensing側のレスポンスが不安定で落ちる場合あります。
おそらく数日したら直ると思います。

参考: https://qiita.com/fastsensing/items/3d6cd7f14f4fde5c394e