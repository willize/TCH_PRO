#include "hmi.h"
#include "main.h"
#include "usart.h"
#include "main.h"
#include "Motor.h"
#include "delay.h"
#include "w25qxx.h"

extern UART_HandleTypeDef UART1_Handler; 
extern u8 USART_RX_BUF[USART_REC_LEN];   
extern u8 Teach_Status_flag;
extern u8 Run_status_flag;

extern float Dist[3][100];

u8 X_Dir,Y_Dir,Z_Dir;  //向左为负，向右为正，向下为正；
extern u16 Z_Num,Y_Num,X_Num; 

static u8 i=0;//运动点数
extern u8 max_run_point;

odom 	downl_x,
			downl_y,
			downl_z,
			X_odom,
			Y_odom,
			Z_odom;

Odometer Teach_Odom;
void Hmi_Commun()
{
  static u8 *data = USART_RX_BUF;
	if (USART_RX_STA&0x8000) //数据接收完成
	{		
		USART_RX_STA=0;
		switch (*(data+1)) //页数查询
		{
			case 0x02:
									if (*(data+2)== 0x01 && *(data+3)== 0x02 && *(data+4)== 0x01 )
									{
										delay_ms(10);
										u8 str[]={"page 3"};
										tran_str(str,6);
										tran_3_0xff();
										Teach_Status_flag=1;
										Run_status_flag=0;	
									}
				break;
			/*----------------------手动调试页面-------------------*/
			case 0xa3:   //手动调试页
									switch (*(data+2))
									{
										case 0x01:  //行数
																if (*(data+3) == 0x01) //列数
																{
																	if (*(data+4)== 0x01) 
																	{
																		X_R_MOV();
																		X_Set_Speed(0.1f);
																		X_Start();

																	}else if (*(data+4)== 0x00)
																		{
																			X_Stop();
																			Teach_Odom.X_Odom += X_Num;
																			X_Num=0;
																		}
																	
																}else if (*(data+3) == 0x02)
																{
																	if (*(data+4)== 0x01) //按键状态，1为按下
																	{
																		X_L_MOV();
																		X_Set_Speed(0.1f);
																		X_Start();

																	}else if (*(data+4)== 0x00)
																		{
																			X_Stop();
																			Teach_Odom.X_Odom -= X_Num;
																			X_Num=0;
																		}
																}
											        
											  break;
										case 0x02:  //行2
																if (*(data+3) == 0x01) //列数1
																{
																	if (*(data+4)== 0x01) 
																	{
																		printf("Y轴移动\r\n");
																		Y_R_MOV();
																		Y_Set_Speed(0.1f);
																		Y_Start();

																	}else if (*(data+4)== 0x00)
																		{
																			Y_Stop();
																			Teach_Odom.Y_Odom += Y_Num;
																			Y_Num=0;
																		}
																	
																}else if (*(data+3) == 0x02)
																{
																	if (*(data+4)== 0x01) //按键状态，1为按下
																	{
																		Y_L_MOV();
																		Y_Set_Speed(0.1f);
																		Y_Start();

																	}else if (*(data+4)== 0x00)
																		{
																			Y_Stop();
																			Teach_Odom.Y_Odom -= Y_Num;
																			Y_Num=0;
																		}
																}
															
												break;
										case 0x03:
																if (*(data+3) == 0x01) //列数1
																{
																	if (*(data+4)== 0x01) 
																	{
																		Z_DOWN_MOV();
																		Z_Set_Speed(0.1f);
																		Z_Start();

																	}else if (*(data+4)== 0x00)
																		{
																			Z_Stop();
																			Teach_Odom.Z_Odom += Z_Num;
																			Z_Num=0;
																		}
																	
																}else if (*(data+3) == 0x02)
																{
																	if (*(data+4)== 0x01) //按键状态，1为按下
																	{
																		Z_UP_MOV();
																		Z_Set_Speed(0.1f);
																		Z_Start();

																	}else if (*(data+4)== 0x00)
																		{
																			Z_Stop();
																			Teach_Odom.Z_Odom -= Z_Num;
																			Z_Num=0;
																			
																		}
																}											
		
												break;
									}
											
				break;				
			/******************手动确认运动点*********************/																
			 case 0xa4:
									if (*(data+2)== 0x01 && *(data+3)== 0x01 && *(data+4)== 0x00 )//机械臂移动点位
									{
										i++;                             //这个在退出调试时要置零啊 ,还要将他输出到最大运动点上。
										X_odom.Dist[i]=Teach_Odom.X_Odom;
										Y_odom.Dist[i]=Teach_Odom.Y_Odom;
										Z_odom.Dist[i]=Teach_Odom.Z_Odom;
										Teach_Odom.X_Odom = 0;
										Teach_Odom.Y_Odom = 0;
										Teach_Odom.Z_Odom = 0;
									}
				break;
			/*------------------            --------------------*/
									
									
			/*------------------退出调试界面--------------------*/
			 case 0xa6:
									if(*(data+2)== 0x01 && *(data+3)== 0x01 && *(data+4)== 0x00 )
									{
										max_run_point=i;
										i=0;
										Flash_Write();
										
									}
			 
				break;
									
		} 
	}
		
}

void tran_str(u8 *str, u8 i)
{
	
	HAL_UART_Transmit(&UART1_Handler,str,i,0xff);
	
}
void tran_3_0xff()
{
	
	u8 Tail[3]={ 0xff ,0xff ,0xff };
	HAL_UART_Transmit(&UART1_Handler,Tail,3,0xff);
	
}

void Flash_Write()
{
	
	W25QXX_Write(X_odom.dist,100,200);
	W25QXX_Write(Y_odom.dist,400,200);
	W25QXX_Write(Z_odom.dist,700,200);
	
}
