#include <ps5.h>
#include <ps5Controller.h>
#include <ps5_int.h>
#include "Encoder.h"
  
void loop() {
ps5.isConnected();
  // The lines of code below are responsible for the movement of the left and right motors
  for (int i = 0; i < ps5.Right(); i) {
    // The lines of code below are responsible for the movement of the left and right motors
    MotorSpeed();
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
  for (int i = 0; i < ps5.Up(); i) {
    // The lines of code below are responsible for moving the middle motor
    MotorSpeed();
    digitalWrite(dirPinM, HIGH);
        
    digitalWrite(stepPinM, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinM, LOW); 
    delayMicroseconds(Motor_Speed);
    }
  delay(1);

  // Down D-Pad button Code
  // While holding down the down D-Pad button the middle motor will spin clock wise
  for (int i = 0; i < ps5.Down(); i) {
    // The lines of code below are responsible for moving the middle motor
    MotorSpeed();
    digitalWrite(dirPinM, LOW);
        
    digitalWrite(stepPinM, HIGH);
    delayMicroseconds(Motor_Speed);
    digitalWrite(stepPinM, LOW); 
    delayMicroseconds(Motor_Speed);
    }
  delay(1);

  // Left D-Pad button Code
  // While holding down the left D-Pad button the right motor will spin clockwise while the left motor spins counter clockwise, moving the array left
  for (int i = 0; i < ps5.Left(); i) {
    // The lines of code below are responsible for moving the left and right motors
    MotorSpeed();
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
  // While holding down the Triangle button the left and right motors will both move counter clockwise, raising the system
  for (int i = 0; i < ps5.Triangle(); i) {
    // The lines of code below are responsible for moving the left and right motors
    MotorSpeed();
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
  // While holding down the Cross Button, the left and right motors will move clockwise
  for (int i = 0; i < ps5.Cross(); i) {
    // The lines of code below are responsible for moving the left and right motors
    MotorSpeed(); 
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
  //Bounds
}
