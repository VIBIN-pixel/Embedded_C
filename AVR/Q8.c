/*
 * LED_Fading_PWM.c
 *
 * Created: 01-10-2025 22:57:22
 * Author : Vibin
 * 
 * LED fading gradually increased and gradually decreased
 * 
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD |= (1<<DDD6); //Output
	TCCR0A |= (1<<WGM00);
	TCCR0A |= (1<<WGM01); //Fast PWM
	TCCR0A |= (1<<COM0A1); //Non-inverting
	TCCR0B |= (1<<CS00);
	TCCR0B |= (1<<CS01); //Prescaling of 64
	
	while(1)
	{
		for(int i=0; i<510; i++)
		{
			if(i<255)
			OCR0A = i;
			else
			OCR0A = 510-i;
			_delay_ms(5);
		}

	}
}

