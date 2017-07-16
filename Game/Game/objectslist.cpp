#include "objectslist.h"

Olist Olist_create(){
	Olist ol;
	
	ol.f = (NodeO*)malloc(sizeof(NodeO));
	if (ol.f == NULL){
		printf("\nList is not created");
	}
	else{
		(*(ol.f)).seg = NULL;
		ol.prv = ol.f;
	}
	return ol;
}

Olist Olist_insert(Olist ol, Object o){
	NodeO *aux;
	aux = (NodeO*)malloc(sizeof(NodeO));
	if (aux == NULL){
		printf("\nInsert error");
	}
	else{
		(*aux).o = o;
		(*aux).seg = (*(ol.prv)).seg;
		(*(ol.prv)).seg = aux;
		ol.prv = aux;
	}
	return ol;
}

Object Olist_consult(Olist ol){
	Object o;
	if ((*(ol.f)).seg == NULL){
		printf("\nObject list is empty");
	}
	else{
		o = (*((*(ol.prv)).seg)).o;
	}
	return o;
}

Olist Olist_delete(Olist ol){
	NodeO *aux;
	if ((*(ol.f)).seg == NULL){
		printf("\nObject list is empty");
	}
	else{
		aux = (*(ol.prv)).seg;
		(*(ol.prv)).seg = (*aux).seg;
		free(aux);
	}
	return ol;
}

Olist Olist_forward(Olist ol){
	if ((*(ol.prv)).seg == NULL){
		printf("\nList is already at the end");
	}
	else{
		ol.prv = (*(ol.prv)).seg;
	}
	return ol;
}

int Olist_empty(Olist ol){
	return (*(ol.f)).seg == NULL;
}

int Olist_final(Olist ol){
	return (*(ol.prv)).seg == NULL;
}

Olist Olist_start(Olist ol){
	ol.prv = ol.f;
	return ol;
}

Olist Olist_destroy(Olist ol){
	NodeO *aux;
	aux = (*(ol.f)).seg;
	free(ol.f);
	while (aux != NULL){
		ol.f = aux;
		aux = (*(ol.f)).seg;
		free(ol.f);
	}
	return ol;
}

int Olist_howmany(Olist ol){
	int compt = 0;
	ol = Olist_start(ol);
	while (!Olist_final(ol)){
		compt++;
		ol = Olist_forward(ol);
	}
	return compt;
}