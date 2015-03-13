#include<Servo.h>

//declarations
Servo rightServo;
Servo leftServo;

//pins
int rightServoPin = 5;
int leftServoPin = 3;
int buttonPin = 6;
int leftPhotoPin = A0;
int rightPhotoPin = A1;

//variables
int leftLight;
int rightLight;
int leftLightMAX = 45;
int rightLightMAX = 45;
boolean leftOn;
boolean rightOn;

//left drive constants
int RIGHT_STOP = 92;
int RIGHT_FORWARD_MAX = RIGHT_STOP - 20;
int RIGHT_BACKWARD_MAX = RIGHT_STOP + 20;
//right drive constants
int LEFT_STOP = 81;
int LEFT_FORWARD_MAX = LEFT_STOP + 20;
int LEFT_BACKWARD_MAX = LEFT_STOP - 20;

void setup() {
  Serial.begin(9600);
  //servos
  rightServo.attach(rightServoPin);
  leftServo.attach(leftServoPin);
  
  //button
  pinMode(buttonPin, INPUT);
  while(digitalRead(buttonPin) != HIGH) {
    rightServo.write(RIGHT_STOP);
    leftServo.write(LEFT_STOP);
  }
 leftLightMAX = analogRead(leftPhotoPin);
 rightLightMAX = analogRead(rightPhotoPin);
}

void loop() {
  //input
  leftLight = analogRead(leftPhotoPin);
  rightLight = analogRead(rightPhotoPin);
  Serial.print(leftLight);
  Serial.print(", ");
  Serial.println(rightLight);
  //process
  leftOn = leftLight < leftLightMAX + 7;
  rightOn = rightLight < rightLightMAX + 7;
  if (rightOn && leftOn) {
    leftServo.write(LEFT_FORWARD_MAX);
    rightServo.write(RIGHT_FORWARD_MAX);
  } else if (!rightOn && !leftOn) {
    leftServo.write(LEFT_STOP);
    rightServo.write(RIGHT_STOP);
  } else if (rightOn && !leftOn) {
    leftServo.write(LEFT_FORWARD_MAX);
    rightServo.write(RIGHT_BACKWARD_MAX);
  } else if (!rightOn && leftOn) {
    leftServo.write(LEFT_BACKWARD_MAX);
    rightServo.write(RIGHT_FORWARD_MAX);
  }
  
  delay(100);
}


