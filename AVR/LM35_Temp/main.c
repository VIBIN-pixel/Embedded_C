/*
 * LM35.c
 *
 * Created: 19-10-2025 23:08:03
 * Author : Vibin
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"

void ADC_Init(void) //ADC initialization
{
	ADMUX |= (1 << REFS0); //Reference = Avcc(5v), Input = ADC0
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); //Enable ADC prescalar = 128 (125 khz ADC clock)
}

uint16_t ADC_Read(uint8_t Channel) //ADC reading
{
	Channel &= 0X07; //Limit to 0-7
	ADMUX = (ADMUX & 0XF8) | Channel; //Select channel
	ADCSRA |= (1 << ADSC); //Start conversion
	while(ADCSRA & (1 << ADSC)); //Wait for conversion complete
	return(ADCL | (ADCH << 8)); //Combine result
}

int main(void)
{
	uint16_t adc_Value;
	lcd_init();
	ADC_Init(); // Call ADC initialisation function
	
	while(1)
	{
		float temp;
		lcd_clear();
		lcd_set_cursor(0,0);
		lcd_print("Temperature:");
		adc_Value = ADC_Read(0); //Read from analog channel(A0 pin of Arduino) 
		temp = adc_Value*0.488; //Converting ADC value into temperature
		lcd_set_cursor(1,0);
		lcd_print_float(temp, 1); //Printing temperature
		lcd_data(0xDF); //To print degree symbol(Came from the data sheet of lcd controller) 
		lcd_print("C");
		_delay_ms(500);
	}
}

