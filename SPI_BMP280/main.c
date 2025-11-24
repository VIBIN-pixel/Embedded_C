/*
 * SPI_BMP280.c
 *
 * Created: 13-11-2025 21:43:05
 * Author : Vibin
 */ 

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

int main() {
	uint8_t chip_id;
	uint32_t MSB, LSB, XLSB, temp;
	float var1, var2, t_fine_f, actual_temp;
	
	// Calibration variables
	uint16_t dig_T1 = 0;
	uint16_t dig_T2 = 0;
	uint16_t dig_T3 = 0;
	
	UART_Init(); 

	// Set MOSI (PB3), SCK (PB5), SS (PB2) and LED (PB0) as output
	DDRB |= (1 << PB3) | (1 << PB5) | (1 << PB2); // | (1 << PB0)
	DDRB &= ~(1 << PB4);  // MISO (PB4) as input
	PORTB |= (1 << PB2);  // SS high initially
	DDRD |= (1 << PD3); // PD3 as output (LED) 
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0); // Enable SPI, set as Master
	//SPCR &= ~((1 << CPOL) | (1 << CPHA)); // Set Clock Polarity and Phase
	_delay_ms(100);

	// Select Slave
	PORTB &= ~(1 << PB2); // CSB low
	
	// Send register address (0xD0 | 0x80)
	SPDR = 0xD0 | 0x80;
	// Wait untill transmission is complete
	while (!(SPSR & (1 << SPIF)));
	(void)SPDR; // Here we get random value stored in slave (Dummy = SPDR)
	//_delay_ms(500);
	// Deselect slave
	//PORTB |= (1 << PB2);
	//_delay_ms(500);
	// Select slave again
	//PORTB &= ~(1 << PB2);
	// For reading the chip id, send 0x00 data from slave comes to master
	SPDR = 0x00; // Send dummy to receive data
   
    
    // Wait untill transmission is complete
	while (!(SPSR & (1 << SPIF)));
	//Read chip id which is now in SPDR
	chip_id = SPDR; //Hemce the original data (CHIP-ID) is obtained (void)SPDR
	//Pull SS high to deselect slave
	PORTB |= (1 << PB2); //CSB high
    _delay_ms(10);
	
	// Wake from sleep
	PORTB &= ~(1 << PB2); //CSB low
	SPDR = 0XF4 & 0X7F; // Chip ID register (0xF4) with read bit
	while (!(SPSR & (1 << SPIF)));
	(void)SPDR;   // Dummy read
	SPDR = 0x27; // Send dummy to receive data
	while (!(SPSR & (1 << SPIF)));
	(void)SPDR;
	PORTB |= (1 << PB2);
	_delay_ms(10);
	
	//Read back CTRL_MEAS to verify mode
	uint8_t ctrl_meas;
	PORTB &= ~(1 << PB2);
	SPDR = 0XF4 | 0X80; // Read ctrl_meas(0xF4)
	while(!(SPSR & (1 << SPIF)));
	(void)SPDR;
	
	//Read MSB
	SPDR = 0X00;
	while(!(SPSR & (1<< SPIF)));
	ctrl_meas = SPDR;
	PORTB |= (1 << PB2);
	
	/*//Read LSB
	SPDR = 0X00;
	while(!(SPSR & (1<<SPIF)));
	LSB = SPDR;
	
	//Read XLSB
	/*SPDR = 0X00;
	while(!(SPSR & (1<<SPIF)));
	XLSB = SPDR;
	
	
	
	while (1)
	{*/
		UART_TxString("CTRL_MEAS: ");
		UART_TxNumber(ctrl_meas);  // This should show 0x27   
		UART_TxChar('\r\n');
		
		// Read temperature calibration registers (dig1, dig2, dig3)
		{
			uint8_t b0, b1, b2, b3, b4, b5;
			PORTB &= ~(1 << PB2); // CSB low
			SPDR = 0x88 | 0x80; //Starting address 0x88 with read bit
			while(!(SPSR & (1 << SPIF)));
			(void)SPDR;
			
			// Read byte 0 (0x88)
			SPDR = 0X00;
			while(!(SPSR & (1 << SPIF))); b0 = SPDR;
			// Read byte 1 (0x89)
			SPDR = 0X00;
			while(!(SPSR & (1 << SPIF))); b1 = SPDR;
			// Read byte 2 (0x8A)
			SPDR = 0X00;
			while(!(SPSR & (1 << SPIF))); b2 = SPDR;
			// Read byte 3 (0x8B)
			SPDR = 0X00;
			while(!(SPSR & (1 << SPIF))); b3 = SPDR;
			// Read byte 4 (0x8C)
			SPDR = 0X00;
			while(!(SPSR & (1 << SPIF))); b4 = SPDR;
			// Read byte 5 (0x8D)
			SPDR = 0X00;
			while(!(SPSR & (1 << SPIF))); b5 = SPDR;
			
			PORTB |= (1 << PB2); //CSB High
			
			// Shifting and or to get 16 bit values
			
			dig_T1 = (uint16_t)((b1 << 8) | b0);
			dig_T2 = (uint16_t)((b3 << 8) | b2);
			dig_T3 =  (uint16_t)((b5 << 8) | b4);
		
		}
// Optional print calibration values for debugging.
/*UART_TxString("Calib T1: ");
UART_TxNumber(dig_T1);
UART_TxChar('\n');	

UART_TxString("Calib T2: ");
if (dig_T2 < 0) {UART_TxChar('-'); UART_TxNumber(-dig_T2); }
else {UART_TxNumber(dig_T2); }	
UART_TxChar('\n');

UART_TxString("Calib T3: ");
if (dig_T3 < 0) {UART_TxChar('-'); UART_TxNumber(-dig_T3); }
else {UART_TxNumber(dig_T3); }
UART_TxChar('\n');	
		} */
		while(1)
		{
			//READ temperature register (0xFA, 0xFB, XFC)
			PORTB &= ~(1 << PB2); // CSB low
			SPDR = 0xFA | 0x80; // Temp MSB address + read bit
			while(!(SPSR & (1 << SPIF)));
			(void)SPDR;
			
			// Read MSB
			SPDR = 0x00;
			while(!(SPSR & (1 << SPIF)));
			MSB = SPDR;
			
			// Read LSB
			SPDR = 0x00;
			while(!(SPSR & (1 << SPIF)));
			LSB = SPDR;
			
			// Read XLSB
			SPDR = 0x00;
			while(!(SPSR & (1 << SPIF)));
			XLSB = SPDR;
			
			PORTB |= (1 << PB2); // CSB high
			
			temp = ((uint32_t)MSB << 12) | ((uint32_t)LSB << 4) | ((uint32_t)XLSB >> 4);
			
			UART_TxString("Raw Temp: ");
			UART_TxNumber(temp); //Print raw temperature
			UART_TxChar('\n');
			
			// Temperature compensation (floating-point, matches datasheet)
			
				float adc_Tf = (float)temp; // Convert raw temperature to float
				
				var1 = (((adc_Tf / 16384.0f)  - ((float)dig_T1 / 1024.0f)) * (float)dig_T2);
				var2 = ((((adc_Tf / 131072.0f) - ((float)dig_T1 / 8192.0f)) * 
				((adc_Tf / 131072.0f) - ((float)dig_T1 / 8192.0f))) * (float)dig_T3);
				
				t_fine_f = var1 + var2;
				actual_temp = t_fine_f / 5120;
			
		/*}
		if (chip_id == 0x58)
		{
			PORTB |= (1 << PB0); // LED ON if BMP280 detected
		}
		else
		{
			PORTB &= ~(1 << PB0); //LED OFF otherwise 
		}*/
		UART_TxString("Actual Temp (C): ");
		UART_TxNumber(actual_temp);
		UART_TxString("\r\n");
		
		_delay_ms(5000);
	} 
}



