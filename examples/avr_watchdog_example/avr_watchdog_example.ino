#include "Arduino.h"
#include "AVR_Watchdog.h"
/*
 *  avr_watchdog example
 */
uint8_t i;
AVR_Watchdog watchdog(4);

void setup() 
{
  cli();
  delay(4000);
  watchdog.set_timeout(4);
  sei();
  Serial.begin(9600);
  Serial.println("Restarting..");
}
 
void loop() {
  Serial.println("Looping 2000ms");
  delay(2000);
  watchdog.clear();
  Serial.println("Looping 5000ms");
  delay(5000);
  watchdog.clear();
}
