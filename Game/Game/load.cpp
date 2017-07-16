#include "load.h"

void LoadFKM(Flist fl){
	FILE *f;
	fopen_s(&f, "FKM.bin", "rb");
	FKM fkm;
	if (f == NULL){
		printf("\nError reading FKM ");
	}
	else{
		fread(&fkm, sizeof(FKM), 1, f);
		while (!feof(f)){
			fl = Flist_insert(fl, fkm);
			fread(&fkm, sizeof(FKM), 1, f);
		}
		fclose(f);
	}
	
}

void LoadT(Tlist tl){
	FILE *f;
	fopen_s(&f, "Trainers.bin", "rb");
	Trainer T;
	if (f == NULL){
		printf("\nError reading trainers ");
	}
	else{
		fread(&T, sizeof(Trainer), 1, f);
		while (!feof(f)){
			tl = Tlist_insert(tl, T);
			fread(&T, sizeof(Trainer), 1, f);
		}
		fclose(f);
	}
	
}

void LoadAtk(Atklist al){
	FILE *f;
	fopen_s(&f, "ATK.bin", "rb");
	Attack a;
	if (f == NULL){
		printf("\nError reading attacks ");
	}
	else{
		fread(&a, sizeof(Attack), 1, f);
		while (!feof(f)){
			al = Atklist_insert(al, a);
			fread(&a, sizeof(Attack), 1, f);
		}
		fclose(f);
	}
}

void LoadPrize(Prize *P){
	FILE *f;
	int num = 0;
	int index = 0;
	char kk;
	fopen_s(&f, "Prize.txt", "r");
	if (f == NULL){
		printf("\nError loading the awards.");
	}
	else{
		fscanf_s(f, "%d", &num);
		fscanf_s(f, "%c", &kk);
		P = (Prize*)malloc(sizeof(Prize)*num);
		if (P == NULL){
			printf("\nError loading the prizes.");
		}
		else{
			while (!feof(f) && index < num){
				fgets(P[index], 50, f);
				index++;
			}
		}
		fclose(f);
	}
	
}

void LoadFoe(Flist foel){
	FILE *f;
	fopen_s(&f, "FoeFKM.bin", "rb");
	FKM fkm; 
	if (f == NULL){
		printf("\nError reading FKM ");
	}
	else{
		fread(&fkm, sizeof(FKM), 1, f);
		while (!feof(f)){
			foel = Flist_insert(foel, fkm);
			fread(&fkm, sizeof(FKM), 1, f);
		}
		fclose(f);
	}
}

void LoadMart(Olist ol){
	FILE *f;
	fopen_s(&f, "OBJ.bin", "rb");
	Object o;
	if (f == NULL){
		printf("\nError reading FKM ");
	}
	else{
		fread(&o, sizeof(Object), 1, f);
		while (!feof(f)){
			ol = Olist_insert(ol, o);
			fread(&o, sizeof(Object), 1, f);
		}
		fclose(f);
	}
}