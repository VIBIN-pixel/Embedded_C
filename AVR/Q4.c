/*
 * DcMotor_delayPass.c
 *
 * Created: 14-09-2025 23:19:26
 * Author : Vibin
 * 
 * Q.4 Pass delay through each function.
 * 
 */ 

#define F_CPU 16000000UL
#define User_delay 5000
#define User_stop 2000
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
		_delay_ms(User_delay);
		
		stop();
		_delay_ms(User_stop);
		
		ccw();
		_delay_ms(User_delay);
		
		stop();
		_delay_ms(User_stop);
	}
}