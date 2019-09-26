/*
Modified by SJBauman from
SparkFun Inventor’s Kit
Circuit 4A-HelloWorld

The LCD will display the first programmed screen until the button is pressed, selecting
the next screen. The button will toggle between or cycle through as many programmed screens as desired

View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v40
Download drawings and code at: https://github.com/sparkfun/SIK-Guide-Code
*/

#include <LiquidCrystal.h>          //the liquid crystal library contains commands for printing to the display

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   // tell the board what pins are connected to the display

const int buttonPin = 2;
int secs = 0;
int mins = 0;
int hrs = 0;
int screenSelect = 0;

void setup() {                     
  pinMode(buttonPin, INPUT_PULLUP); //set up this pin to use the board's internal pullup resistor
  lcd.begin(16, 2);                 //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                      //clear the display
}

void loop() {
  if(screenToggle(buttonCheck())== 0){   //If button is pressed and screen0 is chosen
    screen0();                           //Run the screen0 function
  } else if (screenToggle(buttonCheck()) == 1) {  //If button is pressed and screen1 is chosen
    screen1();                            //Run the screen1 function
  }                                       //One could continue adding elseifs for as many screens as desired
}

bool buttonCheck() {
  //check if the button is being pressed
  if (digitalRead(buttonPin) == LOW) {
    delay(250);             //Allow time for button press to complete, but no so long of a delay that the screen change is slow
    return true;            //Button is being pressed
  } else {
    return false;           //Button is not being pressed
  }
}

int screenToggle(bool buttPress) {
  if (screenSelect == 0 && buttPress == true){  //Button press during screen0?
    screenSelect = 1;                           //Toggle to screen1
    lcd.clear();                                //Clear the screen before printing to lcd
  } else if (screenSelect == 1 && buttPress == true){
    screenSelect = 0;
    lcd.clear();
  }
  return screenSelect;                          //Output selected screen number as int
}  

String count(){
  //Calculate seconds, minutes, and hours since last reset using the milliseconds function
  hrs = (millis()/1000) / 3600;
  mins = ((millis() / 1000) / 60) - (60 * hrs);
  secs = (millis() / 1000) - (60 * mins) - (3600 * hrs);
  String resetTime = String(hrs) + ":" + String(mins) + ":" + String(secs)+ " "; //space needed at the end for every minute transition
  return resetTime;
}

void screen0() {
  lcd.setCursor(0,0);       //set the cursor to the 0,0 position (top left corner)
  lcd.print("Last reset:"); //print "Last reset:" starting at that position
    
  lcd.setCursor(0,1);       //move the cursor to the first space of the bottom row
  lcd.print(count());       //print the number of hours:minutes:seconds that have passed since the last reset 
}

void screen1() {
  lcd.setCursor(0,0);           //set the cursor to the 0,0 position (top left corner)
  lcd.print("Press button for"); 
    
  lcd.setCursor(0,1);           //move the cursor to the first space of the bottom row
  lcd.print("time count :)");   //The plan for screen1 was to implement a countdown timer
}
