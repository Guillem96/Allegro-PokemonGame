#ifndef _TAIL_H_
#define _TAIL_H_

#include "types.h"

typedef struct S{
	FKM p;
	struct S *seg;
}NodeS;

typedef struct{
	NodeS *f;
	NodeS *l;
}Tail;

Tail Tail_create();
void Tail_add(Tail *t, FKM p);
FKM Tail_head(Tail t);
Tail Tail_delete(Tail t);
int Tail_empty(Tail t);
Tail Tail_destroy(Tail t);

#endif