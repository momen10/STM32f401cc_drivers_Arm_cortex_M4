/*
 * NAME : WIFI_Interface.h
 *
 * Created on: Aug 29, 2023
 *
 * Author: Mo'men Ahmed
 */


#ifndef HAL_WIFI_WIFI_INTERFACE_H_
#define HAL_WIFI_WIFI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"



void HESP_vInit(void);
void HESP_u8ConnectWifi(u8 * username, u8 * password);
void HESP_u8ConnectWebsite(u8 * IP, u8 Portnum);
void HESP_u8SendData(u8 * url, u8 datalength);
u8 HESP_u8CheckValue(void);


#endif /* HAL_WIFI_WIFI_INTERFACE_H_ */
