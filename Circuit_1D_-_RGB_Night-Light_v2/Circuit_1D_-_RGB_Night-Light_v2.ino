/*
SparkFun Inventor’s Kit
Circuit 1D-RGB Nightlight

Turns an RGB LED on or off based on the light level read by a photoresistor.
Change colors by turning the potentiometer.

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
 */

int photoresistor;          //variable for storing the photoresistor value
int potentiometer;          //this variable will hold a value based on the position of the knob
int threshold = 100;            //if the photoresistor reading is lower than this value the light will turn on

//LEDs are connected to these pins
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;

void setup() {
  Serial.begin(9600);           //start a serial connection with the computer

  //set the LED pins to output
  pinMode(RedPin,OUTPUT);
  pinMode(GreenPin,OUTPUT);
  pinMode(BluePin,OUTPUT);
}

void loop() {

  photoresistor = analogRead(A0);         //read the value of the photoresistor
  potentiometer = analogRead(A1);

  Serial.print("Photoresistor value:");
  Serial.print(photoresistor);          //print the photoresistor value to the serial monitor
  Serial.print("  Potentiometer value:");
  Serial.println(potentiometer);          //print the potentiometer value to the serial monitor

  if(photoresistor < threshold){          //if it's dark (the photoresistor value is below the threshold) turn the LED on
    //These nested if statements check for a variety of ranges and 
    //call different functions based on the current potentiometer value.
    //Those functions are found at the bottom of the sketch. 
    if(potentiometer > 0 && potentiometer <= 50)
      red();
    if(potentiometer > 50 && potentiometer <= 100){
      analogWrite(RedPin, 100);
      analogWrite(GreenPin, 15);
      analogWrite(BluePin, 0);       }
    if(potentiometer > 100 && potentiometer <= 150){
      analogWrite(RedPin, 100);
      analogWrite(GreenPin, 30);
      analogWrite(BluePin, 0);        }
    if(potentiometer > 150 && potentiometer <= 200)
      orange();
    if(potentiometer > 200 && potentiometer <= 250){
      analogWrite(RedPin, 100);
      analogWrite(GreenPin, 70);
      analogWrite(BluePin, 0); }      
    if(potentiometer > 250 && potentiometer <= 300){
      analogWrite(RedPin, 100);
      analogWrite(GreenPin, 85);
      analogWrite(BluePin, 0);       }
    if(potentiometer > 300 && potentiometer <= 350)
      yellow(); 
    if(potentiometer > 350 && potentiometer <= 400){
      analogWrite(RedPin, 66);
      analogWrite(GreenPin, 100);
      analogWrite(BluePin, 0);       }
    if(potentiometer > 400 && potentiometer <= 450){
      analogWrite(RedPin, 33);
      analogWrite(GreenPin, 100);
      analogWrite(BluePin, 0);       }
    if(potentiometer > 450 && potentiometer <= 500)
      green(); 
    if(potentiometer > 500 && potentiometer <= 550){
      analogWrite(RedPin, 0);
      analogWrite(GreenPin, 100);
      analogWrite(BluePin, 33);       }
    if(potentiometer > 550 && potentiometer <= 600){
      analogWrite(RedPin, 0);
      analogWrite(GreenPin, 100);
      analogWrite(BluePin, 66);       }
    if(potentiometer > 600 && potentiometer <= 650)
      cyan();
    if(potentiometer > 650 && potentiometer <= 700){
      analogWrite(RedPin, 0);
      analogWrite(GreenPin, 66);
      analogWrite(BluePin, 100);        }
    if(potentiometer > 700 && potentiometer <= 750){
      analogWrite(RedPin, 0);
      analogWrite(GreenPin, 33);
      analogWrite(BluePin, 100);        }
    if(potentiometer > 750 && potentiometer <= 800)
      blue();
    if(potentiometer > 800 && potentiometer <= 850){
      analogWrite(RedPin, 33);
      analogWrite(GreenPin, 0);
      analogWrite(BluePin, 100);       }
    if(potentiometer > 850 && potentiometer <= 900){
      analogWrite(RedPin, 66);
      analogWrite(GreenPin, 0);
      analogWrite(BluePin, 100); }
    if(potentiometer > 900)
      magenta();  
  } 
  else {                                //if it isn't dark turn the LED off

    turnOff();                            //call the turn off function

  }  

  delay(100);                             //short delay so that the printout is easier to read
}

void red (){

    //set the LED pins to values that make red    
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 0);
}
void orange (){

    //set the LED pins to values that make orange
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 50);
    analogWrite(BluePin, 0);
}
void yellow (){

    //set the LED pins to values that make yellow
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 100);
    analogWrite(BluePin, 0);
}
void green (){

    //set the LED pins to values that make green    
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 100);
    analogWrite(BluePin, 0);
}
void cyan (){

    //set the LED pins to values that make cyan    
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 100);
    analogWrite(BluePin, 100);
}
void blue (){

    //set the LED pins to values that make blue
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 100);
}
void magenta (){

    //set the LED pins to values that make magenta   
    analogWrite(RedPin, 100);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 100);
}
void turnOff (){

    //set all three LED pins to 0 or OFF
    analogWrite(RedPin, 0);
    analogWrite(GreenPin, 0);
    analogWrite(BluePin, 0);
}
