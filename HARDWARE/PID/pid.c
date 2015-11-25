#include "pid.h"

PID1 pid_set1(double Pro,double Int,double Der)
{
	PID1 pid;
	pid.Pro=Pro;
	pid.Int=Int;
	pid.Der=Der;
	
  pid.int_error=0;
	pid.der_error=0;
	pid.last_error=0;
	pid.now_error=0;
	return pid;
}


double pid_cal1(PID1 pid,double point,double setpoint)
{

	double Pro=pid.Pro;
	double Int=pid.Int;
	double Der=pid.Der;
	double output;
	pid.now_error=setpoint-point;
	
	
	
	pid.int_error+=pid.now_error;
	pid.der_error+=pid.last_error-pid.now_error;
	output=Pro*pid.now_error+Int*pid.int_error+Der*pid.der_error;
	pid.last_error=pid.now_error;
	
	return output;

}


PID2 pid_set2(double Pro,double Int,double Der)
{
  PID2 pid;
	pid.k1=Pro;
	pid.k2=Int;
	pid.k3=Der;
	

	pid.last2_error=0;
	pid.last1_error=0;
	pid.now_error=0;
	return pid;
}

double pid_cal2(PID2 pid,double point,double setpoint)
{
	double k1=pid.k1;
	double k2=pid.k2;
	double k3=pid.k3;
	double output;
	pid.now_error=setpoint-point;
	
	
	output=k1*pid.now_error+k2*pid.last1_error+k3*pid.last2_error;
	pid.last2_error=pid.last1_error;
	pid.last1_error=pid.now_error;
	return output;
}