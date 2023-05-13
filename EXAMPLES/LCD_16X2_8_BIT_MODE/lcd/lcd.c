
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


const uint8_t ROW_16[] = {0x00, 0x40, 0x10, 0x50};
const uint8_t ROW_20[] = {0x00, 0x40, 0x14, 0x54};

/*****************************************************************/


void latch(lcd_t * const lcd) {


	HAL_GPIO_WritePin(lcd->EN_PORT, lcd->EN_PIN,GPIO_PIN_RESET );
	HAL_GPIO_WritePin(lcd->EN_PORT, lcd->EN_PIN,GPIO_PIN_SET );
	HAL_GPIO_WritePin(lcd->EN_PORT, lcd->EN_PIN,GPIO_PIN_SET );



}



void send_nibble_to_lcd(lcd_t * const lcd,uint8_t nibble,uint8_t rs) {


	HAL_GPIO_WritePin(lcd->RS_PORT,lcd->RS_PIN, rs);
	HAL_GPIO_WritePin(lcd->D7_PORT,lcd->D7_PIN, ((nibble >> 3) & 0x01));
	HAL_GPIO_WritePin(lcd->D6_PORT,lcd->D6_PIN, ((nibble >> 2) & 0x01));
	HAL_GPIO_WritePin(lcd->D5_PORT,lcd->D5_PIN, ((nibble >> 1) & 0x01));
	HAL_GPIO_WritePin(lcd->D4_PORT,lcd->D4_PIN, ((nibble >> 0) & 0x01));
	latch(lcd);


}

void send_to_lcd(lcd_t * const lcd,uint8_t nibble,uint8_t rs) {

	HAL_GPIO_WritePin(lcd->RS_PORT,lcd->RS_PIN , rs);
	HAL_GPIO_WritePin(lcd->D7_PORT,lcd->D7_PIN, ((nibble >> 7) & 0x01));
	HAL_GPIO_WritePin(lcd->D6_PORT,lcd->D6_PIN, ((nibble >> 6) & 0x01));
	HAL_GPIO_WritePin(lcd->D5_PORT,lcd->D5_PIN, ((nibble >> 5) & 0x01));
	HAL_GPIO_WritePin(lcd->D4_PORT,lcd->D4_PIN, ((nibble >> 4) & 0x01));
	HAL_GPIO_WritePin(lcd->D3_PORT,lcd->D3_PIN, ((nibble >> 3) & 0x01));
	HAL_GPIO_WritePin(lcd->D2_PORT,lcd->D2_PIN, ((nibble >> 2) & 0x01));
	HAL_GPIO_WritePin(lcd->D1_PORT,lcd->D1_PIN, ((nibble >> 1) & 0x01));
	HAL_GPIO_WritePin(lcd->D0_PORT,lcd->D0_PIN, ((nibble>>	0) & 0x01));
	latch(lcd);

}


/*Function to create caracters
 * aguments are the gpio ports, and the gpio pins
 * thins function will return the the structc lcd with alld de parameters to work for 4 bits mode */




lcd_t lcd_create_4_bit(	GPIO_TypeDef * RS_PORT,GPIO_TypeDef * RW_PORT,GPIO_TypeDef * E_PORT,
						uint16_t RS_PIN,uint16_t RW_PIN,uint16_t E_PIN,
						GPIO_TypeDef * D7_PORT,GPIO_TypeDef * D6_PORT,GPIO_TypeDef * D5_PORT,GPIO_TypeDef * D4_PORT,
						uint16_t D7_PIN,uint16_t D6_PIN,uint16_t D5_PIN,uint16_t D4_PIN,uint8_t character)
{
	lcd_t config_lcd;
	config_lcd.D7_PORT=D7_PORT;
	config_lcd.D6_PORT=D6_PORT;
	config_lcd.D5_PORT=D5_PORT;
	config_lcd.D4_PORT=D4_PORT;
	config_lcd.RS_PORT=RS_PORT;
	config_lcd.RW_PORT=RW_PORT;
	config_lcd.EN_PORT=E_PORT;
	config_lcd.D7_PIN=D7_PIN;
	config_lcd.D6_PIN=D6_PIN;
	config_lcd.D5_PIN=D5_PIN;
	config_lcd.D4_PIN=D4_PIN;
	config_lcd.RS_PIN=RS_PIN;
	config_lcd.RW_PIN=RW_PIN;
	config_lcd.EN_PIN=E_PIN;
	config_lcd.BIT_MODE=lcd_mode_4_bit;//desing lcd in 4 bit mode
	config_lcd.CHARACTER_TYPE=character;//desing if the lcd is 16x2 or 20x4.

	//you have to make the init of the lcd
	lcd_init(&config_lcd);//init the lcd

	return config_lcd;//return the configuration of the lcd
}

lcd_t lcd_create_8_bit(	GPIO_TypeDef * RS_PORT,GPIO_TypeDef * RW_PORT,GPIO_TypeDef * E_PORT,
						uint16_t RS_PIN,uint16_t RW_PIN,uint16_t E_PIN,
						GPIO_TypeDef * D7_PORT,GPIO_TypeDef * D6_PORT,GPIO_TypeDef * D5_PORT,GPIO_TypeDef * D4_PORT,
						GPIO_TypeDef * D3_PORT,GPIO_TypeDef * D2_PORT,GPIO_TypeDef * D1_PORT,GPIO_TypeDef * D0_PORT,
						uint16_t D7_PIN,uint16_t D6_PIN,uint16_t D5_PIN,uint16_t D4_PIN,
						uint16_t D3_PIN,uint16_t D2_PIN,uint16_t D1_PIN,uint16_t D0_PIN,uint8_t character)
{

	lcd_t config_lcd;
	config_lcd.D7_PORT=D7_PORT;
	config_lcd.D6_PORT=D6_PORT;
	config_lcd.D5_PORT=D5_PORT;
	config_lcd.D4_PORT=D4_PORT;
	config_lcd.D3_PORT=D3_PORT;
	config_lcd.D2_PORT=D2_PORT;
	config_lcd.D1_PORT=D1_PORT;
	config_lcd.D0_PORT=D0_PORT;
	config_lcd.RS_PORT=RS_PORT;
	config_lcd.RW_PORT=RW_PORT;
	config_lcd.EN_PORT=E_PORT;
	config_lcd.D7_PIN=D7_PIN;
	config_lcd.D6_PIN=D6_PIN;
	config_lcd.D5_PIN=D5_PIN;
	config_lcd.D4_PIN=D4_PIN;
	config_lcd.D3_PIN=D3_PIN;
	config_lcd.D2_PIN=D2_PIN;
	config_lcd.D1_PIN=D1_PIN;
	config_lcd.D0_PIN=D0_PIN;
	config_lcd.RS_PIN=RS_PIN;
	config_lcd.RW_PIN=RW_PIN;
	config_lcd.EN_PIN=E_PIN;
	config_lcd.BIT_MODE=lcd_mode_8_bit ;//desing lcd in 4 bit mode
	config_lcd.CHARACTER_TYPE=character;//desing if the lcd is 16x2 or 20x4
	lcd_init(&config_lcd);//init the lcd

	return config_lcd;//return the config the configuration of the lcd

}
/*Fin de funciones para funcionamiento interno*/

/* function to init lcd
 * object have all the pin that you cand work
 *also receive the pinmode, 4 bits and 8 bits. */
void lcd_init(lcd_t *const lcd)
{
	HAL_GPIO_WritePin(lcd->RS_PORT, lcd->RS_PIN, lcd_write_mode);//set to write mode

	//check if the lcd are 4 bit mode or 8 bit mode
	if(lcd->BIT_MODE == lcd_mode_4_bit)//for 4 bit mode
	{
		lcd_send_command(lcd, 0X00);
		HAL_Delay(100);
		lcd_send_command(lcd, 0x28);
		lcd_send_command(lcd, 0x28);
		HAL_Delay(30);
		lcd_send_command(lcd, 0x06);
		HAL_Delay(30);
		lcd_send_command(lcd, 0x0C);
		HAL_Delay(30);
		lcd_send_command(lcd, 0x01);
		HAL_Delay(30);

	}

	else
	{
		lcd_send_command(lcd, 0X00);
		HAL_Delay(100);
		lcd_send_command(lcd, 0x38);
		HAL_Delay(30);
		//lcd_send_command(lcd,FUNCTION_SET|OPT_N);
		lcd_send_command(lcd, 0x06);
		HAL_Delay(30);
		lcd_send_command(lcd, 0x0C);
		HAL_Delay(30);
		lcd_send_command(lcd, 0x01);
		HAL_Delay(30);
		lcd_send_command(lcd, 0x02);
		HAL_Delay(30);
		lcd_send_command(lcd, CLEAR_DISPLAY);
		HAL_Delay(30);

	}

}


/*Function to send data to the lcd
 * receive the object lcd and the data byte*/
void lcd_send_data(lcd_t * const lcd,uint8_t data)
{
	uint8_t dataSend;
	if(lcd->BIT_MODE == lcd_mode_4_bit)
		//for 4 bits mode lcd
	{
		dataSend=((data>>4)&0x0f);
		send_nibble_to_lcd(lcd, dataSend, lcd_data_mode);
		dataSend=((data)&0x0f);
		send_nibble_to_lcd(lcd, dataSend, lcd_data_mode);
		HAL_Delay(1);
	}
	else
	{
		//for 8 bits lcd
		send_to_lcd(lcd, data, lcd_data_mode);
		HAL_Delay(1);

	}


}
/*Function to send command to the lcd
 * receive the object lcd and the data byte*/
void lcd_send_command(lcd_t * const lcd, uint8_t command)
{
	uint8_t dataSend;
	if(lcd->BIT_MODE == lcd_mode_4_bit)
		//for 4 bits mode lcd
	{
		dataSend=((command>>4)&0x0f);
		send_nibble_to_lcd(lcd, dataSend, lcd_command_mode);
		dataSend=((command)&0x0f);
		send_nibble_to_lcd(lcd, dataSend, lcd_command_mode);
		HAL_Delay(1);
	}
	else
	{
		//for 8 bits lcd
		send_to_lcd(lcd, command, lcd_command_mode);
		HAL_Delay(1);

	}
}

/*function to put char to lcd
 * receive the object lcd and the char caracter to send*/
void lcd_print_char(lcd_t * const lcd,char c)
{


	lcd_send_data(lcd, c);


}
/*function to set position cursor
 * receive the object lcd, the row and the col*/
void lcd_set_cursor(lcd_t * const lcd,uint8_t row, uint8_t col)
{

if(lcd->CHARACTER_TYPE==lcd_chr_16x2_mode)//if the lcd is 16x2 mode
{

	lcd_send_command(lcd, SET_DDRAM_ADDR + ROW_16[row]+col);

}

else
{
	lcd_send_command(lcd, SET_DDRAM_ADDR + ROW_20[row]+col);
}


}

/*function to print string
 * receive the lcd object and the string*/
void lcd_print_string(lcd_t * const lcd,char *str)
{

	while(*str)
	{

		lcd_send_data(lcd, *str++);


	}

}


//funciones complementarias
void lcd_clear(lcd_t * const lcd)
{
lcd_send_command(lcd, CLEAR_DISPLAY);
HAL_Delay(2);

}
void lcd_return_home(lcd_t * const lcd)
{

	lcd_send_command(lcd, RETURN_HOME);

}
void lcd_scroll_left(lcd_t * const lcd)
{


}
void lcd_scroll_right(lcd_t * const lcd)
{

}
void lcd_no_auto_scroll(lcd_t * const lcd)
{

}
void lcd_move_cursor_R_to_L(lcd_t * const lcd){

}


void lcd_move_cursor_L_to_R(lcd_t * const lcd)
{

}
void lcd_cursor_off(lcd_t * const lcd)
{

}
void lcd_cursor_blinkoff(lcd_t * const lcd)
{

}
