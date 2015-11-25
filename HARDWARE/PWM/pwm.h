#ifndef _TIMER1_H
#define _TIMER1_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//定时器 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/6/16
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	
typedef struct OUTPUT
{
	u16 left_thr;
	u16 right_thr;
	u16 head_thr;
	u16 back_thr;
}OUTPUT;


void TIM11_PWM_Init(u32 arr,u32 psc);
void TIM10_PWM_Init(u32 arr,u32 psc);
void TIM9_PWM_Inita(u32 arr,u32 psc);
void TIM9_PWM_Initb(u32 arr,u32 psc);

void pwm_out(OUTPUT all_out);
#endif
