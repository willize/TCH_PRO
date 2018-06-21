#ifndef __MOTOR_CONTROL_H_
#define __MOTOR_CONTROL_H_

#include "sys.h"
#include "main.h"


#define X_L_MOV()      HAL_GPIO_WritePin(GPIOB, X_Dir_Pin, GPIO_PIN_SET)
#define X_R_MOV()      HAL_GPIO_WritePin(GPIOB, X_Dir_Pin, GPIO_PIN_RESET)

#define Y_L_MOV()      HAL_GPIO_WritePin(GPIOB, Y_Dir_Pin, GPIO_PIN_SET)
#define Y_R_MOV()      HAL_GPIO_WritePin(GPIOB, Y_Dir_Pin, GPIO_PIN_RESET)

#define Z_UP_MOV()     HAL_GPIO_WritePin(GPIOB, Z_Dir_Pin, GPIO_PIN_RESET)
#define Z_DOWN_MOV()   HAL_GPIO_WritePin(GPIOB, Z_Dir_Pin, GPIO_PIN_SET)

#define X_L_Linit     HAL_GPIO_ReadPin(GPIOE,X_L_Limit_Pin)
#define X_R_Linit     HAL_GPIO_ReadPin(GPIOE,X_R_Limit_Pin)

#define Y_L_Linit     HAL_GPIO_ReadPin(GPIOE,Y_L_Limit_Pin)
#define Y_R_Linit     HAL_GPIO_ReadPin(GPIOE,Y_R_Limit_Pin)

#define Z_UP_Linit     HAL_GPIO_ReadPin(GPIOE,Z_UP_Limit_Pin)
#define Z_D_Linit     HAL_GPIO_ReadPin(GPIOE,Z_D_Limit_Pin)


void Motor_Init(void);  // 初始化电机
void xyz_Set_speed(u16 speed);
void xy_Set_speed(u16 speed);
void x_Set_speed(u16 speed);
void y_Set_speed(u16 speed);
void z_Set_speed(u16 speed);
void xyz_Distance(u16 length);
void xy_Distance(u16 length);
void x_Distance(u16 length);
void y_Distance(u16 length);
void z_Distance(u16 length);



#endif



