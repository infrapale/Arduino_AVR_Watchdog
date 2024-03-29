#ifndef __AVR_WATCHDOG__
#define __AVR_WATCHDOG__
#include <stdint.h>

class AVR_Watchdog
{
	public:
		AVR_Watchdog(uint16_t wdt_seconds);
		void clear(void);
		void set_timeout(uint16_t wdt_seconds);
	private:
		uint8_t dummy;
};

#endif
