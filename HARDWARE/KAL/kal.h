#ifndef __KAL_H
#define __KAL_H
#include "sys.h"

typedef struct KAL
{
	float data;
	float p;
}KAL;

KAL kal(KAL last,float nowdata);

#endif