/*
 * lcd.c
 *
 *  Created on: May 2, 2023
 *      Author: el_gl
 */


#include "lcd.h"

/*Definiciones de instrucciones*/

/************************************** Command register **************************************/
#define CLEAR_DISPLAY 0x01

#define RETURN_HOME 0x02

#define ENTRY_MODE_SET 0x04
#define OPT_S	0x01					// Shift entire display to right
#define OPT_INC 0x02					// Cursor increment

#define DISPLAY_ON_OFF_CONTROL 0x08
#define OPT_D	0x04					// Turn on display
#define OPT_C	0x02					// Turn on cursor
#define OPT_B 	0x01					// Turn on cursor blink

#define CURSOR_DISPLAY_SHIFT 0x10		// Move and shift cursor
#define OPT_SC 0x08
#define OPT_RL 0x04

#define FUNCTION_SET 0x20
#define OPT_DL 0x10						// Set interface data length
#define OPT_N 0x08						// Set number of display lines
#define OPT_F 0x04						// Set alternate font
#define SETCGRAM_ADDR 0x040
#define SET_DDRAM_ADDR 0x80				// Set DDRAM address


/*Fin de definniciones de instrucciones*/







/*Funciones para funcionamiento interno */
void latch() {
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_SET);
	//HAL_Delay(1);
	HAL_GPIO_WritePin(EN_GPIO_Port,EN_Pin, GPIO_PIN_RESET);
	//HAL_Delay(1);// retraso de 100 us

}


/*emula la funcion de enviar un nible por medio de un puerto*/
void sendToLcd(uint8_t nibble,uint8_t rs) {

	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, rs);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, ((nibble >> 3) & 0x01));
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, ((nibble >> 2) & 0x01));
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, ((nibble >> 1) & 0x01));
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, ((nibble >> 0) & 0x01));
	latch();


}


/***************************************************************************/


void lcd_clear(void)
{

lcd_send_command(CLEAR_DISPLAY);
HAL_Delay(2);

}
void lcd_return_home(void)
{
	lcd_send_command(RETURN_HOME);
	HAL_Delay(2);

}

void lcd_scroll_left(void)
{

}
void lcd_scroll_right(void)
{

}
void lcd_no_auto_scroll(void)
{

}

void lcd_move_cursor_R_to_L(void)
{

}
void lcd_move_cursor_L_to_R(void)
{

}
void lcd_cursor_off(void)
{

}
void lcd_cursor_blinkoff(void)
{

}


void lcd_print_char(char c)
{
	lcd_send_data(c);
}
//funciones
void lcd_send_data(uint8_t data)
{

	uint8_t datatosend;
	datatosend= ((data>>4)&0x0f);
	sendToLcd(datatosend,1); //enviamos el el primer nible
	datatosend=((data)&0x0f);
	sendToLcd(datatosend,1); //enviamos el segundo nibble
	HAL_Delay(1);

}
void lcd_send_command(uint8_t data)
{
	uint8_t datatosend;
	datatosend= ((data>>4)&0x0f);
	sendToLcd(datatosend,0); //enviamos el el primer nible
	datatosend=((data)&0x0f);
	sendToLcd(datatosend,0); //enviamos el segundo nibble
	HAL_Delay(1);


}

void lcd_print_string(uint8_t *str)
{

	while (*str)
		{

		lcd_send_data(*str++);
		HAL_Delay(1);

		}

}





void lcd_set_cursor(uint8_t row, uint8_t col)
{
    switch (row)
    {
        case 0:
            col |= 0x80;
            break;
        case 1:
            col |= 0xC0;
            break;
    }
    lcd_send_command(col);
}

void lcd_init(void)
{

	/*HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, 0); //apagamos
	HAL_Delay(50);
	lcd_send_command(0x30);
	HAL_Delay(5);
	lcd_send_command(0x30);
	HAL_Delay(5);
	lcd_send_command(0x30);
	HAL_Delay(5);
	lcd_send_command(0x20);
	HAL_Delay(5);
	//display init
	lcd_send_command(0x28);// Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	HAL_Delay(1);
	lcd_send_command(0x08);//Display on/off control --> D=0,C=0, B=0  ---> display off
	HAL_Delay(1);
	lcd_send_command(0x01); // clear display
	HAL_Delay(1);
	HAL_Delay(1);
	//lcd_send_command(0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	//HAL_Delay(10);
	lcd_send_command(0x0c);//Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)
	HAL_Delay(1);*/

	lcd_send_command( 0x33);
	lcd_send_command( 0x32);
	lcd_send_command(FUNCTION_SET | OPT_N);				// 4-bit mode

	lcd_send_command(CLEAR_DISPLAY);						// Clear screen
	lcd_send_command(DISPLAY_ON_OFF_CONTROL | OPT_D);		// Lcd-on, cursor-off, no-blink
	lcd_send_command(ENTRY_MODE_SET | OPT_INC);			// Increment cursor

}
