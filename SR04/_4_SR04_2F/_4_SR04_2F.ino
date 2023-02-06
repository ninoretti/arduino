
/*

 3 febbraio 2022 2F 2023 
 
 Collegato un sensore SR04, misura la distanza e la visualizza sul monitor seriale
 
 
 */
#include <SR04.h>     // libreria software che gestisce il sensore 
 
#define TRIG 7
#define ECHO 8
#define LED_VERDE  3
#define LED_ROSSO  4


SR04 SENSORE = SR04(ECHO, TRIG);    // definisco un oggetto software 

int wait = 500;
float distanza;       // La distanza è un numero reale 

void setup() 
{
  Serial.begin(9600); // imposto la velocità della porta seriale
  pinMode(LED_VERDE, OUTPUT); // definisco la porta come output
  pinMode(LED_ROSSO, OUTPUT); 
}

void loop() {

  distanza = SENSORE.Distance();    // funzione software che calcola la distanza
  Serial.println(distanza);         // stampa il valore sulla porta seriale 
  delay(wait);

  if (distanza > 10)
  {
    digitalWrite(LED_ROSSO, LOW);  
    digitalWrite(LED_VERDE, HIGH); 
  }
  else
  {
    digitalWrite(LED_ROSSO, HIGH);  
    digitalWrite(LED_VERDE, LOW); 

  }

}


