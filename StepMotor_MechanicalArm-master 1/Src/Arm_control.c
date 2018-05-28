#include "Arm_control.h"
#include "Motor_Control.h"

void Arm_Init()
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	
	xyz_Set_speed(1000);
	xyz_Distance(1000);
	
	while (HAL_GPIO_ReadPin(GPIOE,X_L_Limit_Pin|X_R_Limit_Pin)
	
}
