#include "tail.h"

Tail Tail_create(){
	Tail t;
	t.f = (NodeS*)malloc(sizeof(NodeS));
	if (t.f == NULL){
		printf("\nError creating the Tail.");
	}
	else{
		(*(t.f)).seg = NULL;
		t.l = t.f;
	}
	return t;
}

void Tail_add(Tail *t, FKM p){
	NodeS *aux;
	aux = (NodeS*)malloc(sizeof(NodeS));
	if (aux == NULL){
		printf("\nError adding in tail.");
	}
	else{
		(*aux).p = p;
		(*aux).seg = NULL;
		(*((*t).l)).seg=aux;
		(*t).l = aux;
	}
}

Tail Tail_delete(Tail t){
	NodeS *aux;
	if ((*(t.f)).seg == NULL){
		printf("\nThe stack is empty");
	}
	else{
		aux = t.f->seg;
		if ((*aux).seg == NULL){
			printf("\nhola");
			t.l = t.f;
		}
		(*(t.f)).seg = (*aux).seg;
		free(aux);
	}
	return t;
}

FKM Tail_head(Tail t) {
	FKM p;
	if ((*(t.f)).seg == NULL){
		printf("\nThe stack is empty");
		p.lvl = 99;
	}
	else{
		p = (*((*(t.f)).seg)).p;
	}
	return p;
}


int Tail_empty(Tail t){
	return (*(t.f)).seg == NULL;
}

Tail Tail_destroy(Tail t){
	NodeS *aux;
	while (t.f != NULL){
		aux = t.f;
		t.f = (*aux).seg;
		free(aux);
	}
	return t;
}
