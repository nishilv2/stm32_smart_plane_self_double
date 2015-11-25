#include "mymath.h"

double limit(double a,double max,double min)
{
	double b;
	if(a>max)
	{
		b=max;
	}
	else if(a<min)
	{
		b=min;
	}
	else
	{
		b=a;
	}
	return b;
}	