/*
Matthew W., Will K., Ayesh S.
Object Avoidance Robot
*/
#include<Servo.h>
#include<SoftwareSerial.h>

//declarations
Servo rightServo;
Servo leftServo;
SoftwareSerial mySerial = SoftwareSerial(0,1);

//pins
int rightServoPin = 5;
int leftServoPin = 3;
int buttonPin = 6;
//int tx_pin = 1;
//int rx_pin = 0;
int rPin = 8;
int gPin = 7;
int bPin = 2;

//variables
char bluetoothVAR;

//left drive constants
int RIGHT_STOP = 92;
int RIGHT_FORWARD_MAX = RIGHT_STOP - 20;
int RIGHT_BACKWARD_MAX = RIGHT_STOP + 20;
//right drive constants
int LEFT_STOP = 82;
int LEFT_FORWARD_MAX = LEFT_STOP + 20;
int LEFT_BACKWARD_MAX = LEFT_STOP - 20;

void setup() {
  //servos
  rightServo.attach(rightServoPin);
  leftServo.attach(leftServoPin);

  mySerial.begin(9600);
  Serial.begin(9600);
  
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
  if(mySerial.available()) {
        
      //input
      bluetoothVAR = mySerial.read();
      Serial.print(bluetoothVAR);
      
      ///process
      if (bluetoothVAR == '8') {
        //IF Forward
        rightServo.write(RIGHT_FORWARD_MAX);
        leftServo.write(LEFT_FORWARD_MAX);
        delay(10);
      } else if (bluetoothVAR == '2') {
        //IF Backward
        rightServo.write(RIGHT_BACKWARD_MAX);
        leftServo.write(LEFT_BACKWARD_MAX);
        delay(10);//OLD delay(.7 * 1000);
      } else if (bluetoothVAR == '4') {
        //IF Left
        rightServo.write(RIGHT_FORWARD_MAX);
        leftServo.write(LEFT_BACKWARD_MAX);
        delay(10);
      } else if (bluetoothVAR == '6') {
        //IF Right
        rightServo.write(RIGHT_BACKWARD_MAX);
        leftServo.write(LEFT_FORWARD_MAX);
        delay(10);
      } else {
        //IF NO BUMPERS PRESSED
        rightServo.write(RIGHT_STOP);
        leftServo.write(LEFT_STOP);
        
      }
      
      
      //Random Lights
      digitalWrite(rPin, random(0, 2) == 0 ? HIGH : LOW);
      digitalWrite(gPin, random(0, 2) == 0 ? HIGH : LOW);
      digitalWrite(bPin, random(0, 2) == 0 ? HIGH : LOW);
  }
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

