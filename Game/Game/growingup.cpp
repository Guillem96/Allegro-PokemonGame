#include "growingup.h"

FKM Evolution(FKM f, Flist fl){
	FKM evo;
	bool found = false;
	fl = Flist_start(fl);
	while (!Flist_final(fl) && !found){
		evo = Flist_consult(fl);
		if (strcmp(f.name_evo, evo.name) == 0){
			found = true;
			//ShowEvolving(evo,f);
			evo.exp = f.exp;
			evo.next_lvl = f.next_lvl;
			evo.s.fullhp = evo.base.hp + (f.s.fullhp - f.base.hp);
			evo.s.atk = evo.base.atk + (f.s.atk - f.base.atk);
			evo.s.def = evo.base.def + (f.s.def - f.base.def);
			evo.s.spa = evo.base.spa + (f.s.spa - f.base.spa);
			evo.s.spd = evo.base.spd + (f.s.spd - f.base.spd);
			evo.s.speed = evo.base.speed + (f.s.speed - f.base.speed);
		}
		else{
			fl = Flist_forward(fl);
		}
	}
	return evo;
}

FKM LevelUp(FKM f,Flist fl){
	int a[10];
	f.lvl++;
	if (f.lvl == f.evolve){
		f = Evolution(f,fl);
	}
	srand(time(NULL));
	a[0] = rand() % 5;
	f.s.atk += a[0];
	a[1] = rand() % 5;
	f.s.def += a[1];
	a[2] = rand() % 5;
	f.s.spa += a[2];
	a[3] = rand() % 5;
	f.s.spd += a[3];
	a[4] = rand() % 5;
	f.s.speed += a[4];
	a[5] = rand() % 5;
	f.s.fullhp += a[5];
	ShowLevelUp(f,a,f.lvl);
	f.next_lvl = f.lvl * 50;
	f.exp = 0;
	return f;
}


void Earned(FKM f,int exp){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "Your %s has earned %d exp points!!!.", f.name,exp);
	al_flip_display();
	al_rest(3);
}

FKM GrowPKM(FKM f,FKM fe,Flist fl){
	int aux = 0;
	int exp = 0;
	int distance = 0;
	exp = (fe.exp * fe.lvl) / (float)7;
	f.exp = f.exp + exp;

	if (f.exp >= f.next_lvl){
		aux = f.exp - f.next_lvl;
		f = LevelUp(f,fl);
		f.exp =  aux;
	}
	Earned(f, exp);
	return f;
}

