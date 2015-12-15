// DS1302_Serial_Easy 
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//
// A quick demo of how to use my DS1302-library to 
// quickly send time and date information over a serial link
//
// I assume you know how to connect the DS1302.
// DS1302:  RST pin (CE Pin)    -> Arduino Digital 8
//          DAT pin (I/O pin)   -> Arduino Digital 9
//          CLK pin (SCLK pin)  -> Arduino Digital 10
//          GND pin             -> Arduino Digital 11
//          VCC pin             -> Arduino Digital 12


#include <DS1302.h>

// Init the DS1302
DS1302 rtc(8, 9, 10);       // Maken van rtc-object op basis DS1302 klasse
#define DS1302_GND_PIN 11   //Benoeming pin 11 als DS1302_GND_PIN
#define DS1302_VCC_PIN 12   //Benoeming pin 12 als DS1302_VCC_PIN


void setup()
{ 
  digitalWrite(DS1302_GND_PIN, LOW);
  pinMode(DS1302_GND_PIN, OUTPUT);

  digitalWrite(DS1302_VCC_PIN, HIGH);
  pinMode(DS1302_VCC_PIN, OUTPUT);
  
  Serial.println("RTC module activated");
  Serial.println();
  
  // Set the clock to run-mode, and disable the write protection
  rtc.halt(false);
  rtc.writeProtect(false);
  
  // Setup Serial connection
  Serial.begin(9600);

  // The following lines can be commented out to use the values already stored in the DS1302
  rtc.setDOW(TUESDAY);        // Weekdag instellen op dinsdag
  rtc.setTime(20, 50,30 );     // Tijd instellen op 20 u 50 min 30 sec
  rtc.setDate(15, 12, 2015);   // Datum instellen op 15 december 2015
}

void loop()
{
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" -> ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
  
  // Wait one second before repeating :)
  delay (1000);
}
