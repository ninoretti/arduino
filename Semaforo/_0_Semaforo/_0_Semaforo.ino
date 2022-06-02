
/*

  18 marzo 2022 
  semaforo con emulata centralina

*/

int pinSemaforoUno = 7;
int pinSemaforoDue = 4;

int secondi = 1000;
int minuti = 60 * secondi;
int tempoRosso = 5 * secondi;


void setup()
{
  pinMode(pinSemaforoUno, OUTPUT); 
  pinMode(pinSemaforoDue, OUTPUT); 
}

void loop()
{
  digitalWrite(pinSemaforoUno, LOW); 
  digitalWrite(pinSemaforoDue, HIGH); 
  delay(tempoRosso);
  
  digitalWrite(pinSemaforoUno, HIGH); 
  digitalWrite(pinSemaforoDue, LOW); 
  delay(tempoRosso);
}
