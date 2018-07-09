#include "Limit.h"
#include "main.h"


void Limit_Init()
{
	 GPIO_InitTypeDef GPIO_Initure;
   __HAL_RCC_GPIOD_CLK_ENABLE();           //����GPIOBʱ��
	
	GPIO_Initure.Pin= X_L_LIMIT_PIN | X_R_LIMIT_PIN | Y_L_LIMIT_PIN |
										Y_R_LIMIT_PIN | Z_UP_LIMIT_PIN |Z_DOWN_LIMIT_PIN; //
	
	GPIO_Initure.Mode=GPIO_MODE_IT_RISING ;  //�ⲿ�ж�
	GPIO_Initure.Pull=GPIO_PULLDOWN;          //����
	GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //����
	HAL_GPIO_Init(X_L_LIMIT_GPIO,&GPIO_Initure);
}

