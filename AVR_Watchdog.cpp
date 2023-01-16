/*
 * AVR_Watchdog
 *
 * https://www.teachmemicro.com/arduino-watchdog-timer/
 */
#include <stdint.h>
#include <Arduino.h> 
#include <AVR_Watchdog.h>

uint16_t wdt_count;
uint16_t wdt_count_limit;

void(* resetFunc) (void) = 0;


AVR_Watchdog::AVR_Watchdog(uint16_t wdt_seconds)
{
    wdt_count = 0;
    wdt_count_limit = wdt_seconds;   // default value
    WDTCSR = (1 << WDCE) | (1 << WDE);
    WDTCSR = (1<<WDIE)| (1<<WDP2) | (1<<WDP1);
}

void AVR_Watchdog::clear(void)
{
    wdt_count = 0;
}

void AVR_Watchdog::set_timeout(uint16_t wdt_seconds)
{
    wdt_count = 0;
    wdt_count_limit = wdt_seconds;
    WDTCSR = (1 << WDCE) | (1 << WDE);
    WDTCSR = (1<<WDIE)| (1<<WDP2) | (1<<WDP1);
}


ISR(WDT_vect) { // WDT interrupt vector
  wdt_count++; 
  if ( wdt_count > wdt_count_limit )
  {
      resetFunc(); 
  }
}
