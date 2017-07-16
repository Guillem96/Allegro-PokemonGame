#include "team.h"



void Attackslogic(FKM f){
	int end = 0;

	ALLEGRO_BITMAP *sp = al_load_bitmap("special.gif");
	ALLEGRO_BITMAP *fi = al_load_bitmap("fisic.gif");

	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR ORANGE = al_map_rgb(255, 128, 0);
	ALLEGRO_COLOR DARKRED = al_map_rgb(130, 0, 0);
	ALLEGRO_COLOR RED = al_map_rgb(200, 0, 0);

	ALLEGRO_FONT *font3 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 25, 0);

	ALLEGRO_KEYBOARD_STATE kbs;
	int index_a = 0;
	float x = 480;
	float y = 75;
	Draw_stats(f, true);
	al_draw_textf(font3, WHITE, 230, 600, 0, "%d", f.a[index_a].power);
	al_draw_textf(font3, WHITE, 230, 650, 0, "%d", f.a[index_a].accuracy);
	al_draw_rounded_rectangle(x, y, 1055, y+130, 30, 30, RED, 6);
	if (f.a[index_a].category == 'F'){
		al_draw_scaled_bitmap(fi, 0, 0, al_get_bitmap_width(fi), al_get_bitmap_height(fi), 300, 625, al_get_bitmap_width(fi) * 2, al_get_bitmap_height(fi) * 2, 0);
	}
	else{
		al_draw_scaled_bitmap(sp, 0, 0, al_get_bitmap_width(fi), al_get_bitmap_height(fi), 300, 625, al_get_bitmap_width(fi) * 2, al_get_bitmap_height(fi) * 2, 0);
	}
	while (end == 0){
		al_get_keyboard_state(&kbs);
		if (al_key_down(&kbs, ALLEGRO_KEY_ENTER) || al_key_down(&kbs, ALLEGRO_KEY_BACKSPACE) || al_key_down(&kbs, ALLEGRO_KEY_Z)){
			end = 1;
			while (al_key_down(&kbs, ALLEGRO_KEY_ENTER) || al_key_down(&kbs, ALLEGRO_KEY_BACKSPACE) || al_key_down(&kbs, ALLEGRO_KEY_Z)){ al_get_keyboard_state(&kbs); }
		}
		if (al_key_down(&kbs, ALLEGRO_KEY_DOWN) && index_a < 3 && strcmp(f.a[index_a+1].name,"NULL")!=0){
			index_a++;
			while (al_key_down(&kbs, ALLEGRO_KEY_DOWN)){ al_get_keyboard_state(&kbs); }
			y += 160;
			Draw_stats(f, true);
			al_draw_textf(font3, WHITE, 230, 600, 0, "%d", f.a[index_a].power);
			al_draw_textf(font3, WHITE, 230, 650, 0, "%d", f.a[index_a].accuracy);
			//Printem categoria de l'atac
			if (f.a[index_a].accuracy == 'F'){
				al_draw_scaled_bitmap(fi, 0, 0, al_get_bitmap_width(fi), al_get_bitmap_height(fi), 300, 625, al_get_bitmap_width(fi) * 2, al_get_bitmap_height(fi) * 2, 0);
			}
			else{
				al_draw_scaled_bitmap(sp, 0, 0, al_get_bitmap_width(fi), al_get_bitmap_height(fi), 300, 625, al_get_bitmap_width(fi) * 2, al_get_bitmap_height(fi) * 2, 0);
			}
			al_draw_rounded_rectangle(x, y, 1055, y + 130, 30, 30, RED, 6);
		}
		if (al_key_down(&kbs, ALLEGRO_KEY_UP) && index_a != 0){
			index_a--;
			y -= 160;
			while (al_key_down(&kbs, ALLEGRO_KEY_UP)){ al_get_keyboard_state(&kbs); }
			Draw_stats(f, true);
			al_draw_textf(font3, WHITE, 230, 600, 0, "%d", f.a[index_a].power);
			al_draw_textf(font3, WHITE, 230, 650, 0, "%d", f.a[index_a].accuracy);
			al_draw_rounded_rectangle(x, y, 1055, y + 130, 30, 30, RED, 6);
			if (f.a[index_a].accuracy == 'F'){
				al_draw_scaled_bitmap(fi, 0, 0, al_get_bitmap_width(fi), al_get_bitmap_height(fi), 300, 625, al_get_bitmap_width(fi) * 2, al_get_bitmap_height(fi) * 2, 0);
			}
			else{
				al_draw_scaled_bitmap(sp, 0, 0, al_get_bitmap_width(fi), al_get_bitmap_height(fi), 300, 625, al_get_bitmap_width(fi) * 2, al_get_bitmap_height(fi) * 2, 0);
			}
		}
		al_flip_display();
	}
}

void PKMStatus(FKM *f,int index){
	ALLEGRO_KEYBOARD_STATE kbs;

	bool screen = false;//=0 show stadistics, =1 show attacks
	int out = 0;
	Draw_TeamBackground();
	Draw_stats(f[index],screen);

	while (out == 0){
		
		al_get_keyboard_state(&kbs);
		
		if (al_key_down(&kbs, ALLEGRO_KEY_LEFT) || al_key_down(&kbs, ALLEGRO_KEY_RIGHT)){
			screen = !screen;
			Draw_stats(f[index], screen);
		}

		if (al_key_down(&kbs, ALLEGRO_KEY_DOWN) && index < 5 && strcmp(f[index + 1].name,"NULL")!=0){
			index++;
			Draw_stats(f[index], screen);
		}
		if (al_key_down(&kbs, ALLEGRO_KEY_UP) && index != 0){
			index--;
			Draw_stats(f[index], screen);
		}
		if (al_key_down(&kbs, ALLEGRO_KEY_ENTER) || al_key_down(&kbs, ALLEGRO_KEY_Z) && screen){
			while (al_key_down(&kbs, ALLEGRO_KEY_ENTER) || al_key_down(&kbs, ALLEGRO_KEY_Z)){ al_get_keyboard_state(&kbs); }
			Attackslogic(f[index]);
			Draw_stats(f[index], true);
		}
		if (al_key_down(&kbs, ALLEGRO_KEY_BACKSPACE)){
			out = 1;
			while (al_key_down(&kbs, ALLEGRO_KEY_BACKSPACE) == true){ al_get_keyboard_state(&kbs);}
		}
		while (al_key_down(&kbs, ALLEGRO_KEY_UP) || al_key_down(&kbs, ALLEGRO_KEY_DOWN) ){ al_get_keyboard_state(&kbs); }
		while (al_key_down(&kbs, ALLEGRO_KEY_LEFT) || al_key_down(&kbs, ALLEGRO_KEY_RIGHT)){ al_get_keyboard_state(&kbs); }
	}
}

FKM PKMSwitch(FKM *f, int index){
	//Allegro collors
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR PURPLE = al_map_rgb(102, 0, 102);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 35, 0);

	ALLEGRO_KEYBOARD_STATE kbs;

	FKM aux;
	int indexs = 0;
	int chosen = 0;
	Arrow A;
	A.x = 40;
	A.y = 10;
	int out = 0;

	Draw_TeamBackground();
	DrawTeam(f);
	
	al_get_keyboard_state(&kbs);
	al_draw_filled_rounded_rectangle(575, 600, 1060, 680, 20, 20, WHITE);
	al_draw_rounded_rectangle(580, 605, 1055, 675, 20, 20, PURPLE, 5);
	al_draw_text(font, BLACK, 600, 620, 0, "Choose another PKM to swap");
	while (chosen == 0){
		al_get_keyboard_state(&kbs);
		if (al_key_down(&kbs, ALLEGRO_KEY_ENTER) || al_key_down(&kbs, ALLEGRO_KEY_Z)){
			aux = f[indexs];
			f[indexs] = f[index];
			f[index] = aux;
			chosen = 1;
		}
		A = Arrowswitchmenu(A, f, &indexs);
	}
	return *f;
}

void Showoptions(FKM *f,int index){
	ALLEGRO_KEYBOARD_STATE kbs;

	Arrow A;
	A.x = 850;
	A.y = 500;
	int chosen = 0;

	Printlittlemenu(A);
	A = Arrowlittlemenu(A);
	while (chosen == 0){
		A = Arrowlittlemenu(A);
		al_get_keyboard_state(&kbs);
		if ((al_key_down(&kbs, ALLEGRO_KEY_ENTER) || al_key_down(&kbs, ALLEGRO_KEY_Z)) && A.y == 500){
			chosen = 1;
			PKMStatus(f,index);
			while (al_key_down(&kbs, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbs, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbs); }
		}
		if ((al_key_down(&kbs, ALLEGRO_KEY_ENTER) || al_key_down(&kbs, ALLEGRO_KEY_Z)) && A.y == 560){
			while (al_key_down(&kbs, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbs, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbs); }
			chosen = 1;
			*f = PKMSwitch(f, index);
		}
		if ((al_key_down(&kbs, ALLEGRO_KEY_ENTER) || al_key_down(&kbs, ALLEGRO_KEY_Z)) && A.y == 620){
			chosen = 1;
			while (al_key_down(&kbs, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbs, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbs); }
		}
		
		al_flip_display();
	}
}

void ShowTeam(FKM *f){
	Arrow A;
	A.x = 40;
	A.y = 10;
	int out = 0;
	int index = 0;
	ALLEGRO_KEYBOARD_STATE kbs;
	//Printem el fons
	Draw_TeamBackground();
	DrawTeam(f);
	A = ArrowTeam(A, f, &index);
	DrawArrowTeam(A, "ballcursor.png");
	while (out == 0){
		al_get_keyboard_state(&kbs);
		if (al_key_down(&kbs, ALLEGRO_KEY_BACKSPACE))out = 1;
		//Si apretem enter sobre un pkm es mostra el menu petit
		if (al_key_down(&kbs, ALLEGRO_KEY_ENTER) || al_key_down(&kbs, ALLEGRO_KEY_Z)){
			Showoptions(f,index);
			Draw_TeamBackground();
			DrawTeam(f);
		}
		A = ArrowTeam(A,f,&index);
		
	}
}