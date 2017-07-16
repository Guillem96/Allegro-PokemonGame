#include "training.h"

void StartTrain(){
	//Allegro variables
	ALLEGRO_KEYBOARD_STATE kbdstate;
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 30, 0);
	ALLEGRO_BITMAP *firma = al_load_bitmap("firma.png");
	ALLEGRO_BITMAP *red = al_load_bitmap("Red.png");

	Draw_Background();

	//Printem el quadre de text
	al_draw_filled_rounded_rectangle(30, 30, 710, 590, 20, 20, al_map_rgb(255, 255, 255));
	al_draw_rounded_rectangle(35, 35, 705, 585, 20, 20, al_map_rgb(102, 0, 102), 6);
	al_draw_scaled_bitmap(red, 0, 0, al_get_bitmap_width(red), al_get_bitmap_height(red), 610, 50, al_get_bitmap_width(red)*0.7, al_get_bitmap_height(red)*0.7,0);
	al_draw_bitmap(firma, 30, 660, 0);

	//Anem mostran els missatges a mesura que es prem l'enter
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 55, 0, "- Hi, as you may know I'm Red,");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 95, 0, "Now in this mode you will fight against");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 135, 0, "three random foe Pokemon!!!");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	//Fins que es premi enter i espera a que es despremi la tecla
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 215, 0, "- This mode has been made for the prupose ");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 255, 0, "to train your Pokemon easily.");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	//Fins que es premi enter i espera a que es despremi la tecla
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 335, 0, "The level of foe pokemon will be the same");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 385, 0, "as the average of level of your team.");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	//Fins que es premi enter i espera a que es despremi la tecla
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 465, 0, "- Come on!!! You can do it!!! :)");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	//Fins que es premi enter i espera a que es despremi la tecla
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	al_destroy_bitmap(firma);
	al_destroy_bitmap(red);
	al_destroy_font(font);
	al_flip_display();
}

void LoadEnemies(Flist foe, int avg, Flist foel, Atklist al){
	int compt = 0;
	int random, aux;
	FKM e;
	foel = Flist_start(foel);
	while (compt < 3){
		aux = 0;
		srand(time(NULL));
		random = rand() % 60;
		while (aux < random){
			foel = Flist_forward(foel);
			if (Flist_final(foel) == 1){
				foel = Flist_start(foel);
			}
			aux++;
		}
		if (avg > Flist_consult(foel).next_lvl){
			e = Flist_consult(foel);
			e = GiveAttacks(e, al);
			e.lvl = avg;
			e= Generatestadistics(e);
			foe = Flist_insert(foe, e);
			compt++;
		}
	}
}

int Averagelvl(FKM *f){
	int index = 0;
	//mitjana pokemon entrenador
	int acum = 0;
	int compt = 0;
	int avg = 0;
	while (index < 6 && strcmp(f[index].name, "NULL") != 0){
		compt++;
		acum += f[index].lvl;
		index++;
	}
	avg = acum / compt;
	return avg;
}


Trainer Training(Trainer T, Flist foel, Atklist al,Flist fl){
	int avg = 0;
	Flist foe;
	foe = Flist_create();

	StartTrain();
	//Calculem la mitjana de l equip pkm
	avg = Averagelvl(T.team);
	
	LoadEnemies(foe, avg, foel,al);
	
	//Dibuixem la capcelera del combat.
	DrawVs(T, foe);

	T=Combat(T, foe, fl);
	
	
	
	return T;
}