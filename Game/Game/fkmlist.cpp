#include "fkmlist.h"

Flist Flist_create(){
	Flist fl;
	
	fl.f = (NodeF*)malloc(sizeof(NodeF));
	if (fl.f == NULL){
		printf("\nList is not created");
	}
	else{

		(*(fl.f)).seg = NULL;
		fl.prv = fl.f;
	}
	return fl;
}

Flist Flist_insert(Flist fl, FKM f){
	NodeF *aux;
	aux = (NodeF*)malloc(sizeof(NodeF));
	if (aux == NULL){
		printf("\nInsert error");
	}
	else{
		(*aux).f = f;
		(*aux).seg = (*(fl.prv)).seg;
		(*(fl.prv)).seg = aux;
		fl.prv = aux;
	}
	return fl;
}

FKM Flist_consult(Flist fl){
	FKM f;
	if ((*(fl.f)).seg == NULL){
		printf("\nFKM list is empty");
	}
	else{
		f = (*((*(fl.prv)).seg)).f;
	}
	return f;
}

Flist Flist_delete(Flist fl){
	NodeF *aux;
	if ((*(fl.f)).seg == NULL){
		printf("\nFKM list is empty");
	}
	else{
		aux = (*(fl.prv)).seg;
		(*(fl.prv)).seg = (*aux).seg;
		free(aux);
	}
	return fl;
}

Flist Flist_forward(Flist fl){
	if ((*(fl.prv)).seg == NULL){
		printf("\nList is already at the end");
	}
	else{
		fl.prv = (*(fl.prv)).seg;
	}
	return fl;
}

int Flist_empty(Flist fl){
	return (*(fl.f)).seg == NULL;
}

int Flist_final(Flist fl){
	return (*(fl.prv)).seg == NULL;
}

Flist Flist_start(Flist fl){
	fl.prv = fl.f;
	return fl;
}

Flist Flist_destroy(Flist fl){
	NodeF *aux;
	aux = (*(fl.f)).seg;
	free(fl.f);
	while (aux != NULL){
		fl.f = aux;
		aux = (*(fl.f)).seg;
		free(fl.f);
	}
	return fl;
}

int Flist_howmanystarters(Flist fl){
	int compt = 0;
	fl = Flist_start(fl);
	while (!Flist_final(fl)){
		if (Flist_consult(fl).starter == true){
			compt++;
		}
		fl = Flist_forward(fl);
	}
	return compt;
}