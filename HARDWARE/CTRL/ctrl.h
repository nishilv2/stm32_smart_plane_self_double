#ifndef __CTRL_H
#define __CTRL_H
#include "sys.h"

typedef struct ITEM
{
	double pitch;
	double roll;
	double yaw;
	
	u16 thr;
}ITEM;
	
ITEM set_point(double pitch,double roll,double yaw,u16 thr);
void ctrl1(ITEM exp_point);

#endif