#include "hmi.h"
#include "usart.h"
#include "main.h"
#include "Motor.h"
extern UART_HandleTypeDef UART1_Handler; 
extern u8 USART_RX_BUF[USART_REC_LEN];   

void Hmi_Commun()
{
  static u8 *data = USART_RX_BUF;
	if (USART_RX_STA&0x8000) //数据接收完成
	{		
		USART_RX_STA=0;
		switch (*(data+1)) //页数查询
		{
			/*----------------------手动调试页面-------------------*/
			case 0xa3:   //手动调试页
									switch (*(data+2))
									{
										case 0x01:  //行数
																if (*(data+3) == 0x01) //列数
																{
																	if (*(data+4)== 0x01) 
																	{
																		X_L_MOV();
																		X_Set_Speed(0.1f);
																		X_Start();

																	}else if (*(data+4)== 0x00)X_Stop();
																	
																}else if (*(data+3) == 0x02)
																{
																	if (*(data+4)== 0x01) //按键状态，1为按下
																	{
																		X_R_MOV();
																		X_Set_Speed(0.1f);
																		X_Start();

																	}else if (*(data+4)== 0x00)X_Stop();
																}
											        
											  break;
										case 0x02:  //行2
																if (*(data+3) == 0x01) //列数1
																{
																	if (*(data+4)== 0x01) 
																	{
																		printf("Y轴移动\r\n");
																		Y_L_MOV();
																		Y_Set_Speed(0.1f);
																		Y_Start();

																	}else if (*(data+4)== 0x00)Y_Stop();
																	
																}else if (*(data+3) == 0x02)
																{
																	if (*(data+4)== 0x01) //按键状态，1为按下
																	{
																		Y_R_MOV();
																		Y_Set_Speed(0.1f);
																		Y_Start();

																	}else if (*(data+4)== 0x00)Y_Stop();
																}
															
												break;
										case 0x03:
																if (*(data+3) == 0x01) //列数1
																{
																	if (*(data+4)== 0x01) 
																	{
																		Z_UP_MOV();
																		Z_Set_Speed(0.1f);
																		Z_Start();

																	}else if (*(data+4)== 0x00)Z_Stop();
																	
																}else if (*(data+3) == 0x02)
																{
																	if (*(data+4)== 0x01) //按键状态，1为按下
																	{
																		Z_DOWN_MOV();
																		Z_Set_Speed(0.1f);
																		Z_Start();

																	}else if (*(data+4)== 0x00)Z_Stop();
																}											
										
															
												break;
									}
											
				break;				
			/******************手动调试页码结束*********************/																
			 case 0xa4:
									
		
								
					break;
		} 
	}
		
}
void tran_str(u8 *str)
{
	
	HAL_UART_Transmit(&UART1_Handler,str,5,0xff);
	
}
void tran_3_0xff()
{
	u8 Tail[4]={ 0xff ,0xff ,0xff };
	HAL_UART_Transmit(&UART1_Handler,Tail,3,0xff);
	
}

void 

