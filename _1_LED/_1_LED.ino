/*
    17 ottobre 2021 - accensione LED via software
    
    modificato il 7 marzo 2022

*/

#define LED_VERDE 8  // Associo al LED_VERDE il numero 8

int timeBlink = 1000;  // definisco un tempo di lampeggiamento

void setup()
{
    pinMode(LED_VERDE, OUTPUT); // definisco la porta come output
}

void loop()
{
    digitalWrite(LED_VERDE, LOW); // spengo il led
    delay(timeBlink);
    digitalWrite(LED_VERDE, HIGH); // accendo il led
    delay(timeBlink);
}
