#ifndef _TYPES_H_
#define _TYPES_H_

#include "allegroguillem.h"


typedef char Prize[50];

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

typedef struct{
	char name[50];
	char skin[30];
	int win;
	int loose;
	ALLEGRO_BITMAP *tainer;
	int money;
	Object B[20];
	FKM team[6];
	bool Badges[5];
}Trainer;

typedef struct{
	float x;
	float y;
}Arrow;

#endif