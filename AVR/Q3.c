/*
 * HomeWork_03.c
 *
 * Created: 14-09-2025 20:21:50
 * Author : Vibin
 * 
 * Q.3 YOU HAVE TO USE 3 FUNCTIONS.CW, STP AND CCW.
 * CALL IT FROM THE MAIN AND SHOW THE FUNCTIONALITIES. SIMULATE USING SIML IDE.
 *
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

//Functions to rotate motor clockwise
void cw(void) {
	PORTB |= (1 << PORTB5);
	PORTB &= ~(1 << PORTB4);
}
	
//Functions to stop the motor
void stop(void) {
	PORTB &= ~(1 << PORTB5);
	PORTB &= ~(1 << PORTB4);
}	

//Functions to rotate motor counter-clockwise
void ccw(void) {
	PORTB |= (1 << PORTB4);
	PORTB &= ~(1 << PORTB5);
}

int main(void) {
	
	DDRB |= (1 << DDB5);
	DDRB |= (1 << DDB4);
	
	while(1) {
		cw();
		_delay_ms(5000);
		
		stop();
		_delay_ms(1000);
		
		ccw();
		_delay_ms(5000);
		
		stop();
		_delay_ms(1000);
	} 
}