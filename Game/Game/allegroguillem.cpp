#include "allegroguillem.h"

void inicia_allegro(ALLEGRO_DISPLAY *DISPLAY){
	
	al_init_image_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
}

void Draw_Background(){
	ALLEGRO_BITMAP *background = al_load_bitmap("background.png");
	al_draw_bitmap(background, 0, 0, 0);
	
	al_flip_display();
	al_destroy_bitmap(background);
}

void Draw_regionBackground(){
	ALLEGRO_BITMAP *background = al_load_bitmap("background.png");
	al_draw_bitmap_region(background,0,220, 600, 600, 0, 220, 0);
	al_flip_display();
	al_destroy_bitmap(background);
}

void Draw_MenuBackground(){
	ALLEGRO_BITMAP *menubackground = al_load_bitmap("menubackground.jpg");
	al_draw_scaled_bitmap(menubackground, 0, 0, al_get_bitmap_width(menubackground), al_get_bitmap_height(menubackground), 0, 0, al_get_bitmap_width(menubackground)*0.65, al_get_bitmap_height(menubackground)*0.67,0);
	al_flip_display();
	al_destroy_bitmap(menubackground);
}

void Draw_TeamBackground(){
	ALLEGRO_BITMAP *teambackground = al_load_bitmap("teambackground.png");
	al_draw_scaled_bitmap(teambackground, 0, 0, al_get_bitmap_width(teambackground), al_get_bitmap_height(teambackground), 0, 0, al_get_bitmap_width(teambackground)*0.8, al_get_bitmap_height(teambackground)*0.8, 0);
	al_flip_display();
	al_destroy_bitmap(teambackground);
}

void DrawMartBckg(){
	ALLEGRO_BITMAP *martbackground = al_load_bitmap("martbackground.jpg");
	al_draw_scaled_bitmap(martbackground, 0, 0, al_get_bitmap_width(martbackground), al_get_bitmap_height(martbackground), 0, 0, 1080, 720, 0);
	al_flip_display();
	al_destroy_bitmap(martbackground);
}

void Draw_TournamentBackground() {
	ALLEGRO_BITMAP *giovanni = al_load_bitmap("giovanni.png");
	ALLEGRO_BITMAP *tournamentbackground = al_load_bitmap("tournamentbackground.jpg");
	al_draw_scaled_bitmap(tournamentbackground, 0, 0, al_get_bitmap_width(tournamentbackground), al_get_bitmap_height(tournamentbackground), 0, 0, 1080, 720, 0);
	al_draw_scaled_bitmap(giovanni, 0, 0, al_get_bitmap_width(giovanni), al_get_bitmap_height(giovanni), 680, 50, al_get_bitmap_width(giovanni)*0.6, al_get_bitmap_height(giovanni)*0.6, 0);
	al_flip_display();
	al_destroy_bitmap(tournamentbackground);
	al_destroy_bitmap(giovanni);
}