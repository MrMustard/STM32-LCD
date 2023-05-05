/*
 * led.h
 *
 *  Created on: May 2, 2023
 *      Author: el_gl
 */

#ifndef LED_H_
#define LED_H_

#include "main.h"

 enum led_number
{
led_verde,
led_amarillo,
led_rojo,
led_status
};

//turn on the led
void led_on(uint8_t led_number);
//turn off led
void led_off(uint8_t led_number);
//turn on all leds
void led_all_on();
//turn off all leds
void led_all_off();

//funcion para leer los botones
uint8_t button_read();



#endif /* LED_H_ */
