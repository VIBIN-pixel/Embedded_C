/*
 * GPIO.c
 *
 * Created: 05-10-2025 11:13:47
 *  Author: Vibin
 */ 

#include <avr/io.h>
void timer0_init(void)
{
	TCCR0A |= (1<<WGM01); //CTC Mode
	OCR0A = 249; //For count 250 setpoint
	TCNT0 = 0; //Making timer counter 0
	TCCR0B |= (1<<CS00);
	TCCR0B |= (1<<CS01); //Prescaling for 64
	TIFR0 |= (1<<OCF0A); //Setting flag to 0 by writing one
}

void GPIO(uint16_t ms) //Define vibin
{
	timer0_init(); 
	while(ms--) //Creates delay for ms
	{
		while(!(TIFR0&(1<<OCF0A))) //1ms loop
		{
			
		}
		TIFR0 |= (1<<OCF0A);
	}
}
