#include "menu.h"

void Draw_menu(Trainer T){
	//Allegro colors
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR PURPLE = al_map_rgb(102, 0, 102);
	ALLEGRO_COLOR RED = al_map_rgb(200, 0, 0);

	ALLEGRO_BITMAP *firma = al_load_bitmap("firma.png");

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 65, 0);

	//Mostrem per pantalla el menu principal
	al_draw_bitmap(firma, 850, 660, 0);
	al_draw_filled_rounded_rectangle(30, 30, 500, 690, 20, 20, BLACK);
	al_draw_rounded_rectangle(35, 35, 495, 685, 20, 20, RED,4);
	al_draw_text(font, WHITE, 100, 50, 0, "POKEMON");
	al_draw_text(font, WHITE, 100, 135, 0, "BAG");
	al_draw_text(font, WHITE, 100, 220, 0, "MART");
	al_draw_text(font, WHITE, 100, 305, 0, "TRAINING");
	al_draw_text(font, WHITE, 100, 390, 0, "TOURNAMENT");
	al_draw_textf(font, WHITE, 100, 475, 0, "%s", T.name);
	al_draw_text(font, WHITE, 100, 560, 0, "EXIT & SAVE");
	al_flip_display();
	al_destroy_font(font);
	al_destroy_bitmap(firma);
}

void Draw_team(FKM team[6],float x, ALLEGRO_COLOR COLOR){
	//Carreguem bitmap pokeball
	ALLEGRO_BITMAP *pokeball = al_load_bitmap("Pokeball.png");

	//Variables personals
	int index = 0;
	float y = 90;
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 50, 0);
	ALLEGRO_FONT *pkm = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 20, 0);
	al_draw_text(font, COLOR, x-55, 25, 0, "TEAM:");

	//Mentre l slot de l equip estigui ple anem mostran els membres de l'equip a la dreta del menu
	while (index < 6){
		al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), x - 30, y - 10, al_get_bitmap_width(pokeball)*0.15, al_get_bitmap_height(pokeball)*0.15, 0);
		if (strcmp(team[index].name, "NULL") != 0){
			team[index].front = al_load_bitmap(team[index].skin);
			al_draw_scaled_bitmap(team[index].front, 0, 0, al_get_bitmap_width(team[index].front), al_get_bitmap_height(team[index].front), x, y, al_get_bitmap_width(team[index].front)*0.3, al_get_bitmap_height(team[index].front)*0.3, 0);
			al_draw_textf(pkm, COLOR, x, y + 70, 0, "%s", team[index].name);
		}
		
		index++;
		y += 100;
	}
	al_flip_display();
}