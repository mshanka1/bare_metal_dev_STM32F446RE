/**
 ******************************************************************************
 * @file           : config_gpioa_op.c
 * @author         : shankar manne
 * @brief          : program body
 ******************************************************************************
*/

#include "memory_mapping.h"

void gpio_port_a_as_op_init(void)
{
	// Enable clock access
	RCC_REG_BASE_ADDRESS->AHB1ENR = SET_BIT(RCC_REG_BASE_ADDRESS->AHB1ENR,0);//enable GPIOA EN
	// set PA5 as output pin
	GPIO_PORTA_BASE_ADDRESS->MODER = SET_BIT(GPIO_PORTA_BASE_ADDRESS->MODER,10);
	GPIO_PORTA_BASE_ADDRESS->MODER = CLEAR_BIT(GPIO_PORTA_BASE_ADDRESS->MODER,11);
}
