/*
 * NAME :seven_segment.h
 *
 * Created on: Jul 4, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef HAL_SEVEN_SEGMENT_H_
#define HAL_SEVEN_SEGMENT_H_

#include "../../MCAL/GPIO/GPIO_int.h"

//A IF LSB               GFEDCBA
#define  ZERO_SS      0b00111111
#define  ONE_SS       0b00000110
#define  TWO_SS       0b01011011
#define  THREE_SS     0b01001111
#define  FOUR_SS      0b01100110
#define  FIVE_SS      0b01101101
#define  SIX_SS       0b01111101
#define  SEVEN_SS     0b00000111
#define  EIGHT_SS     0b01111111
#define  NINE_SS      0b01101111

#define DIRECT_METHPD   0
#define S2P_METHOD      1

/*OPTIONS
 * 1- DIRECT_METHOD      2- S2P_METHOD*/
#define SEV_SEG_METHOD  S2P_METHOD

#if   SEV_SEG_METHOD == DIRECT_METHOD
#define SEV_SEG_PINS   8
#elif SEV_SEG_METHOD == S2P_METHOD
#define SEV_SEG_PINS   3
#endif

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
	GPIO_PortNum_t     Com_Port;
	GPIO_PinNum_t      Com_Pin;
}Seven_segment_Config_t;

void SevSeg_vInit(void);

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

void Display_Number(Seven_segment_Config_t* , u8 num);
void TurnOff(Seven_segment_Config_t* );
void TurnOn(Seven_segment_Config_t*);

#endif /* HAL_SEVEN_SEGMENT_H_ */
