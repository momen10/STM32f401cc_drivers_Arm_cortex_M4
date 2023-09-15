/*
 * NAME : IR_config.h
 *
 * Created on: Aug 22, 2023
 * 
 * Author: Mo'men Ahmed 
 */

#ifndef HAL_IR_IR_CONFIG_H_
#define HAL_IR_IR_CONFIG_H_

/*        PORT OPTIONS:
 * 1- GPIO_Port_A    2- GPIO_Port_B    3- GPIO_Port_C
 * */
#define   IR_PORT_ID  GPIO_Port_A

/*        PIN OPTIONS:
 * 1- GPIO_Pin0    2- GPIO_Pin1    3- GPIO_Pin2  4- GPIO_Pin3
 * 5- GPIO_Pin4    6- GPIO_Pin5    7- GPIO_Pin6  8- GPIO_Pin7
 * 9- GPIO_Pin8    10- GPIO_Pin9   11- GPIO_Pin10 12- GPIO_Pin13
 * 13- GPIO_Pin12   14- GPIO_Pin13   15- GPIO_Pin14 16- GPIO_Pin15
 * */
#define   IR_PIN_ID   GPIO_Pin0


/*       EXTI LINE OPTIONS :
 * 1- EXTI_LIN0    2- EXTI_LIN1  3- EXTI_LIN2   4- EXTI_LIN3
 * 5- EXTI_LIN4    6- EXTI_LIN5  7- EXTI_LIN6   8- EXTI_LIN7
 * 9- EXTI_LIN8    10-EXTI_LIN9  11-EXTI_LIN10  12-EXTI_LIN11
 * 13-EXTI_LIN12   14-EXTI_LIN13 15-EXTI_LIN14  16-EXTI_LIN15
 * */
#define   IR_EXTI_LINE    EXTI_LIN0


#endif /* HAL_IR_IR_CONFIG_H_ */
