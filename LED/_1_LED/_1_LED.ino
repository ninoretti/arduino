/*
   12 ottobre 2022 Marchi Antonino
   
   STA 2C e 2F - accensione LED via software 

*/

int LED_VERDE = 8;  // Associo al LED_VERDE il numero 8
int timeBlink = 1000;  // definisco un tempo di lampeggiamento

/* Impostazioni iniziali del programma */
void setup()
{
    pinMode(LED_VERDE, OUTPUT); // definisco la porta come output
}

/* Ciclo del programma da eseguire */
void loop()
{
    digitalWrite(LED_VERDE, LOW); // spengo il led
    delay(timeBlink);
    digitalWrite(LED_VERDE, HIGH); // accendo il led
    delay(timeBlink);
}
