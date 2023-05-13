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
 1. RS PORT
 2. RW PORT
 3. E PORT
 4. RS PIN
 5. RW PIN
 6. E PIN
 7. D7 PORT
 8. D6 PORT
 9. D5 PORT
 10. D4 PORT
 11. D7 PIN
 12. D6 PIN
 13. D5 PIN
 14. D4 PIN
 15. CHARACTER MODE
  for 8 bit mode are the same but you have to add 4 port and 4 pins more
 CHARACTER MODE CAN BE 16x2 or 20x4 using the next syntax
 ```
lcd_chr_16x2_mode // use this for 16x2 mode
lcd_chr_20x4_mode  // use tgins  for 20x4 mode
 
 ```
 

 Function for create and init lcd 8 bit mode 
```C


```


