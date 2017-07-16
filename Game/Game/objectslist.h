#ifndef _OBJECTLIST_H_
#define _OBJECTLIST_H_

#include "types.h"
#include "allegroguillem.h"

typedef struct O{
	Object o;
	struct O *seg;
}NodeO;

typedef struct{
	NodeO *f;
	NodeO *prv;
}Olist;


Olist Olist_create();
Olist Olist_insert(Olist ol, Object o);
Object Olist_consult(Olist ol);
Olist Atklist_delete(Olist ol);
Olist Olist_forward(Olist ol);
int Olist_empty(Olist ol);
int Olist_final(Olist ol);
Olist Olist_start(Olist ol);
Olist Olist_destroy(Olist ol);
int Olist_howmany(Olist ol);

#endif