
/*
 * Web Tone
 * 2015
 */

#define BEAT 300   // 音の長さを指定
#define PINNO 13   // 圧電スピーカを接続したピン番号
#define LED_A 2
#define LED_B 3
#define LED_C 4
#define LED_D 5
#define LED_E 6
#define LED_F 7
#define LED_G 8
#define LED_H 9
#define LED_I 10


int inByte; // 受信するシリアル通信の文字列

void setup() {

  //
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_D, OUTPUT);
  pinMode(LED_E, OUTPUT);
  pinMode(LED_F, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_H, OUTPUT);
  pinMode(LED_I, OUTPUT);
  //


  // 9600bpsでシリアルポートを開始
  Serial.begin(9600);
  // 通信を開始
  establishContact();
}

void loop() {
  // もしProcessingから何か文字を受けとったら
  if (Serial.available() > 0) {
    // 受信した文字列を読み込み
    inByte = Serial.read();
    light(inByte);
    ring(inByte);
  }
}

void establishContact() {
  // Processingから何か文字が送られてくるのを待つ
  while (Serial.available() > 0) {
    // 初期化用の文字列
    Serial.println("0,0");
    delay(300);
  }
}

void light(char toneChar) {
  for (int i = LED_A; i <= LED_I; i++) {
    digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
  }
  switch (toneChar) {
    case '1':
      digitalWrite(LED_A, HIGH);
      break;
    case '2':
      digitalWrite(LED_B, HIGH);
      break;
    case '3':
      digitalWrite(LED_C, HIGH);
      break;
    case '4':
      digitalWrite(LED_D, HIGH);
      break;
    case '5':
      digitalWrite(LED_E, HIGH);
      break;
    case '6':
      digitalWrite(LED_F, HIGH);
      break;
    case '7':
      digitalWrite(LED_G, HIGH);
      break;
    case '8':
      digitalWrite(LED_H, HIGH);
      break;
  }

}

void ring(char toneChar) {
  //ドレミファソラシド
  int toneArr[] = {0, 262, 294, 330, 349, 392, 440, 494, 523};
  int toneNum = -1;
  switch (toneChar) {
    case '1':
      tone(PINNO, toneArr[1], BEAT) ;
      break;
    case '2':
      tone(PINNO, toneArr[2], BEAT) ;
      break;
    case '3':
      tone(PINNO, toneArr[3], BEAT) ;
      break;
    case '4':
      tone(PINNO, toneArr[4], BEAT) ;
      break;
    case '5':
      tone(PINNO, toneArr[5], BEAT) ;
      break;
    case '6':
      tone(PINNO, toneArr[6], BEAT) ;
      break;
    case '7':
      tone(PINNO, toneArr[7], BEAT) ;
      break;
    case '8':
      tone(PINNO, toneArr[8], BEAT) ;
      break;
  }

  delay(BEAT) ;
}
