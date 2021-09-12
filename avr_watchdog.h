//#ifndef __AVR_WATCHDOG__
#define __AVR_WATCHDOG__

void wdt_clear(void);
void wdt_init(uint8_t wdt_seconds);
 
//#endif
