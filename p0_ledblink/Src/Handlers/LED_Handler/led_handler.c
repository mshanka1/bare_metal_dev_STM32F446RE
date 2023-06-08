/**
 ******************************************************************************
 * @file           : led_handler.c
 * @author         : shankar manne
 * @brief          : program body
 ******************************************************************************
*/

#include "memory_mapping.h"

extern void gpio_port_a_led_control(unsigned int time)
{
	GPIO_PORTA_BASE_ADDRESS->ODR = SET_BIT(GPIO_PORTA_BASE_ADDRESS->ODR,5);
	for(int i=0;i<time;i++){}
	GPIO_PORTA_BASE_ADDRESS->ODR = CLEAR_BIT(GPIO_PORTA_BASE_ADDRESS->ODR,5);
	for(int i=0;i<time;i++){}
}
