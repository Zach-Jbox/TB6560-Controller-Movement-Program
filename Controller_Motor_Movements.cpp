#define Up_D_Pad 13
#define Left_D_Pad 12
#define Right_D_Pad 14
#define Down_D_Pad 27
#define Up_Button 26
#define Down_Button 18
#define Preset_1 19
#define Preset_2 21
#define Preset_3 22
#define Preset_4 23
#define dirPinR 2
#define stepPinR 15
#define dirPinM 16
#define stepPinM 4
#define dirPinL 5
#define stepPinL 17
#define stepsPerRevolution 0

void setup() {
  //Labeling each GPIO Pin as inputs with pullup resistors, or outputs
  pinMode(Up_D_Pad, INPUT_PULLUP);
  pinMode(Left_D_Pad, INPUT_PULLUP);
  pinMode(Right_D_Pad, INPUT_PULLUP);
  pinMode(Down_D_Pad, INPUT_PULLUP);
  pinMode(Up_Button, INPUT_PULLUP);
  pinMode(Down_Button, INPUT_PULLUP);
  pinMode(Preset_1, INPUT_PULLUP);
  pinMode(Preset_2, INPUT_PULLUP);
  pinMode(Preset_3, INPUT_PULLUP);
  pinMode(Preset_4, INPUT_PULLUP);
  pinMode(stepPinR, OUTPUT);
  pinMode(dirPinR, OUTPUT);
  pinMode(stepPinM, OUTPUT);
  pinMode(dirPinM, OUTPUT);
  pinMode(stepPinL, OUTPUT);
  pinMode(dirPinL, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly

  //Right D-Pad button Code+
  while (digitalRead(Right_D_Pad) == LOW) {
    digitalWrite(dirPinR, LOW);
    digitalWrite(dirPinL, HIGH);
    // While holding down the right D Pad button, the left motor will spin clockwise and the right motor will spin counter clockwise moving the array right
    // The lines of code below are responsible for the movement of the left and right motors
    digitalWrite(stepPinR, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPinR, LOW); 
    delayMicroseconds(200);
    digitalWrite(stepPinL, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPinL, LOW); 
    delayMicroseconds(200);
  }
delay(1);

  // Up D-Pad button Code
  while (digitalRead(Up_D_Pad) == LOW) {
    digitalWrite(dirPinM, LOW);
    // While holding down the up D Pad button the middle motor will spin counter clockwise
    // The lines of code below are responsible for moving the middle motor
    digitalWrite(stepPinM, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPinM, LOW); 
    delayMicroseconds(500);
  }
delay(1);

  // Down D-Pad button Code
  while (digitalRead(Down_D_Pad) == LOW) {
    digitalWrite(dirPinM, HIGH);
    // While holding down the down D-Pad button the middle motor will spin clock wise
    // The lines of code below are responsible for moving the middle motor
    digitalWrite(stepPinM, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPinM, LOW); 
    delayMicroseconds(500);
  }
delay(1);

  // Left D-Pad button Code
  while (digitalRead(Left_D_Pad) == LOW) {
    digitalWrite(dirPinL, LOW);
    digitalWrite(dirPinR, HIGH);
    // While holding down the left D-Pad button the right motor will spin clockwise while the left motor spins counter clockwise, moving the array left
    // The lines of code below are responsible for moving the left and right motors
    digitalWrite(stepPinL, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPinL, LOW); 
    delayMicroseconds(200);
    digitalWrite(stepPinR, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPinR, LOW); 
    delayMicroseconds(200);
  }
delay(1);

  // Up button Code
  while (digitalRead(Up_Button) == LOW) {
    digitalWrite(dirPinL, LOW);
    digitalWrite(dirPinR, LOW); 
    // While holding down the up button the left and right motors will both move counter clockwise, raising the system
    // The lines of code below are responsible for moving the left and right motors
    digitalWrite(stepPinR, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPinR, LOW); 
    delayMicroseconds(200);
    digitalWrite(stepPinL, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPinL, LOW); 
    delayMicroseconds(200);
  }
delay(1);

  // Down button Code
  while (digitalRead(Down_Button) == LOW) {
    digitalWrite(dirPinR, HIGH);
    digitalWrite(dirPinL, HIGH);
    // While holding down the down button, the left and right motors will move clockwise
    // The lines of code below are responsible for moving the left and right motors
    digitalWrite(stepPinR, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPinR, LOW); 
    delayMicroseconds(200);
    digitalWrite(stepPinL, HIGH);
    delayMicroseconds(200);
    digitalWrite(stepPinL, LOW); 
    delayMicroseconds(200);
  }
delay(1);
}
