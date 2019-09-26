/*
SparkFun Inventor’s Kit
Circuit 3A-Servo

Move a servo attached to pin 9 so that it's angle matches a potentiometer attached to A0.

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
 */

#include <Servo.h>          //include the servo library

int photoresistor = 0;     //this variable will hold a value based on the brightness of the ambient light
int servoPosition;         //the servo will move to this position

Servo myservo;              //create a servo object

void setup() {

  Serial.begin(9600);       //start a serial connection with the computer
  myservo.attach(9);        //tell the servo object that its servo is plugged into pin 9

}

void loop() {

  //read the brightness of the ambient light
  photoresistor = analogRead(A0);   //set photoresistor to a number between 0 and 1023 based on how bright the ambient light is

  Serial.println("Photoresistor value:");
  Serial.println(photoresistor);          //print the photoresistor value to the serial monitor


  servoPosition = map(photoresistor, 0,1023,40,160);  //convert the potentiometer number to a servo position from 20-160
                                                    //Note: its best to avoid driving the little SIK servos all the 
                                                    //way to 0 or 180 degrees it can cause the motor to jitter, which is bad for the servo.

  myservo.write(servoPosition);                      //move the servo to the 10 degree position

  delay(250);         //short delay to make the printout easier to read
}
