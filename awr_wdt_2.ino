#include <avr/wdt.h>
/*
 * https://www.teachmemicro.com/arduino-watchdog-timer/
 */
void(* resetFunc) (void) = 0;
static uint8_t wdt_count = 0;
static uint8_t wdt_count_limit;

void wdt_clear(void)
{
    wdt_count = 0;
}

void wdt_init(uint8_t wdt_seconds)
{
    wdt_count_limit = wdt_seconds;
    WDTCSR = (1 << WDCE) | (1 << WDE);
    WDTCSR = (1<<WDIE)| (1<<WDP2) | (1<<WDP1);
}

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
 
ISR(WDT_vect) { // WDT interrupt vector
  wdt_count++; 
  if ( wdt_count > wdt_count_limit )
  {
      resetFunc(); 
  }
}
