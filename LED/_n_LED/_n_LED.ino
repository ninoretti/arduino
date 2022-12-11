/*
    11 dicembre 2022 - accensione di 2 LED via software
    in modalità alternata

*/

#define LED_13 13  // Associo al LED_n il numero n
#define LED_12 12  
#define LED_11 11  
#define LED_10 10  
#define LED_9 9  
#define LED_8 8
#define LED_7 7  
#define LED_6 6   
#define LED_5 5  
#define LED_4 4
#define LED_3 3  
#define LED_2 2   

int timeBlink = 500;  // definisco un tempo di lampeggiamento

void setup()
{
    pinMode(LED_13, OUTPUT); // definisco la porta come output
    pinMode(LED_12, OUTPUT); // definisco la porta come output
    pinMode(LED_11, OUTPUT); // definisco la porta come output
    pinMode(LED_10, OUTPUT); 
    pinMode(LED_9, OUTPUT);
    pinMode(LED_8, OUTPUT);
    pinMode(LED_7, OUTPUT);
    pinMode(LED_6, OUTPUT);
    pinMode(LED_5, OUTPUT);
    pinMode(LED_4, OUTPUT);
    pinMode(LED_3, OUTPUT);
    pinMode(LED_2, OUTPUT);
}

void loop()
{
    digitalWrite(LED_13, LOW); // spengo i led
    digitalWrite(LED_12, LOW); 
    digitalWrite(LED_11, LOW); 
    delay(timeBlink);
    digitalWrite(LED_13, HIGH);  // accendo i led
    digitalWrite(LED_12, HIGH);
    digitalWrite(LED_11, HIGH);
    delay(timeBlink);
}
