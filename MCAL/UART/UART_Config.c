/*
 * NAME :UART_Config.c
 *
 * Created on: Aug 23, 2023
 *
 * Author: Mo'men Ahmed
 */

#include "UART_Interface.h"

MUART_Config_t My_UART = {
	.WordLength = UART_8bits, .TransFlow= UART_TxRx, .StopBits = UART_1StopBit,
	.SampleBitMethod = UART_1SampleMethod, .ParitySelect = UART_EvenParity,
	.ParityControl = UART_ParityDisabled, .OverSample = UART_OverSample_8
	,.BaudRate = 9600
};

