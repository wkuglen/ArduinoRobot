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
int leftLightMAX = 35;
int rightLightMAX = 35;
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
 //leftLightMAX = analogRead(leftPhotoPin)+3;
 //rightLightMAX = analogRead(rightPhotoPin)+3;
 Serial.println(leftLightMAX);
 Serial.println(rightLightMAX);
 Serial.println("~");
}

void loop() {
  //input
  leftLight = analogRead(leftPhotoPin);
  rightLight = analogRead(rightPhotoPin);
  Serial.print(leftLight);
  Serial.print(", ");
  Serial.println(rightLight);
  //process
  leftOn = leftLight < leftLightMAX;
  rightOn = rightLight < rightLightMAX;
  if (rightOn && leftOn) {
    leftServo.write(LEFT_FORWARD_MAX);
    rightServo.write(RIGHT_FORWARD_MAX);
  } else if (!rightOn && !leftOn) {
    if(leftLight < rightLight)
    {
      leftServo.write(LEFT_BACKWARD_MAX);
      rightServo.write(RIGHT_FORWARD_MAX);
    }
    else
    {
      leftServo.write(LEFT_FORWARD_MAX);
      rightServo.write(RIGHT_BACKWARD_MAX);
    }
    //leftServo.write(LEFT_FORWARD_MAX);
    //rightServo.write(RIGHT_FORWARD_MAX);
  } else if (rightOn && !leftOn) {
    leftServo.write(LEFT_FORWARD_MAX);
    rightServo.write(RIGHT_BACKWARD_MAX);
  } else if (!rightOn && leftOn) {
    leftServo.write(LEFT_BACKWARD_MAX);
    rightServo.write(RIGHT_FORWARD_MAX);
  }
  
  delay(100);
}


