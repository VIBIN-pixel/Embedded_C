/*
 * HomeWork_02.c
 *
 * Created: 10-09-2025 19:09:53
 * Author : Vibin
 * Q.2  Write a program to Turn on an LED Connected to PD3 pin of an ATMEGA 328 when a switch connected to PC0 is pressed(show active high and low connections in the switch).
 * Simulate in Simul ide.
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0b00001000;
	DDRC = 0b00000000;
	PORTC = 0b00000010;
	
	while (1)
	{
		if (PINC == 0b00000001)
		{
			PORTD = 0b00001000;
		}
		else if (PINC == 0b00000010)
		{
			PORTD = 0b00001000;
		}
		else
		{
			PORTD = 0b00000000;
		}
	}
}