#ifndef __TIM_H__
#define __TIM_H__

#include "sys.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim12;


void MX_TIM1_Init(void);

void MX_TIM2_Init(u16 pre, u16 arr); //Z轴
void MX_TIM3_Init(u16 pre, u16 arr); //Y轴
void MX_TIM4_Init(u16 pre, u16 arr); //X轴

void MX_TIM5_Init(u16 pre, u16 arr); //Z轴定时
void MX_TIM12_Init(void);
void MX_TIM6_Init(u16 pre, u16 arr); //Y轴定时
void MX_TIM7_Init(u16 pre, u16 arr); //X轴定时

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);


#endif

