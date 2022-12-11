/*
    17 ottobre 2021 - accensione LED via software
    
    modificato il 7 marzo 2022

*/

#define LED 13  // Associo al LED il numero 13

int timeBlink = 100;  // definisco un tempo di lampeggiamento

void setup()
{
    pinMode(LED, OUTPUT); // definisco la porta come output
}

void loop()
{
    digitalWrite(LED, LOW); // spengo il led
    delay(timeBlink);
    digitalWrite(LED, HIGH); // accendo il led
    delay(timeBlink);
}
