#include <SR04.h>

/*

 7 marzo 2022
 
 Collegato un sensore SR04, misura la distanza e la visualizza sul monitor seriale
 
 
 */


int trigPin = 10;
int echoPin = 9;
SR04 SENSORE = SR04(echoPin, trigPin);

int wait = 500;
float distanza;


void setup() 
{
  Serial.begin(9600); // imposto la velocità della porta seriale 
}

void loop() {

  distanza = SENSORE.Distance();
  if (distanza < 10)
    Serial.println(system("/home/znx/git/arduino/_7_SR04_Mail/mail.py"));
  Serial.println(distanza);
  //Serial.println(system("ls"));
  delay(400);
}


