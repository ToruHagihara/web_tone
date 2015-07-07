# web_tone_client

##Overview
スマホのブラウザから登録したメロディーを演奏する電子オルゴールを作ります。
<http://fabble.cc/toruhagihara/web-connected-orgel>

- メロディ配信サーバーからJSON配列を取得して演奏します。

##Tone list JSON Format
```json
[{"id":"1","tone":"1234321_3456543"},{"id":"2","tone":"12345678"},{"id":"3","tone":"5512345"}]
```
- "tone"に格納された1~8の数値をドレミファソラシドに変換します。
- （"_"などそれ以外の文字は休符とします）

<a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/"><img alt="クリエイティブ・コモンズ・ライセンス" style="border-width:0" src="https://i.creativecommons.org/l/by-nc/4.0/88x31.png" /></a><br />この 作品 は <a rel="license" href="http://creativecommons.org/licenses/by-nc/4.0/">クリエイティブ・コモンズ 表示 - 非営利 4.0 国際 ライセンスの下に提供されています。</a>
