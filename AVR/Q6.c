/*
 * Prescalar_delay_1024.c.c
 *
 * Created: 25-09-2025 16:42:57
 * Author : Vibin
 * 
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void delay_1s(void)
{
	unsigned int i;
	unsigned int count=62500;
	for(i=0; i<<count; i++)
	{
		TCNT0 = 0;
		TCCR0A = 0;
		TCCR0B |= (1<<CS00);
		TCCR0B |= (1<<CS02); //Prescalar 1024
		TIFR0 |= (1<<TOV0); //Making timer over flow flag 0
		
		while(!(TIFR0 & (1<<TOV0)));
	}
}

int main(void)
{
	DDRB |= (1<<DDB5); //PB5 As output
    
    while (1) 
    {
		PORTB^=(1<<PORTB5);
		delay_1s();
    }
}

