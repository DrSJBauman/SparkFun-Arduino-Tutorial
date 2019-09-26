/*
SparkFun Inventor’s Kit
Circuit 4A-HelloWorld

The LCD will display the words "Hello World" and show how many seconds have passed since
the RedBoard was last reset.

This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
This code is completely free for any use.

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

#include <LiquidCrystal.h>          //the liquid crystal library contains commands for printing to the display

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   // tell the RedBoard what pins are connected to the display

int secs = 0;
int mins = 0;
int hrs = 0;

void setup() {                     

  lcd.begin(16, 2);                 //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                      //clear the display
}

void loop() {

  lcd.setCursor(0,0);               //set the cursor to the 0,0 position (top left corner)
  lcd.print("Last reset:");       //print hello, world! starting at that position

  
  secs = (millis() / 1000) - (60 * mins);
  mins = ((millis() / 1000) / 60) - (60 * hrs);
  hrs = (millis()/1000) / 3600;
  String count = String(hrs) + ":" + String(mins) + ":" + String(secs)+ " ";
    
  lcd.setCursor(0,1);               //move the cursor to the first space of the bottom row
  lcd.print(count);         //print the number of seconds that have passed since the last reset
}  
