/*
 * SerialUart.c
 *
 *Escrita por: Jose Manuel Ramirez Vega
 *16-junio-2022
 *16-junio-2022
 *16-junio-2022Esta libreria usa las interrupciones para poder controlarse
 *16-junio-2022Esta
 */


//Inicializacion Del serial UART

//init the reception of 1 byte interrupt



#include "serial.h"
#include "String.h"
#include "stdio.h"


extern UART_HandleTypeDef huart2; // if you want to use toher serial port chage this

volatile uint8_t Index =0;
uint8_t Data_Rx[SIZE_RX];// buffer to copy data of uart



// init the uart

void SerialUartInit()
{
	MX_USART1_UART_Init();
}




//config the hal serial uart recevie it
/*
 * Buff -> buffer to stores data
 * lenght -> number of characters
 *
 *
 *
 * */
void SerialUartReceiveEnable(uint8_t buff[50],uint8_t length)
{

//only receive one byte

	HAL_UART_Receive_IT(&huart2, buff, length);

}




void SerialUartSendString(char *ptr)
{
uint16_t DataLen = strlen(ptr);
HAL_UART_Transmit(&huart2, (const uint8_t *)ptr, DataLen, HAL_MAX_DELAY);
}

void SerialUartSendVarInt(char *Text,float var)
{
	char Buffer[50];
	sprintf(Buffer, Text,var);
	SerialUartSendString(Buffer);
}




//Interrupt request of receive data
void SerialUartReceiveIR(uint8_t Buff[50])
{

	//printf("Int\n");
/*
	uint8_t Data = Buff[0];//send the value of serial port
	Data_Rx[Index++] = Data;
	if(Data =='*') Index =0;
	if(Index >= SIZE_MAX) Index =0;
	if(strstr(Data_Rx,"LED1 ON"))
	{
		printf("Led on\n\r");
		memset(Buff, '\0', 50); //limpiar para que no la basura no se quede en la cadena
	}
	SerialUartReceiveEnable(Buff,1);
	*/

}




//Receive commands
/*Fucntion to receive a starcommand and then process the comand*/


void SerialUartReceiveCommand(uint8_t Buff[50])
{

	/*Example*/

	uint8_t Data = Buff[0];//send the value of serial port
		Data_Rx[Index++] = Data;

		if(Data =='*') Index =0;
		if(Index >= SIZE_MAX) Index =0;

		if(strstr(Data_Rx,"POPO"))

		{
			printf("Led on\n\r");
			memset(Buff, '\0', 50); //limpiar para que no la basura no se quede en la cadena

		}








		SerialUartReceiveEnable(Buff,1);

}

/*printf definition*/
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

PUTCHAR_PROTOTYPE
{
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
  return ch;
}
