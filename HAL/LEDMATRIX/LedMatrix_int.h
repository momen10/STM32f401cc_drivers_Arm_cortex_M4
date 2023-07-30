/*
 * LedMatrix_int.h
 *
 *  Created on: Jul 24, 2023
 *      Author: Dell
 */

#ifndef HAL_LEDMATRIX_LEDMATRIX_INT_H_
#define HAL_LEDMATRIX_LEDMATRIX_INT_H_

#include "../../LIB/STD_TYPES.h"

void HLEDMTX_vInit (void);
void HLEDMTX_vDisplayFrame (u8 frame[], u32 frame_delay);
// void HLEDMTX_vDisplayMatrix (u8 matrix[][8] , u32 matrix_delay);



#endif /* HAL_LEDMATRIX_LEDMATRIX_INT_H_ */
