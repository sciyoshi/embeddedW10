#include <p32xxxx.h>
#include <plib.h>
#include <lcd.h>
#include <stdint.h>

#define LCD_PWMPERIOD 0x00FF
/**
 * Backlight is open drain on pin D2, controlled by OC4, using Timer 3
 * Contrast uses normal CMOS with OC3, also driven by Timer 3
 */
void lcd_init(void) {
	//Set backlight to open drain
	mPORTDOpenDrainOpen( BIT_2 );

	//Start the timer for contrast/brightness PWM
	OpenTimer3(T3_ON, LCD_PWMPERIOD);

	//Enable contrast control
	OpenOC3( OC_ON | OC_TIMER_MODE16 | OC_TIMER3_SRC | OC_CONTINUE_PULSE | OC_LOW_HIGH , LCD_PWMPERIOD, 0x500 );

	//Enable brightness control
	OpenOC4( OC_ON | OC_TIMER_MODE16 | OC_TIMER3_SRC | OC_CONTINUE_PULSE | OC_LOW_HIGH , LCD_PWMPERIOD, 0x500 );
}

void lcd_set_contrast(uint32_t value) {
	OC4CONSET = value;
}

void lcd_set_brightness(uint32_t value) {
	OC3CONSET = value;
}
