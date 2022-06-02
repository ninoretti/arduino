
int LED_RIC = 8;
int num = 0;

void setup() {

  pinMode(LED_RIC, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  num = Serial.read(); //Read the serial data and store in var
  Serial.print("Letto il valore ");
  Serial.println(num); //Print data on Serial Monitor
  if (num == 45) digitalWrite(LED_RIC, HIGH);
  delay(500);
  digitalWrite(LED_RIC, LOW);
  delay(500);
}

