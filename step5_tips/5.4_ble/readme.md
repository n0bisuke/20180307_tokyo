
## BLEについて学ぼう

BLEはbluetooth Low Energyの略称です。

その名の通り、省電力なBluetooth通信の規格です。

> 参考: [IoT技術の代表「BLE：Bluetooth Low Energy」の動作原理を理解してみよう](https://codezine.jp/article/detail/9287)

IoTの世界での技術障壁は電源問題や回線問題がよく挙げられますが、電源が取れず、回線が存在しない場所などではBLEを利用するのがおすすめです。

ただし、BLEだけではInternetに繋がらないため、スマートフォンやPCなどにデータを送信したり、Raspberry PiなどBLEだけではなく、Wi-Fiともセットで利用できるデバイスと接続するのが一般的です。

### BLEの登場人物

* Peripheral: 発信側端末、ビーコンやBLEタグなど受信端末に対して情報を送る側
* Central: 受信側端末、iPhoneやMacなどBLEデバイスの情報を探して受け取る側

![](https://dotstud.io/img/blog/143/1.png)

### 1. Nefry BTをBLEペリフェラルにしてデータを送る

Nefry BTをセンサー側として利用して、パソコンにデータを送る例です。

[Nefry BT（ESP32）からBLEでNode.jsにデータを送ってみよう](https://dotstud.io/blog/nefrybt-ble-bluetooth-peripheral/)をみながら進めてみよう。

![](https://i.gyazo.com/2f98195bf2d9c5e72dadd5bf1ae88cf0.png)

![](https://dotstud.io/img/blog/143/5.gif)

### 補足: Nefry BTをBLEセントラルにしてデータをインターネットに送る

Nefry BTをBLEデバイスからのデータを受け取り、インターネットにデータ転送してくれるブリッジのように動作させます。

そもそもESP32自体が消費電力が大きくなっているので、ペリフェラルにするよりもセントラルとして動作させるほうが利口です。

本当は入れ込みたかった項目ですが、大元のEPS32にまだバグがあり、うまく制御できない現状です。



