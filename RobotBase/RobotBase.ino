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
int leftLightMAX = 35;//(default value)
int rightLightMAX = 35;//(default value)
boolean leftOn;
boolean rightOn;

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
  while(digitalRead(buttonPin) != HIGH) {
    //Rewrites Stop values to current darkness on track
    rightServo.write(RIGHT_STOP);
    leftServo.write(LEFT_STOP);
  }//WHILE
}

void loop() {
  //input
  leftLight = analogRead(leftPhotoPin);
  rightLight = analogRead(rightPhotoPin);
  
  //process
  leftOn = leftLight < leftLightMAX;
  rightOn = rightLight < rightLightMAX;
  if (rightOn && leftOn) {
    //IF BOTH ON TRACK
    leftServo.write(LEFT_FORWARD_MAX);
    rightServo.write(RIGHT_FORWARD_MAX);
  } else if (!rightOn && !leftOn) {
    //IF BOTH OFF TRACK
    if(leftLight < rightLight) {
      //IF LEFT-SIDE DARKER
      leftServo.write(LEFT_BACKWARD_MAX);
      rightServo.write(RIGHT_FORWARD_MAX);
    } else {
      //IF RIGHT-SIDE DARKER
      leftServo.write(LEFT_FORWARD_MAX);
      rightServo.write(RIGHT_BACKWARD_MAX);
    }
  } else if (rightOn && !leftOn) {
    //IF RIGHT ON TRACK
    leftServo.write(LEFT_FORWARD_MAX);
    rightServo.write(RIGHT_BACKWARD_MAX);
  } else if (!rightOn && leftOn) {
    //IF LEFT ON TRACK
    leftServo.write(LEFT_BACKWARD_MAX);
    rightServo.write(RIGHT_FORWARD_MAX);
  }//End of IF statements
  
  delay(100);//Small delay to account for change
}


