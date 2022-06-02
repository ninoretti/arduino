
/*
 * LiquidCrystal Library 
 * Altri schemi di collegamento utilizzano porte diverse
 * in questo scratch le porte usate sono:

  Aggiunto un sensore HC-SR04,
  la distanza è visualizzata sul monitor LCD

 This example code is in the public domain.

 10 luglio 2021
 
 11 luglio 2021 
 spostati i pin echo e trig 
 ed i pin del monitor LCD

 */

#include <LiquidCrystal.h>
#include <SR04.h>

int trigPin = 8;
int echoPin = 7;
SR04 SENSORE = SR04(echoPin, trigPin);

const int RS = 12;
const int Enable = 11;
const int D4 = 5;
const int D5 = 4;
const int D6 = 3;
const int D7 = 2;
LiquidCrystal lcd(RS, Enable, D4, D5, D6, D7);

int wait=500;
String vuota = "                "; // 16 char
float distanza;

void cancellaRiga(int riga);
void scriviRiga(int riga, String frase); 

void setup() {

  lcd.begin(16, 2);  // inizializza LDC 16 col 2 righe
  lcd.setCursor(0, 0);
  lcd.print("Lab Arduino 2021");
 // scriviRiga(0,"Lab Arduino 2021");
}

void loop() {
  
    distanza = SENSORE.Distance();
    //dist = int(distanza)
    lcd.setCursor(0, 1);
    cancellaRiga(1);
    lcd.print("Distanza:");
    lcd.print(distanza);
    delay(400);


}




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
