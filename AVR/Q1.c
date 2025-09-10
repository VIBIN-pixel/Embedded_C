/*
 * HomeWork_01.c
 *
 * Created: 10-09-2025 19:09:53
 * Author : Vibin
 * Q.1 Write a program to blink LED Connected to PD3 pin of an ATMEGA 328. Simulate in Siumul ide
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0b00001000;
	DDRC = 0b00000000;
	PORTC = 0b0000001;
	
	while (1)
	{
		if (PINC == 0b00000000)
		{
			PORTD = 0b00001000;
		}
		else
		{
			PORTD = 0b00000000;
		}
	}
}