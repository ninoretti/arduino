/*
 7 marzo 2022
 
 Realizzato un controllo su strada alternata ad una sola corsia con due semafori.
  Un sensore SR04 e un led rosso e uno verde corrispondono ad un semaforo.
  
  Funzionamento: quando non ci sono macchine vicine (distanzaVerde > 50) i semafori sono rossi
  Quando una macchina si avvicina al semaforo lo occupa mettendo verde il semaforo.
  Trascorso il tempo di transito il semaforo ritorna rosso.
 
 Non è stata considerata l'alternanza: quando un semaforo diventa verde, trascorso il tempo di transito,
 se sono prensenti macchine da tutte e due le parti diventa verde l'altro semaforo.
 
 */

#include <SR04.h>
/* Uso dei pin sulla scheda */
int ledVerde_1S = 13;
int ledRosso_1S = 12;
int ledVerde_2S = 11;
int ledRosso_2S = 10;
int trigPin_1S = 8;
int echoPin_1S = 7;
int trigPin_2S = 6;
int echoPin_2S = 5;

/* Creo i due sensori */
SR04 SENSORE_1S = SR04(echoPin_1S, trigPin_1S);
SR04 SENSORE_2S = SR04(echoPin_2S, trigPin_2S);

/* Definisco i tempi d'uso */
int wait = 100;
int secondi = 1000;
int minuti = 60 * secondi;
int transito = 5 * secondi;
int timer = transito;

int distanzaVerde = 10;
int libero = true; // stato di libero o occupato

float distanza_1S;
float distanza_2S;

void closeAllSemafori();
void openSemaforoUno();
void openSemaforoDue();
void barraTempo(int tempo);

void setup() 
{
  pinMode(ledRosso_1S, OUTPUT);
  pinMode(ledVerde_1S, OUTPUT);
  pinMode(ledRosso_2S, OUTPUT);
  pinMode(ledVerde_2S, OUTPUT);
  Serial.begin(9600); // imposto la velocità della porta seriale 
}

void loop() {

  distanza_1S = SENSORE_1S.Distance();
  distanza_2S = SENSORE_2S.Distance();

  if (distanza_1S < distanzaVerde && libero == true)
  {
    libero = false;
    openSemaforoUno();
    Serial.print("Aperto Semarofo 1 - ");
    Serial.println(distanza_1S);
    //delay(transito);
    barraTempo(transito);
    libero = true;
  }
  else if (distanza_2S < distanzaVerde && libero == true)
  {
    libero = false;
    openSemaforoDue();
    Serial.print("Aperto Semarofo 2 - ");
    Serial.println(distanza_2S);
    // delay(transito);
     barraTempo(transito);
    libero = true;
  }
  else
  {
    closeAllSemafori();
    Serial.print("Semafori chiusi - Dist 1S - ");
    Serial.print(distanza_1S);
    Serial.print(" Dist 2S - ");
    Serial.print(distanza_2S);
    Serial.print(" Libero - ");
    Serial.println(libero);
  }

  delay(wait);

}


void closeAllSemafori()
{
  digitalWrite(ledVerde_1S, LOW);
  digitalWrite(ledRosso_1S, HIGH);
  digitalWrite(ledRosso_2S, HIGH);
  digitalWrite(ledVerde_2S, LOW);
}
void openSemaforoUno()
{
  digitalWrite(ledVerde_1S, HIGH);
  digitalWrite(ledRosso_1S, LOW);
}
void openSemaforoDue()
{
  digitalWrite(ledVerde_2S, HIGH);
  digitalWrite(ledRosso_2S, LOW);
}

void barraTempo(int tempo)
{
    int intervallo = tempo/10;
  for(int i = tempo; i > 0; i -= intervallo)
    Serial.print(" - ");
    Serial.println("");
    for(int i = tempo; i > 0; i -= intervallo)
    {
      Serial.print(" * ");
      delay(intervallo);
    }  
    Serial.println("");
}

