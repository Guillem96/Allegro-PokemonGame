#include "atklist.h"

Atklist Atklist_create(){
	Atklist al;
	al.f = (NodeA*)malloc(sizeof(NodeA));
	if (al.f == NULL){
		printf("\nList is not created");
	}
	else{
		(*(al.f)).seg = NULL;
		al.prv = al.f;
	}
	return al;
}

Atklist Atklist_insert(Atklist al, Attack a){
	NodeA *aux;
	aux = (NodeA*)malloc(sizeof(NodeA));
	if (aux == NULL){
		printf("\nInsert error");
	}
	else{
		(*aux).a = a;
		(*aux).seg = (*(al.prv)).seg;
		(*(al.prv)).seg = aux;
		al.prv = aux;
	}
	return al;
}

Attack Atklist_consult(Atklist al){
	Attack a;
	if ((*(al.f)).seg == NULL){
		printf("\nAttack list is empty");
	}
	else{
		a = (*((*(al.prv)).seg)).a;
	}
	return a;
}

Atklist Atklist_delete(Atklist al){
	NodeA *aux;
	if ((*(al.f)).seg == NULL){
		printf("\nAttack list is empty");
	}
	else{
		aux = (*(al.prv)).seg;
		(*(al.prv)).seg = (*aux).seg;
		free(aux);
	}
	return al;
}

Atklist Atklist_forward(Atklist al){
	if ((*(al.prv)).seg == NULL){
		printf ("\nList is already at the end");
	}
	else{
		al.prv = (*(al.prv)).seg;
	}
	return al;
}

int Atklist_empty(Atklist al){
	return (*(al.f)).seg == NULL;
}

int Atklist_final(Atklist al){
	return (*(al.prv)).seg == NULL;
}

Atklist Atklist_start(Atklist al){
	al.prv = al.f;
	return al;
}

Atklist Atklist_destroy(Atklist al){
	NodeA *aux;
	aux = (*(al.f)).seg;
	free(al.f);
	while (aux != NULL){
		al.f = aux;
		aux = (*(al.f)).seg;
		free(al.f);
	}
	return al;
}

Atklist Atklist_insertord(Atklist al, Attack a){
	al = Atklist_start(al);
	while (!Atklist_final(al) && Atklist_consult(al).power < a.power){
		al = Atklist_forward(al);
	}
	al = Atklist_insert(al, a);
	return al;
}