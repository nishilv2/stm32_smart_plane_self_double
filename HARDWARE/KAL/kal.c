#include "kal.h"
#include "delay.h"

KAL kal(KAL last,float nowdata)
{
	float Q;             //要设置的参数
	float R;             //要设置的参数
	float data_pre;
	float p_pre;
	float kg;
	KAL now;
	data_pre=last.data;
	p_pre=last.p+Q;
	kg=p_pre/(p_pre+R);
	now.data=data_pre+kg*(nowdata-data_pre);
	now.p=(1-kg)*p_pre;
	return now;
}
	
	