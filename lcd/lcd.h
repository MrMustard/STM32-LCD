/*
 * lcd.h
 *
 *  Created on: May 2, 2023
 *  Author: Manuel vega
 *
 *
 *  lcd
 *
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



/*Definiciones de posicionamiento*/

#define ROW1	0X02
#define ROW2	0XA0
#define ROW3	0XC0
#define ROW4	0XE0

#define grados					0b11011100
#define cursor_flecha_izquierda 0b11100001
#define cursor_ok 1				0b00101010
#define cursor_flecha_arriba	0b00011010
#define cursor_flecha_abajo		0b00011011
#define cursor_flecha_animacion	0b00010101







//funciones basicas

void lcd_print_char(char c);
void lcd_send_data(uint8_t data);
void lcd_send_command(uint8_t data);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd_print_string(uint8_t *str);
void lcd_init(void);


//funciones complementarias
void lcd_clear(void);
void lcd_return_home(void);
void lcd_print_char(char c);
void lcd_scroll_left(void);
void lcd_scroll_right(void);
void lcd_no_auto_scroll(void);
void lcd_move_cursor_R_to_L(void);
void lcd_move_cursor_L_to_R(void);
void lcd_cursor_off(void);
void lcd_cursor_blinkoff(void);






#endif /* LCD_H_ */
