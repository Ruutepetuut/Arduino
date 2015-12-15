// Pin verbonden ST_CP van 74HC595
int latchPin = 8;
// Pin verbonden SH_CP van 74HC595
int clockPin = 12;
//// Pin verbonden met DS van 74HC595
int dataPin = 11;

// houders voor infromation je gaat geven aan het verschuiven functie
byte dataUur;
byte dataGREEN;
byte dataBLEU;
byte dataArrayUur [12];
byte dataArrayUur2 [4];
byte Arrayminuut [60];
byte Arraywijzer [60];
byte data;
byte hulpuur;
void  setup () {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  // Je setup code in te zetten, om een ​​keer uit te voeren:
 int minuut = 0;
 int Uur = 0;
  int hulpuur = 0;
  // set pinnen om de uitgang, omdat ze in de grote lus aangepakt

  Serial.begin (9600);


  dataArrayUur [0] = 1;
  dataArrayUur [1] = 2;
  dataArrayUur [2] = 4;
  dataArrayUur [3] = 8;
  dataArrayUur [4] = 16;
  dataArrayUur [5] = 32;
  dataArrayUur [6] = 64;
  dataArrayUur [7] = 128;
  dataArrayUur [8] = 0;
  dataArrayUur [9] = 0;
  dataArrayUur [10] = 0;
  dataArrayUur [11] = 0;
   
  dataArrayUur2 [0] = 0;
  dataArrayUur2 [1] = 0;
  dataArrayUur2 [2] = 0;
  dataArrayUur2 [3] = 0;
  dataArrayUur2 [4] = 0;
  dataArrayUur2 [5] = 0;
  dataArrayUur2 [6] = 0;
  dataArrayUur2 [7] = 0;
  dataArrayUur2 [8] = 16;
  dataArrayUur2 [9] = 32;
  dataArrayUur2 [10] = 64;
  dataArrayUur2 [11] = 128;



  
int Arrayminuut [] = { 1 , 3 , 7 , 15 , 16 , 17 , 19 , 23 , 31 , 32 , 33 , 35 , 39 , 47 , 64 , 65 , 67 , 71 , 79 , 0 , 175 , 167 , 163 , 145 , 144 , 143 , 135 , 131 , 129 , 128 , 129 , 131 , 135 , 143 , 144 , 145 , 147 , 151 , 159 , 0 , 47 , 39 , 35 , 1 , 64 , 47 , 39 , 35 , 33 , 32 , 31 , 23 , 19 , 17 , 16 , 15 , 7 , 3 , 1 };

int Arraywijzer[]={ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 5 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 6 , 6 , 6 , 6 , 6 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 };

}
 void loop () {
   digitalWrite (latchPin, LOW);
   shiftOut (dataPin, clockPin, LSBFIRST, 0);
   shiftOut (dataPin, clockPin, LSBFIRST, 0);
   shiftOut (dataPin, clockPin, LSBFIRST, 0);
   digitalWrite (latchPin, HIGH);
 int Arrayminuut [] = { 1 , 3 , 7 , 15 , 16 , 17 , 19 , 23 , 31 , 32 , 33 , 35 , 39 , 47 , 64 , 65 , 67 , 71 , 79 , 0 , 175 , 167 , 163 , 145 , 144 , 143 , 135 , 131 , 129 , 128 , 129 , 131 , 135 , 143 , 144 , 145 , 147 , 151 , 159 , 0 , 47 , 39 , 35 , 1 , 64 , 47 , 39 , 35 , 33 , 32 , 31 , 23 , 19 , 17 , 16 , 15 , 7 , 3 , 1 };
int Arraywijzer[]={ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 5 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 6 , 6 , 6 , 6 , 6 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 };
int Uur = 0;
int minuut = 0;
int hulpuur = 0;

for (int minuut = 0; minuut <= 60; minuut ++) {
if(minuut == 60) {
   Uur = Uur + 1;
  minuut = 0;} // teller for nabootsing van klok
if (Uur == 12) {
   Uur = 0;}   // max 12 Uren
  hulpuur = Uur;
  
 
   
if(minuut> 20) {
hulpuur = Uur + 1;}
 
   if(hulpuur >= 12) {
   hulpuur = 0;}   // max 12 Uren

   dataUur = dataArrayUur [hulpuur];
   dataBLEU = Arrayminuut [minuut];
   dataGREEN = (Arraywijzer [minuut] + dataArrayUur2 [hulpuur]);
  
    // latchPin Laag netto Zo lang DAT we verzenden van data
   digitalWrite (latchPin, LOW);
    // Verstuur data
//shiftOut (dataPin, clockPin, MSBFIRST, dataBLEU);
 // shiftOut (dataPin, clockPin, MSBFIRST, dataUur);
//shiftOut (dataPin, clockPin, MSBFIRST, dataGREEN);   

shiftOut (dataPin, clockPin, MSBFIRST, dataGREEN);
shiftOut (dataPin, clockPin, MSBFIRST, dataBLEU);
shiftOut (dataPin, clockPin, MSBFIRST, dataUur);


    // zet de latchPin hoog zodra alle data verzonden is
digitalWrite   (latchPin, HIGH);
Serial.print   (Uur);
Serial.print (":");
Serial.print(hulpuur);
//Serial.print ("");
Serial.print (minuut);
//Serial.print ("");
//Serial.print(dataUur);
//Serial.print ("");
//Serial.print(dataGREEN);
//Serial.print ("");
//Serial.print(dataBLEU);
Serial.println ();
   delay (1000);
  //}
}
}
