#include <Stepper.h>

/*

  2 giugno 2022 Collodi Antonino
  
  Utilizzo di un motore 28BYJ-48 a 5V controllato da ULN2003
  
  Nota Bene:
  L'intervallo tra ogni passo del motore è circa 2ms -> non è veloce
  Pe effettuare una rotazione divisa in 2048 passi occorrono almeno 2 secondi.
  
  Corrispondenza tra le porte e il controller 
   IN1 -> 8
   IN2 -> 9
   IN3 -> 10
   IN4 -> 11
   
   In caso di alimentazione esterna il GND deve essere condiviso
*/

/* Numero di passi del motore per effettuare un giro */
const int stepsPerRevolution = 2048;

int wait = 50;
int passo = 1;

/* Creo una istanza stepper */
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() 
{
 Serial.begin(9600);
 myStepper.setSpeed(60);
}

void loop() 
{
  for(int i = 0; i < stepsPerRevolution; i++)
  {
    myStepper.step(passo);
    delay(wait);
  }
  delay(wait);     
  for(int i = 0; i < stepsPerRevolution; i++)
  {
    myStepper.step(-1 * passo);
    delay(wait);
  }
  delay(wait * 20);
}
