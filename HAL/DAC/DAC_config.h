/*
 * NAME : DAC_config.h
 *
 * Created on: Aug 21, 2023
 *      
 * Author: Mo'men Ahmed
 */

#ifndef HAL_DAC_DAC_CONFIG_H_
#define HAL_DAC_DAC_CONFIG_H_

/*        PORT OPTIONS:
 * 1- GPIO_Port_A    2- GPIO_Port_B    3- GPIO_Port_C
 * */
#define DAC_PORT_ID   GPIO_Port_A

/*        PIN OPTIONS:
 * 1- GPIO_Pin0    2- GPIO_Pin1    3- GPIO_Pin2  4- GPIO_Pin3
 * 5- GPIO_Pin4    6- GPIO_Pin5    7- GPIO_Pin6  8- GPIO_Pin7
 * 9- GPIO_Pin8    10- GPIO_Pin9   11- GPIO_Pin10 12- GPIO_Pin13
 * 13- GPIO_Pin12   14- GPIO_Pin13   15- GPIO_Pin14 16- GPIO_Pin15
 * */
#define DAC_BIT0_PIN   GPIO_Pin0
#define DAC_BIT1_PIN   GPIO_Pin1
#define DAC_BIT2_PIN   GPIO_Pin2
#define DAC_BIT3_PIN   GPIO_Pin3
#define DAC_BIT4_PIN   GPIO_Pin4
#define DAC_BIT5_PIN   GPIO_Pin5
#define DAC_BIT6_PIN   GPIO_Pin6
#define DAC_BIT7_PIN   GPIO_Pin7

#define DAC_RESOLUTION   8


#endif /* HAL_DAC_DAC_CONFIG_H_ */
