# STM32 LCD LIBRARY
This library is for stm32 but you can make a port for another microcontroller easy
this libraries is still not yet finished but it works.
the microcontroller using in the examples are STM32G030C8T6.


## How to use the library

### 1. Define gpio as output
First you have to define the necesary outputs of microcontroller.
7 output for 4 bit mode  and 11 output for 8 bit mode.
![Definene gpio as output in stm32cubemx](https://github.com/MrMustard/STM32-LCD/blob/main/EXAMPLES/LCD_16X2_8_BIT_MODE/pinout.png)

### 2. import the library to stm32cubeide project, you have to add lcd.c and lcd.h 
### 3. Create a lcd_t varaible and initialice it.
 you have two function for initialice lcd, the 4 bit init function and the 8 bit init function
 Function for create and init the lcd 4 bit mode:
 
  ```C
 
 lcd_t lcd_create_4_bit(	GPIO_TypeDef * RS_PORT,GPIO_TypeDef * RW_PORT,GPIO_TypeDef * E_PORT,
						uint16_t RS_PIN,uint16_t RW_PIN,uint16_t E_PIN,
						GPIO_TypeDef * D7_PORT,GPIO_TypeDef * D6_PORT,GPIO_TypeDef * D5_PORT,GPIO_TypeDef * D4_PORT,
						uint16_t D7_PIN,uint16_t D6_PIN,uint16_t D5_PIN,uint16_t D4_PIN,uint8_t character);
 
 ```
  the arguments are:
 1. RS PORT: port of gpio RS pin
 2. RW PORT: port of gpio rw pin
 3. E PORT: port of gpio e pin
 4. RS PIN: gpio RS pin
 5. RW PIN: gpio RW pin
 6. E PIN: gpio E pin
 7. D7 PORT: port of gpio D7 pin
 8. D6 PORT:port of gpio D6 pin
 9. D5 PORT:port of gpio D5 pin
 10. D4 PORT:port of gpio D4 pin
 11. D7 PIN:gpio D7 pin
 12. D6 PIN:gpio D6 pin
 13. D5 PIN:gpio D5 pin
 14. D4 PIN:gpio D4 pin
 15. CHARACTER MODE: SELECT THE 16X2 OR  20X4  MODE
 16. 
 For 8 bit mode are the same but you have to add 4 port and 4 pins more
 CHARACTER MODE CAN BE 16x2 or 20x4 using the next syntax
 ```
lcd_chr_16x2_mode // use this for 16x2 mode
lcd_chr_20x4_mode  // use tgins  for 20x4 mode
 
 ```
 

 Function for create and init lcd 8 bit mode 
```C

lcd_t lcd_create_8_bit(	GPIO_TypeDef * RS_PORT,GPIO_TypeDef * RW_PORT,GPIO_TypeDef * E_PORT,
						uint16_t RS_PIN,uint16_t RW_PIN,uint16_t E_PIN,
						GPIO_TypeDef * D7_PORT,GPIO_TypeDef * D6_PORT,GPIO_TypeDef * D5_PORT,GPIO_TypeDef * D4_PORT,
						GPIO_TypeDef * D3_PORT,GPIO_TypeDef * D2_PORT,GPIO_TypeDef * D1_PORT,GPIO_TypeDef * D0_PORT,
						uint16_t D7_PIN,uint16_t D6_PIN,uint16_t D5_PIN,uint16_t D4_PIN,
						uint16_t D3_PIN,uint16_t D2_PIN,uint16_t D1_PIN,uint16_t D0_PIN,uint8_t character);
```

### example Create lcd for 4 bit and 16x2 mode: 

```C
  lcd_t lcd_1= lcd_create_4_bit(D1_RS_GPIO_Port, D1_RW_GPIO_Port, D1_E_GPIO_Port,
  				D1_RS_Pin, D1_RW_Pin, D1_E_Pin,
  				D1_D7_GPIO_Port, D1_D6_GPIO_Port, D1_D5_GPIO_Port, D1_D4_GPIO_Port,
  				D1_D7_Pin,D1_D6_Pin, D1_D5_Pin,D1_D4_Pin,lcd_chr_16x2_mode);

```


after to init the object you can use the object in all functions of lcd, remember that you have to send the memory direction of the object

### 4. clear the display:

```C
 lcd_clear(&lcd_1);//clear display 1

```
### 5. Set cursor and put text:

```C
 lcd_set_cursor(&lcd_1, 0, 0);
 lcd_print_string(&lcd_1, "TEST LCD 1");
 lcd_set_cursor(&lcd_1, 1, 0);
 lcd_print_string(&lcd_1, "4 bit mode 16x2");
```





