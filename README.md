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

```C
lcd_t lcd_1= lcd_create_4_bit(D1_RS_GPIO_Port, D1_RW_GPIO_Port, D1_E_GPIO_Port,
  								D1_RS_Pin, D1_RW_Pin, D1_E_Pin,
  								D1_D7_GPIO_Port, D1_D6_GPIO_Port, D1_D5_GPIO_Port, D1_D4_GPIO_Port,
  								D1_D7_Pin,D1_D6_Pin, D1_D5_Pin,D1_D4_Pin,lcd_chr_16x2_mode);

```


