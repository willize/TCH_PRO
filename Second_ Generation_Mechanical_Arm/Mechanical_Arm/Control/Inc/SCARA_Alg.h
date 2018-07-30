#ifndef __SCARA_ALG_H__
#define __SCARA_ALG_H__

#include "sys.h"

void Coordinate_System(double XY_Angle,double YZ_Angle,double Z_Coor_High);
void MechanicalArm_Anti_Solution(double X_Coor, double Y_Coor,double Z_Coor);

void X_Contorl(float Distance);
void Y_Contorl(float Distance);
void Z_Contorl(float Distance);
void SCARA_Control(float *X_Dist,float *Y_Dist,float *Z_Dist);
void Motor_Max_Speed(void);

#endif

