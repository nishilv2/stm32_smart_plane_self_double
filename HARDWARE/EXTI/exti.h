#ifndef __EXTI_H
#define __EXIT_H	 
#include "sys.h"  	
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEK STM32F407������
//�ⲿ�ж� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/4
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

#define balence		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3)	//PE3 
#define start  		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2) //PE2


void EXTIX_Init(void);	//�ⲿ�жϳ�ʼ��		 					    
#endif
























