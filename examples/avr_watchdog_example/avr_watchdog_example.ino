//#include <avr/wdt.h>
#include "avr_watchdog.h"
/*
 * https://www.teachmemicro.com/arduino-watchdog-timer/
 */

void setup() {
  cli();
  delay(5000);
  wdt_init(4);
  sei();
  Serial.begin(9600);
  Serial.println("Restarting..");
}
 
void loop() {
  Serial.println("Looping..");
  delay(5000);
  wdt_clear();
  
}
