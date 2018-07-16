#ifndef __PWM_H__
#define __PWM_H__


#include "sys.h"

void X_PWM_Init(u16 pre, u16 arr);
void Y_PWM_Init(u16 pre, u16 arr);
void Z_PWM_Init(u16 pre, u16 arr);
void TIM4_PWM_Init(u16 pre, u16 arr);

void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim);




#endif 



