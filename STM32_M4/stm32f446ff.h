/*
 * stm32f446ff.h
 *
 *  Created on: Nov 21, 2025
 *      Author: Vibin
 */

#ifndef STM32F446FF_H_
#define STM32F446FF_H_

#include <stdint.h>
#include "stm32f446ff.h"

//GPIO base addresses & Bus is AHB1
#define GPIOA_BASEADDR  0x40020000U
#define GPIOB_BASEADDR  0x40020400U
#define GPIOC_BASEADDR  0x40020800U
#define GPIOD_BASEADDR  0x40020C00U
#define GPIOE_BASEADDR  0x40021000U
#define GPIOF_BASEADDR  0x40021400U
#define GPIOG_BASEADDR  0x40021800U
#define GPIOH_BASEADDR  0x40021C00U

//GPIO register structure
typedef struct
{
 	volatile uint32_t MODER;    //GPIO port mode register               (0x00)
 	volatile uint32_t OTYPER;   //GPIO port output type register        (0x04)
 	volatile uint32_t OSPEEDR; //GPIO port output speed register       (0x08)
 	volatile uint32_t PUPDR;    //GPIO port pull-up/pull-down register  (0x0C)
 	volatile uint32_t IDR;      //GPIO port input data register         (0x10)
 	volatile uint32_t ODR;      //GPIO port output data register        (0x14)
 	volatile uint32_t BSRR;     //GPIO port bit set/reset register      (0x18)
 	volatile uint32_t LCKR;     //GPIO port configuration lock register (0x1c)
 	volatile uint32_t AFRL;     //GPIO alternate function low register  (0x20)
 	volatile uint32_t AFRH;	    //GPIO alternate function high register (0x24)
}GPIO_RegDef_t;

//int a = 10;
//int *p = &a;
//GPIO POINTERS
#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH ((GPIO_RegDef_t*)GPIOH_BASEADDR)

//RCC base address

#define RCC_BASEADDR    0x40023800U

//RCC register structure (STM32F4 Series)
typedef struct
{
	    volatile uint32_t CR;            // RCC clock control register                    (0x00)
	    volatile uint32_t PLLCFGR;       // RCC PLL configuration register                (0x04)
	    volatile uint32_t CFGR;          // RCC clock configuration register              (0x08)
	    volatile uint32_t CIR;           // RCC clock interrupt register                  (0x0C)
	    volatile uint32_t AHB1RSTR;      // RCC AHB1 peripheral reset register            (0x10)
	    volatile uint32_t AHB2RSTR;      // RCC AHB2 peripheral reset register            (0x14)
	    volatile uint32_t AHB3RSTR;      // RCC AHB3 peripheral reset register            (0x18)
	    volatile uint32_t RESERVED0;     // Reserved                                      (0x1C)
	    volatile uint32_t APB1RSTR;      // RCC APB1 peripheral reset register            (0x20)
	    volatile uint32_t APB2RSTR;      // RCC APB2 peripheral reset register            (0x24)
	    volatile uint32_t RESERVED1[2];  // Reserved                                      (0x28-0x2C)
	    volatile uint32_t AHB1ENR;       // RCC AHB1 peripheral clock enable register     (0x30)
	    volatile uint32_t AHB2ENR;       // RCC AHB2 peripheral clock enable register     (0x34)
	    volatile uint32_t AHB3ENR;       // RCC AHB3 peripheral clock enable register     (0x38)
	    volatile uint32_t RESERVED2;     // Reserved                                      (0x3C)
	    volatile uint32_t APB1ENR;       // RCC APB1 peripheral clock enable register     (0x40)
	    volatile uint32_t APB2ENR;       // RCC APB2 peripheral clock enable register     (0x44)
	    volatile uint32_t RESERVED3[2];  // Reserved                                      (0x48-0x4C)
	    volatile uint32_t AHB1LPENR;     // RCC AHB1 peripheral clock enable in low power (0x50)
	    volatile uint32_t AHB2LPENR;     // RCC AHB2 peripheral clock enable in low power (0x54)
	    volatile uint32_t AHB3LPENR;     // RCC AHB3 peripheral clock enable in low power (0x58)
	    volatile uint32_t RESERVED4;     // Reserved                                      (0x5C)
	    volatile uint32_t APB1LPENR;     // RCC APB1 peripheral clock enable in low power (0x60)
	    volatile uint32_t APB2LPENR;     // RCC APB2 peripheral clock enable in low power (0x64)
	    volatile uint32_t RESERVED5[2];  // Reserved                                      (0x68-0x6C)
	    volatile uint32_t BDCR;          // RCC Backup domain control register            (0x70)
	    volatile uint32_t CSR;           // RCC clock control & status register           (0x74)
	    volatile uint32_t RESERVED6[2];  // Reserved                                      (0x78-0x7C)
	    volatile uint32_t SSCGR;         // RCC spread spectrum clock generation register (0x80)
	    volatile uint32_t PLLI2SCFGR;    // RCC PLLI2S configuration register             (0x84)
	    volatile uint32_t PLLSAICFGR;    // RCC PLLSAI configuration register             (0x88)
	    volatile uint32_t DCKCFGR;       // RCC Dedicated Clocks configuration register   (0x8C)
	    volatile uint32_t CKGATENR;      // RCC clocks gated enable register              (0x90)
	    volatile uint32_t DCKCFGR2;      // RCC Dedicated Clocks configuration register 2 (0x94)
} RCC_RegDef_t;

//RCC pointer
#define  RCC  ((RCC_RegDef_t*)RCC_BASEADDR)

//Clock Enable Macros (AHB1 Bus for GPIO)
#define GPIOA_CLK_EN()	(RCC->AHB1ENR |= (1<<0))
#define GPIOB_CLK_EN()	(RCC->AHB1ENR |= (1<<1))
#define GPIOC_CLK_EN()	(RCC->AHB1ENR |= (1<<2))
#define GPIOD_CLK_EN()	(RCC->AHB1ENR |= (1<<3))
#define GPIOE_CLK_EN()	(RCC->AHB1ENR |= (1<<4))
#define GPIOF_CLK_EN()	(RCC->AHB1ENR |= (1<<5))
#define GPIOG_CLK_EN()	(RCC->AHB1ENR |= (1<<6))
#define GPIOH_CLK_EN()	(RCC->AHB1ENR |= (1<<7))

/* SPI base addresses & Bus in APB2 */
#define SPI1_BASEADDR  0x40013000U
#define SPI4_BASEADDR  0x40013400U

/* SPI base addresses & Bus in APB1 */
#define SPI2_BASEADDR  0x40003800U
#define SPI3_BASEADDR  0x40003C00U

/* SPI Register structure (APB1 & APB2 Bus) */
typedef struct
{
	volatile uint32_t CR1;      // Control Register 1
	volatile uint32_t CR2;      // Control Register 2
	volatile uint32_t SR;       // Status Register
	volatile uint32_t DR;       // Dataa Register
	volatile uint32_t CRCPR;    // CRC Polynomial Register
	volatile uint32_t RXCRCR;   // RX CRC Register
	volatile uint32_t TXCRCR;   // TX CRC Register
	volatile uint32_t I2SCFGR;  // I2S Configuration Register
	volatile uint32_t I2SPR;    // I2S Prescaler Register
}SPI_RefDef_t;

/* SPI POINTERS */
#define  SPI1  ((SPI_RefDef_t*)SPI1_BASEADDR)
#define  SPI2  ((SPI_RefDef_t*)SPI2_BASEADDR)
#define  SPI3  ((SPI_RefDef_t*)SPI3_BASEADDR)
#define  SPI4  ((SPI_RefDef_t*)SPI4_BASEADDR)

/* I2C Base address & Bus in APB1 */
#define I2C1_BASEADDR  0x40005400U
#define I2C2_BASEADDR  0x40005800U
#define I2C3_BASEADDR  0x40005C00U

/*I2C Register structure (APB1 Bus) */
typedef struct
{
	volatile uint32_t CR1;    // Control Register 1
	volatile uint32_t CR2;    // Control Register 2
	volatile uint32_t OAR1;   // Own Address Register 1
	volatile uint32_t OAR2;   // Own Address Register 2
	volatile uint32_t DR;     // Data Register
	volatile uint32_t SR1;    // Status Register 1
	volatile uint32_t SR2;    // Status Register 2
	volatile uint32_t CCR;    // Clock Control Register
	volatile uint32_t TRISE;  // Maximum Rise Time Register
	volatile uint32_t FLTR;   // Filter Register
}I2C_RefDef_t;

/*I2C POINTERS */
#define  I2C1  ((I2C_RefDef_t*)I2C1_BASEADDR)
#define  I2C2  ((I2C_RefDef_t*)I2C2_BASEADDR)
#define  I2C3  ((I2C_RefDef_t*)I2C3_BASEADDR)

#endif /* STM32F446FF_H_ */
