#include "arrowlogic.h"

Arrow arrowprincipalmenu(Arrow a){
	//allegro variables
	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout(&timeout, 1000);

	//Obtenim els botons que s'han apretat i depenent d 'aixo movem la fleta en una o altra direccio
	bool get_event = al_wait_for_event_until(q, &ev, &timeout);
	if (ev.type == ALLEGRO_EVENT_KEY_UP){
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP && a.y > 365){
			a.y -= 85;
			a.x -= 5;
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && a.y < 510){
			a.y += 85;
			a.x += 5;
			
		}
	}
	return a;
}

Arrow ArrowPM(Arrow a,Trainer T){
	//allegro variables
	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout(&timeout, 1000);

	bool get_event = al_wait_for_event_until(q, &ev, &timeout);
	if (ev.type == ALLEGRO_EVENT_KEY_UP){
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP && a.y > 50){
			a.y -= 85;
			Draw_menu(T);
			DrawArrow(a, "arrowmenu.png");
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && a.y < 560){
			a.y += 85;
			Draw_menu(T);
			DrawArrow(a, "arrowmenu.png");
		}
	}
	return a;
}

void DrawArrow(Arrow A, char *name){
	ALLEGRO_BITMAP *a = al_load_bitmap(name);
	al_draw_scaled_bitmap(a, 0, 0, al_get_bitmap_width(a), al_get_bitmap_height(a), A.x, A.y, al_get_bitmap_width(a)*0.6, al_get_bitmap_height(a)*0.6,0);
	al_flip_display();
	al_destroy_bitmap(a);
}

void DrawArrowTeam(Arrow A, char *name){
	ALLEGRO_BITMAP *a = al_load_bitmap(name);
	al_draw_scaled_bitmap(a, 0, 0, al_get_bitmap_width(a), al_get_bitmap_height(a), A.x-5, A.y-5, al_get_bitmap_width(a)*0.13, al_get_bitmap_height(a)*0.13, 0);
	al_flip_display();
	al_destroy_bitmap(a);
}

Arrow ArrowTeam(Arrow a, FKM f[6], int *index){
	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout(&timeout, 1000);
	DrawArrowTeam(a, "ballcursor.png");
	bool get_event = al_wait_for_event_until(q, &ev, &timeout);
	if (ev.type == ALLEGRO_EVENT_KEY_UP){
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP && a.y > 10){
			a.y -= 115;
			DrawTeam(f);
			DrawArrowTeam(a, "ballcursor.png");
			(*index)--;
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && a.y < 585 && strcmp("NULL",f[(*index)+1].name)!=0){
			a.y += 115;
			DrawTeam(f);
			DrawArrowTeam(a, "ballcursor.png");
			(*index)++;
		}
	}
	return a;
}

Arrow Arrowlittlemenu(Arrow a){
	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout(&timeout, 1000);
	bool get_event = al_wait_for_event_until(q, &ev, &timeout);
	if (ev.type == ALLEGRO_EVENT_KEY_UP){
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP && a.y > 500){
			a.y -= 60;
			Printlittlemenu(a);
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && a.y < 620){
			a.y += 60;
			Printlittlemenu(a);
		}
	}
	return a;
}

Arrow Arrowswitchmenu(Arrow a, FKM f[6], int *index){
	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT timeout;
	ALLEGRO_BITMAP *pokeball = al_load_bitmap("Pokeball.png");
	al_init_timeout(&timeout, 1000);
	DrawArrowTeam(a, "ballcursor.png");
	bool get_event = al_wait_for_event_until(q, &ev, &timeout);
	if (ev.type == ALLEGRO_EVENT_KEY_UP){
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP && a.y > 10){
			al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), 40, a.y, al_get_bitmap_width(pokeball)*0.35, al_get_bitmap_height(pokeball)*0.35, 0);
			a.y -= 115;
			DrawArrowTeam(a, "ballcursor.png");
			(*index)--;
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && a.y < 585 && strcmp("NULL", f[(*index) + 1].name) != 0){
			al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), 40, a.y, al_get_bitmap_width(pokeball)*0.35, al_get_bitmap_height(pokeball)*0.35, 0);
			a.y += 115;
			DrawArrowTeam(a, "ballcursor.png");
			(*index)++;
		}
	}
	
	return a;
}

Arrow HoodLogic(Arrow a){
	//allegro variables
	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout(&timeout, 1000);

	bool get_event = al_wait_for_event_until(q, &ev, &timeout);
	if (ev.type == ALLEGRO_EVENT_KEY_UP){
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP && a.y != 570){
			a.y -= 70;
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && a.y != 640){
			a.y += 70;
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT && a.x != 755){
			a.x += 245;
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT && a.x!= 510){
			a.x -= 245;
		}
	}
	return a;
}

Arrow HoodAtkLogic(Arrow a,FKM f){
	//allegro variables
	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout(&timeout, 1000);

	bool get_event = al_wait_for_event_until(q, &ev, &timeout);
	if (ev.type == ALLEGRO_EVENT_KEY_UP){
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP && a.y != 570){
			a.y -= 70;
			AttackHood(f, a);
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && a.y != 640){
			a.y += 70;
			AttackHood(f, a);
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT && a.x != 475){
			a.x += 450;
			AttackHood(f, a);
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT && a.x != 25){
			a.x -= 450;
			AttackHood(f, a);
		}
	}
	return a;
}
Arrow MartArrow(Arrow a, int *index_o){
	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT timeout;
	ALLEGRO_BITMAP *pokeball = al_load_bitmap("Pokeball.png");
	al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), a.x, a.y, al_get_bitmap_width(pokeball)*0.1, al_get_bitmap_height(pokeball)*0.1, 0);
	al_flip_display();
	al_init_timeout(&timeout, 1000);
	bool get_event = al_wait_for_event_until(q, &ev, &timeout);
	if (ev.type == ALLEGRO_EVENT_KEY_UP){
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP && a.y > 50){
			al_draw_filled_rectangle(340, 50 , 390, 540, al_map_rgb(150, 150, 150));
			a.y -= 50;
			al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), a.x, a.y, al_get_bitmap_width(pokeball)*0.1, al_get_bitmap_height(pokeball)*0.1, 0);
			(*index_o)--;
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && a.y < 500){
			al_draw_filled_rectangle(340, 50, 390, 540, al_map_rgb(150, 150, 150));
			a.y += 50;
			al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), a.x, a.y, al_get_bitmap_width(pokeball)*0.1, al_get_bitmap_height(pokeball)*0.1, 0);
			
			(*index_o)++;
		}
	}

	return a;
}

Arrow ObjectLogic(Arrow A,Object *o,int *index){
	ALLEGRO_COLOR ORANGE = al_map_rgb(255, 178, 102);

	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT timeout;

	al_draw_rounded_rectangle(A.x, A.y, A.x + 200, A.y + 112, 20, 20, al_map_rgb(255, 0, 0),3);

	al_flip_display();

	al_init_timeout(&timeout, 1000);
	bool get_event = al_wait_for_event_until(q, &ev, &timeout);
	if (ev.type == ALLEGRO_EVENT_KEY_UP){
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP && A.y > 222){
			al_draw_rounded_rectangle(A.x, A.y, A.x + 200, A.y + 112, 20, 20, ORANGE, 3);
			(*index) = (*index) - 5;
			A.y -= 120;
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && A.y < 702){
			if (strcmp(o[*index + 5].name, "NULL") != 0){
				al_draw_rounded_rectangle(A.x, A.y, A.x + 200, A.y + 112, 20, 20, ORANGE, 3);
				(*index) = (*index) + 5;
				A.y += 120;
			}
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT && A.x < 854){
			if (strcmp(o[*index + 1].name, "NULL") != 0){
				al_draw_rounded_rectangle(A.x, A.y, A.x + 200, A.y + 112, 20, 20, ORANGE, 3);
				(*index) = (*index) + 1;
				A.x += 208;
			}
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT && A.x > 22){
			al_draw_rounded_rectangle(A.x, A.y, A.x + 200, A.y + 112, 20, 20, ORANGE, 3);
			(*index) = (*index) - 1;
			A.x -= 208;
		}
	}
	return A;
}

Arrow Enemies_arrow(Arrow a) {
	ALLEGRO_BITMAP *pokeball = al_load_bitmap("Pokeball.png");

	ALLEGRO_EVENT_QUEUE* q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout(&timeout, 1000);
	bool used = false;
	
	bool get_event = al_wait_for_event_until(q, &ev, &timeout);
	if (ev.type == ALLEGRO_EVENT_KEY_UP) {
		al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), a.x, a.y, 50, 50, 0);
		//-----------------------Comportament quan la fletxa al girar a l'esquerra-----------------
		if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT && a.x != 30 && a.y != 300 && !used) {
			a.x -= 420;
			used = true;
		}

		//---------------------Comportament de la fletxa al tirar a la dreta---------------------
		if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT && a.x != 450 && a.y != 300 && !used) {
			a.x += 420;
			used = true;
		}
	
		//-----------------Comportament de la fletxa al tirar cap amunt--------------------
		//Al mig
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP && a.x == 240 && a.y != 170 && !used) {
			a.x -= 210;
			a.y -= 130;
			used = true;
		}
		//Abaix a l'esquerra
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP && a.x == 30 && a.y != 170 && !used) {
			a.x += 210;
			a.y -= 150;
			used = true;
		}
		//Abaix a al dreta
		if (ev.keyboard.keycode == ALLEGRO_KEY_UP && a.x == 450 && a.y != 170 && !used) {
			a.x -= 210;
			a.y -= 150;
			used = true;
		}

		//--------------------Comportament al tirar la fletxa cap abaix------------------

		//adalt esquerra
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && a.y != 450 && a.x == 30 && !used) {
			a.x += 210;
			a.y += 130;
			used = true;
		}
		//Adalt dreta
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && a.y != 450 && a.x == 450 && !used) {
			a.x -= 210;
			a.y += 130;
			used = true;
		}

		//Al mig
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN && a.y != 450 && a.x == 240 && !used) {
			a.x -= 210;
			a.y += 150;
			used = true;
		}
		
	}
	return a;
}

void Draw_enemiesarrow(Arrow a) {
	ALLEGRO_BITMAP *ar = al_load_bitmap("ballcursor.png");

	al_draw_scaled_bitmap(ar,0,0,al_get_bitmap_width(ar),al_get_bitmap_height(ar),a.x,a.y,50,50,0);
	al_flip_display();
}

