#include <p32xxxx.h>
#include <plib.h>
#include <speakers.h>
#include <lcd.h>
#include <stdint.h>


// (XTAL / FPLLIDIV) * FPLLMUL / FPLLODIV
// (4MHz / 1) * 20 / 1 = 80MHz 
// No WDT
// 40MHz PB clock
//#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_1, FPLLODIV = DIV_1, FWDTEN = OFF
//#pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_2

#define SYS_FREQ (80000000L)

int main(void) {
	SYSTEMConfigPerformance(SYS_FREQ);

	lcd_init();

	while(1);
	return 0;
}

