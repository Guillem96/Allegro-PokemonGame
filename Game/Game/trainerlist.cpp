#include "trainerlist.h"

Tlist Tlist_create(){
	Tlist tl;
	
	tl.f = (NodeT*)malloc(sizeof(NodeT));
	if (tl.f == NULL){
		printf("\nList is not created");
	}
	else{
		(*(tl.f)).seg = NULL;
		tl.prv = tl.f;
	}
	return tl;
}

Tlist Tlist_insert(Tlist tl, Trainer t){
	NodeT *aux;
	aux = (NodeT*)malloc(sizeof(NodeT));
	if (aux == NULL){
		printf("\nInsert error");
	}
	else{
		(*aux).t = t;
		(*aux).seg = (*(tl.prv)).seg;
		(*(tl.prv)).seg = aux;
		tl.prv = aux;
	}
	return tl;
}

Trainer Tlist_consult(Tlist tl){
	Trainer t;
	if ((*(tl.f)).seg == NULL){
		printf("\nTrainer list is empty");
	}
	else{
		t = (*((*(tl.prv)).seg)).t;
	}
	return t;
}

Tlist  Tlist_start(Tlist tl){
	tl.prv= tl.f;
	return tl;
}

Tlist Tlist_delete(Tlist tl){
	NodeT *aux;
	if ((*(tl.f)).seg == NULL){
		printf("\nTrainer list is empty");
	}
	else{
		aux = (*(tl.prv)).seg;
		(*(tl.prv)).seg = (*aux).seg;
		free(aux);
	}
	return tl;
}

Tlist Tlist_forward(Tlist tl){
	if ((*(tl.prv)).seg == NULL){
		printf("\nList is already at the end");
	}
	else{
		tl.prv = (*(tl.prv)).seg;
	}
	return tl;
}

int Tlist_empty(Tlist tl){
	return (*(tl.f)).seg == NULL;
}

int Tlist_final(Tlist tl){
	return (*(tl.prv)).seg == NULL;
}

Tlist Atklist_start(Tlist tl){
	tl.prv = tl.f;
	return tl;
}

Tlist Tlist_destroy(Tlist tl){
	NodeT *aux;
	aux = (*(tl.f)).seg;
	free(tl.f);
	while (aux != NULL){
		tl.f = aux;
		aux = (*(tl.f)).seg;
		free(tl.f);
	}
	return tl;
}

int Tlist_howmany(Tlist tl){
	int compt = 0;
	tl = Tlist_start(tl);
	while (!Tlist_final(tl)){
		compt++;
		tl = Tlist_forward(tl);
	}
	return compt;
}