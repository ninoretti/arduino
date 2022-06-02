#include <SR04.h>


/*

 7 marzo 2022
 
 Collegato un sensore SR04, misura la distanza e la visualizza sul monitor seriale
 
 
 */


int trigPin = 8;
int echoPin = 7;
SR04 SENSORE = SR04(echoPin, trigPin);

int wait = 500;
float distanza;

void setup() 
{
  Serial.begin(9600); // imposto la velocità della porta seriale 
}

void loop() {

  distanza = SENSORE.Distance();
  Serial.println(distanza);
  delay(400);
}


