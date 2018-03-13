## Nefry BTでMQTTを使おう

`ThingsからInternetへ`と`InternetからThingsへ`の両方をやります。

## MQTTとは

[MQTT の基本知識](https://www.ibm.com/developerworks/jp/iot/library/iot-mqtt-why-good-for-iot/)から引用

モノのインターネット (IoT) デバイスでは、インターネットに接続することが要件となります。IoT デバイスはインターネットに接続することで、他のデバイスやバックエンド・サービスと通信するからです。インターネットの基礎となっているネットワーク・プロトコルは TCP/IP であり、IoT 通信では TCP/IP スタックをベースに作成された MQTT (Message Queue Telemetry Transport) が標準的な通信プロトコルとなっています。

MQTT は、1990 年代後半に IBM が考案して開発したプロトコルです。当初は油田パイプラインに取り付けられたセンサーを衛星とリンクするために使用されていました。その名前が示唆するように、MQTT は 2 者間の非同期通信をサポートするプロトコルです。非同期メッセージング・プロトコルは、メッセージの送信側と受信側を空間という点でも、時間という点でも切り離すため、信頼できないネットワーク環境内でスケーラブルな性質を発揮します。一方、その名前に反して、MQTT はメッセージング・キューとはまったく関係がなく、パブリッシュ/サブスクライブ・モデルに従っています。2014 の後半になって MQTT は正式に OASIS オープン・スタンダードになりました。現在は、よく使われているプログラミング言語で、さまざまなオープンソース実装を使用して MQTT がサポートされるようになっています。

### ざっくりいうと

**IBMが主導で進めているM2MやIoT向けの通信プロトコル**

* TCP/IPベースで軽量
* PUB/SUB
* M2M 向けのプロトコル
* 軽量なので省電力
    * 制約が厳しいデバイス・ハードウェア上でも、待ち時間が長かったり帯域幅が限られていたりするネットワーク上でも利用可能

### 用途

* 機器にメッセージを配信する
* 機器がメッセージを配信する

> 参考 https://gist.github.com/voluntas/8238751

## MQTTの登場人物たち

* Broker - 通信のサーバー
* Publisher - 情報の送信側
* Subscriber - 情報の受信側

WebSocketではサーバーとクライアントだけで双方向通信をしますが、MQTTではサーバーはBrocker、クライアント側が送信者のPublisherと受信者のSubscriberに分かれます。

![](https://dotstud.io/img/blog/141/1.png)

## 1. Publisherを実装してみよう

Publisher(パブリッシャー) = データの送信側です。

[こちらのコード](5.3.1_publisher/5.3.1_publisher.ino)をNefryに書き込んで実行してみましょう。

![](https://i.gyazo.com/9e3a1d1a700b1284ce39957e4238be18.png)

このような形でシリアルモニタが表示されればOKです。

前のスクリーンで自分のデータが送られているか確認してみましょう。

### チャレンジ

* TOPICを"Tokyo20180313"に変更
* 送信しているメッセージの"hello world"の部分を別のメッセージに変更してみよう。

前のスクリーンで自分のデータが送られているか確認してみましょう。

### 消費電力

0.14A程度でした。

![](https://i.gyazo.com/33b1601aedc85a196e3f656aa112841d.jpg)

## 2. Subscriberを実装してみよう

Subscriber(サブスクライバー) = データの受信側です。

**[手順記事を参照しましょう！！](https://dotstud.io/blog/nefry-bt-connect-mqtt/)**

[こちらのコード](https://github.com/n0bisuke/20180119_tokushima/blob/master/step5_tips/5.3_mqtt/5.3.2_subscriber/5.3.2_subscriber.ino)をNefryに書き込んで実行してみましょう。

受信してみましょう。

![](https://i.gyazo.com/7d02cd7509e64017ddd3f1a3c0e69aaf.gif)

### チャレンジ

* TOPICを"Tokyo20180313"に変更
* データを受信したらNefryのLEDの色が変わるようにしてみましょう。

## 3. Nefry Cloudの利用

## 4. Brokerについて学ぼう

最初に紹介したとおり、MQTTのサーバーにあたるのがブローカーです。

通常はブローカーは自分でサーバーを用意するか、有料サービスを契約するかで利用できるようになります。

![](https://i.gyazo.com/17221f80f75a99a3e88cda6c4a3a907e.png)

今回は[Mosquitto](https://mosquitto.org/)のサーバーをテスト的に利用しました。

Mosquittoはオープンソースのブローカーサービスで、通常は自分のサーバーに組み込んで利用しますが、開発者がテストしやすいように公開してくれています。

![](https://i.gyazo.com/3480e886dd3e6bf497742f114acb4b62.png)

無料で使えますが、基本的にデータは公開されてしまうので注意しましょう。

### MQTTのブローカーサービス

* [Nifty](https://cloud.nifty.com/service/mqtt.htm)
* [Milkcocoa](https://mlkcca.com/)
* [Azure IoT Hub](https://docs.microsoft.com/ja-jp/azure/iot-hub/iot-hub-mqtt-support)
* [AWS IoT](https://aws.amazon.com/jp/iot-core/features/)

など

### Node.jsで自分で立ててみる

Node.jsはサーバーサイドJavaScriptと呼ばれるWebのサーバーサイド言語です。活躍の場が増えていて、Web以外にもデバイスやデスクトップアプリ、スマホアプリなど様々な場所で活躍しています。JavaScript自体はWebブラウザでも利用できるためIoT時代には相性の良いプログラミング環境です。

以下のライブラリを使うとMQTTのPub/SubとBrokerが実装可能です。

* Publisher/Subscriberの実装
    * [https://www.npmjs.com/package/mqtt](https://www.npmjs.com/package/mqtt)
* Brokerの実装
    * [Mosquitto](https://mosquitto.org/)
    * [Mosca](http://www.mosca.io/)

[Brokerのコード](https://github.com/n0bisuke/20180119_tokushima/blob/master/step5_tips/5.3_mqtt/5.3.3_broker/broker.js)をのぞいてみよう。