#define Up_D_Pad 13
#define Left_D_Pad 12
#define Right_D_Pad 14
#define Down_D_Pad 27
#define Up_Button 26
#define Down_Button 18
#define Home 21
#define Maintenance 22
#define dirPinR 2
#define stepPinR 15
#define dirPinM 16
#define stepPinM 4
#define dirPinL 5
#define stepPinL 17
#define Speed_Switch 19


void setup() {
  //Labeling each GPIO Pin as inputs with pullup resistors, or outputs
  Serial.begin(9600);
  pinMode(Speed_Switch, INPUT_PULLUP);
  pinMode(Up_D_Pad, INPUT_PULLUP);
  pinMode(Left_D_Pad, INPUT_PULLUP);
  pinMode(Right_D_Pad, INPUT_PULLUP);
  pinMode(Down_D_Pad, INPUT_PULLUP);
  pinMode(Up_Button, INPUT_PULLUP);
  pinMode(Down_Button, INPUT_PULLUP);
  pinMode(Home, INPUT_PULLUP);
  pinMode(Maintenance, INPUT_PULLUP);
  pinMode(stepPinR, OUTPUT);
  pinMode(dirPinR, OUTPUT);
  pinMode(stepPinM, OUTPUT);
  pinMode(dirPinM, OUTPUT);
  pinMode(stepPinL, OUTPUT);
  pinMode(dirPinL, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly

  int Motor_Speed;

  if (digitalRead(Speed_Switch) == HIGH) {
    Motor_Speed = 2000;
  } else {
    Motor_Speed = 500;
  }
 Serial.println(5);
 delay(1);
  
  
  //Right D-Pad button Code
  // While holding down the right D Pad button, the left motor will spin clockwise and the right motor will spin counter clockwise moving the array right
for (int i = 1; digitalRead(Right_D_Pad) < i; i) {
    // The lines of code below are responsible for the movement of the left and right motors
    digitalWrite(dirPinR, HIGH);
    digitalWrite(dirPinL, LOW);
    
    digitalWrite(stepPinR, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinR, LOW); 
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinL, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinL, LOW); 
    delayMicroseconds(Motor_Speed);
  }
delay(1);

  // Up D-Pad button Code 
  // While holding down the up D Pad button the middle motor will spin counter clockwise
  for (int i = 1; digitalRead(Up_D_Pad) < i; i) {
    // The lines of code below are responsible for moving the middle motor
    digitalWrite(dirPinM, LOW);
        
    digitalWrite(stepPinM, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinM, LOW); 
    delayMicroseconds(Motor_Speed);
  }
delay(1);

  // Down D-Pad button Code
  // While holding down the down D-Pad button the middle motor will spin clock wise
  for (int i = 1; digitalRead(Down_D_Pad) < i; i) {
    // The lines of code below are responsible for moving the middle motor
    digitalWrite(dirPinM, HIGH);
    
    digitalWrite(stepPinM, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinM, LOW); 
    delayMicroseconds(Motor_Speed);
  }
delay(1);

  // Left D-Pad button Code
  // While holding down the left D-Pad button the right motor will spin clockwise while the left motor spins counter clockwise, moving the array left
  for (int i = 1; digitalRead(Left_D_Pad) < i; i) {
    // The lines of code below are responsible for moving the left and right motors
    digitalWrite(dirPinL, HIGH);
    digitalWrite(dirPinR, LOW);
  
    digitalWrite(stepPinL, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinL, LOW); 
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinR, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinR, LOW); 
    delayMicroseconds(Motor_Speed);
  }
delay(1);

  // Up button Code
  // While holding down the up button the left and right motors will both move counter clockwise, raising the system
  for (int i = 1; digitalRead(Up_Button) < i; i) {
    // The lines of code below are responsible for moving the left and right motors
    digitalWrite(dirPinL, LOW);
    digitalWrite(dirPinR, LOW);
    digitalWrite(stepPinR, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinR, LOW); 
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinL, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinL, LOW); 
    delayMicroseconds(Motor_Speed);
  }
delay(1);

  // Down button Code
  // While holding down the down button, the left and right motors will move clockwise
  for (int i = 1; digitalRead(Down_Button) < i; i) {
    // The lines of code below are responsible for moving the left and right motors
    digitalWrite(dirPinR, HIGH);
    digitalWrite(dirPinL, HIGH);
  
    digitalWrite(stepPinR, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinR, LOW); 
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinL, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinL, LOW); 
    delayMicroseconds(Motor_Speed);
  }
delay(1);

  for (int i = 1; digitalRead(Maintenance) < i; i) {
    // The lines of code below are responsible for moving the left and right motors
    digitalWrite(dirPinR, LOW);
    digitalWrite(dirPinL, LOW);
    digitalWrite(dirPinM, LOW);
  
    digitalWrite(stepPinR, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinR, LOW); 
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinM, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinM, LOW); 
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinL, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinL, LOW); 
    delayMicroseconds(Motor_Speed);
  }
delay(1);
}
