#include "tournament.h"

void Tournament_Start() {
	//Allegro variables
	ALLEGRO_KEYBOARD_STATE kbdstate;
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 30, 0);
	ALLEGRO_BITMAP *firma = al_load_bitmap("firma.png");
	ALLEGRO_BITMAP *n = al_load_bitmap("n.gif");

	Draw_Background();

	//Printem el quadre de text
	al_draw_filled_rounded_rectangle(30, 30, 710, 590, 20, 20, al_map_rgb(255, 255, 255));
	al_draw_rounded_rectangle(35, 35, 705, 585, 20, 20, al_map_rgb(102, 0, 102), 6);
	//Busca algu epip per presenta torneig
	al_draw_scaled_bitmap(n, 0, 0, al_get_bitmap_width(n), al_get_bitmap_height(n), 650, 20, al_get_bitmap_width(n)*1.2, al_get_bitmap_height(n)*1.2, 0);
	al_draw_bitmap(firma, 30, 660, 0);

	//Anem mostran els missatges a mesura que es prem l'enter
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 55, 0, "- Welcom to FKM Tournament! Are you ready?");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 95, 0, "Now in this mode you will fight ");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 135, 0, "against a Crime syndicate!!!");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	//Fins que es premi enter i espera a que es despremi la tecla
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false) { al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true) { al_get_keyboard_state(&kbdstate); }
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 215, 0, "- You will be able to fight agains Team  ");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 255, 0, "Rocket, Aqua, Magma, Galaxy or Plasma.");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	//Fins que es premi enter i espera a que es despremi la tecla
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false) { al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true) { al_get_keyboard_state(&kbdstate); }
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 335, 0, "In this tournament you will battle 4 grunts");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 385, 0, "and the leader of the organitzation.");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	//Fins que es premi enter i espera a que es despremi la tecla
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false) { al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true) { al_get_keyboard_state(&kbdstate); }
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 465, 0, "- If you have not trained enough you shoud");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 505, 0, "lieave now that you are on time!!!");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	//Fins que es premi enter i espera a que es despremi la tecla
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false) { al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true) { al_get_keyboard_state(&kbdstate); }
	al_destroy_bitmap(firma);
	al_destroy_bitmap(n);


	al_destroy_font(font);
	al_flip_display();
}

char ChooseEnemy() {
	char option='m';
	ALLEGRO_KEYBOARD_STATE kbdstate;
	Arrow a;
	
	bool end = false;


	a.x = 30;
	a.y = 170;

	ShowEnemiesOptions();
	Draw_enemiesarrow(a);
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true) { al_get_keyboard_state(&kbdstate); }
	while (!end) {
		al_get_keyboard_state(&kbdstate);
		a = Enemies_arrow(a);
		Draw_enemiesarrow(a);
	
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && a.x == 30 && a.y == 170) {
			
			option = 'R';
			end = true;
			while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true) { al_get_keyboard_state(&kbdstate); }
		}
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && a.x == 450 && a.y == 170) {
	
			option = 'M';
			end = true;
			while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true) { al_get_keyboard_state(&kbdstate); }
		}
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && a.x == 240 && a.y == 300) {
			
			option = 'A';
			end = true;
			while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true) { al_get_keyboard_state(&kbdstate); }
		}
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && a.x == 30 && a.y == 450) {

			option = 'G';
			end = true;
			while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true) { al_get_keyboard_state(&kbdstate); }
		}
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && a.x == 450 && a.y == 450) {
			
			option = 'P';
			end = true;
			while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true) { al_get_keyboard_state(&kbdstate); }
		}
	}
	return option;
}

Tlist Team_Create(char chamopionship, Atklist al, Flist foel,Tlist enemies) {
	Trainer aux;
	int compt = 0, pokemon = 0, pos = 0, slot = 0, lvl;
	char sking[30], skinl[30];
	foel = Flist_start(foel);

	if (chamopionship == 'R') {
		lvl = 20;
		strcpy(sking, "gruntr.png");
		strcpy(skinl, "giovanni.png");
	}
	if (chamopionship == 'M') {
		lvl = 30;
		strcpy(sking, "gruntm.png");
		strcpy(skinl, "maxie.png");
	}
	if (chamopionship == 'A') {
		lvl = 40;
		strcpy(sking, "grunta.png");
		strcpy(skinl, "aquiles.png");
	}
	if (chamopionship == 'G') {
		lvl = 50;
		strcpy(sking, "gruntg.png");
		strcpy(skinl, "zero.png");
	}
	if (chamopionship == 'P') {
		lvl = 60;
		strcpy(sking, "gruntp.png");
		strcpy(skinl, "gechis.png");
	}

	//Generem els grunts

	while (compt < 5) {
		slot = 0;
		while (slot < 3) {
			foel = Flist_start(foel);
			pos = 0;
			pokemon = rand() % 100;
			while (pos < pokemon) {
				foel = Flist_forward(foel);
				pos++;
			}
			aux.team[slot] = Flist_consult(foel);
			aux.team[slot].lvl = lvl;
			aux.team[slot] = Generatestadistics(aux.team[slot]);
			aux.team[slot] = GiveAttacks(aux.team[slot], al);
			slot++;
		}
		enemies = Tlist_insert(enemies, aux);
		compt++;
	}
	return enemies;
}
Trainer Tournament(Flist foel, Trainer T, Atklist al, Flist fl) {
	
	Tlist enemies;

	char chamopionship;//R -> Rocket, A-> Aqua, M-> Magma, G-> Galaxia, p-> Plasma.

	enemies = Tlist_create();

	//Start tournament
	Tournament_Start();

	//Triar l'equip contra qui vols combatir.
	chamopionship = ChooseEnemy();

	//Crear els reclutes.
	//enemies = Team_Create(chamopionship, al, foel,enemies);

	//Pantalla Presentació
	//Presentation(T,chamopionship);

	//Comença el combat
	//Pokemon_Batlle(T,enemies,fl);

	enemies = Tlist_destroy(enemies);
	
	return T;
	
}