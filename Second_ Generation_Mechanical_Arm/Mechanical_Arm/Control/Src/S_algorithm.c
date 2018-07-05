#include "S_algorithm.h"
#include "timer.h"
#include <math.h>
#include "usart.h"

//CalaculateSModel_Accel(float fre[], unsigned short period[], float len, float fre_max, float fre_min, float flexible)

void CalaculateSModel_Accel(float fre[], unsigned short period[], float len, float fre_max, float fre_min, float flexible)
{
	int i=0;
	float deno;
	float melo;
	float delt = fre_max - fre_min;
	for ( ; i<len ; i++)
	{
		melo = flexible * (i-len/2) /(len/2);
		deno = 1.0 / (1+exp(-melo));
		fre [i] = delt * deno + fre_min;
		period[i] = (unsigned short)(1000000 / fre[i]);
	//	printf("加速次数:%d\r\n",i);
	//	printf("此时速度:%d\r\n\n",period[i]);
	}
	return ;	
}

void CalaculateSModel_Decel(float fre[], u16 period [], float len, float fre_max, float fre_min , float flexible) //flexible is 4 to 6 
{
	int i=0;
	float deno;
	float melo;
	float delt = fre_max - fre_min;
	for (;i<len; i++)
	{
		melo = flexible  * (i - len/2) / (len/2);
		deno = 1.0 / ( 1.0 + exp(-melo));
		fre [i]= fre_max - delt / deno;
		period[i]	= (unsigned short) (1000000 / fre[i]);
		
	//	printf("减速次数:%d\r\n",i);
	//	printf("此时速度:%d\r\n",period[i]);
	}
	
}

//void StartPWM()
//{
//    DriverMotorFlag = TRUE;
//    Index = 0;
//    
//    MOTOR_EN_DISABLE = ENABLE;
//    OpenOC4(OC_ON | OC_TIMER_MODE16 | OC_TIMER3_SRC | OC_PWM_FAULT_PIN_DISABLE, 0, 0);


//    // map rc13 to oc4 output
//    RPC13R = 11;


//    // 50 percent duty
//    OC4RS = OC_PERIOD_MIN / 2;
//    OpenTimer3(T3_ON | T3_PS_1_8, OC_PERIOD_MIN);


//    INTSetVectorPriority(INT_TIMER_3_VECTOR, INT_PRIORITY_LEVEL_6);
//    INTSetVectorSubPriority(INT_TIMER_3_VECTOR, INT_SUB_PRIORITY_LEVEL_1);
//    EnableIntT3;
//}

////stop motor, hereis no deceleration 

//void StopPWM()
//{
//    DriverMotorFlag = FALSE;
//    Index = 0;
//    
//    MOTOR_EN_DISABLE = DISENABLE;
//    OpenOC4(OC_OFF | OC_TIMER_MODE16 | OC_TIMER3_SRC | OC_PWM_FAULT_PIN_DISABLE, 0, 0);
//    // map rc13 to oc4 output
//    RPC13R = 0;
//    PORTCbits.RC13 = 0;
//    
//    CloseTimer3();
//    DisableIntT3;
//}


//static unsigned short CountForAcc = 0;
//void __ISR(_TIMER_3_VECTOR, ipl6) Timer3OutHandler(void)
//{
//    // clear the interrupt flag, or the interrupt will not occur again.
//    mT3ClearIntFlag();

//    if(CountForAcc++ > 2)    // here can adjust the totally time of acceleration
//    {
//        CountForAcc = 0;
//        //if(DriverMotorFlag == TRUE && PR3 > OC_PERIOD_MAX + SPEED_STEP)
//        if(DriverMotorFlag == TRUE && Index < ACC_TIMES)
//        {
//            PR3 = Period[Index++];
//            OC4RS = PR3 / 2;
//        }
//    }
//}

//CalculateSModelLine(Freq, Period, 1000, 56000, 16000, 4);

//CalculateSModelLine(Freq, Period, 1000, 64000, 500, 8);

//CalculateSModelLine(Freq, Period, 1000, 64000, 500, 15);

//CalculateSModelLine(Freq, Period, 1000, 40000, 500, 5);

//float time[]={5.0f, 4.5f, 4.0f, 3.5f, 3.0f, 2.5f, 2.0f, 1.5f, 1.0f, 0.5f  };
////u16   accl[]={6250, 5625, 5000, 4375, 3750, 3125, 2500, 1875, 1250, 625   };
//u8    num []={  8 ,  9  ,   10,  12 ,  14 ,  16 ,  20 ,  27 ,  40 ,  80   };

//u8 accl_long=106;
//#define MAX_SPEED  0.5
//#define MIN_SPEED  5

//float   time_gap =0.05;
//float   accl_time=0.5;

