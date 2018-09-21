/*
 * 7 Segment 4 Digit Display Example
 * 
 * by Niyas Thalappil
 * 
 * www.youtube.com/c/NiyasThalappil
 * NiyazThalappil@gmail.com
 * 
 * TM1637 Libray can be downloaded from: https://github.com/avishorp/TM1637
 */

 
#include <DS3231.h>                                           //RTC Library
#include <Wire.h>                                             //I2C Library
#include <TM1637Display.h>                                    //TM1637 Library

#define CLK 2                                                 //display clock on digital 2
#define DIO 3                                                 //display data on digital 3

DS3231 Clock;                                                 //create instance of DS3131 called Clock
TM1637Display display(CLK, DIO);                              //create instance of 7/4 display called display

byte year, month, date, DoW, hour, minute, second;            //global variables for DS3231

void setup() {

  Wire.begin();                                           
  Serial.begin(9600);                                  
  display.setBrightness(0x0f);                                //set max brightness
}

void loop() {

Clock.getTime(year, month, date, DoW, hour, minute, second);  //get time from DS3231

String myTime = String(hour)+String(minute);                  
int myTimeInt = myTime.toInt();                               
//Serial.print(myTimeInt);                                    
display.showNumberDecEx(myTimeInt, (0x80 >> 1), true,4,0);    
delay(1000);                                                  
display.showNumberDec(myTimeInt, true, 4, 0);                
delay(1000);                                                 

}
