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


//ALIENTEK 探索者STM32F407开发板 实验8
//定时器中断实验-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK  
ITEM exp_point;
int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  //初始化延时函数
	EXTIX_Init(); 
	LED_Init();
  uart_init(115200);
  TIM10_PWM_Init(10000-1,336-1);	//84M/84=1Mhz的计数频率,重装载值500，所以PWM频率为 1M/500=2Khz.   
	TIM11_PWM_Init(10000-1,336-1);
	TIM9_PWM_Inita(10000-1,336-1);
	TIM9_PWM_Initb(10000-1,336-1);
 	//TIM3_Int_Init(5000-1,8400-1);	//定时器时钟84M，分频系数8400，所以84M/8400=10Khz的计数频率，计数5000次为500ms 
  exp_point=set_point(0,0,0,700);
	MPU_Init(); 
	while(mpu_dmp_init()){}
		printf("aaa\r\n");
	while(1)
	{
		LED0=!LED0;//DS0翻转
		delay_ms(200);//延时200ms
	};
}
