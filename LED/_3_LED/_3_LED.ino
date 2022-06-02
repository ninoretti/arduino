/*
    17 ottobre 2021 - accensione di 3 LED via software
    in modalità alternata

*/

#define LED_VERDE 8  // Associo al LED_VERDE il numero 8
#define LED_GIALLO 7  // Associo al LED_BIANCO il numero 7
#define LED_ROSSO 12  // Associo al LED_ROSSO il numero 12

int timeBlink = 1000;  // definisco un tempo di lampeggiamento

void setup()
{
    pinMode(LED_VERDE, OUTPUT); // definisco la porta come output
    pinMode(LED_GIALLO, OUTPUT); // definisco la porta come output
    pinMode(LED_ROSSO, OUTPUT); // definisco la porta come output
}

void loop()
{
    digitalWrite(LED_ROSSO, LOW); // spengo i led
    digitalWrite(LED_GIALLO, LOW); 
    digitalWrite(LED_VERDE, LOW); 
    delay(timeBlink);
    digitalWrite(LED_ROSSO, HIGH);  // accendo i led
    digitalWrite(LED_GIALLO, HIGH);
    digitalWrite(LED_VERDE, HIGH);
    delay(timeBlink);
}
