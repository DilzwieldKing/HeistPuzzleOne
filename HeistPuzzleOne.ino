//Atelier Art Heist Puzzle One

#include <Servo.h>

Servo myservo;

const int analogInPin1 = A1;
const int analogInPin2 = A2;
const int analogInPin3 = A3;

const int switchpin = 13;
int buttonState = 0; 

//Answer Values
const int answerOne = 44;
const int answerTwo = 95;
const int answerThree = 81;

int sensorValue1 = 0;
int outputValue1 = 0;
int sensorValue2 = 0;
int outputValue2 = 0;
int sensorValue3 = 0;
int outputValue3 = 0;

//Variable to store the initial servo position
int pos = 0;

void setup() {
  //Sets the input pins as well as the initial servo angle
  Serial.begin(9600);
  myservo.attach(6);
  myservo.write(0);
  pinMode(switchpin, INPUT);
}

void loop() {
  buttonState = digitalRead(switchpin);
  //Calculates the difference between the input from the potentiometers and the answer values
  int difference1 = outputValue1 - answerOne;
  int difference2 = outputValue2 - answerTwo;
  int difference3 = outputValue3 - answerThree;

  //Potentiometer values are mapped from 0-100
  sensorValue1 = analogRead(analogInPin1);
  outputValue1 = map(sensorValue1, 0, 1023, 0, 100);
  sensorValue2 = analogRead(analogInPin2);
  outputValue2 = map(sensorValue2, 0, 1023, 0, 100);
  sensorValue3 = analogRead(analogInPin3);
  outputValue3 = map(sensorValue3, 0, 1023, 0, 100);

  //Determines if the absolute difference of the values calculated earlier are within a range of 10, if true then the servo angle changes.
  if (abs(difference1) < 10 && abs(difference2) < 10 && abs(difference3) < 10){
    myservo.write(90);
    delay(10);
  }else{
    delay(10);
  }
  //Backup switch used to reset the servo angle to default
  if (buttonState == HIGH) {
    myservo.write(0);
  }

  //Used for calibration within the serial monitor
  Serial.println(outputValue1);
  Serial.print("    ");
  Serial.print(outputValue2);
  Serial.print("    ");
  Serial.print(outputValue3);
  Serial.print("    ");

  delay(2);
}
