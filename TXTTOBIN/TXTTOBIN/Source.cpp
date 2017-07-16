#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include <allegro5\/allegro.h>

typedef struct{
	ALLEGRO_BITMAP *object;
	char name[20];
	char type;
	int effect;
	int q;
	int price;
	char description[100];
	char image[30];
}Object;

typedef struct{
	char name[20];
	char type[20];
	char category;
	int power;
	int accuracy;
	int pp;
	int leftpp;
}Attack;

typedef struct{
	int hp;
	int fullhp;
	int atk;
	int def;
	int spa;
	int spd;
	int speed;
}Statistics;

typedef struct{
	char name[20];
	char first_type[20];
	char second_type[20];
	bool starter;
	int exp;
	int lvl;
	int next_lvl;
	int evolve;
	Attack a[4];
	Statistics s;
	Statistics base;
	char skin[20];
	char skinb[20];
	ALLEGRO_BITMAP *front;
	ALLEGRO_BITMAP *back;
	char name_evo[20];
	char status;
}FKM;

void main(){
	FILE *ft, *fb;
	FKM f;
	int aux;
	char kk[20];
	fopen_s(&ft,"FKM.txt", "r");
	fopen_s(&fb, "FKM.bin", "wb");
	if (ft == NULL || fb == NULL){
		printf("\nError");
	}
	else{
		fgets(f.name, 20, ft);
		while (!feof(ft)){
			f.name[strlen(f.name) - 1] = '\0';
			fgets(f.first_type, 20, ft);
			f.first_type[strlen(f.first_type) - 1] = '\0';
			fgets(f.second_type, 20, ft);
			f.second_type[strlen(f.second_type) - 1] = '\0';
			fscanf_s(ft, "%d", &aux);
			if (aux == 1){
				f.starter = true;
			}
			else{
				f.starter = false;
			}
			fscanf_s(ft, "%d", &f.exp);
			fscanf_s(ft, "%d", &f.lvl);
			fscanf_s(ft, "%d", &f.next_lvl);
			fscanf_s(ft, "%d", &f.evolve);
			fscanf_s(ft, "%d", &f.base.hp);
			f.s.fullhp = f.base.hp;
			fscanf_s(ft, "%d", &f.base.atk);
			fscanf_s(ft, "%d", &f.base.def);
			fscanf_s(ft, "%d", &f.base.spa);
			fscanf_s(ft, "%d", &f.base.spd);
			fscanf_s(ft, "%d", &f.base.speed);
			fscanf_s(ft,"%c",&kk[0]);
			fgets(f.skin, 20, ft);
			f.skin[strlen(f.skin) - 1] = '\0';
			fgets(f.skinb, 20, ft);
			f.skinb[strlen(f.skinb)-1] = '\0';
			fgets(f.name_evo, 20, ft);
			f.name_evo[strlen(f.name_evo) - 1] = '\0';
			fgets(kk, 20, ft);
			f.status = ' ';
			fwrite(&f, sizeof(FKM), 1, fb);
			fgets(f.name, 20, ft);
		}
	}
	fclose(ft);
	fclose(fb);
	Attack a;
	fopen_s(&ft, "atk.txt", "r");
	fopen_s(&fb, "ATK.bin", "wb+");
	if (ft == NULL || fb == NULL){
		printf("\nError");
	}
	else{
		fgets(a.name, 20, ft);
		while (!feof(ft)){
			a.name[strlen(a.name) - 1] = '\0';
			fgets(a.type, 20, ft);
			a.type[strlen(a.type) - 1] = '\0';
			fscanf_s(ft, "%c", &a.category);
			fscanf_s(ft, "%d", &a.power);
			fscanf_s(ft, "%d", &a.accuracy);
			fscanf_s(ft, "%d", &a.pp);
			fgets(kk, 20, ft);
			fgets(kk, 20, ft);
			fwrite(&a, sizeof(Attack), 1, fb);
			fgets(a.name, 20, ft);
		}
		fclose(ft);
		fclose(fb);
	}
	fopen_s(&ft, "FoeFKM.txt", "r");
	fopen_s(&fb, "FoeFKM.bin", "wb+");
	if (ft == NULL || fb == NULL){
		printf("\nError");
	}
	else{
		fgets(f.name, 20, ft);
		while (!feof(ft)){
			f.name[strlen(f.name) - 1] = '\0';
			fscanf_s(ft, "%d", &f.next_lvl);
			fscanf_s(ft, "%c", &kk[0]);
			fgets(f.first_type, 20, ft);
			f.first_type[strlen(f.first_type) - 1] = '\0';
			fgets(f.second_type, 20, ft);
			f.second_type[strlen(f.second_type) - 1] = '\0';
			fscanf_s(ft, "%d", &f.base.hp);
			f.s.fullhp = f.base.hp;
			fscanf_s(ft, "%d", &f.base.atk);
			fscanf_s(ft, "%d", &f.base.def);
			fscanf_s(ft, "%d", &f.base.spa);
			fscanf_s(ft, "%d", &f.base.spd);
			fscanf_s(ft, "%d", &f.base.speed);
			fscanf_s(ft, "%c", &kk[0]);
			fgets(f.skin, 20, ft);
			f.skin[strlen(f.skin) - 1] = '\0';
			fscanf_s(ft, "%d", &f.exp);
			fscanf_s(ft, "%c", &kk[0]);
			fgets(kk, 20, ft);
			f.status = ' ';
			fwrite(&f, sizeof(FKM), 1, fb);
			fgets(f.name, 20, ft);
		}
		fclose(ft);
		fclose(fb);
	}
	Object o;
	fopen_s(&ft, "OBJ.txt", "r");
	fopen_s(&fb, "OBJ.bin", "wb+");
	if (ft == NULL || fb == NULL){
		printf("\nError");
	}
	else{
		fgets(o.name, 20, ft);
		while (!feof(ft)){
			o.name[strlen(o.name) - 1] = '\0';
			fscanf_s(ft, "%c", &o.type);
			fscanf_s(ft, "%d", &o.effect);
			fscanf_s(ft, "%c", &kk[0]);
			fgets(o.description, 100, ft);
			o.description[strlen(o.description) - 1] = '\0';
			o.q = 1;
			fscanf_s(ft, "%d", &o.price);
			fscanf_s(ft, "%c", &kk[0]);
			fgets(o.image, 30, ft);
			o.image[strlen(o.image) - 1] = '\0';
			fgets(kk, 20, ft);
			fwrite(&o, sizeof(Object), 1, fb);
			fgets(o.name, 20, ft);
		}
		fclose(ft);
		fclose(fb);
	}
}