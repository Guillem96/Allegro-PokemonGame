#include "firstoptions.h"



bool StartGame(int* out){
	//Allegro colors
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR PURPLE = al_map_rgb(102, 0, 102);

	//Allegro variables
	ALLEGRO_KEYBOARD_STATE kbdstate;
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 60, 0);
	ALLEGRO_FONT *font2 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);
	ALLEGRO_BITMAP *title = al_load_bitmap("title.png");
	ALLEGRO_BITMAP *arrow = al_load_bitmap("arrow.png");
	ALLEGRO_BITMAP *firma = al_load_bitmap("firma.png");
	ALLEGRO_BITMAP *init = al_load_bitmap("init.png");

	//variables
	bool ng = false;
	Arrow A;
	A.x = 375;
	A.y = 365;
	int chosen = 0;

	Draw_Background();
	al_draw_bitmap(init, 200, 270, 0);
	al_draw_scaled_bitmap(title, 0, 0, al_get_bitmap_width(title), al_get_bitmap_height(title), 140, 15, al_get_bitmap_width(title)*0.75, al_get_bitmap_height(title)*0.75, 0);
	al_draw_text(font2, WHITE, 430, 650, 0, "PRESS ENTER");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true ){ al_get_keyboard_state(&kbdstate); }
	Draw_Background();

	//Bucle que iterara mentre no s'ahagi escollit una opcio inicial
	while (chosen == 0 && *out == 0){

		//dibuixem per pantalla el quadre text i el missatge que e smostrara dins
		al_draw_scaled_bitmap(title, 0, 0, al_get_bitmap_width(title), al_get_bitmap_height(title), 140, 15, al_get_bitmap_width(title)*0.75, al_get_bitmap_height(title)*0.75, 0);
		al_draw_filled_rounded_rectangle(330, 330, 760, 590, 20, 20, WHITE);
		al_draw_rounded_rectangle(335, 335, 755, 585, 20, 20, PURPLE, 6);
		al_draw_bitmap(firma, 850, 660, 0);
		al_draw_scaled_rotated_bitmap(arrow, A.x + ((0.06*al_get_bitmap_width(arrow))/2),  A.y + ((0.06*al_get_bitmap_height(arrow))/2), A.x, A.y, 0.06, 0.06, -ALLEGRO_PI/2, 0);
		al_draw_text(font, BLACK, 390, 340, 0, "NEW GAME");
		al_draw_text(font, BLACK, 390, 425, 0, "LOAD GAME");
		al_draw_text(font, BLACK, 390, 510, 0, "EXIT");
		al_flip_display();

		//A partir de l'estat del teclat controlem les tecles que estan premudes.
		al_get_keyboard_state(&kbdstate);
		A = arrowprincipalmenu(A);
		//Si srrow esta sobre exit;
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && A.y > 510) {
			*out = 1;
			printf("\nEnd of game.");
		}
		//Si arrow esta sobre new
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && A.y == 365) {
			chosen = 1;
			ng = true;
			printf("\nNew game.");
		}
		//Si arrow esta sobre load
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && A.y == 450) {
			chosen = 1;
			printf("\nLoad game.");

		}
	}
	al_destroy_bitmap(arrow);
	al_destroy_bitmap(title);
	al_destroy_bitmap(firma);
	al_flip_display();
	al_destroy_font(font);
	return ng;
}

Trainer grab_input(Trainer T){
	
	//Allegro colors
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR PURPLE = al_map_rgb(102, 0, 102);

	//variables personals
	int caret = 0;
	//Letra que es va introduint pel teclat.
	char letter[255] = "";
	int exit = 0;

	//Variables allegro
	ALLEGRO_BITMAP *background = al_load_bitmap("background.png");
	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);
	ALLEGRO_BITMAP *firma = al_load_bitmap("firma.png");
	al_draw_bitmap(firma, 30, 660, 0);
	al_draw_text(font, WHITE, 15, 15, 0, "What's your name?");
	al_flip_display();

	//Bucle que iterara mentre no s'hagi introduit el nom
	while (exit == 0){
		//Event allegro
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;
		al_init_timeout(&timeout, 1000);
		bool get_event = al_wait_for_event_until(q, &ev, &timeout);

		//A partir de la variable ev controlem les tecles que estan apretades del teclat
		if (ev.type == ALLEGRO_EVENT_KEY_UP){
				if (ev.keyboard.keycode == ALLEGRO_KEY_BACKSPACE){
					if (caret > 0) caret--;
					T.name[caret] = '\0';
				}
				else
					if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER){
						exit = 1;
					}
					else{
						if (caret < 13 && ev.keyboard.keycode != ALLEGRO_KEY_SPACE){
							sprintf_s(letter, "%c", ev.keyboard.keycode + 64);
							strcat_s(T.name, letter);
							caret++;
						}
							
					}
					al_draw_bitmap_region(background,15,50,600,600,15,50,0);
					al_draw_textf(font, WHITE, 15, 70, 0, "%s", T.name);
					al_flip_display();
		}
		
	}
	al_destroy_bitmap(background);
	al_destroy_font(font);
	return T;

}

Trainer WhichSkin(Trainer T){
	//Allegro variables
	ALLEGRO_BITMAP *SEL = al_load_bitmap("se.png");
	ALLEGRO_BITMAP *firma = al_load_bitmap("firma.png");
	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//variables personals
	Arrow A;
	Trainer aux_t[2];
	int index = 0;
	int chosen = 0;

	//Copiem el nom del jugador a cada entrenador auxiliar
	while (index <= 1){
		aux_t[index] = T;
		index++;
	}

	//Adssigno un sexe a cada entrenador auxiliar
	strcpy_s(aux_t[0].skin, "trainer1.png");
	strcpy_s(aux_t[1].skin, "trainer2.png");

	//Printo per pantalla els dos sexes
	aux_t[0].tainer = al_load_bitmap(aux_t[0].skin);
	aux_t[1].tainer = al_load_bitmap(aux_t[1].skin);

	index = 0;
	al_draw_textf(font, al_map_rgb(255, 255, 255), 15, 170, 0, "%s are you a boy or a girl?", T.name);
	al_flip_display();

	//Bucle que iterara mentre no s'elegeixi un sexe
	while (chosen == 0){
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;
		al_draw_bitmap(aux_t[index].tainer, 200, 250, 0);
		al_draw_bitmap(firma, 30, 660, 0);
		//Mirem on hem de printar la fletxa de seleccio
		if (index == 0){
			A.x = 550;
			A.y = 400;
			al_draw_scaled_rotated_bitmap(SEL, A.x + ((0.08*al_get_bitmap_width(SEL)) / 2), A.y + ((0.08*al_get_bitmap_height(SEL)) / 2), A.x, A.y, 0.08, 0.08, -ALLEGRO_PI / 2, 0);
		}
		else{
			A.x = 100;
			A.y = 400;
			al_draw_scaled_rotated_bitmap(SEL, A.x + ((0.08*al_get_bitmap_width(SEL)) / 2), A.y + ((0.08*al_get_bitmap_height(SEL)) / 2), A.x, A.y, 0.08, 0.08, ALLEGRO_PI / 2, 0);
		}
		al_flip_display();
		al_init_timeout(&timeout, 1000);
		bool get_event = al_wait_for_event_until(q, &ev, &timeout);
		if (ev.type == ALLEGRO_EVENT_KEY_UP){
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER || ev.keyboard.keycode == ALLEGRO_KEY_Z){
				chosen = 1;
				T = aux_t[index];
				T.win = 0;
				T.loose = 0;
			}
			if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT && index != 0){
				index--;
				Draw_regionBackground();
			}
			if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT && index != 1){
				index++;
				Draw_regionBackground();
			}
		}
	}
	al_destroy_bitmap(SEL);
	al_destroy_bitmap(firma);
	al_destroy_font(font);
	return T;
}

Trainer ChooseStarter(Trainer T, Flist fl, Atklist al){
	//Variables bitmap
	ALLEGRO_BITMAP *pokeball = al_load_bitmap("Pokeball.PNG");
	ALLEGRO_BITMAP *background = al_load_bitmap("background.png");
	ALLEGRO_BITMAP *SEL = al_load_bitmap("se.png");
	ALLEGRO_BITMAP *firma = al_load_bitmap("firma.png");

	//Variables allegro
	
	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_FONT *font1 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 50, 0);
	ALLEGRO_FONT *font2 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//Variable spersonals
	int chosen = 0;
	int index = 0;
	int num = Flist_howmanystarters(fl);
	Arrow A;
	FKM *f;

	//Generem un array am el numero d'starters que tenim
	f = (FKM*)malloc(sizeof(FKM)* num);
	if (f == NULL){
		printf("\nError generating the starters");
	}
	else{
		//Omplim l'array amb els starters
		fl = Flist_start(fl);
		while (index < num){
			if (Flist_consult(fl).starter == true){
				f[index] = Flist_consult(fl);
				index++;
			}
			fl = Flist_forward(fl);
		}
		index = 0;
		al_draw_text(font1, al_map_rgb(255, 255, 255), 15, 15, 0, "Now is time to choose your new friend!!!");
		while (chosen == 0){
			//Anem mostran per pantalla tots els starters possibles
			f[index].front = al_load_bitmap(f[index].skin);
			al_draw_bitmap(f[index].front, 440, 230, 0);
			al_draw_textf(font2, al_map_rgb(255, 255, 255), 480, 540,0, "%s", f[index].name);
			al_draw_bitmap(pokeball, 850, 500, 0); 
			al_draw_bitmap(pokeball, -70, 500, 0);
			al_draw_bitmap(firma, 430, 660, 0);
			DrawTypes(f[index], 450, 170);
			ALLEGRO_EVENT ev;
			ALLEGRO_TIMEOUT timeout;
			//Mirem on he de printar la fletxa
			if (index > 0 && index < num-1 && index != num-1){
				A.x = 820;
				A.y = 340;
				al_draw_scaled_rotated_bitmap(SEL, A.x + ((0.08*al_get_bitmap_width(SEL)) / 2), A.y + ((0.08*al_get_bitmap_height(SEL)) / 2), A.x, A.y, 0.08, 0.08, -ALLEGRO_PI / 2, 0);
				A.x = 260;
				A.y = 380;
				al_draw_scaled_rotated_bitmap(SEL, A.x + ((0.08*al_get_bitmap_width(SEL)) / 2), A.y + ((0.08*al_get_bitmap_height(SEL)) / 2), A.x, A.y, 0.08, 0.08, ALLEGRO_PI / 2, 0);
			}
			else{
				if (index == 0){
					A.x = 820;
					A.y = 340;
					al_draw_scaled_rotated_bitmap(SEL, A.x + ((0.08*al_get_bitmap_width(SEL)) / 2), A.y + ((0.08*al_get_bitmap_height(SEL)) / 2), A.x, A.y, 0.08, 0.08, -ALLEGRO_PI / 2, 0);
				}
				else{
					if (index == num - 1){
						A.x = 260;
						A.y = 380;
						al_draw_scaled_rotated_bitmap(SEL, A.x + ((0.08*al_get_bitmap_width(SEL)) / 2), A.y + ((0.08*al_get_bitmap_height(SEL)) / 2), A.x, A.y, 0.08, 0.08, +ALLEGRO_PI / 2, 0);
					}
				}
			}
			al_flip_display();
			al_init_timeout(&timeout, 1000);
			bool get_event = al_wait_for_event_until(q, &ev, &timeout);
			if (ev.type == ALLEGRO_EVENT_KEY_UP){
				if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER || ev.keyboard.keycode == ALLEGRO_KEY_Z){
					chosen = 1;
					al = Atklist_start(al);
					while (strcmp(Atklist_consult(al).type, f[index].first_type) != 0){
						al = Atklist_forward(al);
					}
					//caracteristiques inicials dels pokemon
					f[index].a[0] = Atklist_consult(al);
					f[index].a[0].leftpp = f[index].a[0].pp;
					strcpy_s(f[index].a[1].name, "NULL");
					strcpy_s(f[index].a[2].name, "NULL");
					strcpy_s(f[index].a[3].name, "NULL");
					f[index].s.hp = f[index].s.fullhp;
					f[index].s.atk = f[index].base.atk;
					f[index].s.def = f[index].base.def;
					f[index].s.speed = f[index].base.speed;
					f[index].s.spa = f[index].base.spa;
					f[index].s.spd = f[index].base.spd;
					//Assignem els pokemons de l'entrenador
					T.team[0] = f[index];
					strcpy_s(T.team[1].name, "NULL");
					strcpy_s(T.team[2].name, "NULL");
					strcpy_s(T.team[3].name, "NULL");
					strcpy_s(T.team[4].name, "NULL");
					strcpy_s(T.team[5].name, "NULL");
					//Inicianiltzem la motxilla.
					int aux = 0;
					while (aux < 20){
						strcpy_s(T.B[aux].name, "NULL");
						aux++;
					}
					//Inicialitzem les medalles
					aux = 0;
					while (aux < 5){
						T.Badges[aux] = false;
						aux++;
					}
				}
				if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT && index != 0){
					index--;
					al_draw_bitmap_region(background, 150, 80, 700, 650, 150, 80, 0);
				}
				if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT && index != num - 1){
					index++;
					al_draw_bitmap_region(background,150, 80, 700, 650, 150, 80, 0);
				}
			}

		}
		
	}
	//Eliminem bitmas del heap
	al_destroy_bitmap(pokeball);
	al_destroy_bitmap(firma);
	al_destroy_bitmap(SEL);
	al_destroy_bitmap(background);
	al_destroy_font(font1);
	al_destroy_font(font2);
	return T;
}

void ShowMissage(){
	//Printem el quadre de text
	al_draw_filled_rounded_rectangle(30, 30, 710, 590, 20, 20, al_map_rgb(255, 255, 255));
	al_draw_rounded_rectangle(35, 35, 705, 585, 20, 20, al_map_rgb(102, 0, 102), 6);

	//Allegro variables
	ALLEGRO_KEYBOARD_STATE kbdstate;
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 30, 0);
	ALLEGRO_BITMAP *firma = al_load_bitmap("firma.png");

	al_draw_bitmap(firma, 30, 660, 0);

	//Anem mostran els missatges a mesura que es prem l'enter
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 55, 0, "- Now that you've have chosen who is gonna");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 95, 0, "be your friend, your adventure is about");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 135, 0, "to begin!!!");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	//Fins que es premi enter i espera a que es despremi la tecla
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 215, 0, "- As you go on you will be able to achieve ");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 255, 0, "new victories and also obtain new PKM!!!");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	//Fins que es premi enter i espera a que es despremi la tecla
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 335, 0, "- Please do not take into account about the");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 375, 0, "programming of this game, since it's simply");
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 415, 0, "a personal project for enterteinment");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	//Fins que es premi enter i espera a que es despremi la tecla
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	al_draw_text(font, al_map_rgb(0, 0, 0), 50, 495, 0, "- Thanks for playing and have fun!!! :)");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	//Fins que es premi enter i espera a que es despremi la tecla
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	al_destroy_bitmap(firma);
	al_destroy_font(font);
}

Trainer ChooseTrainer(Trainer T, Tlist tl, Flist fl, Atklist al){
	Draw_Background();
	ALLEGRO_BITMAP *prof = al_load_bitmap("Profesor.png");
	al_draw_bitmap(prof, 700, 100, 0);
	al_flip_display();
	//Enter name;
	T = grab_input(T);
	T.money = 1000;
	//Choose skin
	T = WhichSkin(T);
	Draw_Background();
	//Choose starter
	T = ChooseStarter(T, fl, al);
	Draw_Background();
	al_draw_bitmap(prof, 700, 100, 0);
	al_flip_display();
	ShowMissage();
	al_destroy_bitmap(prof);
	return T;
}

Trainer LoadTrainer(Trainer T, Tlist tl,Flist fl,Atklist al){
	//Variables bitmaps
	ALLEGRO_BITMAP *SEL = al_load_bitmap("se.png");
	ALLEGRO_BITMAP *firma = al_load_bitmap("firma.png");
	ALLEGRO_BITMAP *background = al_load_bitmap("background.png");

	//Variables allegro

	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_FONT *font1 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 50, 0);
	ALLEGRO_FONT *font2 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);
	ALLEGRO_KEYBOARD_STATE kbd;
	//Variable spersonals
	int chosen = 0;
	int index = 0;
	int num = Tlist_howmany(tl);
	Arrow A;
	Trainer *aux_t;
	aux_t = (Trainer*)malloc(sizeof(Trainer)*num);
	if (aux_t == NULL){
		printf("\nError loading trainers");
	}
	else{
		Draw_Background();
		
		//Omplim l'array amb els starters
		tl = Tlist_start(tl);
		if (Tlist_empty(tl)){
			Draw_Background();
			//Printem el quadre de text
			al_draw_filled_rounded_rectangle(30, 540, 1050, 700, 20, 20, al_map_rgb(255, 255, 255));
			al_draw_rounded_rectangle(35, 545, 1045, 695, 20, 20, al_map_rgb(102, 0, 102), 6);
			al_draw_text(font1, al_map_rgb(0, 0, 0), 170, 590, 0, "There's no previous savedata!!!");
			al_flip_display();
			al_get_keyboard_state(&kbd);
			while (al_key_down(&kbd, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbd, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbd); }
			while (al_key_down(&kbd, ALLEGRO_KEY_ENTER) == true && al_key_down(&kbd, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbd); }
			T = ChooseTrainer(T, tl,fl,al);
		} else{
			while (index < num){
				aux_t[index] = Tlist_consult(tl);
				index++;
				tl = Tlist_forward(tl);
			}
			index = 0;

			while (chosen == 0){
				//Anem mostrant per pantalla totes le spartides guardades
				al_draw_text(font1, al_map_rgb(255, 255, 255), 130, 30, 0, "choose your character:");
				aux_t[index].tainer = al_load_bitmap(aux_t[index].skin);
				al_draw_bitmap(aux_t[index].tainer, 380,130, 0);
				al_draw_textf(font2, al_map_rgb(255, 255, 255), 400, 570, 0, "%s", aux_t[index].name);
				al_draw_bitmap(firma, 30, 660, 0);
				Draw_team(aux_t[index].team, 900,al_map_rgb(255,255,255));
				ALLEGRO_EVENT ev;
				ALLEGRO_TIMEOUT timeout;
				//Mirem on he de printar la fletxa
				if (index > 0 && index < num - 1){
					A.x = 760;
					A.y = 220;
					al_draw_scaled_rotated_bitmap(SEL, A.x + ((0.08*al_get_bitmap_width(SEL)) / 2), A.y + ((0.08*al_get_bitmap_height(SEL)) / 2), A.x, A.y, 0.08, 0.08, -ALLEGRO_PI / 2, 0);
					A.x = 200;
					A.y = 260;
					al_draw_scaled_rotated_bitmap(SEL, A.x + ((0.08*al_get_bitmap_width(SEL)) / 2), A.y + ((0.08*al_get_bitmap_height(SEL)) / 2), A.x, A.y, 0.08, 0.08, ALLEGRO_PI / 2, 0);
				}
				else{
					if (index == 0 && num !=1){
						A.x = 760;
						A.y = 220;
						al_draw_scaled_rotated_bitmap(SEL, A.x + ((0.08*al_get_bitmap_width(SEL)) / 2), A.y + ((0.08*al_get_bitmap_height(SEL)) / 2), A.x, A.y, 0.08, 0.08, -ALLEGRO_PI / 2, 0);
					}
					else{
						if (index == num - 1 && num != 1){
							A.x = 200;
							A.y = 260;
							al_draw_scaled_rotated_bitmap(SEL, A.x + ((0.08*al_get_bitmap_width(SEL)) / 2), A.y + ((0.08*al_get_bitmap_height(SEL)) / 2), A.x, A.y, 0.08, 0.08, +ALLEGRO_PI / 2, 0);
						}
					}
				}
				al_flip_display();
				al_init_timeout(&timeout, 1000);
				bool get_event = al_wait_for_event_until(q, &ev, &timeout);
				if (ev.type == ALLEGRO_EVENT_KEY_UP){
					if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER || ev.keyboard.keycode == ALLEGRO_KEY_Z){
						chosen = 1;
						T = aux_t[index];
					}
					if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT && index != 0){
						index--;
						Draw_Background();
					}
					if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT && index != num - 1){
						index++;
						Draw_Background();
					}
				}

			}
		}
	}
	al_destroy_bitmap(SEL);
	al_destroy_bitmap(firma);
	al_destroy_bitmap(background);
	al_destroy_font(font1);
	al_destroy_font(font2);
	return T;
}