#include<Servo.h>

//declarations
Servo rightServo;
Servo leftServo;
int cyclesLeft;//1 cycle = 50 ms

//pins
int rightServoPin = 5;
int leftServoPin = 3;
int buttonPin = 6;
int rightBumperPin = 11;//?
int centerBumperPin = 12;//?
int leftBumperPin = 13;//?

//variables
boolean leftBumper;
boolean centerBumper;
boolean rightBumper;

//left drive constants
int RIGHT_STOP = 92;
int RIGHT_FORWARD_MAX = RIGHT_STOP - 10;
int RIGHT_BACKWARD_MAX = RIGHT_STOP + 10;
//right drive constants
int LEFT_STOP = 81;
int LEFT_FORWARD_MAX = LEFT_STOP + 10;
int LEFT_BACKWARD_MAX = LEFT_STOP - 10;

void setup() {
  Serial.begin(9600);
  
  //servos
  rightServo.attach(rightServoPin);
  leftServo.attach(leftServoPin);

  //button
  pinMode(buttonPin, INPUT);
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
  Serial.print(leftBumper);
  Serial.print(" ");
  Serial.print(centerBumper);
  Serial.print(" ");
  Serial.println(rightBumper);

  //process
  if (!leftBumper && centerBumper && !rightBumper) {
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.5 * 1000);
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_FORWARD_MAX);
    delay(.4 * 1000);
  } else if (leftBumper && !centerBumper && !rightBumper) {
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.5 * 1000);
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_FORWARD_MAX);
    delay(.4 * 1000);
  } else if (!leftBumper && !centerBumper && rightBumper) {
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.5 * 1000);
    rightServo.write(RIGHT_FORWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.4 * 1000);
  } else if (leftBumper && centerBumper && rightBumper) {
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.5 * 1000);
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_FORWARD_MAX);
    delay(.4 * 1000);
  } else if (leftBumper && centerBumper && !rightBumper) {
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.5 * 1000);
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_FORWARD_MAX);
    delay(.4 * 1000);
  } else if (!leftBumper && centerBumper && rightBumper) {
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.5 * 1000);
    rightServo.write(RIGHT_FORWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.4 * 1000);
  } else {
    rightServo.write(RIGHT_FORWARD_MAX);
    leftServo.write(LEFT_FORWARD_MAX);
  }

  //delay
  delay(.05 * 1000);
}


