#include "mart.h"

void Introduce(char *name){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR BLUE = al_map_rgb(0, 102, 204);

	ALLEGRO_KEYBOARD_STATE kbdstate;

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, WHITE);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, BLUE, 4);

	al_draw_textf(font, BLACK, 40, 570, 0, "Hi %s!, here you can buy some interesting items",name);
	al_draw_textf(font, BLACK, 40, 640, 0, "they will help you to heal an improve your pkm!!!");

	al_flip_display();

	al_get_keyboard_state(&kbdstate);
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	al_destroy_font(font);
}

void LoadMart(Object*o, Olist ol){
	int index = 0;

	while (index < Olist_howmany(ol)){
		o[index] = Olist_consult(ol);
		ol = Olist_forward(ol);
		index++;
	}
}

void NotEnoughMoney(){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR BLUE = al_map_rgb(0, 102, 204);

	ALLEGRO_KEYBOARD_STATE kbdstate;

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 60, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, WHITE);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, BLUE, 4);

	al_draw_textf(font, BLACK, 40, 590, 0, "You can't afford this item!!!");


	al_flip_display();

	al_get_keyboard_state(&kbdstate);
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	al_destroy_font(font);
}

void ShowUse(Object o){
	//Proc per a mostra la descripcio i la imatge de l'objecte
	o.object = al_load_bitmap(o.image);

	ALLEGRO_COLOR BLUE = al_map_rgb(0, 102, 204);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR GRAY = al_map_rgb(150, 150, 150);

	ALLEGRO_FONT*font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 30, 0);

	al_draw_filled_rectangle(320, 560, 920, 690, BLUE);
	al_draw_textf(font, WHITE, 350, 610, 0, "%s", o.description);
	al_draw_filled_rounded_rectangle(920, 560, 1040, 680, 20, 20, GRAY);
	al_draw_bitmap(o.object, 950, 570, 0);
	al_flip_display();
	al_destroy_bitmap(o.object);
	al_destroy_font(font);
}

int Howmany(char *name){
	//Funcio cantitat de item que vols.
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR BLUE = al_map_rgb(0, 102, 204);
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);

	ALLEGRO_KEYBOARD_STATE kbdstate;

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 60, 0);

	int q = 1;

	//Pregunta del venedor
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, WHITE);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, BLUE, 4);
	al_draw_textf(font, BLACK, 30, 600, 0, "How many %s do you want?", name);

	//Marc de la quantitat
	al_draw_filled_rounded_rectangle(900, 380, 1050, 530, 20, 20, WHITE);
	al_draw_rounded_rectangle(905, 385, 1045, 525, 20, 20, BLUE, 4);
	al_draw_textf(font, BLACK, 920, 420, 0, "x %d", q);

	al_get_keyboard_state(&kbdstate);

	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){
		al_get_keyboard_state(&kbdstate);
		
		if (al_key_down(&kbdstate, ALLEGRO_KEY_UP) && q<99){
			while (al_key_down(&kbdstate, ALLEGRO_KEY_UP) == true){ al_get_keyboard_state(&kbdstate); }
			q++;
			al_draw_filled_rectangle(915, 390, 1037, 520, WHITE);
			al_draw_textf(font, BLACK, 920, 420, 0, "x %d", q);
		}

		if (al_key_down(&kbdstate, ALLEGRO_KEY_DOWN) && q>1){
			while (al_key_down(&kbdstate, ALLEGRO_KEY_DOWN) == true){ al_get_keyboard_state(&kbdstate); }
			q--;
			al_draw_filled_rectangle(915, 390, 1037, 520, WHITE);
			al_draw_textf(font, BLACK, 920, 420, 0, "x %d", q);
		}
		al_flip_display();
	}
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	al_destroy_font(font); 
	return q;
}

Trainer AddBag(Object o, int q, Trainer T){
	int slot = 0;
	o.q = q;
	while (strcmp(T.B[slot].name, "NULL") != 0 && strcmp(T.B[slot].name, o.name) != 0){
		slot++;
	}
	if (strcmp(T.B[slot].name, o.name) == 0){
		T.B[slot].q += q;
	}
	else{
		T.B[slot] = o;
	}
	return T;
}

void Thanks(){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR BLUE = al_map_rgb(0, 102, 204);

	ALLEGRO_KEYBOARD_STATE kbdstate;

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 60, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, WHITE);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, BLUE, 4);

	al_draw_textf(font, BLACK, 40, 590, 0, "Thank you! Good bye! :)");


	al_flip_display();

	al_get_keyboard_state(&kbdstate);
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	al_destroy_font(font);
}

Trainer Mart(Olist ol, Trainer T){

	Object *o;

	ALLEGRO_KEYBOARD_STATE kbdstate;

	int index_o = 0;
	bool done = false;
	int many = 0;

	Arrow A;
	A.x = 350;
	A.y = 50;

	o = (Object*)malloc(sizeof(Object)*Olist_howmany(ol));
	if (o == NULL){
		printf("\nError loading mart.");
	}
	else{
		//Carreguem la tenda
		LoadMart(o, ol);

		//Printem i expliquem la tenda
		DrawMart(o, Olist_howmany(ol),T);
		Introduce(T.name);
		DrawMart(o, Olist_howmany(ol),T);

		//Mentre no s'hagi realitzat la venta
		while (!done){
			al_get_keyboard_state(&kbdstate);

			//Proc per a mostra la descripcio i la imatge de l'objecte
			ShowUse(o[index_o]);
			
			//Logica del cursor pokeball
			A=MartArrow(A,&index_o);
			
			//Si premem enter o z accedim al menu de elegir la quantitat que volem, si no tenim prous $ el seller ens mostra un missatge d'error
			if (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){
				while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
				if (T.money >= o[index_o].price){
					many=Howmany(o[index_o].name);
					if (T.money >= o[index_o].price*many){
						T = AddBag(o[index_o],many,T);
						Thanks();
						done = true;
						T.money -= o[index_o].price*many;
					}
					else{
						NotEnoughMoney();
					}
				}
				else{
					NotEnoughMoney();
				}
				DrawMart(o, Olist_howmany(ol), T);
			}

			//Retroces per sortir de la tenda
			if (al_key_down(&kbdstate, ALLEGRO_KEY_BACKSPACE) == true){
				while (al_key_down(&kbdstate, ALLEGRO_KEY_BACKSPACE) == true){ al_get_keyboard_state(&kbdstate); }
				done = true;
				Thanks();
			}
			al_flip_display();
		}
	}
	return T;
}