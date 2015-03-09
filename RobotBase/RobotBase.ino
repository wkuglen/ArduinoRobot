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

//constants
int RIGHT_STOP = 92;
int RIGHT_FORWARD_MAX = RIGHT_STOP - 50;
int RIGHT_BACKWARD_MAX = RIGHT_STOP + 50;

int LEFT_STOP = 81;
int LEFT_FORWARD_MAX = LEFT_STOP + 50;
int LEFT_BACKWARD_MAX = LEFT_STOP - 50;

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
}

void loop() {
  leftLight = analogRead(leftPhotoPin);
  rightLight = analogRead(rightPhotoPin);
  //rightServo.write(RIGHT_FORWARD_MAX);
  //leftServo.write(LEFT_FORWARD_MAX);
  
  Serial.println("~");
  Serial.println(leftLight);
  Serial.println(rightLight);
}
