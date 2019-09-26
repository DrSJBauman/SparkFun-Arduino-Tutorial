/*
SparkFun Inventor’s Kit
Circuit 1D-RGB Nightlight

Turns an RGB LED on or off based on the light level read by a photoresistor.
Set the turn-on threshold by turning the potentiometer.
While on, the light smoothly cycles through the full visible spectrum.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
 */

int photoresistor;    //variable for storing the photoresistor value
int potentiometer;    //this variable will hold a value based on the position of the knob
int threshold = 100;  //if the photoresistor reading is lower than this value the light will turn on

//LEDs are connected to these pins
int RED = 9;
int GREEN = 10;
int BLUE = 11;

void setup() {
  Serial.begin(9600);           //start a serial connection with the computer

  //set the LED pins to output
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
}

// define variables
int redValue;
int greenValue;
int blueValue;

void loop() {     //The main program cycled through on a loop

  #define delayTime 50 // fading time between colors

  photoresistor = analogRead(A0);         //read the value of the photoresistor
  potentiometer = analogRead(A1);
//  Serial.print("Photoresistor value:");
//  Serial.print(photoresistor);          //print the photoresistor value to the serial monitor
//  Serial.print("  Potentiometer value:");
//  Serial.println(potentiometer);          //print the potentiometer value to the serial monitor
  setThreshold();

  if(photoresistor < threshold){          //if it's dark (the photoresistor value is below the threshold) turn the LED on
    redValue = 255; // choose a value between 1 and 255 to change the color.
    greenValue = 0;
    blueValue = 0;
    }  

  else {                                //if it isn't dark turn the LED off
    turnOff();                            //call the turn off function
  }  
   
  for(int i = 0; i < 255;) // fades out red bring green full when i=255
  {
    photoresistor = analogRead(A0);         //read the value of the photoresistor
    potentiometer = analogRead(A1);
    setThreshold();
    
    if(photoresistor < threshold){          //if it's dark (the photoresistor value is below the threshold) turn the LED on
      i += 1;   //count up from 0 to 255 only while its dark (while LED is lit)
      redValue -= 1;
      greenValue += 1;
      analogWrite(RED, redValue);
      analogWrite(GREEN, greenValue);
      delay(delayTime);
    }
    
    else {                                //if it isn't dark turn the LED off
      turnOff();                            //call the turn off function
    }
  }  

  if(photoresistor < threshold){          //if it's dark (the photoresistor value is below the threshold) turn the LED on
    redValue = 0;
    greenValue = 255;
    blueValue = 0;
  }

  else{
    turnOff();
  }
  
  for(int i = 0; i < 255;) // fades out green bring blue full when i=255
  {
    photoresistor = analogRead(A0);         //read the value of the photoresistor
    potentiometer = analogRead(A1);
    setThreshold();
    
    if(photoresistor < threshold){          //if it's dark (the photoresistor value is below the threshold) turn the LED on
      i += 1;     //count from 0 to 255 only while it's dark (while LED is lit)
      greenValue -= 1;
      blueValue += 1;
      analogWrite(GREEN, greenValue);
      analogWrite(BLUE, blueValue);
      delay(delayTime);
    }

    else {                                //if it isn't dark turn the LED off
      turnOff();                            //call the turn off function
    }
  }

  if(photoresistor < threshold){          //if it's dark (the photoresistor value is below the threshold) turn the LED on
    redValue = 0;
    greenValue = 0;
    blueValue = 255;
  }

  else{
    turnOff();
  }
  
  for(int i = 0; i < 255;) // fades out blue bring red full when i=255
  {
    photoresistor = analogRead(A0);         //read the value of the photoresistor
    potentiometer = analogRead(A1);
    setThreshold();
    
    if(photoresistor < threshold){          //if it's dark (the photoresistor value is below the threshold) turn the LED on
      i += 1;     //count from 0 to 255 only while it's dark (while LED is lit)
      blueValue -= 1;
      redValue += 1;
      analogWrite(BLUE, blueValue);
      analogWrite(RED, redValue);
      delay(delayTime);
    }

    else {                                //if it isn't dark turn the LED off
      turnOff();                            //call the turn off function
    }
    
  } 

//delay(100);                             //short delay so that the printout is easier to read

}

void turnOff (){    //define the turnOff function that runs each time it's called
    //set all three LED pins to 0 or OFF
    analogWrite(RED, 0);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 0);
}

void setThreshold (){     //define the setThreshold function which sets the LED turn-on threshold
                          //based on the pot setting
    if(potentiometer > 0 && potentiometer <= 50){
      threshold = 5; }
    if(potentiometer > 50 && potentiometer <= 100){
      threshold = 10; }
    if(potentiometer > 100 && potentiometer <= 150){
      threshold = 15; }
    if(potentiometer > 150 && potentiometer <= 200){
      threshold = 20; }
    if(potentiometer > 200 && potentiometer <= 250){
      threshold = 35; }
    if(potentiometer > 250 && potentiometer <= 300){
      threshold = 50; }
    if(potentiometer > 300 && potentiometer <= 350){
      threshold = 70; }
    if(potentiometer > 350 && potentiometer <= 400){
      threshold = 100; }
    if(potentiometer > 400 && potentiometer <= 450){
      threshold = 150; }
    if(potentiometer > 450 && potentiometer <= 500){
      threshold = 250; }
    if(potentiometer > 500 && potentiometer <= 550){
      threshold = 350; }
    if(potentiometer > 550 && potentiometer <= 600){
      threshold = 500; }
    if(potentiometer > 600 && potentiometer <= 650){
      threshold = 600; }
    if(potentiometer > 650 && potentiometer <= 700){
      threshold = 700; }
    if(potentiometer > 700 && potentiometer <= 750){
      threshold = 800; }
    if(potentiometer > 750 && potentiometer <= 800){
      threshold = 900; }
    if(potentiometer > 800 && potentiometer <= 850){
      threshold = 1000; }
    if(potentiometer > 850 && potentiometer <= 900){
      threshold = 1100; }
    if(potentiometer > 900){
      threshold = 1250;  }
}
