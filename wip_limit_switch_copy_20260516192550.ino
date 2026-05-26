#include <Wire.h>

// NOTE : cannot open serial monitor and upload sketch code
// otherwise the IDE will complain "cannot access COM port COMN"
//
const int startButtonMain = 6;
const int startButton = 5;
const int b4 = 4;
const int b3 = 3;
const int b2 = 2;

bool started = false;
bool time2Taken = false;
bool time3Taken = false;
bool time4Taken = false;


unsigned long initTime, timer2, timer3, timer4 = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("setup started");

//  lcd.begin(16, 2);

//  lcd.setRGB(colorR, colorG, colorB);
  
//  pinMode(startButtonMain, INPUT_PULLUP);
//  pinMode(startButton, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(b4, INPUT_PULLUP);
  pinMode(startButtonMain, INPUT_PULLUP);
  pinMode(startButton, INPUT_PULLUP);

//  lcd.setCursor(0, 0);
//  lcd.print("Brachistochrone");
//  lcd.setCursor(0, 1);
//  lcd.print("Experiment");
  Serial.println("setup done");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (((digitalRead(startButtonMain) == 0) ) && (!started)){
    Serial.println("timer started");
    initTime = millis();
    // started = true;
    delay(500);
  }

  if ( digitalRead(b2) == 0) {
    Serial.println("pin b2 read 0 ");
    timer2 = millis();
    time2Taken = true;
    Serial.print("pin b2 delta time ");
    float result = float((timer2 - initTime) / 1000.0);
    Serial.print(result, 3);
    Serial.println(" seconds");
  } else {
    // Serial.println("pin b2 read 1 ");
  }

  if ( digitalRead(b3) == 0) {
    Serial.println("pin b3 read 0 ");
    timer3 = millis();
    time3Taken = true;
    Serial.print("pin b3 delta time ");
    float result = float((timer3 - initTime) / 1000.0);
    Serial.print(result, 3);
    Serial.println(" seconds");

  } else {
    // Serial.println("pin b3 read 1 ");
  }

  if ( digitalRead(b4) == 0) {
    Serial.println("pin b4 read 0 ");
    timer4 = millis();
    time4Taken = true;
    Serial.print("pin b4 delta time ");
    float result = float((timer4 - initTime) / 1000.0);
    Serial.print(result, 3);
    Serial.println(" seconds");
  } else {
    //Serial.println("pin b4 read 1 ");
  }

  delay(100); // ms
}
