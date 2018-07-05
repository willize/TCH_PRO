#include "pwm.h"
#include "main.h" 

TIM_HandleTypeDef htim10;
TIM_HandleTypeDef htim11;
TIM_HandleTypeDef htim13;

TIM_HandleTypeDef htim4;
extern void _Error_Handler(char *, int);

void X_PWM_Init(u16 pre, u16 arr)
{
	TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim10.Instance = TIM10;
  htim10.Init.Prescaler = pre;
  htim10.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim10.Init.Period = arr;
  htim10.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim10) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim10, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_Init(&htim10) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim10, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = arr/2;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim10, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

void Y_PWM_Init(u16 pre, u16 arr)
{
	TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim11.Instance = TIM11;
  htim11.Init.Prescaler = pre;
  htim11.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim11.Init.Period = arr;
  htim11.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim11) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim11, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_Init(&htim11) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim11, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = arr/2;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim10, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
}

void Z_PWM_Init(u16 pre, u16 arr)
{
	TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim13.Instance = TIM13;
  htim13.Init.Prescaler = pre;
  htim13.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim13.Init.Period = arr;
  htim13.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim13) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim13, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_Init(&htim13) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim13, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = arr/2;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim13, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
}


void TIM4_PWM_Init(u16 pre, u16 arr)
{
	TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim4.Instance = TIM4;
  htim4.Init.Prescaler = pre;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = arr;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = arr/2;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
	HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_2);
	HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3);
	HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_4);

}



void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	if (htim->Instance == TIM10)
	{
		GPIO_InitStruct.Pin = X_PWM_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull=GPIO_PULLUP;
		 GPIO_InitStruct.Alternate=GPIO_AF3_TIM10;
    HAL_GPIO_Init(X_PWM_GPIO, &GPIO_InitStruct);
		HAL_NVIC_SetPriority(TIM1_UP_TIM10_IRQn,1,0);    //设置中断优先级，抢占优先级1，子优先级3
		HAL_NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);          //开启ITM3中断		
		
	}
	if (htim->Instance == TIM11)
	{
		GPIO_InitStruct.Pin = Y_PWM_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull=GPIO_PULLUP;
		 GPIO_InitStruct.Alternate=GPIO_AF3_TIM11;
    HAL_GPIO_Init(Y_PWM_GPIO, &GPIO_InitStruct);
		
		HAL_NVIC_SetPriority(TIM1_TRG_COM_TIM11_IRQn,1,1);    //设置中断优先级，抢占优先级1，子优先级3
		HAL_NVIC_EnableIRQ(TIM1_TRG_COM_TIM11_IRQn);          //开启ITM3中断  
		
	}
	if (htim->Instance == TIM13)
	{
		GPIO_InitStruct.Pin = Z_PWM_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull=GPIO_PULLUP;
		 GPIO_InitStruct.Alternate=GPIO_AF9_TIM13;
    HAL_GPIO_Init(Z_PWM_GPIO, &GPIO_InitStruct);
		
		HAL_NVIC_SetPriority(TIM8_UP_TIM13_IRQn ,1,2);    //设置中断优先级，抢占优先级1，子优先级3
		HAL_NVIC_EnableIRQ(TIM8_UP_TIM13_IRQn );          //开启ITM3中断
	}
	if (htim->Instance == TIM4)
	{
		GPIO_InitStruct.Pin = PWM_1_PIN | PWM_2_PIN | PWM_3_PIN | PWM_4_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull=GPIO_PULLUP;
		GPIO_InitStruct.Alternate=GPIO_AF9_TIM13;
    HAL_GPIO_Init(PWM_1_GPIO, &GPIO_InitStruct);
		
		HAL_NVIC_SetPriority(TIM4_IRQn ,1,3);    //设置中断优先级，抢占优先级1，子优先级3
		HAL_NVIC_EnableIRQ(TIM4_IRQn);           //开启ITM3中断		
	}
	
}



