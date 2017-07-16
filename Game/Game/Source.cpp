
#include "types.h"
#include "atklist.h"
#include "objectslist.h"
#include "fkmlist.h"
#include "trainerlist.h"
#include "firstoptions.h"
#include "load.h"
#include "savedata.h"
#include "menu.h"
#include "team.h"
#include "growingup.h"
#include "generate.h"
#include "calculator.h"
#include "training.h"
#include "mart.h"
#include "bag.h"
#include "tournament.h"

Trainer T;
Prize *P;
int main(void){
	//Init allegro
	al_init();

	//Variable que ens mantindra dins el bucle general.
	int out = 0;

	//Variable new_game
	bool ng = true; 

	//Arrow variable
	Arrow A;
	A.x = 30;
	A.y = 50;

	//Variables de llista
	Atklist al;
	Olist ol;
	Flist fl,foel;
	Tlist tl;


	al = Atklist_create();
	ol = Olist_create();
	fl = Flist_create();
	tl = Tlist_create();
	foel = Flist_create();

	//Load data
	LoadFKM(fl);
	LoadT(tl);
	LoadAtk(al);
	LoadPrize(P);
	LoadFoe(foel);
	LoadMart(ol);

	//allegro variables
	ALLEGRO_DISPLAY *DISPLAY;
	ALLEGRO_KEYBOARD_STATE kbdstate;
	DISPLAY = al_create_display(1080, 720);
	inicia_allegro(DISPLAY);

	//New game or !new game
	ng = StartGame(&out);

	if (out == 0){
		if (!ng){
			T = LoadTrainer(T,tl,fl,al);
		}
		else{
			T = ChooseTrainer(T, tl, fl, al);
		}

		//fons epic del menu *-*
		Draw_MenuBackground();

		//Dibuixem el menu
		Draw_menu(T);

		//Printem l'equip de l'entrenador
		Draw_team(T.team, 580, al_map_rgb(0, 0, 0));

		//Printem la fletxa de seleccio
		DrawArrow(A, "arrowmenu.png");
	}
	
	//--------------------------------------------
	T.team[1].s.hp = 15;
	T.team[1].a[0] = Atklist_consult(al);
	T.team[1].a[0].leftpp = T.team[1].a[0].pp;
	
	T.team[1].s.atk = T.team[1].base.atk;
	T.team[1].s.def = T.team[1].base.def;
	T.team[1].s.speed = T.team[1].base.speed;
	T.team[1].s.spa = T.team[1].base.spa;
	T.team[1].s.spd = T.team[1].base.spd;
	//-------------------------------------------------

	//Bucle general
	while (out == 0){
		al_get_keyboard_state(&kbdstate);
		if (al_key_down(&kbdstate, ALLEGRO_KEY_ESCAPE)) out = 1; 
		A = ArrowPM(A, T);
		//Opcio que ens permetra interactuar amb els nostres pokemon
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && A.y == 50){
			ShowTeam(T.team);
			//fons epic del menu *-*
			Draw_MenuBackground();

			//Dibuixem el menu
			Draw_menu(T);

			//Printem l'equip de l'entrenador
			Draw_team(T.team, 580, al_map_rgb(0, 0, 0));

			//Printem la fletxa de seleccio
			DrawArrow(A, "arrowmenu.png");
			while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
		}
		//Opcio que ens permetra interactuar am la motxila
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && A.y == 135){
			T=Bag(T);

			//fons epic del menu *-*
			Draw_MenuBackground();

			//Dibuixem el menu
			Draw_menu(T);

			//Printem l'equip de l'entrenador
			Draw_team(T.team, 580, al_map_rgb(0, 0, 0));

			//Printem la fletxa de seleccio
			DrawArrow(A, "arrowmenu.png");
			while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
		}

		//Opcioq ue ens permetra comprar objectes per a la mtxilla
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && A.y == 220){
			T=Mart(ol,T);
			//fons epic del menu *-*
			Draw_MenuBackground();

			//Dibuixem el menu
			Draw_menu(T);

			//Printem l'equip de l'entrenador
			Draw_team(T.team, 580, al_map_rgb(0, 0, 0));

			//Printem la fletxa de seleccio
			DrawArrow(A, "arrowmenu.png");
			while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
		}

		//Opcio que ens permetra pujar de nivell als nostres pokemon
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && A.y == 305){
			T=Training(T, foel,al,fl);

			//fons epic del menu *-*
			Draw_MenuBackground();

			//Dibuixem el menu
			Draw_menu(T);

			//Printem l'equip de l'entrenador
			Draw_team(T.team, 580, al_map_rgb(0, 0, 0));

			//Printem la fletxa de seleccio
			DrawArrow(A, "arrowmenu.png");
			while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
		}
		//torneig pokemon
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && A.y == 390) {
			T = Tournament(foel, T, al, fl);

			//fons epic del menu *-*
			Draw_MenuBackground();

			//Dibuixem el menu
			Draw_menu(T);

			//Printem l'equip de l'entrenador
			Draw_team(T.team, 580, al_map_rgb(0, 0, 0));

			//Printem la fletxa de seleccio
			DrawArrow(A, "arrowmenu.png");
			while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true) { al_get_keyboard_state(&kbdstate); }
		}
		//Mostra estadistiques
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && A.y == 475){
			//TrainerEstadistics();
			while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
		}
		//Sortir del joc
		if ((al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) || al_key_down(&kbdstate, ALLEGRO_KEY_Z)) && A.y == 560){
			out = 1;
		}
		while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	}
	SaveTrainers(tl,T);
	tl = Tlist_destroy(tl);
	al = Atklist_destroy(al);
	fl = Flist_destroy(fl);
	ol = Olist_destroy(ol);
	al_rest(2);
	al_destroy_display(DISPLAY);
	return 0;
}