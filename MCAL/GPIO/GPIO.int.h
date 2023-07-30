/*
 * GPIO.int.h
 *
 *  Created on: Jul 3, 2023
 *      Author: Mo'men Ahmed
 */

#ifndef MCAL_GPIO_GPIO_INT_H_
#define MCAL_GPIO_GPIO_INT_H_


#include "GPIO_prv.h"

typedef enum{
	Port_A, Port_B, Port_C
}GPIO_PortNum_t;

typedef enum{
	Pin0,  Pin1,  Pin2 , Pin3,
	Pin4,  Pin5,  Pin6 , Pin7,
	Pin8,  Pin9,  Pin10, Pin11,
	Pin12, Pin13, Pin14, Pin15
}GPIO_PinNum_t;

typedef struct{
	GPIO_PortNum_t Port_ID;
	GPIO_PinNum_t  Pin_ID;
	GPIO_Mode_t mode;
	GPIO_OutType_t output_type;
	GPIO_OutSpeed_t output_speed;
	GPIO_InputPullType_t input_pull_type;
	GPIO_AlternativeFunctions_t Alt_func;
}MGPIO_Config_t;

void MGPIO_vInit(MGPIO_Config_t* copy_Config_Struct);

void MGPIO_vSetPin(GPIO_PortNum_t copy_Port_ID, GPIO_PinNum_t copy_Pin_ID, GPIO_PinValues_t copy_Pin_value );

void MGPIO_vSetPinFast(GPIO_PortNum_t copy_Port_ID, GPIO_PinNum_t copy_Pin_ID,GPIO_PinValues_t copy_Pin_value );

u8 MGPIO_u8GetPin(GPIO_PortNum_t copy_Port_ID, GPIO_PinNum_t copy_Pin_ID );



#endif /* MCAL_GPIO_GPIO_INT_H_ */
