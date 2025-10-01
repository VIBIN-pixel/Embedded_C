/*
 * CTC_Prescalar64.c
 *
 * Created: 28-09-2025 22:17:33
 * Author : Vibin
 * 
 * Make 5 second delay using timer0, CTC mode and prescalar 64.
 * 
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>


int main(void)
{
    DDRB |= (1<<DDB5); //PB5 as output
	TCCR0A |= (1<<WGM01);
	OCR0A = 200;
	TCNT0 = 0;
	TCCR0B |= (1<<CS00);
	TCCR0B |= (1<<CS01); //Prescalar of 64
	TIFR0 |= (1<<OCF0A);
    while (1) 
    {
		PORTB ^= (1<<PORTB5);
		for(int i=0; i<6250; i++)
		{
			while(!(TIFR0&(1<<OCF0A)))
			{
				
			}
			TIFR0 |= (1<<OCF0A);
		}
    }
}

