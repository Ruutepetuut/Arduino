/* Bluetooth testprogramma:
 Op de tablet komt de tekst: "Press 1 to turn Arduino pin 13 LED ON or 0 to turn it OFF:"
En ja een 1 doet de LED branden, een 0 doet ‘m uit.

Opmerking: het kan niet genoeg gezegd worden: VERGEET NIET DE VERBINDING RX en TX weg te nemen wanneer we uploaden !

Het resultaat is zoals verwacht, geen hoogdravende technologie, maar toch…
Op de tablet branden de LEDs of gaan ze uit, ook bij een druk op ‘4’ gaat de LED 2 keer knipperen. Deel 2 van het programma maakt een berekening van de input en geeft het resultaat weer op de tablet. Bij input van een 1 komt er een ‘c’ als antwoord, dit is inderdaad 50 posities verder in de ASCII-tabel. 
 
 */
 
char INBYTE;
int  LED = 13; // LED on pin 13
int red = 12;

void setup() {
  Serial.begin(9600); 
  pinMode(LED, OUTPUT);
  pinMode (red,OUTPUT);
}

void loop() {
  Serial.println("Press 1 to turn Arduino pin 13 LED ON or 0 to turn it OFF:");
  while (!Serial.available());   // stay here so long as COM port is empty   
  INBYTE = Serial.read();        // read next available byte
  if( INBYTE == '0' ) digitalWrite(LED, LOW);  // if it's a 0 (zero) turn LED off
  if( INBYTE == '1' ) digitalWrite(LED, HIGH); // if it's a 1 (one) turn LED on
  if( INBYTE == '2') digitalWrite(red, HIGH);
  if( INBYTE == '3') digitalWrite(red, LOW);
  if( INBYTE == '4') Blink();
  Serial.write(INBYTE);
  Serial.write("   ");
   int Som = INBYTE+50;
  Serial.write(Som);
  Serial.write("   ");
  int dec = (Som, DEC);
  Serial.write(dec);
  Serial.write("   ");
  delay(50);
  
}

void Blink()
 {digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);}

/* Het resultaat is zoals verwacht, geen hoogdravende technologie, maar toch…
Op de tablet branden de LEDs of gaan ze uit, ook bij een druk op ‘4’ gaat de LED 2 keer knipperen. 
Deel 2 van het programma maakt een berekening van de input en geeft het resultaat weer op de tablet. 
Bij input van een 1 komt er een ‘c’ als antwoord, dit is inderdaad 50 posities verder in de ASCII-tabel. 
*/
