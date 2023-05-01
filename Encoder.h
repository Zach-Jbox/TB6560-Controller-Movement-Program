#ifndef ENCODER_H
#define ENCODER_H

#include "Arduino.h"

#define dirPinR 2
#define stepPinR 15
#define dirPinM 16
#define stepPinM 4
#define dirPinL 5
#define stepPinL 17

#define CLKEncoderR 33
#define DTEncoderR 25
#define CLKEncoderM 34
#define DTEncoderM 23
#define CLKEncoderL 32
#define DTEncoderL 35

#define DEBONCE_TO 150

int Motor_Speed;

int MAXR = -105;
int MAXL = 105;
int MINM = 0;

volatile bool turnedCWR = false;
volatile bool turnedCCWR = false;

volatile bool turnedCWM = false;
volatile bool turnedCCWM = false;

volatile bool turnedCWL = false;
volatile bool turnedCCWL = false;

unsigned long debounceTimeR = 0;
unsigned long debounceTimeM = 0;
unsigned long debounceTimeL = 0;

bool lastWasCWR = false;
bool lastWasCCWR = false;

bool lastWasCWM = false;
bool lastWasCCWM = false;

bool lastWasCWL = false;
bool lastWasCCWL = false;

static int valueR = 0;
static int valueM = 0;
static int valueL = 0;

int MotorSpeed() {
    if (ps5.R1() == 1) {
     Motor_Speed = 500;
     } else {
     Motor_Speed = 1000;
     }
  delay(1); 
}

void checkEncoderR() {
  if ((!turnedCWR)&&(!turnedCCWR)) {
    int pinAR = digitalRead(CLKEncoderR);
    delayMicroseconds(1500);
    int pinBR = digitalRead(DTEncoderR);
    if (pinAR == pinBR){
      if (lastWasCWR) {
        turnedCWR = true;
      } else {
        turnedCCWR = true;
      }      
    } else {
      if (lastWasCCWR) {
        turnedCCWR = true;
      } else {
        turnedCWR = true;
      }
    }    
  }
}

void checkEncoderM() {
  if ((!turnedCWM)&&(!turnedCCWM)) {
    int pinAM = digitalRead(CLKEncoderM);
    delayMicroseconds(1500);
    int pinBM = digitalRead(DTEncoderM);
    if (pinAM == pinBM){
      if (lastWasCWM) {
        turnedCWM = true;
      } else {
        turnedCCWM = true;
      }      
    } else {
      if (lastWasCCWM) {
        turnedCCWM = true;
      } else {
        turnedCWM = true;
      }
    }    
  }
}

void checkEncoderL() {
  if ((!turnedCWL)&&(!turnedCCWL)) {
    int pinAL = digitalRead(CLKEncoderL);
    delayMicroseconds(1500);
    int pinBL = digitalRead(DTEncoderL);
    if (pinAL == pinBL){
      if (lastWasCWL) {
        turnedCWL = true;
      } else {
        turnedCCWL = true;
      }      
    } else {
      if (lastWasCCWL) {
        turnedCCWL = true;
      } else {
        turnedCWL = true;
      }
    }    
  }
}

void setup() {
  Serial.begin(115200);
  ps5.begin("48:18:8D:16:BB:9A"); //replace with MAC address of your controller
  Serial.println("Ready.");

  pinMode(stepPinR, OUTPUT);
  pinMode(dirPinR, OUTPUT);
  pinMode(stepPinM, OUTPUT);
  pinMode(dirPinM, OUTPUT);
  pinMode(stepPinL, OUTPUT);
  pinMode(dirPinL, OUTPUT);
  
  pinMode(CLKEncoderR, INPUT_PULLUP);
  pinMode(DTEncoderR, INPUT_PULLUP);
  attachInterrupt(DTEncoderR, checkEncoderR, CHANGE);
  pinMode(CLKEncoderM, INPUT_PULLUP);
  pinMode(DTEncoderM, INPUT_PULLUP);
  attachInterrupt(DTEncoderM, checkEncoderM, CHANGE);
  pinMode(CLKEncoderL, INPUT_PULLUP);
  pinMode(DTEncoderL, INPUT_PULLUP);
  attachInterrupt(DTEncoderL, checkEncoderL, CHANGE);
}

void Encoders() {
    if (turnedCWR) {
    valueR++;
    Serial.print("Turned Right CW: ");
    Serial.println(valueR);
    turnedCWR = false;
    lastWasCWR = true;
    debounceTimeR = millis();
  }

  if (turnedCWM) {
    valueM++;
    Serial.print("Turned Middle CW: ");
    Serial.println(valueM);
    turnedCWM = false;
    lastWasCWM = true;
    debounceTimeM = millis();
  }
  
  if (turnedCWL) {
    valueL++;
    Serial.print("Turned Left CW: ");
    Serial.println(valueL);
    turnedCWL = false;
    lastWasCWL = true;
    debounceTimeL = millis();
  }
  
  if (turnedCCWR) {
    valueR--;
    Serial.print("Turned Right CCW: ");
    Serial.println(valueR);
    turnedCCWR = false;
    lastWasCCWR = true;
    debounceTimeR = millis();
  }
  
  if (turnedCCWM) {
    valueM--;
    Serial.print("Turned Middle CCW: ");
    Serial.println(valueM);
    turnedCCWM = false;
    lastWasCCWM = true;
    debounceTimeM = millis();
  }
  
  if (turnedCCWL) {
    valueL--;
    Serial.print("Turned Left CCW: ");
    Serial.println(valueL);
    turnedCCWL = false;
    lastWasCCWL = true;
    debounceTimeL = millis();
  }
  
  if ((millis()-debounceTimeR) > DEBONCE_TO) {
    lastWasCWR = false;
    lastWasCCWR = false;
  }

  if ((millis()-debounceTimeM) > DEBONCE_TO) {
    lastWasCWM = false;
    lastWasCCWM = false;
  }

  if ((millis()-debounceTimeL) > DEBONCE_TO) {
    lastWasCWL = false;
    lastWasCCWL = false;
  } 
}

/*int MBound(){
   if (valueM == MINM) {
    Motor_Speed = 0;
   }
}

void RBound() {
  if (valueR <= MAXR) {
    Motor_Speed = 0;
  }
}

void LBound() {
  if (MAXL <= valueL) {
    Motor_Speed = 0;
  }
}*/

void Reset() {
  valueR = 0;
  valueM = 0;
  valueL = 0;
}

void ResetAll() {
  valueR = 200;
  valueM = 200;
  valueL = 200;
}
#endif
