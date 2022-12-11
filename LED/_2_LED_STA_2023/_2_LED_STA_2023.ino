/*
    5 ottobre 2022 - accensione di 2 LED via software
    in modalità alternata

*/

int LED_VERDE = 8;  // Associo al LED_VERDE il numero 8
int LED_ROSSO = 11;  // Associo al LED_ROSSO il numero 11

int wait = 1500;  // definisco un tempo di lampeggiamento in ms

void setup()
{
    pinMode(LED_VERDE, OUTPUT); // definisco la porta come output
    pinMode(LED_ROSSO, OUTPUT); // definisco la porta come output
    Serial.begin(9600);
    Serial.println("");
}

void loop()
{

    digitalWrite(LED_ROSSO, LOW); // spengo i led
    digitalWrite(LED_VERDE, HIGH);
    Serial.write("|^^^");
    delay(wait);
    digitalWrite(LED_ROSSO, HIGH);  // accendo i led
    digitalWrite(LED_VERDE, LOW); 
    Serial.write("|___");

    delay(wait);
}
