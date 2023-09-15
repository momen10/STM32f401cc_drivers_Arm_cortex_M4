/*
 * NAME : WIFI_Prog.c
 *
 * Created on: Aug 29, 2023
 *
 * Author: Mo'men Ahmed
 */


#include "WIFI_Interface.h"
#include "WIFI_Config.h"
#include "WIFI_Prv.h"

#include "../../MCAL/UART/UART_Interface.h"
#include "../../MCAL/SYSTICK/SYSTICK_int.h"

u8 *test_cmd = "AT\r\n";
u8 *echo_off_cmd = "ATE0\r\n";
u8 *mode_cmd ="AT+CWMODE=1\r\n";

static u8 ESP_u8ValidateData(void)
{
	u8 RecState=0;
	u8 Local_u8RecString[100]={0};
	MUSART_vReceiveStringSynchNonBlocking(UART1,Local_u8RecString,100);
	for(u8 i=0; i<100; i++)
	{
		if(Local_u8RecString[i] == 'O' && Local_u8RecString[i+1] == 'K')
		{
           RecState = 1;
           break;
		}
	}
	return RecState;
}

u8 HESP_u8CheckValue(void)
{
	u8 RecValue=5;
	u8 Local_u8RecString[100]={0};
	MUSART_vReceiveStringSynchNonBlocking(UART1,Local_u8RecString,100);
	for(u8 i=0; i<100; i++)
	{
		if(Local_u8RecString[i] == 'I' && Local_u8RecString[i+1] == 'P' && Local_u8RecString[i+1] == 'D')
		{
           RecValue = Local_u8RecString[i+6];
           break;
		}
	}
	return RecValue;
}

void HESP_vInit(void)
{
    MUART_vInit(UART1);
    //0- SEND TEST
//    do{
//    	MUART_vTransmitString(UART1,"AT\r\n");
    MUART_vTransmitByteSynch(UART1,'A');
    MUART_vTransmitByteSynch(UART1,'T');
    MUART_vTransmitByteSynch(UART1,'\r');
    MUART_vTransmitByteSynch(UART1,'\n');

//    	MSTK_vDelayms(500);
//    }while(ESP_u8ValidateData() == 0);

	//1- DISABLE THE ECHO
//    do
//    {
    	MUART_vTransmitString(UART1,"ATE0\r\n");
//    	MSTK_vDelayms(500);
//    }while(ESP_u8ValidateData() == 0);

	//2-SET STATION MODE (1)
//    do
//    {
    	MUART_vTransmitString(UART1,"AT+CWMODE=1\r\n");
//    	MSTK_vDelayms(500);
//    }while(ESP_u8ValidateData() == 0);
}

void HESP_u8ConnectWifi(u8 * username, u8 * password)
{
//	do
//	{
		MUART_vTransmitString(UART1,(u8*)"AT+CWJAP_CUR=\"");
		MUART_vTransmitString(UART1,username);
		MUART_vTransmitString(UART1,(u8*)"\",\"");
		MUART_vTransmitString(UART1,password);
		MUART_vTransmitString(UART1,(u8*)"\"\r\n");
//		MSTK_vDelayms(500);
//	}while(ESP_u8ValidateData() == 0);
}


void HESP_u8ConnectWebsite(u8 * IP, u8 Portnum)
{
//   do
//   {
	   MUART_vTransmitString(UART1, (u8*)"AT+CIPSTART=\"TCP\",\"");
	   MUART_vTransmitString(UART1,IP);
	   MUART_vTransmitString(UART1,(u8*)"\",");
	   MUART_vTransmitString(UART1,Portnum);
	   MUART_vTransmitString(UART1,(u8*)"\r\n");
	   MSTK_vDelayms(500);
//   }while(ESP_u8ValidateData() == 0);
}

void HESP_u8SendData(u8 * url, u8 datalength)
{
//	do
//	{
		MUART_vTransmitString(UART1, (u8*)"AT+CIPSEND=");
		MUART_vTransmitString(UART1,datalength);
		MUART_vTransmitString(UART1,(u8*)"\r\n");
		MSTK_vDelayms(500);
//	}while(ESP_u8ValidateData() == 0);

//	do
//	{
		MUART_vTransmitString(UART1 ,(u8*)">GET \"");
		MUART_vTransmitString(UART1,url);
		MUART_vTransmitString(UART1, (u8*)"\"\r\n");
		MSTK_vDelayms(500);
//	}while(ESP_u8ValidateData() == 0);
}
