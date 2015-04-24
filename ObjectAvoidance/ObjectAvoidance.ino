/*
Matthew W., Will K., Ayesh S.
Object Avoidance Robot
*/
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
    //IF CENTER BUMPER PRESSED
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.5 * 1000);
    //turn toward light
    if (leftLight < rightLight) {
      rightServo.write(RIGHT_BACKWARD_MAX);
      leftServo.write(LEFT_FORWARD_MAX);
    } else {
      rightServo.write(RIGHT_FORWARD_MAX);
      leftServo.write(LEFT_BACKWARD_MAX);
    }
    delay(.4 * 1000);
  } else if (leftBumper && !centerBumper && !rightBumper) {
    //IF LEFT BUMPER PRESSED
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.5 * 1000);
    //turn
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_FORWARD_MAX);
    delay(.4 * 1000);
  } else if (!leftBumper && !centerBumper && rightBumper) {
    //IF RIGHT BUMPER PRESSED
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.5 * 1000);
    //turn
    rightServo.write(RIGHT_FORWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.4 * 1000);
  } else if (leftBumper && centerBumper && rightBumper) {
    //IF ALL BUMPERS PRESSED
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.5 * 1000);
    //turn toward light
    if (leftLight < rightLight) {
      rightServo.write(RIGHT_BACKWARD_MAX);
      leftServo.write(LEFT_FORWARD_MAX);
    } else {
      rightServo.write(RIGHT_FORWARD_MAX);
      leftServo.write(LEFT_BACKWARD_MAX);
    }
    delay(.4 * 1000);
  } else if (leftBumper && centerBumper && !rightBumper) {
    //IF LEFT & CENTER BUMPER PRESSED
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.5 * 1000);
    //turn
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_FORWARD_MAX);
    delay(.4 * 1000);
  } else if (!leftBumper && centerBumper && rightBumper) {
    //IF CENTER & RIGHT BUMPER PRESSED
    rightServo.write(RIGHT_BACKWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.5 * 1000);
    //turn
    rightServo.write(RIGHT_FORWARD_MAX);
    leftServo.write(LEFT_BACKWARD_MAX);
    delay(.4 * 1000);
  } else {
    //IF NO BUMPERS PRESSED
    if (abs(rightLight - leftLight) < 25) {
      //drive straight
      rightServo.write(RIGHT_FORWARD_MAX);
      leftServo.write(LEFT_FORWARD_MAX);
    } else if (rightLight > leftLight) {
      //turn hard right
      rightServo.write(RIGHT_STOP);
      leftServo.write(LEFT_FORWARD_MAX);
    } else if (rightLight < leftLight) {
      //turn hard left
      rightServo.write(RIGHT_FORWARD_MAX);
      leftServo.write(LEFT_STOP);
    }
  }
  
  //Random Lights
  digitalWrite(rPin, random(0, 2) == 0 ? HIGH : LOW);
  digitalWrite(gPin, random(0, 2) == 0 ? HIGH : LOW);
  digitalWrite(bPin, random(0, 2) == 0 ? HIGH : LOW);

  //delay
  delay(.02 * 1000);
}

//REFERENCES
/* Light Patterns
RED R--
YELLOW RG-
WHITE RGB
PINK/PURPLE R-B
BLACK ---
GREEN -G-
LIGHT BLUE -GB
BLUE --B
*/
/*Print Formatting
  Serial.print(leftBumper);
  Serial.print(" ");
  Serial.print(centerBumper);
  Serial.print(" ");
  Serial.print(rightBumper);
  Serial.print(" | ");
  Serial.print(leftLight);
  Serial.print(" ");
  Serial.println(rightLight);
*/

