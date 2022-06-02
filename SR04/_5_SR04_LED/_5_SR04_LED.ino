
/*
 7 marzo 2022
 Collegato un sensore SR04, misura la distanza e la visualizza sul monitor seriale
 se la distanza è minore di distanzaVerde -> LED ross
 altrimenti LED Verde
 */
 
#include <SR04.h>
int ledRosso = 11;
int ledVerde = 10;
int trigPin = 8;
int echoPin = 7;
SR04 SENSORE = SR04(echoPin, trigPin);

int wait = 50;
float distanzaVerde = 50.0;
float distanza;

void setup() 
{
  pinMode(ledRosso, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600); // imposto la velocità della porta seriale 
}

void loop() {

  distanza = SENSORE.Distance();
  if (distanza < distanzaVerde)
  {
    digitalWrite(ledRosso, HIGH);
    digitalWrite(ledVerde, LOW);
    Serial.print("Rosso - ");
    Serial.println(distanza);
  }
  else
  {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRosso, LOW);
    Serial.print("Verde - ");
    Serial.println(distanza);
  }
  delay(wait);
}


