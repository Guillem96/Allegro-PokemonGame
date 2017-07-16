#include "bag.h"

void ShowIncorrect() {
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR PURPLE = al_map_rgb(102, 0, 102);

	ALLEGRO_KEYBOARD_STATE kbdstate;

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 600, 1060, 710, 20, 20, WHITE);
	al_draw_rounded_rectangle(15, 605, 1055, 705, 20, 20, PURPLE, 6);

	al_draw_textf(font, BLACK, 160, 633, 0, "The object hasn't been applied correctly!");


	al_flip_display();

	al_get_keyboard_state(&kbdstate);
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false) { al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true) { al_get_keyboard_state(&kbdstate); }
	al_destroy_font(font);
}

void ShowCorrect() {
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR PURPLE = al_map_rgb(102, 0, 102);

	ALLEGRO_KEYBOARD_STATE kbdstate;

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 600, 1060, 710, 20, 20, WHITE);
	al_draw_rounded_rectangle(15, 605, 1055, 705, 20, 20, PURPLE, 6);

	al_draw_textf(font, BLACK, 160, 633, 0, "The object has been applied correctly!");
	

	al_flip_display();

	al_get_keyboard_state(&kbdstate);
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false) { al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true) { al_get_keyboard_state(&kbdstate); }
	al_destroy_font(font);
}


FKM ApplyItem(FKM f, Object o, bool *could) {
	int index_a;

	if (o.type == 'H') {
		f.s.hp += o.effect;
		if (f.s.hp > f.s.fullhp) f.s.hp = f.s.fullhp;
		(*could) = true;
	}
	if (o.type == 'A') {
		f.s.atk += o.effect;
		(*could) = true;
	}
	if (o.type == 'D') {
		f.s.def += o.effect;
		(*could) = true;
	}
	if (o.type == 'S') {
		f.s.spd += o.effect;
		(*could) = true;
	}
	if (o.type == 'a') {
		f.s.spa += o.effect;
		(*could) = true;
	}
	if (o.type == 'd') {
		f.s.spd += o.effect;
		(*could) = true;
	}
	if (o.type == 'R') {
		if (f.s.hp <= 0) {
			f.s.hp = f.s.fullhp;
			if (f.s.hp > f.s.fullhp) f.s.hp = f.s.fullhp;
			(*could) = true;
		}
		else {
			ShowIncorrect();
		}
	}
	if (o.type == 'P') {
		f.a[0].leftpp += f.a[0].pp;
		f.a[1].leftpp += f.a[1].pp;
		f.a[2].leftpp += f.a[2].pp;
		f.a[3].leftpp += f.a[3].pp;
		(*could) = true;
	}
	return f;
}

Trainer Usage(Object *o,Trainer T){
	
	Arrow A;
	A.x = 40;
	A.y = 10;
	int index = 0;

	bool used = false;
	
	ALLEGRO_KEYBOARD_STATE kbd;

	

	//Mostrem l'equip per a aplicar l'objecte
	Draw_TeamBackground();
	DrawTeam(T.team);

	while (!used){
		al_get_keyboard_state(&kbd);
		A=ArrowTeam(A, T.team, &index);
		if (al_key_down(&kbd, ALLEGRO_KEY_ENTER) || al_key_down(&kbd, ALLEGRO_KEY_Z)){
			T.team[index]=ApplyItem(T.team[index], *o,&used);
			if (used) {//Reduim l'objecte
				Draw_TeamBackground();
				DrawTeam(T.team);
				ShowCorrect();		
			}
			else if (!used) {
				Draw_TeamBackground();
				DrawTeam(T.team);
			}
			while (al_key_down(&kbd, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbd, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbd); }
		}
		//Backspace per a tirar enrrere
		if (al_key_down(&kbd, ALLEGRO_KEY_BACKSPACE)){
			used = true;
			while (al_key_down(&kbd, ALLEGRO_KEY_BACKSPACE) == false){ al_get_keyboard_state(&kbd); }
		}
	}

	return T;
}

Trainer Bag(Trainer T){
	bool used = false;
	int index = 0;
	Arrow A;
	A.x = 22;
	A.y = 222;

	ALLEGRO_KEYBOARD_STATE kbd;

	DrawBag(T);

	while (!used){
		A=ObjectLogic(A,T.B,&index);
		al_get_keyboard_state(&kbd);

		//Si apretem enter utilitzem l'objecte
		if (al_key_down(&kbd, ALLEGRO_KEY_ENTER) || al_key_down(&kbd, ALLEGRO_KEY_Z)){
			T=Usage(&T.B[index],T);
			//CheckItems(T.B,index);
			DrawBag(T);
			while (al_key_down(&kbd, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbd, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbd); }
		}

		//Backspace per a tirar enrrere
		if (al_key_down(&kbd, ALLEGRO_KEY_BACKSPACE) ){
			used = true;
			while (al_key_down(&kbd, ALLEGRO_KEY_BACKSPACE) == false ){ al_get_keyboard_state(&kbd); }
		}
	}
	return T;
}