#ifndef _TRINERLIST_H_
#define _TRINERLIST_H_

#include "types.h"
#include "allegroguillem.h"

typedef struct T{
	Trainer t;
	struct T *seg;
}NodeT;

typedef struct{
	NodeT *f;
	NodeT *prv;
}Tlist;




Tlist Tlist_create();
Tlist Tlist_insert(Tlist al, Trainer t);
Trainer Tlist_consult(Tlist al);
Tlist Tlist_delete(Tlist al);
Tlist Tlist_forward(Tlist al);
int Tlist_empty(Tlist al);
int Tlist_final(Tlist al);
Tlist Tlist_start(Tlist al);
Tlist Tlist_destroy(Tlist al);
int Tlist_howmany(Tlist tl);

#endif