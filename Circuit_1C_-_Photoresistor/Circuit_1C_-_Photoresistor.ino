/*
SparkFun Inventor’s Kit
Circuit 1C-Photoresistor

Use a photoresistor to monitor how bright a room is, and turn an LED on when it gets dark.

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

int photoresistor = 0;              //this variable will hold a value based on the brightness of the ambient light
int threshold = 40;                //if the photoresistor reading is below this value the light will turn on

void setup()
{
  Serial.begin(9600);               //start a serial connection with the computer

  pinMode(13, OUTPUT);              //set pin 13 as an output that can be set to HIGH or LOW
}

void loop()
{
  //read the brightness of the ambient light
  photoresistor = analogRead(A0);   //set photoresistor to a number between 0 and 1023 based on how bright the ambient light is
  Serial.println(photoresistor);    //print the value of photoresistor in the serial monitor on the computer

  //if the photoresistor value is below the threshold turn the light on, otherwise turn it off
  if (photoresistor < threshold){
      digitalWrite(13, HIGH);
      digitalWrite(7, LOW); 
      delay(250);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      delay(250);
      digitalWrite(7, HIGH);
      digitalWrite(12, LOW);
  } else{
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(7, LOW);
  }

  delay(250);                       //short delay to make the printout easier to read
}
