# Nefry BTからAmbientにデータをあげて可視化しよう

## 1. Ambient

https://ambidata.io/

![](https://i.gyazo.com/0627e9980becca68b8d74c018f14eac0.png)

```
AmbientはIoTデーターの可視化サービスです。

マイコンなどから送られるセンサーデーターを受信し、蓄積し、可視化(グラフ化)します。
```

様々なマイコンボードに対応しています。

![](https://ambidata.io/wp/wp-content/uploads/2016/08/chart2.jpg)

## 2. 利用準備

### ユーザー登録

メールアドレスとパスワードを入力して登録しましょう。

### ログインしてチャンネルを作る

![](https://i.gyazo.com/d88631e273d2ebb8312d0a313077dbc4.png)

![](https://i.gyazo.com/ec26b7309bf4d0472f863f3740f6703e.png)

#### ログインできない人

##### 1個目 8人まで

* id: rkv43994@pdold.com
* pass: hogehoge

##### 2コメ 8人まで

* id: m2067647512@dqnwara.com
* pass: 123456

## 3. Nefry BTにプログラムを書き込む

[Ambient利用のコード(4.1_ambient.ino)](4.1.1_ambient/4.1.1_ambient.ino)を書き込んでみましょう。

- ※ちなみにサンプルスケッチもあります。

![](https://i.gyazo.com/cd415ad4c3c07e988788b94556c1c27d.png)

`ファイル > スケッチ例 > Nefry Ambient library`

### 配線

GroveのA0(A1)ピンにLight Sensorを差し込みましょう。

> 今回の研修の場合は(Nefry BT R2ではA0)

![](https://i.gyazo.com/c67a34a72d8b01b1f3b6b2797c08737d.jpg)

### Nefry BTのWebコンソールでキーを設定

* PCなどからWebコンソールにアクセスし、`Data Store`を選択

![](https://i.gyazo.com/d7499928a193e688742d58dbf4cec1b3.png)


* Ambientで登録した`ライトキー(Write Key)`と`Channel ID`を入力して`Save`

![](https://i.gyazo.com/2f063d19b534feb4089b7c4027e81a5d.png)

するとNefry BTが再起動します。

### 確認

Ambientでチャネル名のリンクをクリックすると、そのチャネルのグラフページになります。

![](https://i.gyazo.com/4bde98b6cdf3ebebe2f9ed9580f35461.gif)

このような形でNefry BTからデータが送信され、外出先などからでもWeb上でデータを監視することが可能です。

### チャレンジ

棒グラフを作ってみよう。

Ambientの管理画面を触って棒グラフを作ってみましょう。

![](https://i.gyazo.com/931c8cd5567c7c619467119a7b178d48.gif)

## 4. 二つのデータを扱ってみる

先ほどは光センサ単体でしたが、音センサも同時に使ってみましょう

### プログラムの書き込み

[Ambient利用のコード2(4.1.2_ambient.ino)](4.1.2_ambient/4.1.2_ambient.ino)を書き込んでみましょう。

### 配線

ジャンパワイヤーを利用して、GPIOのA2に配線します。

![](https://i.gyazo.com/73c91fc0a29021943a5107fe679010a2.png)

![](https://i.gyazo.com/9d5f79c6545ef77e5500b1dda1c62ef1.png)

* Groveの黒 -> GPIOのGND (マイナス)
* Groveの赤 -> GPIOの5v (プラス)
* Groveの黄色 -> GPIOのA2 (信号)

### Ambientの設定

歯車マークから編集します。

![](https://i.gyazo.com/81b9662ae14d7429c1d37ca8e7f2f0e2.png)

* d1 -> 左軸
* d2 -> 右軸

にチェックを入れて`設定を変更`を選択すると二つ目のデータが扱えるようになります。

### 確認

![](https://i.gyazo.com/04c5c81b0c21e906040d4739b916d3c8.gif)

## 5. Ambient活用

### データをダウンロードして開いてみる

右上のダウンロードボタンを押します。

![](https://i.gyazo.com/0ee08b95c6ecb08867584afc9ec3a968.png)

`dataXXXX.csv`といったファイルがダウンロードできます。

![](https://i.gyazo.com/09c76b75621432295ce6b0757eac63ee.png)

エクセルなどで開いて確認できます。

### グラフを公開して外出先から確認する

右上の歯車マーク（チャンネル設定）を選択します。

![](https://i.gyazo.com/e1c101242fca2f6e25cabfe08d70ba0a.png)

`公開チャネル?`にチェックを入れます。

![](https://i.gyazo.com/53c2b1a10719fed38c2bf2cbc10b4a59.png)

`こちらでユーザー名を設定してください。`の箇所からユーザー設定をします。

![](https://i.gyazo.com/9bba8d38287667f66997c867c5a91217.png)

`チャネル属性を設定する`ボタンで確定です。

右上の目のマークから`公開ビュー`が見れるようになります。

公開ビューのURLにスマートフォンからアクセスしてみましょう。

![](https://i.gyazo.com/812fed6d272b5dc6a303e5be992e2ed6.png)

外出先などからでも確認できます。