/*
* Web Tone - Client
* 2015
*/
import processing.serial.*;

int BEAT = 500;

//settings from settings.json
JSONObject settings;

//Serial port
Serial myPort;
//Tones
JSONArray toneArray;
String tone; //tone playing now
int toneListIndex = 0; //index of a tone in tone list.
int toneIndex = 0; //index of tone character
int START_POSITION = 0;

//Timer thread for loop
Thread thread1; // thread for timer
boolean tick;

void setup() {
  settings = loadJSONObject("settings.json");
  size(400, 200);
  String port = settings.getString("ARDUINO_PORT");
  myPort = new Serial(this, port, 9600);
  //Start loop thread
  thread1 = new Thread(new timerThread());
  thread1.start();
}

//draw Array List
void draw() {
  if (toneArray != null) {
    background(99, 99, 99);
    for (int i=0; i<toneArray.size (); i++) {
      String tones = toneArray.getJSONObject(i).getString("tone");
      text(tones, 12, 12+i*10);
    }
  }
}

// thread for 1 sec. timer
class timerThread implements Runnable {
  public synchronized void run() {
    int[] LEDStates;
    while (true) {
      try {
        myPort.write(getToneVal());
        println(tick);
        Thread.sleep(BEAT);
      }
      catch (InterruptedException e) {
      }
      tick = !tick;
    }
  }
}

//get 1 charactor from tone list
String getToneVal() {
  if (toneIndex == START_POSITION) {
    if (toneListIndex == START_POSITION) {
      //prepare tone list
      //get tone list as json format from web server.
      String URL = settings.getString("TONE_LIST_URL");
      toneArray = getToneListFromURL(URL);
      delay(5000);
    }
    delay(1000);
  }

  String tone = toneArray.getJSONObject(toneListIndex).getString("tone");
  String toneVal = tone.substring(toneIndex, toneIndex+1);
  println(toneVal);

  toneIndex++;
  if (toneIndex >= tone.length())
  {
    toneListIndex++;
    toneIndex = START_POSITION;
    if (toneListIndex >= toneArray.size()) {
      //loop toneList
      toneListIndex = START_POSITION;
    }
  }
  return toneVal;
}

JSONArray getToneListFromURL(String URL) {
  JSONArray jsonResult = new JSONArray();
  try {
    jsonResult = loadJSONArray(URL);
    println(jsonResult);
  }
  catch(Exception e)
  {
    println("Error:invalid JSON data " + e);
  }
  return jsonResult;
}
