/*

 15 maggio 2022 - Pescia - Antonino
 
 Illuminazione di un led RGB 
 
 uso di tre porte analogiche 9 10 11 e del GND
 */
 
#define LED_RED 11
#define LED_GREEN 10
#define LED_BLUE 9
#define LED_SEI 6
 
int wait = 500;

void setup()
{

  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_SEI, OUTPUT);
  analogWrite(LED_RED, 0);
  analogWrite(LED_GREEN, 0);
  analogWrite(LED_BLUE, 0);
}


void loop()
{

for(int i = 0; i < 255; i++)
{
  analogWrite(LED_RED, 8 * i % 256);
  analogWrite(LED_GREEN, 4 * i % 256);
  analogWrite(LED_BLUE, i );
  analogWrite(LED_SEI, i );
  
  delay(10);

}

  /*  
   Serial.println("Accendo il led rosso");
   analogWrite(LED_RED, 255);
   delay(wait);
   Serial.println("Accendo il led verde");
   analogWrite(LED_RED, 0);
   analogWrite(LED_GREEN, 255);
   delay(wait);
   Serial.println("Accendo il led blu");
   analogWrite(LED_GREEN, 0);
   analogWrite(LED_BLUE, 255);
   delay(wait);
   analogWrite(LED_BLUE, 0);
   */
}

