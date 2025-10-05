/*
 * Interrupt_mode_CTC.c
 *
 * Created: 05-10-2025 12:55:05
 * Author : Vibin
 * 
 * Q.1 second delay led blink using timer overflow interrupt.Timer 0 overflow interrupt in ctc mode with OCR0A
 * 
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

volatile uint16_t count = 0;
ISR(TIMER0_COMPA_vect) //Interrupt service routine
{
	if (count >= 977) //Prescaling for 64
		{
			PORTB^=(1<<PORTB5);
			count = 0;
		}
		count++;
}

int main(void)
{
    DDRB |= (1<<DDB5);
	TCCR0A |= (1<<WGM01); //CTC Mode
	OCR0A = 200;
	TCCR0B |= (1<<CS00) | (1<<CS01); //Prescaling for 64
	TIMSK0 |= (1<<OCIE0A); //Enabling timer overflow interrupt for timer0 in ctc mode
	sei();
    while (1) 
    {
		
    }
}

