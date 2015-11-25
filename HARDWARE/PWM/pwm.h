#ifndef _TIMER1_H
#define _TIMER1_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//��ʱ�� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/6/16
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
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
