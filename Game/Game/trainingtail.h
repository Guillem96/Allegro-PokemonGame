#ifndef _TRAININGTAIL_H_
#define _TRAININGTAIL_H_

#include "types.h"
#include "allegroguillem.h"

typedef struct T{
	FKM f;
	struct 
		T*seg;
}NodeF;

typedef struct{
	NodeF *f;
	NodeF *prv;
}Ttail;

Ttail Tail_create();
Ttail 