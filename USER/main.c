#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "timer.h"
#include "ctrl.h"
#include "pwm.h"
#include "exti.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 


//ALIENTEK ̽����STM32F407������ ʵ��8
//��ʱ���ж�ʵ��-�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK  
ITEM exp_point;
int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	EXTIX_Init(); 
	LED_Init();
  uart_init(115200);
  TIM10_PWM_Init(10000-1,336-1);	//84M/84=1Mhz�ļ���Ƶ��,��װ��ֵ500������PWMƵ��Ϊ 1M/500=2Khz.   
	TIM11_PWM_Init(10000-1,336-1);
	TIM9_PWM_Inita(10000-1,336-1);
	TIM9_PWM_Initb(10000-1,336-1);
 	//TIM3_Int_Init(5000-1,8400-1);	//��ʱ��ʱ��84M����Ƶϵ��8400������84M/8400=10Khz�ļ���Ƶ�ʣ�����5000��Ϊ500ms 
  exp_point=set_point(0,0,0,700);
	MPU_Init(); 
	while(mpu_dmp_init()){}
		printf("aaa\r\n");
	while(1)
	{
		LED0=!LED0;//DS0��ת
		delay_ms(200);//��ʱ200ms
	};
}
