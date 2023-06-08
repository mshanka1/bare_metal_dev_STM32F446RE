/*
 * memory_mapping.h
 *
 *  Created on: Jun 8, 2023
 *      Author: Shankar
 */

#ifndef MEMORY_MAPPING_H_
#define MEMORY_MAPPING_H_


#define SET_BIT(REG_VAL,POS)    (REG_VAL|(1<<POS))
#define CLEAR_BIT(REG_VAL,POS)  (REG_VAL&~(1<<POS))


typedef volatile struct {
    volatile unsigned int CR;           // RCC clock control register,                                  Address offset: 0x00
    volatile unsigned int PLLCFGR;      // RCC PLL configuration register,                              Address offset: 0x04
    volatile unsigned int CFGR;         // RCC clock configuration register,                            Address offset: 0x08
    volatile unsigned int CIR;          // RCC clock interrupt register,                                Address offset: 0x0C
    volatile unsigned int AHB1RSTR;     // RCC AHB1 peripheral reset register,                          Address offset: 0x10
    volatile unsigned int AHB2RSTR;     // RCC AHB2 peripheral reset register,                          Address offset: 0x14
    volatile unsigned int AHB3RSTR;     // RCC AHB3 peripheral reset register,                          Address offset: 0x18
             unsigned int RESERVED0;    // Reserved,                                                    Address offset: 0x1C
    volatile unsigned int APB1RSTR;     // RCC APB1 peripheral reset register,                          Address offset: 0x20
    volatile unsigned int APB2RSTR;     // RCC APB2 peripheral reset register,                          Address offset: 0x24
             unsigned int RESERVED1[2]; // Reserved,                                                    Address offset: 0x28-0x2C
    volatile unsigned int AHB1ENR;      // RCC AHB1 peripheral clock register,                          Address offset: 0x30
    volatile unsigned int AHB2ENR;      // RCC AHB2 peripheral clock register,                          Address offset: 0x34
    volatile unsigned int AHB3ENR;      // RCC AHB3 peripheral clock register,                          Address offset: 0x38
             unsigned int RESERVED2;    // Reserved,                                                    Address offset: 0x3C
    volatile unsigned int APB1ENR;      // RCC APB1 peripheral clock enable register,                   Address offset: 0x40
    volatile unsigned int APB2ENR;      // RCC APB2 peripheral clock enable register,                   Address offset: 0x44
             unsigned int RESERVED3[2]; // Reserved,                                                    Address offset: 0x48-0x4C
    volatile unsigned int AHB1LPENR;    // RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50
    volatile unsigned int AHB2LPENR;    // RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54
    volatile unsigned int AHB3LPENR;    // RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58
             unsigned int RESERVED4;    // Reserved,                                                    Address offset: 0x5C
    volatile unsigned int APB1LPENR;    // RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60
    volatile unsigned int APB2LPENR;    // RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64
             unsigned int RESERVED5[2]; // Reserved,                                                    Address offset: 0x68-0x6C
    volatile unsigned int BDCR;         // RCC Backup domain control register,                          Address offset: 0x70
    volatile unsigned int CSR;          // RCC clock control & status register,                         Address offset: 0x74
             unsigned int RESERVED6[2]; // Reserved,                                                    Address offset: 0x78-0x7C
    volatile unsigned int SSCGR;        // RCC spread spectrum clock generation register,               Address offset: 0x80
    volatile unsigned int PLLI2SCFGR;   // RCC PLLI2S configuration register,                           Address offset: 0x84
    volatile unsigned int PLLSAICFGR;   // RCC PLLSAI configuration register,                           Address offset: 0x88
    volatile unsigned int DCKCFGR;      // RCC Dedicated Clocks configuration register,                 Address offset: 0x8C
    volatile unsigned int CKGATENR;     // RCC Clocks Gated ENable Register,                            Address offset: 0x90
    volatile unsigned int DCKCFGR2;     // RCC Dedicated Clocks configuration register 2,               Address offset: 0x94
} RCC_TypeDef;


typedef volatile struct {
    volatile unsigned int MODER;    // GPIO port mode register,               Address offset: 0x00
    volatile unsigned int OTYPER;   // GPIO port output type register,        Address offset: 0x04
    volatile unsigned int OSPEEDR;  // GPIO port output speed register,       Address offset: 0x08
    volatile unsigned int PUPDR;    // GPIO port pull-up/pull-down register,  Address offset: 0x0C
    volatile unsigned int IDR;      // GPIO port input data register,         Address offset: 0x10
    volatile unsigned int ODR;      // GPIO port output data register,        Address offset: 0x14
    volatile unsigned int BSRR;     // GPIO port bit set/reset register,      Address offset: 0x18
    volatile unsigned int LCKR;     // GPIO port configuration lock register, Address offset: 0x1C
    volatile unsigned int AFR[2];   // GPIO alternate function registers,     Address offset: 0x20-0x24
} GPIO_TypeDef;

#define RCC_REG_BASE_ADDRESS		((RCC_TypeDef *)0x40023800UL) 
#define GPIO_PORTA_BASE_ADDRESS		((GPIO_TypeDef *)0x40020000UL)

//#define CONFIG_GPIO_PORTA_PIN1_AS_OP()       gpio_port_a_as_op_init()
//#define LED_CONTROL(TIME)                    gpio_port_a_led_control(unsigned int t)

//void gpio_port_a_as_op_init(void);
void gpio_port_a_led_control(unsigned int);

#endif /* MEMORY_MAPPING_H_ */
