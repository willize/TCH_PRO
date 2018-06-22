
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
	*/
	
 // 物品栏之间相差 x 26.2f y 24.8f
 // y轴到第一个点位为：103.5f 
 // x轴到第一个点位为: 134.0f
 
/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */

#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "TIM.h"
#include "Arm_Control.h"
#include "Key_Limit.h"
#include "Motor_Control.h"
#include "S_algorithm.h"

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

DMA_HandleTypeDef hdma_usart1_rx;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
                        

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
u16 X_TI_stuta=0x0000;
u16 Y_TI_stuta=0x0000;
u16 Z_TI_stuta=0x0000;
u16 main_sta=0x0000;


extern 	u16 Z_num5;
extern 	u16	Y_num6;
extern 	u16	X_num7;

float  Z_Accel_Freq	 [1000]={0};
u16 	 Z_Accel_Period[1000]={0};
float  XY_Accel_Freq	[50]={0};
u16 	 XY_Accel_Period[50]={0};

static float Glue_Machine_High = 18.0f;
static float Down_Distance = 3.0f;
static float Y_Tool_Mov_Distance = 78.0f;
static float X_Tool_Groove_Distance = 26.2f;
static float Y_Tool_Groove_Distance = 24.8f;
static float Y_LR_Tool_Mov_Distance ;
static float Z_Improve = 5.0f;

u8 Z_downn_point_1=2;
u8 Z_downn_point_2=2;
u8 Z_downn_point_3=2;

u8 Z_downn_fla_1=0;
u8 Z_downn_fla_2=0;
u8 Z_downn_fla_3=0;
u16 start_key_fla=0;
//u16 	 Decel_Period[1000]={0};
/* USER CODE END 0 */

	/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
		Y_LR_Tool_Mov_Distance = Y_Tool_Mov_Distance - Y_Tool_Groove_Distance ;
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
   MX_TIM1_Init();
	 delay_init(168);
  /* USER CODE END Init */
	
  /* Configure the system clock */
   Stm32_Clock_Init(336,8,2,8);
  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
	uart_init(115200);
	CalaculateSModel_Accel(Z_Accel_Freq, Z_Accel_Period, 1000, 3200, 160, 4);
	CalaculateSModel_Accel(XY_Accel_Freq, XY_Accel_Period, 50, 800, 160, 5);
//	CalaculateSModel_Decel(Decel_Freq, Decel_Period, 1000, 160, 1600, 4);

  /* USER CODE BEGIN 2 */
		HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin, GPIO_PIN_RESET);
		delay_ms(1000);
	  HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin, GPIO_PIN_SET);
		delay_ms(1000);
		HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin, GPIO_PIN_RESET);
		delay_ms(1000);
	  HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin, GPIO_PIN_SET);
		delay_ms(1000);


	X_TI_stuta=0x0000;
  Y_TI_stuta=0x0000;
  Z_TI_stuta=0x0000;
  main_sta=0x0000;
	Arm_Init();
	//Motor_Init();   //MX_TIM4_Init( 83, 200);  //HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
	printf("Init_ok!!\r\n");
	

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		
		Limit_control();

			if ( (X_TI_stuta&0x0001) && (Y_TI_stuta&0x0001) && (Z_TI_stuta&0x0001)) //夹取右边的物品
			{
				if (start_key_fla>0)
				{
					if (main_sta&0x0001)
					{
						printf("main1!!\r\n");
						
						X_L_MOV();
						Y_R_MOV();
						Z_DOWN_MOV();
						delay_ms(1000);	
						Z_Control(27.0f); //z轴最长高度28
							delay_ms(1000);
						X_Control(134.0f);  //6bei
								delay_ms(50);
						Y_Control(103.5f);
						
						main_sta=0x0002;
					}
				}
			}
			
		if ( (X_TI_stuta&0x0002) && (Y_TI_stuta&0x0002) && (Z_TI_stuta&0x0002)) //放置右边的物品  
		{
			if (main_sta&0x0002)
			{
				printf("main2\r\n");
				Air_CLOSE();
				delay_ms(500);
				X_L_MOV();
				Y_L_MOV();
				Z_UP_MOV();
				
				Z_Control(Glue_Machine_High);
				delay_ms(2500);
				X_TI_stuta=0x0004; //6bei
				Y_Control(Y_Tool_Mov_Distance);
				
				main_sta=0x0004;
				Z_downn_point_1=1;
				
			}
		}
		/*****************加入下降点1******************************/
		if (( Z_downn_point_1==1) && ( Z_downn_fla_1==1))
		{
			
			delay_ms(500);
			Z_DOWN_MOV();
			Z_Control(Down_Distance);
			Z_downn_point_1=0;
		}
		
		
		if ( (X_TI_stuta&0x0004) && (Y_TI_stuta&0x0004) && (Z_TI_stuta&0x0004))//提升z轴
		{
			if (main_sta&0x0004)
			{	
				printf("main3\r\n");
				Air_OPEN();
				delay_ms(500);
				X_L_MOV();
				Y_R_MOV();
				Z_UP_MOV();
				
				Z_Control( Z_Improve );
				delay_ms(50);
				
				X_TI_stuta=0x0008;
				Y_TI_stuta=0x0008;
				main_sta=0x0008;
			}
		}
	
		if ( (X_TI_stuta&0x0008) && (Y_TI_stuta&0x0008) && (Z_TI_stuta&0x0008))//夹取左边的物品
		{
			
		if (main_sta&0x0008)
			{	
				printf("main4\r\n");
				delay_ms(500);
				X_R_MOV();
				Y_R_MOV();
				Z_DOWN_MOV();
				
				X_Control(X_Tool_Groove_Distance);
				Y_Control(Y_LR_Tool_Mov_Distance);
				delay_ms(1500);
				Z_Control((Glue_Machine_High + Z_Improve - Down_Distance));
				
				main_sta=0x0010;
				
			}	
		}
		if ( (X_TI_stuta&0x0010) && (Y_TI_stuta&0x0010) && (Z_TI_stuta&0x0010))//放置左边的物品
		{
			
			if (main_sta&0x0010)
				{	
					printf("main5\r\n");
					Air_CLOSE();
					delay_ms(500);
					X_R_MOV();
					Y_L_MOV();
					Z_UP_MOV();
					
					Z_Control(Glue_Machine_High);
					delay_ms(2500);
					X_TI_stuta=0x0020;//X_Control( 45.0f);
					Y_Control( Y_Tool_Mov_Distance);
					
					Z_downn_point_2=1;
			
					main_sta=0x0020;
					
				}	
		}
		/*****************加入下降点2******************************/
		if (( Z_downn_point_2==1) && ( Z_downn_fla_2==1))
		{

			delay_ms(500);
			Z_DOWN_MOV();
			Z_Control(Down_Distance);
			Z_downn_point_2=0;
			
		}
		
		
		
		if ( (X_TI_stuta&0x0020) && (Y_TI_stuta&0x0020) && (Z_TI_stuta&0x0020))//等待位置
		{
			
			if (main_sta&0x0020)
				{	
					printf("main6\r\n");
					Air_OPEN();
					delay_ms(500);
					X_L_MOV();
					Y_R_MOV();
					Z_UP_MOV();
					
					Z_Control(Z_Improve);
					delay_ms(1500);
					X_Control( 35.0f);
					Y_Control( 45.0f);
					HAL_TIM_Base_Start_IT(&htim5);    //等待区计时开始
					Glue_Mathine_Start();
					delay_ms(500);
					Glue_Mathine_Stop();
					main_sta=0x0040;
					
				}	
		}
	
				if ( (X_TI_stuta&0x0040) && (Y_TI_stuta&0x0040) && (Z_TI_stuta&0x0040))//夹取打胶右面的物品
				{
			
					if (main_sta&0x0040)
						{	
							HAL_TIM_Base_Stop_IT(&htim5);
							printf("main7\r\n");
							X_R_MOV();
							Y_L_MOV();
							Z_DOWN_MOV();
							
							X_Control( (35.0f-X_Tool_Groove_Distance));
							Y_Control( (45.0f-Y_Tool_Groove_Distance));						
						  delay_ms(1000);
							Z_Control( Z_Improve );
							
							main_sta=0x0080;
							
						}	
				}
				if ( (X_TI_stuta&0x0080) && (Y_TI_stuta&0x0080) && (Z_TI_stuta&0x0080))//提升z轴
				{
					
					if (main_sta&0x0080)
						{	
							printf("main8\r\n");
							Air_CLOSE();
							delay_ms(500);
							X_R_MOV();
							Y_L_MOV();
							Z_UP_MOV();
							
							X_TI_stuta=0x0100;//Z_Control(15.0f);
							Y_TI_stuta=0x0100;//X_Control( 45.0f);
							Z_Control( Z_Improve );

							main_sta=0x0100;
							
						}	
				}
				
	
				if ( (X_TI_stuta&0x0100) && (Y_TI_stuta&0x0100) && (Z_TI_stuta&0x0100))//放置打胶后右面的物品
				{
					
					if (main_sta&0x0100)
						{	
							printf("main4\r\n");
							
							X_R_MOV();
							Y_R_MOV();
							Z_DOWN_MOV();
								
							X_TI_stuta=0x0200;
							Y_Control( Y_Tool_Mov_Distance);
							delay_ms(2000);
							Z_Control( (Glue_Machine_High + Z_Improve - Down_Distance) );

							main_sta=0x0200;
							
						}	
				}
				if ( (X_TI_stuta&0x0200) && (Y_TI_stuta&0x0200) && (Z_TI_stuta&0x0200))//抓取打胶后左面的物品
				{
					
					if (main_sta&0x0200)
						{	
							printf("main4\r\n");
							Air_OPEN();
							delay_ms(500);
							X_R_MOV();
							Y_L_MOV();
							Z_UP_MOV();
							
							Z_Control( Glue_Machine_High );
							delay_ms(3000);
							X_Control( X_Tool_Groove_Distance);
							Y_Control( (Y_Tool_Mov_Distance + Y_Tool_Groove_Distance));
							
							Z_downn_point_3=1;
							main_sta=0x0400;
							
						}	
				}
				/*****************加入下降点******************************/
			if (( Z_downn_point_3==1) && ( Z_downn_fla_3==1))
			{

				delay_ms(1000);
				Z_DOWN_MOV();
				Z_Control(Down_Distance);
				Z_downn_point_3=0;
				
			}
				
				
				
				if ( (X_TI_stuta&0x0400) && (Y_TI_stuta&0x0400) && (Z_TI_stuta&0x0400))//提升z轴
				{
					
					if (main_sta&0x0400)
						{	
							printf("main4\r\n");
							Air_CLOSE();
							delay_ms(500);
							X_R_MOV();
							Y_L_MOV();
							Z_UP_MOV();
							
							Z_Control( Z_Improve );
							X_TI_stuta=0x0800;//X_Control( 45.0f);
							Y_TI_stuta=0x0800;//Y_Control( 75.0f);
				

							main_sta=0x0800;
							
						}	
				}
				
				if ( (X_TI_stuta&0x0800) && (Y_TI_stuta&0x0800) && (Z_TI_stuta&0x0800))//放置打胶后左面的物品
				{
					
					if (main_sta&0x0800)
						{	
							printf("main4\r\n");
							X_R_MOV();
							Y_R_MOV();
							Z_DOWN_MOV();
							
							X_TI_stuta=0x1000;//X_Control( 45.0f);
							Y_Control( Y_Tool_Mov_Distance);
							delay_ms(1500);
							Z_Control((Glue_Machine_High + Z_Improve - Down_Distance));

							main_sta=0x1000;
							
						}	
				}
				
					/*****************************初始化位置**********************************/
				if ( (X_TI_stuta&0x1000) && (Y_TI_stuta&0x1000) && (Z_TI_stuta&0x1000))//初始位置
				{
					
					if (main_sta&0x1000)
						{	
							
							Air_OPEN();
							delay_ms(1000);
							X_R_MOV();
							Y_L_MOV();
							Z_UP_MOV();
							X_TI_stuta=0x0000;
							Y_TI_stuta=0x0000;
							Z_TI_stuta=0x0000;
							main_sta=0x0000;
							Z_num5=0;
							Y_num6=0;
							X_num7=0;
							if (start_key_fla==1)
							{
								start_key_fla=0;
							}
							else
							{
								start_key_fla=1;
							}
							Arm_Init();
							
							main_sta=0x0001;
						}	
				}
			
				
//				if ( (X_TI_stuta&0x2000) && (Y_TI_stuta&0x2000) && (Z_TI_stuta&0x2000))//抓取右面物品
//				{
//					
//					if (main_sta&0x2000)
//						{	
//							printf("main4\r\n");
//							delay_ms(2000);
//							X_L_MOV();
//							Y_R_MOV();
//							Z_DOWN_MOV();
//							
//							
//							X_Control( (X_Tool_Groove_Distance - 20) );
//							Y_Control( (20 + Y_Tool_Groove_Distance) );
//							delay_ms(1000);
//							Z_Control(Z_Improve);

//							main_sta=0x0002;                                    //回到放置物品
//							
//						}	
//				}
				
			
		
			
	
		
	
	
	
		HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin, GPIO_PIN_RESET);
		


  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
    if (HAL_GPIO_ReadPin(GPIOE,G_key_Pin) == GPIO_PIN_RESET)   //开始键
		{
			delay_ms(20);
			if (HAL_GPIO_ReadPin(GPIOE,G_key_Pin) == GPIO_PIN_RESET)
			{
//							HAL_TIM_Base_Stop_IT(&htim5);
//				HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
//							HAL_TIM_Base_Stop_IT(&htim6);
//				HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
//							HAL_TIM_Base_Stop_IT(&htim7);
//				HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
					if(start_key_fla==0) main_sta=0x0001;		
					start_key_fla++;
			printf("Green_Key!!\r\n");
			
				while(HAL_GPIO_ReadPin(GPIOE,G_key_Pin) == GPIO_PIN_SET);
			}
		}
		
		if (HAL_GPIO_ReadPin(GPIOE,B_key_Pin) == GPIO_PIN_RESET)  //复位键
		{
			delay_ms(20);
			if (HAL_GPIO_ReadPin(GPIOE,B_key_Pin) == GPIO_PIN_RESET)
			{
				HAL_TIM_Base_Stop_IT(&htim2);
				HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
				HAL_TIM_Base_Stop_IT(&htim3);
				HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
				HAL_TIM_Base_Stop_IT(&htim4);
				HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
				HAL_TIM_Base_Stop_IT(&htim5);
				
					X_TI_stuta=0x0000;
					Y_TI_stuta=0x0000;
					Z_TI_stuta=0x0000;
					main_sta=0x0000;
				Z_num5=0;
				Y_num6=0;
				X_num7=0;
				start_key_fla=0;
				Air_OPEN();
				Arm_Init();
				printf("Black_Key!!\r\n");
				
				while (HAL_GPIO_ReadPin(GPIOE,B_key_Pin) == GPIO_PIN_SET);
			}
		}
		
		if (HAL_GPIO_ReadPin(GPIOE,R_key_Pin)== GPIO_PIN_RESET)  //停止
		{
			delay_ms(20);
			if (HAL_GPIO_ReadPin(GPIOE,R_key_Pin)== GPIO_PIN_RESET)
			{
			__HAL_TIM_DISABLE(&htim4);
			__HAL_TIM_DISABLE(&htim3);
			__HAL_TIM_DISABLE(&htim2);
			
			HAL_TIM_Base_Stop_IT(&htim4);
			HAL_TIM_PWM_Stop(&htim4, TIM_CHANNEL_1);
			HAL_TIM_Base_Stop_IT(&htim3);
			HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);			
			HAL_TIM_Base_Stop_IT(&htim2);
			HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);	

			printf("Red_Key!!\r\n");
				while(HAL_GPIO_ReadPin(GPIOE,R_key_Pin)== GPIO_PIN_SET);
			}
			
		}
  }
}
  /* USER CODE END 3 */
	



/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream2_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream2_IRQn, 0, 3);
  HAL_NVIC_EnableIRQ(DMA2_Stream2_IRQn);

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, Air_Open_Pin|GLUE_SW_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED1_Pin|LED2_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Z_Dir_Pin|X_Dir_Pin|X_En_Pin|Y_Dir_Pin 
                          |Y_En_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE, G_key_Pin|B_key_Pin|R_key_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(Z_En_GPIO_Port, Z_En_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : G_key_Pin B_key_Pin R_key_Pin */
  GPIO_InitStruct.Pin = G_key_Pin|B_key_Pin|R_key_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : Air_Open_Pin Air_Close_Pin */
  GPIO_InitStruct.Pin = Air_Open_Pin|GLUE_SW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	

  /*Configure GPIO pins : LED1_Pin LED2_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : X_L_Limit_Pin X_R_Limit_Pin Y_L_Limit_Pin Y_R_Limit_Pin 
                           Z_UP_Limit_Pin Z_D_Limit_Pin */
  GPIO_InitStruct.Pin = X_L_Limit_Pin|X_R_Limit_Pin|Y_L_Limit_Pin|Y_R_Limit_Pin 
                          |Z_UP_Limit_Pin|Z_D_Limit_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : Z_Dir_Pin Z_En_Pin X_Dir_Pin X_En_Pin 
                           Y_Dir_Pin Y_En_Pin */
  GPIO_InitStruct.Pin = Z_Dir_Pin|Z_En_Pin|X_Dir_Pin|X_En_Pin 
                          |Y_Dir_Pin|Y_En_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 2);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 3);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
