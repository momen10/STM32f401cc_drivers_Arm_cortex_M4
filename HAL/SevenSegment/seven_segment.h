/*
 * seven_segment.h
 *
 *  Created on: Jul 4, 2023
 *      Author: Dell
 */

#ifndef HAL_SEVEN_SEGMENT_H_
#define HAL_SEVEN_SEGMENT_H_

#include "../../MCAL/GPIO/GPIO.int.h"

//7 segment type options: 1- COMMON_ANODE  2- COMMON_CATHODE
typedef enum{
	COMMON_CATHODE, COMMON_ANODE
}Seven_segment_type;

typedef struct{
	Seven_segment_type type;
	GPIO_PortNum_t     A_Port;
	GPIO_PinNum_t      A_Pin;
	GPIO_PortNum_t     B_Port;
	GPIO_PinNum_t      B_Pin;
	GPIO_PortNum_t     C_Port;
	GPIO_PinNum_t      C_Pin;
	GPIO_PortNum_t     D_Port;
	GPIO_PinNum_t      D_Pin;
	GPIO_PortNum_t     E_Port;
	GPIO_PinNum_t      E_Pin;
	GPIO_PortNum_t     F_Port;
	GPIO_PinNum_t      F_Pin;
	GPIO_PortNum_t     G_Port;
	GPIO_PinNum_t      G_Pin;
	GPIO_PortNum_t     Dot_Port;
	GPIO_PinNum_t      Dot_Pin;
}Seven_segment_Config_t;

void Seven_seg_Init (Seven_segment_Config_t*);

void Led_A_On(Seven_segment_Config_t*);
void Led_B_On(Seven_segment_Config_t*);
void Led_C_On(Seven_segment_Config_t*);
void Led_D_On(Seven_segment_Config_t*);
void Led_E_On(Seven_segment_Config_t*);
void Led_F_On(Seven_segment_Config_t*);
void Led_G_On(Seven_segment_Config_t*);
void Led_Dot_On(Seven_segment_Config_t*);

void Display_Zero(Seven_segment_Config_t*);
void Display_One(Seven_segment_Config_t*);
void Display_Two(Seven_segment_Config_t*);
void Display_Three(Seven_segment_Config_t*);
void Display_Four(Seven_segment_Config_t*);
void Display_Five(Seven_segment_Config_t*);
void Display_Six(Seven_segment_Config_t*);
void Display_Seven(Seven_segment_Config_t*);
void Display_Eight(Seven_segment_Config_t*);
void Display_Nine(Seven_segment_Config_t*);

#endif /* HAL_SEVEN_SEGMENT_H_ */
