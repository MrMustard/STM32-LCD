/*
 * serial_uart.h
 *
 *  Created on: Apr 4, 2023
 *      Author: el_gl
 */

#ifndef SERIAL_UART_H_
#define SERIAL_UART_H_

#define SIZE_RX 50

//init the reception of 1 byte in

void SerialUartInit();

// Send a string via serial
void SerialUartSendString(char *ptr);
//config the hal serial uart recevie it
void SerialUartReceiveEnable(uint8_t buff[50],uint8_t length);
//Send Variable Via Serial
void SerialUartSendVarInt(char *Text,float var);
//Interrupt request of receive data
void SerialUartReceiveIR();

//Receive commands
/*Fucntion to receive a starcommand and then process the comand*/

void SerialUartReceiveCommand(uint8_t Buff[50]);



#endif /* SERIAL_UART_H_ */
