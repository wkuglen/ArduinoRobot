#include<Servo.h>

//declarations
Servo rightServo;
Servo leftServo;

//pins
int rightServoPin = 5;
int leftServoPin = 3;
int buttonPin = 6;
int rightBumperPin = 11;
int centerBumperPin = 12;
int leftBumperPin = 13;
int leftLightPin = A0;
int rightLightPin = A1;
int rPin = 8;
int gPin = 7;
int bPin = 2;

//variables
boolean leftBumper;
boolean centerBumper;
boolean rightBumper;
int leftLight;
int rightLight;

//left drive constants
int RIGHT_STOP = 92;
int RIGHT_FORWARD_MAX = RIGHT_STOP - 10;
int RIGHT_BACKWARD_MAX = RIGHT_STOP + 10;
//right drive constants
int LEFT_STOP = 81;
int LEFT_FORWARD_MAX = LEFT_STOP + 10;
int LEFT_BACKWARD_MAX = LEFT_STOP - 10;

void setup() {
  //servos
  rightServo.attach(rightServoPin);
  leftServo.attach(leftServoPin);

  //button
  pinMode(buttonPin, INPUT);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  while (digitalRead(buttonPin) != HIGH) {
    rightServo.write(RIGHT_STOP);
    leftServo.write(LEFT_STOP);
  }//while
}

void loop() {
  //input
  leftBumper = digitalRead(leftBumperPin);
  centerBumper = digitalRead(centerBumperPin);
  rightBumper = digitalRead(rightBumperPin);
  leftLight = analogRead(leftLightPin);
  rightLight = analogRead(rightLightPin);

  //process
  if (!leftBumper && centerBumper && !rightBumper) {
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.7 * 1000);
    if (leftLight < rightLight) {
      rightServo.write(RIGHT_BACKWARD_MAX);
      leftServo.write(LEFT_FORWARD_MAX);
    } else {
      rightServo.write(RIGHT_FORWARD_MAX);
      leftServo.write(LEFT_BACKWARD_MAX);
    }
    delay(.4 * 1000);
  } else if (leftBumper && !centerBumper && !rightBumper) {
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.7 * 1000);
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_FORWARD_MAX);
    delay(.4 * 1000);
  } else if (!leftBumper && !centerBumper && rightBumper) {
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.7 * 1000);
    rightServo.write(RIGHT_FORWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.4 * 1000);
  } else if (leftBumper && centerBumper && rightBumper) {
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.7 * 1000);
    if (leftLight < rightLight) {
      rightServo.write(RIGHT_BACKWARD_MAX);
      leftServo.write(LEFT_FORWARD_MAX);
    } else {
      rightServo.write(RIGHT_FORWARD_MAX);
      leftServo.write(LEFT_BACKWARD_MAX);
    }
    delay(.4 * 1000);
  } else if (leftBumper && centerBumper && !rightBumper) {
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.7 * 1000);
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_FORWARD_MAX);
    delay(.4 * 1000);
  } else if (!leftBumper && centerBumper && rightBumper) {
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.7 * 1000);
    rightServo.write(RIGHT_FORWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.4 * 1000);
  } else {
    if (abs(rightLight - leftLight) < 25) {
      rightServo.write(RIGHT_FORWARD_MAX);
      leftServo.write(LEFT_FORWARD_MAX);
    } else if (rightLight > leftLight) {
      rightServo.write(RIGHT_STOP);
      leftServo.write(LEFT_FORWARD_MAX);
    } else if (rightLight < leftLight) {
      rightServo.write(RIGHT_FORWARD_MAX);
      leftServo.write(LEFT_STOP);
    }
  }
  
  digitalWrite(rPin, random(0, 2) == 0 ? HIGH : LOW);
  digitalWrite(gPin, random(0, 2) == 0 ? HIGH : LOW);
  digitalWrite(bPin, random(0, 2) == 0 ? HIGH : LOW);

  //delay
  delay(.02 * 1000);
}


