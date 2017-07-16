#ifndef _ATKLIST_H_
#define _ATKLIST_H_

#include "types.h"
#include "allegroguillem.h"

typedef struct A{
	Attack a;
	struct A *seg;
}NodeA;

typedef struct{
	NodeA *f;
	NodeA *prv;
}Atklist;


Atklist Atklist_create();
Atklist Atklist_insert(Atklist al, Attack a);
Attack Atklist_consult(Atklist al);
Atklist Atklist_delete(Atklist al);
Atklist Atklist_forward(Atklist al);
int Atklist_empty(Atklist al);
int Atklist_final(Atklist al);
Atklist Atklist_start(Atklist al);
Atklist Atklist_destroy(Atklist al);
Atklist Atklist_insertord(Atklist al, Attack a);


#endif