//WOORDKLOK

// ER WORDT GEWERKT MET 3 SHIFTREGISTERS, VOOR ELK REGISTER
// WORDT EEN DECIMALE WAARDE BEREKEND VOLGENS ONDERSTAANDE TABEL

//WAARDE  SHIFT1  SHIFT2    SHIFT3
//1       EEN     NEGEN     VIJF
//2       TWEE    TIEN      TIEN  
//4       DRIE    ELF       KWART
//8       VIER    TWAALF    HALF  
//16      VIJF    MINUUT1   VOOR
//32      ZES     MINUUT2   OVER
//64      ZEVEN   MINUUT3   UUR
//128     ACHT    MINUUT4   HET IS


void setup() {
  
Serial.begin(9600);

}

void loop() {

// uren en minuten van de realtime klok, hier gesimuleerd door ingegeven waarden
  
int uren = 0;
int minuten = 1;

// voor de shift registers wordt een array gebruikt , met 4 indexen, voor overeenstemming
// met de nummer van het shiftregister wordt de waarde voor index nul niet gebruik. 

int shift[4]= {0,0,0,0};

// vermits het hier over een 12-uur klokt worden volgende correcties toegepast : voor nul uur wordt 12 bijgeteld,
// voor waarden boven twaalf wordt 12 afgetrokken

if (uren>12){uren=uren-12;};
if (uren==0) {uren=uren+12;};
int hoekminuten = minuten%5;
int vijfminuten = (minuten-hoekminuten)/5;

// zodra het aantal minuten hoger is dan 19 wordt er bij het uur 1 bijgeteld (dus vanaf 10 voor half ...'komende' uur

if (minuten>19)
  {uren=uren+1;}  

// bepaling van de waarden voor shiftregisters 1 en 2
  
if (uren<9)
  {shift[1]=pow(2, (uren-1));}
else 
  {shift[2]=pow(2, (uren-9));}

shift[2]=shift[2]+pow(2,(hoekminuten+3));

// bepaling van waarden voor shiftregister 3

switch (vijfminuten){

  case 0:shift[3]=192;break; 
  case 1:shift[3]=161;break;
  case 2:shift[3]=162;break;
  case 3:shift[3]=164;break;
  case 4:shift[3]=154;break;
  case 5:shift[3]=153;break;
  case 6:shift[3]=136;break;
  case 7:shift[3]=169;break;
  case 8:shift[3]=170;break;
  case 9:shift[3]=148;break;
  case 10:shift[3]=146;break;
  case 11:shift[3]=145;break;
  
}

Serial.print("Shift 1= ");Serial.println(shift[1]);
Serial.print("Shift 2= ");Serial.println(shift[2]);
Serial.print("Shift 3= ");Serial.println(shift[3]);
Serial.println();
delay(5000);

}
