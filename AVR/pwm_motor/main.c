/*
 * pwm_motor.c
 *
 * Created: 02-11-2025 15:04:29
 * Author : Vibin
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"



int main(void)
{
	DDRD|=(1<<DDD6);
	TCCR0A|=(1<<WGM00);
	TCCR0A|=(1<<WGM01);
	TCCR0A|=(1<<COM0A1);
	TCCR0B|=(1<<CS00);
	TCCR0B|=(1<<CS01);
	
	
	while (1)
	{
		int duty,temp;
		temp = 50;
		if(temp<28)
		{
			duty=60;
		}
		else if(temp>28 && temp<60)
		{
			
			duty=255;
		}
		else if (temp>60)
		{
			UART_transmit();
		}
		OCR0A=duty;
		
		
	}
}

