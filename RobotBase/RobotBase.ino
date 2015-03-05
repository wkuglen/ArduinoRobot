#include<Servo.h>

//DECLARATIONS
int rightServoPin = 5;
int leftServoPin = 3;
int buttonPin = 6;

int RIGHT_STOP = 92;
int RIGHT_FORWARD_MAX = RIGHT_STOP - 50;
int RIGHT_BACKWARD_MAX = RIGHT_STOP + 50;

int LEFT_STOP = 82;
int LEFT_FORWARD_MAX = LEFT_STOP + 50;
int LEFT_BACKWARD_MAX = LEFT_STOP - 50;

Servo rightServo;
Servo leftServo;

void setup() {
  rightServo.attach(rightServoPin);
  leftServo.attach(leftServoPin);
  pinMode(buttonPin, INPUT);
  while(digitalRead(buttonPin) != HIGH) {
    rightServo.write(RIGHT_STOP);
    leftServo.write(LEFT_STOP);
  }
  
  
  
}

void loop() {
  rightServo.write(RIGHT_FORWARD_MAX);
  leftServo.write(LEFT_FORWARD_MAX);
}
