/*
 * 162_LCD.c
 *
 * Created: 13-10-2025 17:47:42
 * Author : Vibin
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include <stdint.h>

int main(void)
{
	lcd_init();
	lcd_set_cursor(0, 0);
	lcd_print("Hello LCD");

	lcd_set_cursor(1, 0);
	lcd_print("It works! ");

	// small demo: print a number
	
	//uint16_t int_v = 1234;
	float v =1.234;
	uint8_t precision =3;
	
	lcd_init();
	lcd_clear();
	

	while (1)
	{
		lcd_cmd(0x80);
		lcd_print_uint16(1234);
		_delay_ms(2000);
		
		lcd_clear();
		
		lcd_cmd(0x80);
		lcd_print_float(v, precision );
		_delay_ms(2000);
		
		lcd_clear();

	}
}


