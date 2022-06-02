/*

26 maggio 2022 Pescia Antonino

Uso di due HC-SR04 
Istanzio due oggetti


*/
#include <SR04.h>

/* Pin di controllo dei due dispositivi */
const int TRIG_UNO = 8; 
const int ECHO_UNO = 9;
const int TRIG_DUE = 10;
const int ECHO_DUE = 11;

/* Pin di controllo dei due led */
const int LED_UNO = 7;
const int LED_DUE = 6;

/* Istanzio i due oggetti */
SR04 SENSORE_UNO = SR04(ECHO_UNO, TRIG_UNO);
SR04 SENSORE_DUE = SR04(ECHO_DUE, TRIG_DUE);

double distanza_uno, distanza_due;
double distanza_min = 50;
int wait = 100;


void setup()
{
  pinMode(LED_UNO, OUTPUT);
  pinMode(LED_DUE, OUTPUT);
  Serial.begin(9600); // imposto la velocità della porta seriale 
}


void loop()
{
  /* Misuro la distanza dai due sensori */
distanza_uno = SENSORE_UNO.Distance();
distanza_due = SENSORE_DUE.Distance();

  Serial.print("Dist uno ");
  Serial.println(distanza_uno);
  Serial.print("Dist due ");
  Serial.println(distanza_due);

/* Controllo la distanza se è minore della distanza min accende il led */
if (distanza_uno < distanza_min)
{
  digitalWrite(LED_UNO, HIGH);
}
if (distanza_due < distanza_min)
{
  digitalWrite(LED_DUE, HIGH);
}
delay(wait);

digitalWrite(LED_UNO, LOW);
digitalWrite(LED_DUE, LOW);


}
