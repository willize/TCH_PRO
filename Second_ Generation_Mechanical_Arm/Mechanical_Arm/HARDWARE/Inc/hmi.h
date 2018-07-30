#ifndef HMI_H
#define HMI_H
#include "sys.h"

void Hmi_Commun(void);
void tran_3_0xff(void);
void tran_str(u8 *str,u8 i);

void Flash_Write(void);
#endif 


