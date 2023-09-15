/*
 * NAME: TFT_config.h
 *
 * Created on: Aug 25, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef HAL_TFT_TFT_CONFIG_H_
#define HAL_TFT_TFT_CONFIG_H_

/*       OPTIONS FOR PORTS
 * 1- GPIO_Port_A  2- GPIO_Port_B  3-GPIO_Port_C*/

/*       OPTIONS FOR PINS
 * 	GPIO_Pin0, GPIO_Pin1, GPIO_Pin2 ,GPIO_Pin3,
	GPIO_Pin4, GPIO_Pin5, GPIO_Pin6 ,GPIO_Pin7,
	GPIO_Pin8, GPIO_Pin9, GPIO_Pin10,GPIO_Pin11,
	GPIO_Pin12,GPIO_Pin13,GPIO_Pin14,GPIO_Pin15
 * */

#define TFT_RESET_PORT    GPIO_Port_A
#define TFT_RESET_PIN     GPIO_Pin0
#define TFT_A0_PORT       GPIO_Port_A
#define TFT_A0_PIN        GPIO_Pin1


#endif /* HAL_TFT_TFT_CONFIG_H_ */
