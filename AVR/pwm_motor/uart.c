/*
 * UART_Transmission.c
 *
 * Created: 02-11-2025 12:11:54
 * Author : Vibin
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
void UART_transmit(void)
	{
		UART_init();
		char a[] = "A\n";
		int i;
		
		while (1)
		{
			for (i=0; a[i]!='\0'; i++)
			{
				while (!(UCSR0A & (1<<UDRE0)));
				UDR0 = a[i];
			}
			_delay_ms(1000);
		}
	}
	


void UART_init(void)
{
	UBRR0H = 0;
	UBRR0L = 103; // Baud rate
	UCSR0B |= (1<<TXEN0); // Enable transmission
	UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00); // 8-Bit data
}
