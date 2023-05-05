/*
 * leds.c
 *
 *  Created on: May 2, 2023
 *      Author: el_gl
 */


#include "led.h"



//turn on the led
void led_on(uint8_t led_number)
{
	switch(led_number)
	{
	case led_verde:
		HAL_GPIO_WritePin(led_green_GPIO_Port, led_green_Pin, GPIO_PIN_SET);
		break;
	case led_amarillo:
		HAL_GPIO_WritePin(led_yellow_GPIO_Port, led_yellow_Pin, GPIO_PIN_SET);
		break;
	case  led_rojo:
		HAL_GPIO_WritePin(led_red_GPIO_Port, led_red_Pin, GPIO_PIN_SET);
		break;
	case led_status:

		HAL_GPIO_WritePin(led_status_GPIO_Port, led_status_Pin, GPIO_PIN_SET);
		break;

	default:
		HAL_GPIO_WritePin(led_green_GPIO_Port, led_green_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(led_yellow_GPIO_Port, led_yellow_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(led_red_GPIO_Port, led_red_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(led_status_GPIO_Port, led_status_Pin, GPIO_PIN_RESET);

		break;

	}
}
//turn off led
void led_off(uint8_t led_number)
{
	switch(led_number)
	{
	case led_verde:
		HAL_GPIO_WritePin(led_green_GPIO_Port, led_green_Pin, GPIO_PIN_RESET);
		break;
	case led_amarillo:
		HAL_GPIO_WritePin(led_yellow_GPIO_Port, led_yellow_Pin, GPIO_PIN_RESET);
		break;
	case  led_rojo:
		HAL_GPIO_WritePin(led_red_GPIO_Port, led_red_Pin, GPIO_PIN_RESET);
		break;
	case led_status:

		HAL_GPIO_WritePin(led_status_GPIO_Port, led_status_Pin, GPIO_PIN_RESET);
		break;

	default:
		HAL_GPIO_WritePin(led_green_GPIO_Port, led_green_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(led_yellow_GPIO_Port, led_yellow_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(led_red_GPIO_Port, led_red_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(led_status_GPIO_Port, led_status_Pin, GPIO_PIN_RESET);

		break;

	}
}
//turn on all leds
void led_all_on()
{
	HAL_GPIO_WritePin(led_green_GPIO_Port, led_green_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(led_yellow_GPIO_Port, led_yellow_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(led_red_GPIO_Port, led_red_Pin, GPIO_PIN_SET);



}
//turn off all leds
void led_all_off()
{

	HAL_GPIO_WritePin(led_green_GPIO_Port, led_green_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(led_yellow_GPIO_Port, led_yellow_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(led_red_GPIO_Port, led_red_Pin, GPIO_PIN_RESET);
}



//funcion para leer los botones
uint8_t button_read()
{
uint8_t btn_var=0,b1,b2,b3,b4,b5;

b1=HAL_GPIO_ReadPin(button_1_GPIO_Port, button_1_Pin);
b2=HAL_GPIO_ReadPin(button_2_GPIO_Port, button_2_Pin);
b3=HAL_GPIO_ReadPin(button_3_GPIO_Port, button_3_Pin);
b4=HAL_GPIO_ReadPin(button_4_GPIO_Port, button_4_Pin);
b5=HAL_GPIO_ReadPin(button_5_GPIO_Port, button_5_Pin);
/*b1=~b1;
b2=~b2;
b3=~b3;
b4=~b4;
b5=~b5;*/
btn_var=((b5<<4)|(b4<<3)|(b3<<2)|(b2<<1)|b1);
btn_var=btn_var|0b11100000;

return btn_var;
}
