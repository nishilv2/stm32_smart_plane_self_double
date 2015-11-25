#ifndef __PID_H
#define __PID_H
#include "sys.h"

typedef struct PID1
{
	double Pro;        //比例系数  
	double Int;        //积分系数
	double Der;        //微分系数
	
	
	double int_error;
	double der_error;
	double last_error;
	double now_error;
}PID1;

PID1 pid_set1(double Pro,double Int,double Der);
double pid_cal1(PID1 pid,double point,double setpoint);


typedef struct PID2
{
	double k1;          
	double k2;        
	double k3;        
	
	
  double last2_error;
	double last1_error;
	double now_error;
}PID2;

PID2 pid_set2(double Pro,double Int,double Der);
double pid_cal2(PID2 pid,double point,double setpoint);
#endif
