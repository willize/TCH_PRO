#ifndef __ARM_CONTROL_H__
#define __ARM_CONTROL_H__

#include "sys.h"

#define  Air_OPEN()   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET)
#define  Air_CLOSE()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET)

#define  Glue_Mathine_Start() HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET)
#define  Glue_Mathine_Stop()  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET)

typedef struct
{
	int X_TInum;
	int Y_TInum;
	int Z_TInum;
	
	
}TI_num;

void Arm_Init(void);
void Arm_Control(float Xspeed, float Xangle, float Yspeed, float Yangle, float Zspeed, float Zhigh) ;
void X_Control(float Xangle);
void Y_Control( float Yangle);
void Z_Control(float Zhigh);




#endif 



