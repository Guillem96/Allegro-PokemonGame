#ifndef _FKMLIST_H_
#define _FKMLIST_H_

#include "types.h"
#include "allegroguillem.h"

typedef struct F{
	FKM f;
	struct F *seg;
}NodeF;

typedef struct{
	NodeF *f;
	NodeF *prv;
}Flist;



Flist Flist_create();
Flist Flist_insert(Flist fl, FKM f);
FKM Flist_consult(Flist fl);
Flist Flist_delete(Flist fl);
Flist Flist_forward(Flist fl);
int Flist_empty(Flist fl);
int Flist_final(Flist fl);
Flist Flist_start(Flist fl);
Flist Flist_destroy(Flist fl);
int Flist_howmanystarters(Flist fl);

#endif