
/* 
  https://www.arduino.cc/reference/en/libraries/servo/

  Collegamenti 
    brown -> GNR
    red -> 5V
    orange -> pin  
  
  Methods
    attach()    // collega il servo, meglio non usare min e max il servo slitta.
    write()    // angolo da 0 a 180  90 middle-point
    writeMicroseconds()  // movimento tra 1000 e 2000  1500 middle-point
    read()  // return value of angle
    attached()  Check whether the Servo variable is attached to a pin
      true if the servo is attached to pin; false otherwise.
    detach()
      Detach the Servo variable from its pin. 
        If all Servo variables are detached, then pins can be used for PWM

  
  Note that in Arduino 0016 and earlier, the Servo library supports servos on only two pins: 9 and 10.
  con Mega funzionano anche altri pin

*/

#include <Servo.h>

Servo servoUno;

  int pinServoUno = 5;
  int secondo = 10;            // un secondo = 1000 millisecondi
  int minuti = 60 * secondo;
  int timer = 5 * minuti; // 300000 millisecondi

void setup() 
{
  servoUno.attach(pinServoUno);
  servoUno.write(0);
}

void loop() 
{
  
  servoUno.write(0);
  for (int i = 0; i <= 180; i+=2)
  {
    delay(100);
    servoUno.write(i);
  }
  delay(timer);
  for (int i = 180; i > 0; i-=2)
  {
    delay(100);
    servoUno.write(i);
  }
  delay(timer);
}
