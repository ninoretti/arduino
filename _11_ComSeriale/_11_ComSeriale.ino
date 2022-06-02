
//String data 

char mystr[8] = {'a', 'r', 'd', 'u', 'i', 'n', 'o', '\0'}; 
int num = 45;

void setup() 
{

  Serial.begin(9600);
}

void loop() {
  Serial.write(num); //Write the serial data
  Serial.write("Inviato: ");
   Serial.println(num);
  delay(1000);
}
