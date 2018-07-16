#ifndef  __MOTOR_H__
#define  __MOTOR_H__

#include "sys.h"
#include "main.h"

#define  Z_SUBDIVISION 800
#define XY_SUBDIVISION 2000  //x y��ϸ����  ÿת2000������  Ҫ��100������ļӼ��ٹ��̣� ������30�ļ��ٱ� ��е�۵�xy����������Ҫ1.2�ȼӼ���
#define One_Pulse_Agle   (XY_SUBDIVISION / 360)
#define  REDUCTION_RATIO  30

#define X_L_MOV()  HAL_GPIO_WritePin(X_DIR_GPIO,X_DIR_PIN,GPIO_PIN_SET)	
#define X_R_MOV()  HAL_GPIO_WritePin(X_DIR_GPIO,X_DIR_PIN,GPIO_PIN_RESET)

#define Y_L_MOV()  HAL_GPIO_WritePin(Y_DIR_GPIO,Y_DIR_PIN,GPIO_PIN_SET)	
#define Y_R_MOV()  HAL_GPIO_WritePin(Y_DIR_GPIO,Y_DIR_PIN,GPIO_PIN_RESET)

#define Z_UP_MOV()    HAL_GPIO_WritePin(Z_DIR_GPIO,Z_DIR_PIN,GPIO_PIN_SET)
#define Z_DOWN_MOV()  HAL_GPIO_WritePin(Z_DIR_GPIO,Z_DIR_PIN,GPIO_PIN_RESET)

void Motor_Dir_GPIO_Init(void);

void X_Set_AutoReload(u16 AutoReload);
void Y_Set_AutoReload(u16 AutoReload);
void Z_Set_AutoReload(u16 AutoReload);

void X_Set_Speed(float speed);
void Y_Set_Speed(float speed);
void Z_Set_Speed(float speed);
void XY_Set_Speed(float X_speed,float Y_speed );
void XZ_Set_Speed(float X_speed,float Z_speed );
void YZ_Set_Speed(float Y_speed,float Z_speed );
void XYZ_Set_Speeed(float X_speed ,float Y_speed ,float Z_speed );

void X_Move_Angle(float Xangle);
void Y_Move_Angle(float Yangle);
void Z_Move_High(float Zhigh);
void X_Start(void);
void Y_Start(void);
void Z_Start(void);
void X_Stop(void);
void Y_Stop(void);
void Z_Stop(void);
void XYZ_Stop(void);
#endif

