/* Uso joystick 

    Si collegano la x e la y alle porte analogiche A0 e A1
    Il pin switch alla porta 2 digitale (Se si preme lo joystick)

*/

#define X_PIN 0
#define Y_PIN 1
#define SWITCH_PIN 2

int x, y, bottone;
int wait = 1000;

void setup() 
{
  pinMode(SWITCH_PIN, INPUT);               // Imposto la porta di ingresso
  digitalWrite(SWITCH_PIN, HIGH);            // attivo il joystic
  Serial.begin(9600);                   // setto la velocità della seriale
}

void loop() 
{
  x = analogRead(X_PIN);    // Leggo i valori
  y = analogRead(Y_PIN);
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" ");
  Serial.print("Y: ");
  Serial.print(y);
  Serial.print("\n\n");
//  bottone = digitalRead(SWITCH_PIN);
//  Serial.println(bottone);
  delay(wait);
}
