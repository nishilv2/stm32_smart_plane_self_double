#include "ctrl.h"
#include "pid.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include "pwm.h"
#include "mymath.h"
#include "usart.h"

float pitch,roll,yaw; 		//欧拉角
short aacx,aacy,aacz;		//加速度传感器原始数据
short gyrox,gyroy,gyroz;	//陀螺仪原始数据
void ctrl1(ITEM exp_point)
{
	double k=0.4;
	
	PID1 pid_pitch;
	PID1 pid_roll;
	PID1 pid_yaw;
	
	PID1 pid_omegax;
	PID1 pid_omegay;
	PID1 pid_omegaz;
	
	double pid_pitch_out=0;
	double pid_roll_out=0;
	double pid_yaw_out=0;
	double pid_omegax_in=0;
  double pid_omegay_in=0;
  double pid_omegaz_in=0;	
	double pid_omegax_out=0;
	double pid_omegay_out=0;
	double pid_omegaz_out=0;
	double omegax=0;
	double omegay=0;
	double omegaz=0;
	OUTPUT all_out;
	OUTPUT all_out_f;
	
	pid_pitch=pid_set1(1.1,2.2,3.3);
	pid_roll=pid_set1(0,0,0);
	pid_yaw=pid_set1(1.1,2.2,3.3);
	
	pid_omegax=pid_set1(1.1,2.2,3.3);
	pid_omegay=pid_set1(10,0,0);
	pid_omegaz=pid_set1(1.1,2.2,3.3);
	
	if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
	{ 
//		temp=MPU_Get_Temperature();	//得到温度值
		MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
		MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
	}
	printf("%d\r\n",pitch);
  printf("%d\r\n",gyroy);
	printf("%d\r\n",gyroz);
	printf("aaa\r\n");
	
	if((pitch<50)&&(pitch>-50)&&(roll<50)&&(roll>-50))
	{	
	omegax=((double)gyrox+26.00)/16.4;
	omegay=((double)gyroy+26.00)/16.4;
	omegaz=((double)gyroz+26.00)/16.4;
	

	pid_pitch_out=pid_cal1(pid_pitch,pitch,exp_point.pitch);
	pid_roll_out=pid_cal1(pid_roll,roll,exp_point.roll);
	pid_yaw_out=pid_cal1(pid_yaw,yaw,exp_point.yaw);
	
	pid_omegax_in=omegax-k*pid_pitch_out;
	pid_omegay_in=omegay-k*pid_roll_out;
	pid_omegaz_in=omegaz-k*pid_yaw_out;
	
	pid_omegax_out=pid_cal1(pid_omegax,pid_omegax_in,0);
	pid_omegay_out=pid_cal1(pid_omegay,pid_omegay_in,0);
	pid_omegaz_out=pid_cal1(pid_omegaz,pid_omegaz_in,0);
	
	pid_omegax_out=0;
//	pid_omegay_out=0;
	pid_omegaz_out=0;
	
//	all_out.back_thr=exp_point.thr+pid_omegax_out-pid_omegay_out+pid_omegaz_out;
//	all_out.head_thr=exp_point.thr+pid_omegax_out+pid_omegay_out+pid_omegaz_out;
//	all_out.left_thr=exp_point.thr-pid_omegax_out-pid_omegay_out-pid_omegaz_out;
	all_out.right_thr=exp_point.thr-pid_omegax_out+pid_omegay_out-pid_omegaz_out;
	
//	  all_out_f.back_thr=limit(all_out.back_thr,1000,500);
//	  all_out_f.head_thr=limit(all_out.head_thr,1000,500);
//	  all_out_f.left_thr=limit(all_out.left_thr,1000,500);
		all_out_f.right_thr=limit(all_out.right_thr,1000,500);	
	}
	else
	{
//		all_out.back_thr=500;
//		all_out.head_thr=500;
//		all_out.left_thr=500;
		all_out.right_thr=500;		
	}
}

ITEM set_point(double pitch,double roll,double yaw,u16 thr)
{
	ITEM point;
	point.pitch=pitch;
	point.roll=roll;
	point.yaw=yaw;
	point.thr=thr;
	
	return point;
}
