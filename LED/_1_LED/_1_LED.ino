/*
   12 ottobre 2022 Marchi Antonino
   
   STA 2C e 2F - accensione LED via software 
*/

int LED_VERDE = 12;  // Associo al LED_VERDE il numero 12
int LED_ROSSO = 10;
int timeBlink = 1000;  // definisco un tempo di lampeggiamento in ms

/* Impostazioni iniziali del programma */
void setup()
{
    pinMode(LED_VERDE, OUTPUT); // definisco la porta come output
    pinMode(LED_ROSSO, OUTPUT);
}

/* Ciclo del programma da eseguire */
void loop()
{
    digitalWrite(LED_VERDE, LOW); // spengo il led
    delay(timeBlink);
    digitalWrite(LED_VERDE, HIGH); // accendo il led
    delay(timeBlink);
    
    digitalWrite(LED_ROSSO, LOW); // spengo il led
    delay(timeBlink);
    digitalWrite(LED_ROSSO, HIGH); // accendo il led
    delay(timeBlink);
    
}
