/*
 * lcd.h
 *
 *  Created on: 12 may. 2023
 *      Author: el_gl
 */

#ifndef LCD_H_
#define LCD_H_


#include "main.h"
/*Inicio de definiciones y varaiables de lcd*/
/************************************************************************************************************************/

#define RS_Pin RSD_Pin
#define RS_GPIO_Port RSD_GPIO_Port
#define RW_Pin RWD_Pin
#define RW_GPIO_Port RWD_GPIO_Port
#define EN_Pin ED_Pin
#define EN_GPIO_Port ED_GPIO_Port
#define D4_Pin  D4D_Pin
#define D4_GPIO_Port D4D_GPIO_Port
#define D5_Pin  D5D_Pin
#define D5_GPIO_Port D5D_GPIO_Port
#define D6_Pin  D6D_Pin
#define D6_GPIO_Port D6D_GPIO_Port
#define D7_Pin  D7D_Pin
#define D7_GPIO_Port D7D_GPIO_Port

/*FUNDAMENTAL COMMAND SET*/




#define ClearDisplay	0b00000001//Write "20H" to DDRAM and set DDRAM address to "00H" from AC.
#define ReturnHome		0b00000010//Set DDRAM address to "00H" from AC and return cursor to its original position if shifted. The contents of DDRAM are not changed

#define	EntryMode1		0b00000100//0x04  cursor blick moves to left and ddram adress is decreased by 1, display shifht dissabled(por)
#define	EntryMode2		0b00000101//0x05 cursor/blink moves to right and ddram address is increaded by 1
#define EntryMode3		0b00000110//0x06 cursor blinck moves to left and ddram addres is decreased by 1, make displa shift of the enalbeline by the DS4 to DS1 bits in the shift enable instruction. left/right direction dependes on i/d bit selectrion
#define	EntryMode4		0b00000111//0x07 I/D = "1": cursor/ blink moves to right and DDRAM address is increased by 1 (POR), S = "1": make display shift of the enabled lines by the DS4 to DS1 bits in the shift enable instruction. Left/ right direction depends on I/D bit selection.


#define lcd_mode_8_bit 	0
#define lcd_mode_4_bit  1

#define lcd_write_mode  0
#define lcd_read_mode   1

#define lcd_command_mode 0
#define lcd_data_mode	1

#define lcd_chr_16x2_mode 0
#define lcd_chr_20x4_mode 1




//lcd struct this struct is the object
typedef struct
{

//GPIO PIN
uint16_t 	D7_PIN;
uint16_t	D6_PIN;
uint16_t	D5_PIN;
uint16_t	D4_PIN;
uint16_t	D3_PIN;
uint16_t	D2_PIN;
uint16_t	D1_PIN;
uint16_t	D0_PIN;
uint16_t	EN_PIN;
uint16_t	RW_PIN;
uint16_t	RS_PIN;
//GPIO PORTS
GPIO_TypeDef *	D7_PORT;
GPIO_TypeDef *	D6_PORT;
GPIO_TypeDef *	D5_PORT;
GPIO_TypeDef *	D4_PORT;
GPIO_TypeDef *	D3_PORT;
GPIO_TypeDef *	D2_PORT;
GPIO_TypeDef * 	D1_PORT;
GPIO_TypeDef *	D0_PORT;
GPIO_TypeDef *	EN_PORT;
GPIO_TypeDef *	RW_PORT;
GPIO_TypeDef *	RS_PORT;
//DELAY FOR LCD CONTROL
uint16_t LCD_DELAY;
//lcd bit mode cam be 8 or 4 bit
uint8_t BIT_MODE;
//lcd characte type,it can be 16x2or 20x4
uint8_t CHARACTER_TYPE;
}lcd_t;

/*Function to create caracters
 * aguments are the gpio ports, and the gpio pins
 * thins function will return the the structc lcd with alld de parameters to work for 4 bits mode the character var is to select
 * 16x2 or 20x4 lcd */
lcd_t lcd_create_4_bit(	GPIO_TypeDef * RS_PORT,GPIO_TypeDef * RW_PORT,GPIO_TypeDef * E_PORT,
						uint16_t RS_PIN,uint16_t RW_PIN,uint16_t E_PIN,
						GPIO_TypeDef * D7_PORT,GPIO_TypeDef * D6_PORT,GPIO_TypeDef * D5_PORT,GPIO_TypeDef * D4_PORT,
						uint16_t D7_PIN,uint16_t D6_PIN,uint16_t D5_PIN,uint16_t D4_PIN,uint8_t character);

lcd_t lcd_create_8_bit(	GPIO_TypeDef * RS_PORT,GPIO_TypeDef * RW_PORT,GPIO_TypeDef * E_PORT,
						uint16_t RS_PIN,uint16_t RW_PIN,uint16_t E_PIN,
						GPIO_TypeDef * D7_PORT,GPIO_TypeDef * D6_PORT,GPIO_TypeDef * D5_PORT,GPIO_TypeDef * D4_PORT,
						GPIO_TypeDef * D3_PORT,GPIO_TypeDef * D2_PORT,GPIO_TypeDef * D1_PORT,GPIO_TypeDef * D0_PORT,
						uint16_t D7_PIN,uint16_t D6_PIN,uint16_t D5_PIN,uint16_t D4_PIN,
						uint16_t D3_PIN,uint16_t D2_PIN,uint16_t D1_PIN,uint16_t D0_PIN,uint8_t character);

/* function to init lcd
 * object have all the pin that you cand work
 *also receive the pinmode, 4 bits and 8 bits. */
void lcd_init(lcd_t *const lcd);


/*Function to send data to the lcd
 * receive the object lcd and the data byte*/
void lcd_send_data(lcd_t * const lcd,uint8_t data);
/*Function to send command to the lcd
 * receive the object lcd and the data byte*/
void lcd_send_command(lcd_t * const lcd, uint8_t command);

/*function to put char to lcd
 * receive the object lcd and the char caracter to send*/
void lcd_print_char(lcd_t * const lcd,char c);
/*function to set position cursor
 * receive the object lcd, the row and the col*/
void lcd_set_cursor(lcd_t * const lcd,uint8_t row, uint8_t col);

/*function to print string
 * receive the lcd object and the string*/
void lcd_print_string(lcd_t * const lcd,char *str);


//complemenetary functions
void lcd_clear(lcd_t * const lcd);
void lcd_return_home(lcd_t * const lcd);
//void lcd_scroll_left(lcd_t * const lcd);
//void lcd_scroll_right(lcd_t * const lcd);
//void lcd_no_auto_scroll(lcd_t * const lcd);
//void lcd_move_cursor_R_to_L(lcd_t * const lcd);
//void lcd_move_cursor_L_to_R(lcd_t * const lcd);
//void lcd_cursor_off(lcd_t * const lcd);
//void lcd_cursor_blinkoff(lcd_t * const lcd);


#endif /* LCD_H_ */
