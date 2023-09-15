/*
 * NAME: TFT_prv.h
 *
 * Created on: Aug 25, 2023
 *
 * Author: Mo'men Ahmed
 */

#ifndef HAL_TFT_TFT_PRV_H_
#define HAL_TFT_TFT_PRV_H_

//TFT COMMANDS
#define TFT_SLEEPOUT_CMD   0x11
#define TFT_CLRMODE_CMD    0x3A
#define TFT_RGB565_MODE    0x05
#define TFT_DISPLAYON_CMD  0X29
#define TFT_SETX_CMD       0x2A
#define TFT_SETY_CMD       0x2B
#define TFT_IMGDATA_CMD    0x2c

//TFT LIMITS
#define TFT_XSTART         0
#define TFT_XEND           127
#define TFT_YSTART         0
#define TFT_YEND           159

#endif /* HAL_TFT_TFT_PRV_H_ */
