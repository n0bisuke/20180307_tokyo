
## Nefry BTを省電力モードで起動する

### 消費電力を抑える

乾電池やバッテリー駆動をした際に気になるのが電力消費です。

### 消費電力がどれくらいになるか

[ESP32の仕様書](http://akizukidenshi.com/download/ds/espressifsystems/esp_wroom_32_datasheet_en.pdf)

![](https://i.gyazo.com/d435df3d57b89b3849caa398404b3f36.png)

通常に使用していると**0.16A~0.26A**がESP32の消費電力（理論値）になります。

> [アンペア数が高い（消費電力が大きい）家電を知って、上手に節約しよう](https://enechange.jp/articles/large-consumption-appliances)

### Nefry BT通常時

**約0.13A**

![](https://i.gyazo.com/d3ff6528fff0ba2a3c4a6c29494dc919.jpg)

### Light Sleepモード

以下のコードをNefry BTに書き込んでみましょう！

[Light Sleep](https://github.com/n0bisuke/20180119_tokushima/blob/master/step5_tips/5.2_power_saving/5.2.1_light_sleep/5.2.1_light_sleep.ino)

**0.02A**になりました。

![](https://i.gyazo.com/503c45f7987931d3486c43ff644aa1ab.jpg)

通常時の`0.13A`から`0.02A`ということで、電池駆動したときに約6倍長持ちさせることができます。

### Deep Sleepモード

以下のコードをNefry BTに書き込んでみましょう。

[Deep Sleep](https://github.com/n0bisuke/20180119_tokushima/blob/master/step5_tips/5.2_power_saving/5.2.2_deep_sleep/5.2.2_deep_sleep.ino)

5秒ごとに再起動を繰り返しますが、loop関数までは読み込まれず、指定した時間ごとに起動して、setup関数の中に記述してある処理を実行します。

1時間に一回データをポストしてあとは落としておく、などといった運用が考えられそうです。

![](https://i.gyazo.com/594ad90cf2c8700ac45eb2fe29c081ed.jpg)

**0.01A**になりました。
もっと詳細に調べられる測定器で図ると違いが分かりやすいかもしれません。