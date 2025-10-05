/*
 * Modular_coding_GPIO.c
 *
 * Created: 05-10-2025 11:12:19
 * Author : Vibin
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "Gpio.h"
#include <stdint.h>

int main(void)
{
    DDRB |= (1<<DDB1);
	DDRB |= (1<<DDB2);
	DDRB |= (1<<DDB3);
	DDRB |= (1<<DDB4);
	DDRB |= (1<<DDB5);
    while (1) 
    {
		PORTB^=(1<<PORTB1);
		PORTB^=(1<<PORTB2);
		PORTB^=(1<<PORTB3);
		PORTB^=(1<<PORTB4);
		PORTB^=(1<<PORTB5);
		GPIO(2000);
    }
}

