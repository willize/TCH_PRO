/* Includes ------------------------------------------------------------------*/
#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "w25qxx.h"
#include "spi.h"
#include "main.h"
#include "hmi.h"

#include "SCARA_Alg.h"
#include "SCARA_Control.h"
#include "Motor.h"
#include "pwm.h"

/* Private function prototypes -----------------------------------------------*/
float Dis[3]={0,0,1000};
s8 Dir[3]={0,0,1};
	
const u8 Text_Buffer[]={"Mechainel_ARM Flash and SPI Text"};
#define BUF_SIZE sizeof(Text_Buffer)
/* Private functions ---------------------------------------------------------*/
extern TIM_HandleTypeDef htim13;
extern TIM_HandleTypeDef htim4;
extern u8 USART_RX_BUF[USART_REC_LEN];
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
	u32 FLASH_SIZE;       //W25Q16的储存空间
	u8 datatemp[BUF_SIZE];    //要读取的字符串
	u8 key=0;               //具体按键的返回值
	u8 i,j=0;
	u8 len=0;
	
  HAL_Init();

  /* Configure the System clock to 168 MHz */
  Stm32_Clock_Init(336,8,2,4);
  delay_init(168);                //初始化延时函数
  uart_init(115200);              //初始化USART
	LED_Init();                     //初始化LED 
  KEY_Init(); 	//初始化按键
  
	W25QXX_Init();
	SPI1_Init();

  Mechaical_Arm_Init();
	
	while (W25QXX_ReadID() != W25Q16)
	{
		delay_ms(1000);
		printf ("检测不到W25Q16\r\n");
		LED0=!LED0;
	}
	printf ("检测W25Q16成功\r\n");
	FLASH_SIZE=2*1024*1024;	//FLASH 大小为2M字节
	
  while (1)
  {
		key=KEY_Scan(0);
		if (key == KEY0_PRES)
		{
			printf ("写入W25Q16数据！\r\n");
			W25QXX_Write((u8*)Text_Buffer,FLASH_SIZE-100,BUF_SIZE);
			printf ("写入完毕！！\r\n");
		}
		if (key == KEY1_PRES)
		{
			//printf ("读取W25Q16数据！\r\n");
			//W25QXX_Read(datatemp,FLASH_SIZE-100,BUF_SIZE);
			//SCARA_Control( Dis,Dir);
			tran_3_0xff();
			//Z_Set_Speed(1.0f);
			//Z_Set_AutoReload(2000.0f);
			//HAL_TIM_PWM_Start(&htim13,TIM_CHANNEL_1);
			
//			for (j=0;j <= (BUF_SIZE-1); j++ )
//			{
//				delay_ms(20);
//				printf ("%c",datatemp[j]);
//			}
//			printf("\r\n");
		}
		i++;
		delay_ms(10);
		if (i==20)
		{
			LED1=!LED1;//提示系统正在运行	
			i=0;
		}	
	   if(USART_RX_STA&0x8000)
		{	
			//printf("fadong\r\n");
			len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
			//printf("\r\n您发送的消息为:\r\n");
			HAL_UART_Transmit(&UART1_Handler,(uint8_t*)USART_RX_BUF,len,1000);	//发送接收到的数据
			while(__HAL_UART_GET_FLAG(&UART1_Handler,UART_FLAG_TC)!=SET);		//等待发送结束
			//printf("\r\n\r\n");//插入换行

			Hmi_Commun();		
				
							
		}
  }
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
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
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
/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
