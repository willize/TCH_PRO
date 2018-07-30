#include "SCARA_Alg.h"
#include "Motor.h"
#include <math.h>

#define PI 3.14  // π

const double Y_Long= 10.0f, X_Long=10.0f, Z_High=10.0f , R_High=3.0f;//各轴机械臂的长度，Z是竖直轴的长度。R_High为与x轴链接的夹具本身的高度

double XY_Angle, YZ_Angle ,Z_Coor_High;//逆解得到各轴需要运动的位置。Z_Coor_High为夹具需要移动的高度

double X_Coordinate, Y_Coordinate, Z_Coordinate; //机械臂

/*----------------------------计算电机的最大速度---------------------*/
//根据设置的最快电机每秒多少转（r/s） ，输出需要设定的定时器自动装载值ARR

u16 XY_Min_AutoReload,Z_Min_AutoReload;  //对应着电机最高速度
u16 XY_Max_AutoReload,Z_Max_AutoReload;

void Motor_Max_Speed()
{
	float XY_Pulses,Z_Pulses;
	XY_Pulses= XY_MOTOR_SPEED * XY_SUBDIVISION;
	XY_Min_AutoReload =(u16) 10000/XY_Pulses;
	
	Z_Pulses= Z_MOTOR_SPEED * XY_SUBDIVISION;
	Z_Min_AutoReload =(u16) 10000/Z_Pulses;
	
}

/**********************************************************************/
void X_Run_Contorl(float Dist)
{
	if (Dist >0)X_R_MOV();
	else if(Dist <0)X_L_MOV();
	
	X_Move_Angle(Dist);
	X_Start();	
}
void Y_Run_Contorl(float Dist)
{
	if (Dist >0)Y_R_MOV();
	else if(Dist <0)Y_L_MOV();
	
	Y_Move_Angle(Dist);
	Y_Start();	
}
void Z_Run_Contorl(float Dist)
{
	if (Dist >0)Z_UP_MOV();
	else if(Dist <0)Z_DOWN_MOV();
	
	Z_Move_High(Dist);
	Z_Set_Speed(10.0f);
	Z_Start();	
}


void SCARA_Control(float *X_Dist,float *Y_Dist,float *Z_Dist)
{ 
	printf("SCARA_Control!\r\n");
	X_Run_Contorl(*X_Dist);
	Y_Run_Contorl(*Y_Dist);
	Z_Run_Contorl(*Z_Dist);
}

void Coordinate_System(double XY_Angle,double YZ_Angle,double Z_Coor_High)
{
	X_Coordinate = Y_Long * cos(YZ_Angle) + X_Long * cos(XY_Angle+YZ_Angle);
	Y_Coordinate = Y_Long * sin(YZ_Angle) + X_Long * sin(XY_Angle+YZ_Angle);
	Z_Coordinate = Z_High + Z_Coor_High - R_High; 
}

void MechanicalArm_Anti_Solution(double X_Coor, double Y_Coor,double Z_Coor)
{
	double YZ_Coor_Except, YZ_acos_Operation0, YZ_acos_Operation1,
      	 YZ_acos_Operation2 ,YZ_acos_Operation,XY_acos_Operation1,
      	 XY_acos_Operation2 ,XY_acos_Operation;
	
	YZ_Coor_Except = Y_Coor / X_Coor ;
	
	YZ_acos_Operation0 = X_Coor*X_Coor + Y_Coor*Y_Coor;
	YZ_acos_Operation1 = X_Coor*X_Coor + Y_Coor*Y_Coor + Y_Long*Y_Long - X_Long*X_Long;
	YZ_acos_Operation2 = 2 * Y_Long *sqrt ( YZ_acos_Operation0 );
	YZ_acos_Operation  =YZ_acos_Operation1 / YZ_acos_Operation2 ;
	
	XY_acos_Operation1 = X_Coor*X_Coor + Y_Coor*Y_Coor - Y_Long*Y_Long - X_Long*X_Long;
	XY_acos_Operation2 = 2 * Y_Long * X_Long ;
	XY_acos_Operation  = XY_acos_Operation1 / XY_acos_Operation2;
	
	
	YZ_Angle = (atan (YZ_Coor_Except ) + acos (YZ_acos_Operation )) * 180.0 / PI;
	XY_Angle = acos ( XY_acos_Operation )* 180.0 / PI;
	Z_Coor_High = Z_Coor + Z_High - R_High;
}









