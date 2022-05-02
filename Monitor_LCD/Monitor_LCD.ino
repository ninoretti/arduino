#include <SR04.h>
#include <LiquidCrystal.h>

/*
 * LiquidCrystal Library 
 * Altri schemi di collegamento utilizzano porte diverse
 * in questo scratch le porte usate sono:

 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 This example code is in the public domain.

 11 luglio 2021
 spostati i pin LCD secondo lo schema del circuito
 prendete sul sito arduino.cc

 */



const int RS = 12;
const int Enable = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;
float distanza;

int trigPin = 8;
int echoPin = 9;
SR04 SENSORE = SR04(echoPin, trigPin);

LiquidCrystal lcd(RS, Enable, D4, D5, D6, D7);

int wait=400;

String  vuota = "                ";
String  marchi = "   ITS Marchi   ";
String  lab = "Lab Arduino 2021";
String  estate = "Progetto estate ";
String antonino = "Antonino Oretti ";
String marco = "Marco Rosellini";
String matteo = "Matteo D'Agnello";

void cancellaRiga(int riga)
{
   if (riga == 1) {
      lcd.setCursor(0, 1);
      lcd.print(vuota);
      lcd.setCursor(0, 1);
   }
   if (riga == 0) {
      lcd.setCursor(0, 0);
      lcd.print(vuota);
      lcd.setCursor(0, 0);
   }
}
void scriviRiga(int riga, String frase)
{
    for(int k=frase.length(); k>=0; --k){
      lcd.setCursor(k,riga);
      lcd.print(frase);
      delay(wait);
    }  
}
  
void setup() {

  lcd.begin(16, 2);  // inizializza LDC 16 col 2 righe
  lcd.print("Lab Arduino 2021");
  lcd.setCursor(0, 1);
  lcd.print("   ITS MARCHI   ");
  delay(1000);
//  lcd.setCursor(0, 1);
//  lcd.print("Progetto Estate  ");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print(vuota);
  
}

void loop() {
    distanza = SENSORE.Distance();
//    cancellaRiga(1);
//    scriviRiga(1,estate);
//    cancellaRiga(1);
//    scriviRiga(1,marco);
//    cancellaRiga(1);
//    scriviRiga(1,matteo);
//    cancellaRiga(0);
//    lcd.setCursor(0, 0);
//    lcd.print(marchi);
//    cancellaRiga(1);
//    scriviRiga(1,lab);
//    cancellaRiga(0);
    lcd.print(distanza);
    delay(wait);
}
