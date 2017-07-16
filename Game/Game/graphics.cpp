#include "graphics.h"

void DrawTeam(FKM f[6]){
	//Allegro colors
	ALLEGRO_COLOR GREEN = al_map_rgb(0, 153, 153);
	ALLEGRO_COLOR BGREEN = al_map_rgb(0, 220, 153);
	ALLEGRO_COLOR SKIN = al_map_rgb(255, 229, 204);
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR ORANGE = al_map_rgb(255, 128, 0);
	ALLEGRO_COLOR BLUE = al_map_rgb(0, 102, 204);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR YELLOW = al_map_rgb(255, 255, 153);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_BITMAP *pokeball = al_load_bitmap("Pokeball.png");

	ALLEGRO_FONT *fontname = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);
	ALLEGRO_FONT *fontstats = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 22, 0);

	//variables personals
	int index = 0;
	float x = 200;
	float y = 10;
	float auxx = 0;
	//% de vida
	float pc;
	int hp = 0;
	int max = 0;


	//Mostrem tot l'equip per pantalla
	while (index < 6){
		//Recuadres sobre els quals ficarem els pkm
		al_draw_filled_rounded_rectangle(x, y, x + 795, y + 105, 20, 20, GREEN);
		al_draw_filled_rounded_rectangle(x + 5, y + 5, x + 790, y + 100, 20, 20, SKIN);
		al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), x - 160, y, al_get_bitmap_width(pokeball)*0.35, al_get_bitmap_height(pokeball)*0.35, 0);
		//Si hi ha un pokm a l slot el printem
		if (strcmp(f[index].name, "NULL") != 0){
			//Bitmap pkm
			f[index].front = al_load_bitmap(f[index].skin);
			al_draw_scaled_bitmap(f[index].front, 0, 0, al_get_bitmap_width(f[index].front), al_get_bitmap_height(f[index].front), x + 20, y + 8, al_get_bitmap_width(f[index].front)*0.35, al_get_bitmap_height(f[index].front)*0.35, 0);
			//Nom pkm
			al_draw_textf(fontname, BLACK, x + 120, y + 10, 0, "%s", f[index].name);
			//Nivell
			al_draw_textf(fontname, BLUE, x + 320, y + 10, 0, "LVL: %d", f[index].lvl);
			//Calculem el % de vida
			max = f[index].s.fullhp;
			hp = f[index].s.hp;
			pc = (float)hp / (float)max;
			//Barra de vida
			al_draw_filled_rounded_rectangle(x + 135, y + 60, x + 603, y + 90, 15, 15, BLACK);
			//Si la vida esta al maxim mostrem la barra sencera
			if (pc == 1){
				al_draw_filled_rounded_rectangle(x + 177, y + 62, x + 600, y + 87, 15, 15, BGREEN);
			}
			else{
				//Sino marquem un interval utilitzant l'auxx perque la barra verda no es printi cap a les x negatives
				auxx = x + 200;
				if(pc>0.5)al_draw_filled_rounded_rectangle(x + 177, y + 62, auxx + (423 * pc), y + 87, 15, 15, BGREEN);
				if (pc<=0.5 && pc >0.2)al_draw_filled_rounded_rectangle(x + 177, y + 62, auxx + (423 * pc), y + 87, 15, 15, YELLOW);
				if (pc <= 0.2 && pc != 0)al_draw_filled_rounded_rectangle(x + 177, y + 62, auxx + (423 * pc), y + 87, 15, 15, RED);
			}
			//Punts hp
			al_draw_textf(fontstats, BLACK, x + 615, y + 60, 0, "%d / %d", f[index].s.hp, f[index].s.fullhp);
			al_draw_text(fontstats, ORANGE, x + 145, y + 63, 0, "HP.");
		}
		index++;
		y += 115;
		al_draw_text(fontstats, WHITE, 750, 690, 0, "PRESS BACKSPACE TO GO BACK");
		al_flip_display();
	}
	al_flip_display();
	al_destroy_bitmap(pokeball);
	al_destroy_font(fontname);
	al_destroy_font(fontstats);
}

void Printlittlemenu(Arrow A){
	//Allegro collors
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR PURPLE = al_map_rgb(102, 0, 102);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 45, 0);

	ALLEGRO_BITMAP *arrow = al_load_bitmap("arrowteam.png");

	al_draw_filled_rounded_rectangle(850, 490, 1060, 680, 20, 20, WHITE);
	al_draw_rounded_rectangle(855, 495, 1055, 675, 20, 20, PURPLE, 5);
	al_draw_scaled_bitmap(arrow, 0, 0, al_get_bitmap_width(arrow), al_get_bitmap_height(arrow), A.x, A.y, al_get_bitmap_width(arrow)*0.4, al_get_bitmap_height(arrow)*0.4, 0);
	al_draw_text(font, BLACK, 900, 500, 0, "Status");
	al_draw_text(font, BLACK, 900, 560, 0, "Switch");
	al_draw_text(font, BLACK, 900, 620, 0, "back");
	al_flip_display();
	al_destroy_bitmap(arrow);
	al_destroy_font(font);
}

void DrawTypes(FKM f,float x,float y){
	ALLEGRO_BITMAP *normal = al_load_bitmap("normal.gif");
	ALLEGRO_BITMAP *water = al_load_bitmap("water.gif");
	ALLEGRO_BITMAP *grass = al_load_bitmap("grass.gif");
	ALLEGRO_BITMAP *fire = al_load_bitmap("fire.gif");
	ALLEGRO_BITMAP *fight = al_load_bitmap("fighting.gif");
	ALLEGRO_BITMAP *poison = al_load_bitmap("poison.gif");
	ALLEGRO_BITMAP *psychic = al_load_bitmap("psychic.gif");
	ALLEGRO_BITMAP *ground = al_load_bitmap("ground.gif");
	ALLEGRO_BITMAP *rock = al_load_bitmap("rock.gif");
	ALLEGRO_BITMAP *dragon = al_load_bitmap("dragon.gif");
	ALLEGRO_BITMAP *electric = al_load_bitmap("electric.gif");
	ALLEGRO_BITMAP *ice = al_load_bitmap("ice.gif");
	ALLEGRO_BITMAP *ghost = al_load_bitmap("ghost.gif");
	ALLEGRO_BITMAP *dark = al_load_bitmap("dark.gif");
	ALLEGRO_BITMAP *steel = al_load_bitmap("steel.gif");
	ALLEGRO_BITMAP *bug = al_load_bitmap("bug.gif");
	ALLEGRO_BITMAP *flying = al_load_bitmap("flying.gif");

	//First types
	if (strcmp(f.first_type, "NORMAL") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(normal, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal)*2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "NORMAL") == 0)al_draw_scaled_bitmap(normal, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal)*2.2, 0);
	}
	if (strcmp(f.first_type, "WATER") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(water, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "WATER") == 0)al_draw_scaled_bitmap(water, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}

	if (strcmp(f.first_type, "GRASS") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(grass, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2, 0);
	}
	else{
		if (strcmp(f.first_type, "GRASS") == 0)al_draw_scaled_bitmap(grass, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2, 0);
	}
	if (strcmp(f.first_type, "FIRE") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(fire, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "FIRE") == 0)al_draw_scaled_bitmap(fire, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	if (strcmp(f.first_type, "FIGHT") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(fight, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "FIGHT") == 0)al_draw_scaled_bitmap(fight, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	
	if (strcmp(f.first_type, "POISON") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(poison, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "POISON") == 0)al_draw_scaled_bitmap(poison, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	if (strcmp(f.first_type, "PSYCHIC") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(psychic, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "PSYCHIC") == 0)al_draw_scaled_bitmap(psychic, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	if (strcmp(f.first_type, "GROUND") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(ground, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "GROUND") == 0)al_draw_scaled_bitmap(ground, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	if (strcmp(f.first_type, "ROCK") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(rock, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "ROCK") == 0)al_draw_scaled_bitmap(rock, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	if (strcmp(f.first_type, "DRAGON") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(dragon, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "DRAGON") == 0)al_draw_scaled_bitmap(dragon, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	if (strcmp(f.first_type, "ELECTRIC") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(electric, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "ELECTRIC") == 0)al_draw_scaled_bitmap(electric, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	if (strcmp(f.first_type, "ICE") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(ice, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "ICE") == 0)al_draw_scaled_bitmap(ice, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	if (strcmp(f.first_type, "GHOST") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(ghost, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "GHOST") == 0)al_draw_scaled_bitmap(ghost, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	if (strcmp(f.first_type, "DARK") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(dark, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "DARK") == 0)al_draw_scaled_bitmap(dark, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	if (strcmp(f.first_type, "STEEL") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(steel, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+40, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "STEEL") == 0)al_draw_scaled_bitmap(steel, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	if (strcmp(f.first_type, "BUG") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(bug, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	else{
		if (strcmp(f.first_type, "BUG") == 0)al_draw_scaled_bitmap(bug, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	if (strcmp(f.first_type, "FLYING") == 0 && strcmp(f.second_type, "NULL") == 0){
		al_draw_scaled_bitmap(flying, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x+50, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}else{
		if (strcmp(f.first_type, "FLYING") == 0)al_draw_scaled_bitmap(flying, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	}
	
	//second types
	x = x + 100;
	if (strcmp(f.second_type, "NORMAL") == 0) al_draw_scaled_bitmap(normal, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "WATER") == 0) al_draw_scaled_bitmap(water, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "GRASS") == 0) al_draw_scaled_bitmap(grass, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "FIRE") == 0) al_draw_scaled_bitmap(fire, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "FIGHT") == 0) al_draw_scaled_bitmap(fight, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "POISON") == 0) al_draw_scaled_bitmap(poison, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "PSYCHIC") == 0) al_draw_scaled_bitmap(psychic, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "GROUND") == 0) al_draw_scaled_bitmap(ground, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "ROCK") == 0) al_draw_scaled_bitmap(rock, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "DRAGON") == 0) al_draw_scaled_bitmap(dragon, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "ELECTRIC") == 0) al_draw_scaled_bitmap(electric, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "ICE") == 0) al_draw_scaled_bitmap(ice, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "GHOST") == 0) al_draw_scaled_bitmap(ghost, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "DARK") == 0) al_draw_scaled_bitmap(dark, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "STEEL") == 0) al_draw_scaled_bitmap(steel, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "BUG") == 0) al_draw_scaled_bitmap(bug, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	if (strcmp(f.second_type, "FLYING") == 0) al_draw_scaled_bitmap(flying, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 2.2, 0);
	al_flip_display();
	al_destroy_bitmap(normal);
	al_destroy_bitmap(water);
	al_destroy_bitmap(grass);
	al_destroy_bitmap(fire);
	al_destroy_bitmap(fight);
	al_destroy_bitmap(poison);
	al_destroy_bitmap(psychic);
	al_destroy_bitmap(ground);
	al_destroy_bitmap(rock);
	al_destroy_bitmap(dragon);
	al_destroy_bitmap(electric);
	al_destroy_bitmap(steel);
	al_destroy_bitmap(bug);
	al_destroy_bitmap(flying);

}

void PrintAttacks(FKM f){
	//Bitmaps dels tipus
	ALLEGRO_BITMAP *normal = al_load_bitmap("normal.gif");
	ALLEGRO_BITMAP *water = al_load_bitmap("water.gif");
	ALLEGRO_BITMAP *grass = al_load_bitmap("grass.gif");
	ALLEGRO_BITMAP *fire = al_load_bitmap("fire.gif");
	ALLEGRO_BITMAP *fight = al_load_bitmap("fighting.gif");
	ALLEGRO_BITMAP *poison = al_load_bitmap("poison.gif");
	ALLEGRO_BITMAP *psychic = al_load_bitmap("psychic.gif");
	ALLEGRO_BITMAP *ground = al_load_bitmap("ground.gif");
	ALLEGRO_BITMAP *rock = al_load_bitmap("rock.gif");
	ALLEGRO_BITMAP *dragon = al_load_bitmap("dragon.gif");
	ALLEGRO_BITMAP *electric = al_load_bitmap("electric.gif");
	ALLEGRO_BITMAP *ice = al_load_bitmap("ice.gif");
	ALLEGRO_BITMAP *ghost = al_load_bitmap("ghost.gif");
	ALLEGRO_BITMAP *dark = al_load_bitmap("dark.gif");
	ALLEGRO_BITMAP *steel = al_load_bitmap("steel.gif");
	ALLEGRO_BITMAP *bug = al_load_bitmap("bug.gif");
	ALLEGRO_BITMAP *flying = al_load_bitmap("flying.gif");


	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);

	//Font noms
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 50, 0);
	//Font pp
	ALLEGRO_FONT *font2 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 30, 0);

	int index = 0;
	float x, y;
	x = 500;
	y = 100;
	while (index < 4){
		if (strcmp(f.a[index].name, "NULL") != 0){
			//Mirem de quin tipus es l'attack
			if (strcmp(f.a[index].type, "NORMAL") == 0) al_draw_scaled_bitmap(normal, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "WATER") == 0) al_draw_scaled_bitmap(water, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "GRASS") == 0) al_draw_scaled_bitmap(grass, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "FIRE") == 0) al_draw_scaled_bitmap(fire, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "FIGHT") == 0) al_draw_scaled_bitmap(fight, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "POISON") == 0) al_draw_scaled_bitmap(poison, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "PSYCHIC") == 0) al_draw_scaled_bitmap(psychic, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "GROUND") == 0) al_draw_scaled_bitmap(ground, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "ROCK") == 0) al_draw_scaled_bitmap(rock, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "DRAGON") == 0) al_draw_scaled_bitmap(dragon, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "ELECTRIC") == 0) al_draw_scaled_bitmap(electric, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "ICE") == 0) al_draw_scaled_bitmap(ice, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "GHOST") == 0) al_draw_scaled_bitmap(ghost, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "DARK") == 0) al_draw_scaled_bitmap(dark, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "STEEL") == 0) al_draw_scaled_bitmap(steel, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "BUG") == 0) al_draw_scaled_bitmap(bug, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 3, al_get_bitmap_height(normal) * 3, 0);
			if (strcmp(f.a[index].type, "FLYING") == 0) al_draw_scaled_bitmap(flying, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2.2, al_get_bitmap_height(normal) * 3, 0);
			//Printem el nom i els pp de l'atack
			al_draw_textf(font, BLACK, x + 100, y + 40, 0, "%s", f.a[index].name);
			al_draw_textf(font2, BLACK, x + 420, y + 60, 0, "%d/%d pp", f.a[index].leftpp, f.a[index].pp);
			
		}
		else{
			//Si encara no te csap attack assignat mostrem un guio
			al_draw_text(font, BLACK, x + 250, y, 0, "-");
		}
		index++;
		y = y + 160;
	}
	al_flip_display();
	al_destroy_bitmap(normal);
	al_destroy_bitmap(water);
	al_destroy_bitmap(grass);
	al_destroy_bitmap(fire);
	al_destroy_bitmap(fight);
	al_destroy_bitmap(poison);
	al_destroy_bitmap(psychic);
	al_destroy_bitmap(ground);
	al_destroy_bitmap(rock);
	al_destroy_bitmap(dragon);
	al_destroy_bitmap(electric);
	al_destroy_bitmap(steel);
	al_destroy_bitmap(bug);
	al_destroy_bitmap(flying);
	al_destroy_font(font);
	al_destroy_font(font2);
}

void Draw_stats(FKM f, bool screen){
	//Allegro collors
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);
	ALLEGRO_COLOR DARKRED = al_map_rgb(130, 0, 0);
	ALLEGRO_COLOR GRAY = al_map_rgb(220, 220, 220);
	ALLEGRO_COLOR BLUE = al_map_rgb(0, 102, 204);
	ALLEGRO_COLOR DARKBLUE = al_map_rgb(0, 76, 153);
	ALLEGRO_COLOR ORANGE = al_map_rgb(255, 128, 0);
	ALLEGRO_COLOR DARKYELLOW = al_map_rgb(220, 207, 80);
	ALLEGRO_COLOR YELLOW = al_map_rgb(255, 255, 153);
	ALLEGRO_COLOR BGREEN = al_map_rgb(0, 220, 153);

	ALLEGRO_BITMAP *pkdx = al_load_bitmap("pkdx.png");
	ALLEGRO_BITMAP *pokeball = al_load_bitmap("Pokeball.png");

	//Font per mostra no0ms generals nom pkm, nom atak, nom stst
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 50, 0);
	//Font per mostra nivell
	ALLEGRO_FONT *font2 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 35, 0);
	//FOnt per a caracteristiques attack i exp.
	ALLEGRO_FONT *font3 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 25, 0);
	//Font per a orientacio
	ALLEGRO_FONT *font4 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 22, 0);

	float pc = 0;
	//Assigno una imatge al pokemon
	f.front = al_load_bitmap(f.skin);

	//Printo la capsalera
	al_draw_filled_rounded_rectangle(-100, 0, 700, 50, 30, 30, DARKBLUE);
	al_draw_filled_rounded_rectangle(-100, 0, 570, 50, 30, 30, BLUE);
	al_draw_text(font, WHITE, 50, -4, 0, "Pokemon info.");

	//Printem part esquerra de la pantalla
	al_draw_filled_rounded_rectangle(5, 55, 455, 715, 30, 30, RED);
	al_draw_filled_rounded_rectangle(10, 100, 430, 170, 10, 10, DARKRED);
	al_draw_textf(font, WHITE, 85, 105, 0, "%s", f.name);
	al_draw_textf(font2, WHITE, 340, 120, 0, "LV.%d", f.lvl);
	al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), 30, 110, al_get_bitmap_width(pokeball)*0.15, al_get_bitmap_height(pokeball)*0.15, 0);
	al_draw_filled_rounded_rectangle(40, 220, 420, 570, 20, 20, GRAY);
	al_draw_bitmap(f.front, 110, 250, 0);
	al_draw_scaled_bitmap(pkdx, 0, 0, al_get_bitmap_width(pkdx), al_get_bitmap_height(pkdx), 350, 620, al_get_bitmap_width(pkdx)*0.08, al_get_bitmap_height(pkdx)*0.08, 0);
	al_draw_filled_rounded_rectangle(40, 590, 420, 690, 10, 10, DARKRED);
	al_draw_filled_rounded_rectangle(65, 600, 215, 630, 15, 15, BLACK);
	al_draw_filled_rounded_rectangle(65, 650, 215, 680, 15, 15, BLACK);

	//Printem el tipus del pokemon
	DrawTypes(f, 140, 520);

	//Pantalla atacs o stats
	if (screen == false){
		//Pantalla d stats
		al_draw_filled_circle(620, 25, 10, WHITE);
		al_draw_filled_circle(670, 25, 10, BLACK);
		al_draw_textf(font3, BLUE, 75, 600, 0, "Experience");
		al_draw_textf(font3, BLUE, 85, 650, 0, "Next lvl.");
		al_draw_textf(font3, WHITE, 230, 600, 0, "%d POINTS", f.exp);
		al_draw_textf(font3, WHITE, 230, 650, 0, "%d POINTS",f.next_lvl);
		al_draw_filled_rounded_rectangle(460, 55, 1075, 715, 30, 30, DARKYELLOW);
		//recuadres on es mostraran els stats
		al_draw_filled_rounded_rectangle(480, 70, 1055, 165, 30, 30, YELLOW);
		al_draw_filled_rounded_rectangle(480, 175, 1055, 270, 30, 30, YELLOW); 
		al_draw_filled_rounded_rectangle(480, 280, 1055, 385, 30, 30, YELLOW);
		al_draw_filled_rounded_rectangle(480, 395, 1055, 490, 30, 30, YELLOW);
		al_draw_filled_rounded_rectangle(480, 500, 1055, 595, 30, 30, YELLOW);
		al_draw_filled_rounded_rectangle(480, 605, 1055, 700, 30, 30, YELLOW);
		al_draw_filled_rounded_rectangle(490, 90, 690, 130, 20, 20, BLACK);
		//Mostrem stats
		al_draw_text(font2, WHITE, 570, 90, 0, "HP");
		//Calculem el % de vida
		pc= (float)f.s.hp /(float) f.s.fullhp;
		//Barra de vida
		al_draw_filled_rounded_rectangle(570 , 135, 923, 160, 15, 15, BLACK);
		//Si la vida esta al maxim mostrem la barra sencera
		if (pc == 1){
			al_draw_filled_rounded_rectangle(570 + 50, 137, 920, 158, 13, 13, BGREEN);
		}
		else{
			//Sino marquem un interval utilitzant l'auxx perque la barra verda no es printi cap a les x negatives

			if(pc>0.5)al_draw_filled_rounded_rectangle(570 + 50, 137, 680 + (220 * pc), 158, 13, 13, BGREEN);
			if (pc <= 0.5&& pc > 0.2)al_draw_filled_rounded_rectangle(570 + 50, 137, 680 + (220 * pc), 158, 13, 13, YELLOW);
			if (pc <= 0.2 && pc != 0)al_draw_filled_rounded_rectangle(570 + 50, 137, 680 + (220 * pc), 158, 13, 13, RED);
		}
		//Punts hp
		al_draw_textf(font3, BLACK, 930, 135, 0, "%d / %d", f.s.hp, f.s.fullhp);
		al_draw_text(font3, ORANGE, 580, 132, 0, "HP.");
		al_draw_filled_rounded_rectangle(490, 195, 690, 235, 20, 20, BLACK);
		al_draw_text(font2, WHITE, 540, 195, 0, "ATTACK");
		al_draw_textf(font, BLACK, 920, 215, 0, "%d", f.s.atk);
		al_draw_filled_rounded_rectangle(490, 300, 690, 340, 20, 20, BLACK);
		al_draw_text(font2, WHITE, 530, 300, 0, "DEFENSE");
		al_draw_textf(font, BLACK, 920, 320, 0, "%d", f.s.def);
		al_draw_filled_rounded_rectangle(490, 415, 690, 455, 20, 20, BLACK);
		al_draw_text(font2, WHITE, 510, 415, 0, "SP.ATTACK");
		al_draw_textf(font, BLACK, 920, 435, 0, "%d", f.s.spa);
		al_draw_filled_rounded_rectangle(490, 520, 690, 560, 20, 20, BLACK);
		al_draw_text(font2, WHITE, 505, 520, 0, "SP.DEFENSE");
		al_draw_textf(font, BLACK, 920, 540, 0, "%d", f.s.spd);
		al_draw_filled_rounded_rectangle(490, 625, 690, 665, 20, 20, BLACK);
		al_draw_text(font2, WHITE, 550, 625, 0, "SPEED");
		al_draw_textf(font, BLACK, 920, 635, 0, "%d", f.s.speed);
	}
	else{
		//Pantalla dels attacks
		al_draw_filled_circle(620, 25, 10, BLACK);
		al_draw_filled_circle(670, 25, 10, WHITE);
		al_draw_textf(font3, ORANGE, 110, 600, 0, "POWER");
		al_draw_textf(font3, ORANGE, 90, 650, 0, "ACCURACY");
		//Recuadres on es mostraran els attacks
		al_draw_filled_rounded_rectangle(460, 55, 1075, 715, 30, 30, DARKYELLOW);
		al_draw_filled_rounded_rectangle(480, 75, 1055, 205, 30, 30, YELLOW);
		al_draw_filled_rounded_rectangle(480, 235, 1055, 365, 30, 30, YELLOW);
		al_draw_filled_rounded_rectangle(480, 395, 1055, 525, 30, 30, YELLOW);
		al_draw_filled_rounded_rectangle(480, 555, 1055, 685, 30, 30, YELLOW);
		//Proc per mostrar atacs i els eu tipus.
		PrintAttacks(f);
	}
	al_draw_text(font4, WHITE, 750, 10, 0, "PRESS BACKSPACE TO GO BACK");
	al_flip_display();
	al_destroy_font(font);
	al_destroy_font(font2);
	al_destroy_font(font3);
	al_destroy_font(font4);
	al_destroy_bitmap(pkdx);
	al_destroy_bitmap(pokeball);
}

void DrawVs(Trainer T, Flist foe){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);

	ALLEGRO_BITMAP *vs = al_load_bitmap("vs.png");
	ALLEGRO_BITMAP *pkb = al_load_bitmap("Pokeball.png");
	ALLEGRO_BITMAP *versus = al_load_bitmap("versus.png");

	ALLEGRO_KEYBOARD_STATE kbdstate;

	//Font per mostra nomentrenador
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 70, 0);
	//Font per mostra noms pkm
	ALLEGRO_FONT *font2 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 35, 0);
	//font titol
	ALLEGRO_FONT *title = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 110, 0);

	FKM e;
	al_clear_to_color(BLACK);
	//Bitmap vs
	al_draw_scaled_bitmap(vs, 0, 0, al_get_bitmap_width(vs), al_get_bitmap_height(vs), 0, 150, al_get_bitmap_width(vs)*1.3 ,al_get_bitmap_height(vs)*1.3, 0);
	al_draw_bitmap(versus, 450, 250, 0);
	//Pokeballs esquines
	al_draw_scaled_bitmap(pkb, 0, 0, al_get_bitmap_width(pkb), al_get_bitmap_height(pkb), 1080 - al_get_bitmap_width(pkb)*0.5, -0, al_get_bitmap_width(pkb)*0.5, al_get_bitmap_height(pkb)*0.5, 0);
	al_draw_scaled_bitmap(pkb, 0, 0, al_get_bitmap_width(pkb), al_get_bitmap_height(pkb), 0, 0, al_get_bitmap_width(pkb)*0.5, al_get_bitmap_height(pkb)*0.5, 0);
	//Tttol training
	al_draw_text(title, WHITE, 330, 10, 0, "TRAINING");
	//Mostrem l entrenador a la part esquerra
	T.tainer = al_load_bitmap(T.skin);
	al_draw_bitmap(T.tainer, 100, 150, 0);
	al_draw_textf(font, WHITE, 150, 600, 0, "%s", T.name);

	foe = Flist_start(foe);
	//Carreguem el primer enemic
	e = Flist_consult(foe);
	e.front = al_load_bitmap(e.skin);
	al_draw_scaled_bitmap(e.front, 0, 0, al_get_bitmap_width(e.front), al_get_bitmap_height(e.front), 620, 150, al_get_bitmap_width(e.front)*0.5, al_get_bitmap_height(e.front)*0.5, 0);
	al_draw_textf(font2, BLACK, 630, 250, 0, "%s", e.name);
	foe = Flist_forward(foe);


	//carreguem el segon enemic
	e = Flist_consult(foe);
	e.front = al_load_bitmap(e.skin);
	al_draw_scaled_bitmap(e.front, 0, 0, al_get_bitmap_width(e.front), al_get_bitmap_height(e.front), 760, 280, al_get_bitmap_width(e.front)*0.5, al_get_bitmap_height(e.front)*0.5, 0);
	al_draw_textf(font2, BLACK, 770, 380, 0, "%s", e.name);
	foe = Flist_forward(foe);

	//carreguem el tercer enemic
	e = Flist_consult(foe);
	e.front = al_load_bitmap(e.skin);
	al_draw_scaled_bitmap(e.front, 0, 0, al_get_bitmap_width(e.front), al_get_bitmap_height(e.front), 900, 410, al_get_bitmap_width(e.front)*0.5, al_get_bitmap_height(e.front)*0.5, 0);
	al_draw_textf(font2, BLACK, 910, 510, 0, "%s", e.name);
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	//Fins que es premi enter i espera a que es despremi la tecla
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	al_destroy_font(font);
	al_destroy_font(font2);
	al_destroy_font(title);
	al_destroy_bitmap(vs);
	al_destroy_bitmap(pkb);
	al_destroy_bitmap(versus);
}

void DrawArena(){
	ALLEGRO_BITMAP *back = al_load_bitmap("arenabackground.jpg");
	ALLEGRO_BITMAP *foep = al_load_bitmap("wildcombat_foe.png");
	ALLEGRO_BITMAP *youp = al_load_bitmap("wildcombat_you.png");
	al_draw_scaled_bitmap(back, 0, 0, al_get_bitmap_width(back), al_get_bitmap_height(back), -100, 0, 1200, 720, 0);
	al_draw_scaled_bitmap(youp, 0, 0, al_get_bitmap_width(youp), al_get_bitmap_height(youp), 0, 345, al_get_bitmap_width(youp) * 2, al_get_bitmap_height(youp)*2,0);
	al_draw_scaled_bitmap(foep, 0, 0, al_get_bitmap_width(foep), al_get_bitmap_height(foep), 520, 100, al_get_bitmap_width(foep) * 3, al_get_bitmap_height(foep) * 3, 0);
	al_flip_display();
}

void Drawcondition(FKM f, FKM e){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);
	ALLEGRO_COLOR BLUE = al_map_rgb(0, 102, 204);
	ALLEGRO_COLOR CBLUE = al_map_rgb(0, 152, 254);
	ALLEGRO_COLOR BGREEN = al_map_rgb(0, 220, 153);
	ALLEGRO_COLOR ORANGE = al_map_rgb(255, 128, 0);
	ALLEGRO_COLOR GRAY = al_map_rgb(100, 100, 100);
	ALLEGRO_COLOR YELLOW = al_map_rgb(255, 255, 153);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	ALLEGRO_FONT *font2 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 20, 0);

	float pc = 0;

	//----------PKM RIVAL------------
	al_draw_filled_rounded_rectangle(20, 20, 580, 150, 20, 20, BLACK);
	al_draw_rounded_rectangle(25, 25, 575, 145, 20, 20, RED, 4);
	e.front = al_load_bitmap(e.skin);
	al_draw_scaled_bitmap(e.front, 0, 0, al_get_bitmap_width(e.front), al_get_bitmap_height(e.front), 720, 145, al_get_bitmap_width(e.front)*0.8, al_get_bitmap_height(e.front)*0.8, 0);
	al_draw_textf(font, WHITE, 40, 30, 0, "%s", e.name);
	al_draw_textf(font, BLUE, 425, 30, 0, "Lvl.%d", e.lvl);
	//----------HP-----------
	pc = (float)e.s.hp / (float)e.s.fullhp;
	//Barra de vida
	al_draw_filled_rounded_rectangle(150, 100, 530, 120, 13, 13, GRAY);
	//Si la vida esta al maxim mostrem la barra sencera
	if (pc == 1){
		al_draw_filled_rounded_rectangle(190, 102, 527, 118, 10, 10, BGREEN);
	}
	else{
		//Sino marquem un interval utilitzant l'auxx perque la barra verda no es printi cap a les x negatives
		if (pc>0.5)al_draw_filled_rounded_rectangle(190, 102, 200 + (315 * pc), 118, 10, 10, BGREEN);
		if (0.2<pc && pc<=0.5)al_draw_filled_rounded_rectangle(190, 102, 200 + (315 * pc), 118, 10, 10, YELLOW);
		if (pc <= 0.2 && pc != 0)al_draw_filled_rounded_rectangle(190, 102, 200 + (315 * pc), 118, 10, 10, RED);
	}
	al_draw_text(font2, ORANGE, 160, 98, 0, "HP.");

	//-----------PKM AMIC-------------
	al_draw_filled_rounded_rectangle(500, 390, 1060, 540, 20, 20, BLACK);
	al_draw_rounded_rectangle(505, 395, 1055, 535, 20, 20, RED, 4);
	f.back = al_load_bitmap(f.skinb);
	al_draw_bitmap(f.back, 130, 310, 0);
	al_draw_textf(font, WHITE, 520, 400, 0, "%s", f.name);
	al_draw_textf(font, BLUE, 930, 400, 0, "Lvl.%d", f.lvl);

	//----------HP-----------
	pc = (float)f.s.hp / (float)f.s.fullhp;
	//Barra de vida
	al_draw_filled_rounded_rectangle(530, 460, 910, 480, 13, 13, GRAY);
	//Si la vida esta al maxim mostrem la barra sencera
	if (pc == 1){
		al_draw_filled_rounded_rectangle(570, 462, 907, 478, 10, 10, BGREEN);
	}
	else{
		//Sino marquem un interval utilitzant l'auxx perque la barra verda no es printi cap a les x negatives
		if (pc > 0.5)al_draw_filled_rounded_rectangle(570, 462, 580 + (310 * pc), 478, 10, 10, BGREEN);
		if (0.2 < pc && pc<= 0.5)al_draw_filled_rounded_rectangle(570, 462, 580 + (310 * pc), 478, 10, 10, YELLOW);
		if (pc <= 0.2 && pc != 0)al_draw_filled_rounded_rectangle(570, 462, 580 + (310 * pc), 478, 10, 10, RED);
	}
	al_draw_text(font2, ORANGE, 540, 458, 0, "HP.");
	al_draw_textf(font2, WHITE, 920, 470, 0, "%d / %d", f.s.hp, f.s.fullhp);

	//--------EXP-----------
	pc = (float)f.exp / (float)f.next_lvl;
	//barra exp
	al_draw_filled_rectangle(530, 500, 1010, 520, GRAY);
	al_draw_filled_rectangle(580, 502, 590 + (420 * pc), 518, CBLUE);
	al_draw_text(font2, YELLOW, 540, 498, 0, "Exp.");


	al_flip_display();
	
}

void DrawHood(FKM f, Arrow a){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 50, 0);

	ALLEGRO_BITMAP *arrow = al_load_bitmap("arrowmenu.png");
	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_filled_rounded_rectangle(500, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(505, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_text(font, WHITE, 570, 570, 0, "ATTACK");
	al_draw_text(font, WHITE, 570, 640, 0, "BAG");
	al_draw_text(font, WHITE, 815, 570, 0, "POKEMON");
	al_draw_text(font, WHITE, 815, 640, 0, "ESCAPE");
	al_draw_scaled_bitmap(arrow, 0, 0, al_get_bitmap_width(arrow), al_get_bitmap_height(arrow), a.x, a.y, al_get_bitmap_width(arrow)*0.5, al_get_bitmap_height(arrow)*0.5, 0);
	al_draw_textf(font, WHITE, 40, 570, 0, "What will");
	al_draw_textf(font, WHITE, 40, 640, 0, "%s do?",f.name);
	al_flip_display();
	al_destroy_bitmap(arrow);
	al_destroy_font(font);
}

void AtkCaracteristics(Attack a){
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 30, 0);

	//Bitmaps dels tipus
	ALLEGRO_BITMAP *normal = al_load_bitmap("normal.gif");
	ALLEGRO_BITMAP *water = al_load_bitmap("water.gif");
	ALLEGRO_BITMAP *grass = al_load_bitmap("grass.gif");
	ALLEGRO_BITMAP *fire = al_load_bitmap("fire.gif");
	ALLEGRO_BITMAP *fight = al_load_bitmap("fighting.gif");
	ALLEGRO_BITMAP *poison = al_load_bitmap("poison.gif");
	ALLEGRO_BITMAP *psychic = al_load_bitmap("psychic.gif");
	ALLEGRO_BITMAP *ground = al_load_bitmap("ground.gif");
	ALLEGRO_BITMAP *rock = al_load_bitmap("rock.gif");
	ALLEGRO_BITMAP *dragon = al_load_bitmap("dragon.gif");
	ALLEGRO_BITMAP *electric = al_load_bitmap("electric.gif");
	ALLEGRO_BITMAP *ice = al_load_bitmap("ice.gif");
	ALLEGRO_BITMAP *ghost = al_load_bitmap("ghost.gif");
	ALLEGRO_BITMAP *dark = al_load_bitmap("dark.gif");
	ALLEGRO_BITMAP *steel = al_load_bitmap("steel.gif");
	ALLEGRO_BITMAP *bug = al_load_bitmap("bug.gif");
	ALLEGRO_BITMAP *flying = al_load_bitmap("flying.gif");

	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	
	float x = 920;
	float y = 590;

	if (strcmp(a.name, "NULL") != 0){
		//Mirem de quin tipus es l'attack
		if (strcmp(a.type, "NORMAL") == 0) al_draw_scaled_bitmap(normal, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		if (strcmp(a.type, "WATER") == 0) al_draw_scaled_bitmap(water, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		if (strcmp(a.type, "GRASS") == 0) al_draw_scaled_bitmap(grass, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		if (strcmp(a.type, "FIRE") == 0) al_draw_scaled_bitmap(fire, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		if (strcmp(a.type, "FIGHT") == 0) al_draw_scaled_bitmap(fight, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		if (strcmp(a.type, "POISON") == 0) al_draw_scaled_bitmap(poison, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		if (strcmp(a.type, "PSYCHIC") == 0) al_draw_scaled_bitmap(psychic, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		if (strcmp(a.type, "GROUND") == 0) al_draw_scaled_bitmap(ground, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		if (strcmp(a.type, "ROCK") == 0) al_draw_scaled_bitmap(rock, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		if (strcmp(a.type, "DRAGON") == 0) al_draw_scaled_bitmap(dragon, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) *2, 0);
		if (strcmp(a.type, "ELECTRIC") == 0) al_draw_scaled_bitmap(electric, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 3, 0);
		if (strcmp(a.type, "ICE") == 0) al_draw_scaled_bitmap(ice, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) *2, 0);
		if (strcmp(a.type, "GHOST") == 0) al_draw_scaled_bitmap(ghost, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		if (strcmp(a.type, "DARK") == 0) al_draw_scaled_bitmap(dark, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		if (strcmp(a.type, "STEEL") == 0) al_draw_scaled_bitmap(steel, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		if (strcmp(a.type, "BUG") == 0) al_draw_scaled_bitmap(bug, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		if (strcmp(a.type, "FLYING") == 0) al_draw_scaled_bitmap(flying, 0, 0, al_get_bitmap_width(normal), al_get_bitmap_height(normal), x, y, al_get_bitmap_width(normal) * 2, al_get_bitmap_height(normal) * 2, 0);
		//Printem els pp de l'atack
		al_draw_textf(font, WHITE, x - 30, y + 50, 0, "%d/%d pp", a.leftpp, a.pp);

	}
	else{
		//Si encara no te csap attack assignat mostrem un guio
		al_draw_text(font, WHITE, x + 250, y+60, 0, "-");
	}

}

void AttackHood(FKM f, Arrow a){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 45, 0);

	ALLEGRO_BITMAP *arrow = al_load_bitmap("arrowmenu.png");

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 80, 570, 0, "%s",f.a[0].name);
	if (strcmp(f.a[1].name, "NULL") != 0){
		al_draw_textf(font, WHITE, 80, 640, 0, "%s", f.a[1].name);
	}
	else{
		al_draw_textf(font, WHITE, 130, 640, 0, "-");
	}
	if (strcmp(f.a[2].name, "NULL") != 0){
		al_draw_textf(font, WHITE, 550, 570, 0, "%s", f.a[2].name);
	}
	else{
		al_draw_textf(font, WHITE, 600, 570, 0, "-");
	}
	if (strcmp(f.a[3].name, "NULL") != 0){
		al_draw_textf(font, WHITE, 550, 640, 0, "%s", f.a[3].name);
	}
	else{
		al_draw_textf(font, WHITE, 600, 640, 0, "-");
	}
	al_draw_filled_rounded_rectangle(830, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(835, 555, 1055, 705, 20, 20, RED, 4);
	if (a.x == 25 && a.y == 570)AtkCaracteristics(f.a[0]);
	if (a.x == 25 && a.y == 640)AtkCaracteristics(f.a[1]);
	if (a.x == 475 && a.y == 570)AtkCaracteristics(f.a[2]);
	if (a.x == 475 && a.y == 640)AtkCaracteristics(f.a[3]);
	al_draw_scaled_bitmap(arrow, 0, 0, al_get_bitmap_width(arrow), al_get_bitmap_height(arrow), a.x, a.y, al_get_bitmap_width(arrow)*0.5, al_get_bitmap_height(arrow)*0.5, 0);
	
	
	al_flip_display();
	al_destroy_bitmap(arrow);
	al_destroy_font(font);
}

void ShowLevelUp(FKM f,int *a,int lvl){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 45, 0);

	al_draw_filled_rounded_rectangle(700, 20, 1060, 520, 20, 20, BLACK);
	al_draw_rounded_rectangle(705, 25, 1055, 515, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 730, 70, 0, "HP");
	al_draw_textf(font, WHITE, 970, 70, 0, "+%d",a[5]);
	al_draw_textf(font, WHITE, 730, 140, 0, "ATTACK");
	al_draw_textf(font, WHITE, 970, 140, 0, "+%d", a[0]);
	al_draw_textf(font, WHITE, 730, 210, 0, "DEFENSE");
	al_draw_textf(font, WHITE, 950, 210, 0, "+%d", a[1]);
	al_draw_textf(font, WHITE, 730, 280, 0, "SP.ATTACK");
	al_draw_textf(font, WHITE, 970, 280, 0, "+%d", a[2]);
	al_draw_textf(font, WHITE, 730, 350, 0, "SP.DEFENSE");
	al_draw_textf(font, WHITE, 970, 350, 0, "+%d", a[3]);
	al_draw_textf(font, WHITE, 730, 420, 0, "SPEED");
	al_draw_textf(font, WHITE, 970, 420, 0, "+%d", a[4]);
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "Your %s has grow into level %d!!!.", f.name,lvl);
	al_flip_display();
	al_rest(3);
	al_draw_filled_rounded_rectangle(700, 20, 1060, 520, 20, 20, BLACK);
	al_draw_rounded_rectangle(705, 25, 1055, 515, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 730, 70, 0, "HP");
	al_draw_textf(font, WHITE, 970, 70, 0, "%d", f.s.fullhp);
	al_draw_textf(font, WHITE, 730, 140, 0, "ATTACK");
	al_draw_textf(font, WHITE, 970, 140, 0, "%d", f.s.atk);
	al_draw_textf(font, WHITE, 730, 210, 0, "DEFENSE");
	al_draw_textf(font, WHITE, 950, 210, 0, "%d", f.s.def);
	al_draw_textf(font, WHITE, 730, 280, 0, "SP.ATTACK");
	al_draw_textf(font, WHITE, 970, 280, 0, "%d", f.s.spa);
	al_draw_textf(font, WHITE, 730, 350, 0, "SP.DEFENSE");
	al_draw_textf(font, WHITE, 970, 350, 0, "%d", f.s.spd);
	al_draw_textf(font, WHITE, 730, 420, 0, "SPEED");
	al_draw_textf(font, WHITE, 970, 420, 0, "%d", f.s.speed);
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "Your %s has grow into level %d!!!.", f.name, lvl);
	al_flip_display();
	al_rest(3);
}

void DrawMart(Object *o, int max,Trainer T){
	//Allegro collors
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR PURPLE = al_map_rgb(102, 0, 102);
	ALLEGRO_COLOR GRAY = al_map_rgb(150, 150, 150);
	ALLEGRO_COLOR BLUE = al_map_rgb(0, 102, 204);

	//Bitmaps
	ALLEGRO_BITMAP *seller = al_load_bitmap("seller.png");
	ALLEGRO_BITMAP *icon = al_load_bitmap("marticon.gif");

	//Fonts
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 35, 0);
	ALLEGRO_FONT *font2 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 20, 0);

	int index = 0;
	float x = 400;
	float y = 50;

	//Dibuixem el fons de la tenda
	DrawMartBckg();

	//Dibuixem la interficie de la tenda
	al_draw_filled_rounded_rectangle(300, 10, 1070, 710, 20, 20, BLACK);
	al_draw_filled_rounded_rectangle(310, 20, 1060, 700, 20, 20, BLUE);
	al_draw_filled_rounded_rectangle(330, 40, 1040, 550, 20, 20, GRAY);
	al_draw_filled_rounded_rectangle(920, 560, 1040, 680, 20, 20, GRAY);
	

	//Escrivim tots els objectes disponibles
	while (index < max){
		al_draw_textf(font, BLACK, x, y, 0, "%s", o[index].name);
		al_draw_textf(font, BLACK, x+500, y, 0, "%d $", o[index].price);
		index++;
		y += 50;
	}
	//Printem el venedor a l'esquerra
	al_draw_scaled_bitmap(seller, 0, 0, al_get_bitmap_width(seller), al_get_bitmap_height(seller), -95, 10, al_get_bitmap_width(seller)*0.8, al_get_bitmap_height(seller)*0.8, 0);
	al_draw_text(font2, WHITE, 10, 700, 0, "Backspace to go back");

	//Interficie on es mostren els diners
	al_draw_filled_rounded_rectangle(20, 550, 280, 700, 20, 20, BLACK);
	al_draw_filled_rounded_rectangle(30, 560, 270, 690, 20, 20, BLUE);
	al_draw_filled_rounded_rectangle(40, 570, 150, 680, 20, 20, GRAY);
	al_draw_text(font2, WHITE, 160, 590, 0, "YOUR MONEY:");
	al_draw_textf(font2, WHITE, 160, 630, 0, "%d $",T.money);
	al_draw_bitmap(icon, 55, 580, 0);

	//Eliminem els bitmpas
	al_flip_display();
	
	al_destroy_bitmap(seller);
	al_destroy_bitmap(icon);
	al_destroy_font(font);
	al_destroy_font(font2);
}

void DrawBagInterface(char *name){
	//AllegroCollors
	ALLEGRO_COLOR GREENC = al_map_rgb(106, 228, 130);
	ALLEGRO_COLOR GREEND = al_map_rgb(92, 204, 114);
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR DARKORANGE = al_map_rgb(255, 153, 51);
	ALLEGRO_COLOR ORANGE = al_map_rgb(255, 178, 102);

	//Fonts
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 80, 0);
	ALLEGRO_FONT *font2 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 20, 0);

	//Bitmaps
	ALLEGRO_BITMAP *bag = al_load_bitmap("bag.png");
	ALLEGRO_BITMAP *back = al_load_bitmap("bagbackground.png");

	//Printem fons
	al_draw_scaled_bitmap(back, 0, 0, al_get_bitmap_width(back), al_get_bitmap_height(back), 0, 0, 1080, 720, 0);

	//Dibuixem part superior de la interfas
	al_draw_filled_rounded_rectangle(10, -50, 1070, 200, 20, 20, BLACK);
	al_draw_filled_rounded_rectangle(15, -50, 1065, 195, 20, 20, GREENC);
	al_draw_filled_rounded_rectangle(30, 20, 190, 180, 20, 20, GREEND);
	al_draw_textf(font, BLACK, 270, 60, 0, "%s 's bag",name);
	al_draw_scaled_bitmap(bag, 0, 0, al_get_bitmap_width(bag), al_get_bitmap_height(bag), 60, 40, al_get_bitmap_width(bag)*2, al_get_bitmap_height(bag)*2, 0);

	//Base per als objectes
	al_draw_filled_rounded_rectangle(10, 210, 1070, 710, 20, 20, BLACK);
	al_draw_filled_rounded_rectangle(15, 215, 1065, 705, 20, 20, ORANGE);

	al_draw_text(font2, BLACK, 790, 680, 0, "Press Backspace to go back");

	al_flip_display();

	al_destroy_font(font);
	al_destroy_font(font2);
	al_destroy_bitmap(bag);
	al_destroy_bitmap(back);
}

void DrawObjects(Object *o){
	//Allegro color
	ALLEGRO_COLOR DARKORANGE = al_map_rgb(255, 153, 51);
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	
	//fonts
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 20, 0);
	ALLEGRO_FONT *font2 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 30, 0);

	int index = 0;
	float x = 25;
	float y = 225;

	while (strcmp(o[index].name,"NULL")!=0){
		al_draw_filled_rounded_rectangle(x, y, x + 198, y + 110, 20, 20, DARKORANGE);
		o[index].object = al_load_bitmap(o[index].image);
		al_draw_bitmap(o[index].object, x + 10, y + 10, 0);
		al_draw_textf(font, BLACK, x + 80, y + 20, 0, "%s", o[index].name);
		al_draw_textf(font2, BLACK, x + 130, y + 55, 0, "x%d", o[index].q);
		index++;
		if (index % 5 != 0){
			x += 208;
		}
		else{
			x = 25;
			y += 120;
		}

	}
	al_flip_display();

	al_destroy_font(font);
	al_destroy_font(font2);
}

void DrawBag(Trainer T){
	DrawBagInterface(T.name);
	if (strcmp(T.B[0].name, "NULL") == 0){
		//empty
	}
	else{
		DrawObjects(T.B);
	}
}

void ShowEnemiesOptions() {
	ALLEGRO_BITMAP *rocket = al_load_bitmap("rocket.png");
	ALLEGRO_BITMAP *plasma = al_load_bitmap("plasma.png");
	ALLEGRO_BITMAP *galaxy = al_load_bitmap("galaxy.png");
	ALLEGRO_BITMAP *tournament = al_load_bitmap("tournament.png");
	ALLEGRO_BITMAP *aqua = al_load_bitmap("aqua.png");
	ALLEGRO_BITMAP *magma = al_load_bitmap("magma.png");
	ALLEGRO_BITMAP *pokeball = al_load_bitmap("Pokeball.png");
	
	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 70, 0);
	ALLEGRO_FONT *font2 = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 15, 0);

	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);

	Draw_TournamentBackground();

	al_draw_text(font, WHITE, 50, 30, 0, "Choose your enemy:");
	
	//Mostrar wquip rocket
	al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), 30, 170, 50, 50, 0);
	al_draw_scaled_bitmap(rocket, 0, 0, al_get_bitmap_width(rocket), al_get_bitmap_height(rocket), 100, 160, 105, 105, 0);
	al_draw_text(font2, WHITE, 50, 250, 0, "lvl.20");

	//Mostrear equip magma
	al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), 450, 170, 50, 50, 0);
	al_draw_scaled_bitmap(magma, 0, 0, al_get_bitmap_width(magma), al_get_bitmap_height(magma), 520, 160, 140, 120, 0);
	al_draw_text(font2, WHITE, 470, 250, 0, "lvl.30");

	//Mostrar equip aqua
	al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), 240, 300, 50, 50, 0);
	al_draw_scaled_bitmap(aqua, 0, 0, al_get_bitmap_width(aqua), al_get_bitmap_height(aqua), 300, 290, 130, 150, 0);
	al_draw_text(font2, WHITE, 250, 400, 0, "lvl.40");

	//Mostrar equip galaxia
	al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), 30, 450, 50, 50, 0);
	al_draw_scaled_bitmap(galaxy, 0, 0, al_get_bitmap_width(galaxy), al_get_bitmap_height(galaxy), 100, 440, 120, 120, 0);
	al_draw_text(font2, WHITE, 50, 540, 0, "lvl.50");

	//Mostrar equip plasma
	al_draw_scaled_bitmap(pokeball, 0, 0, al_get_bitmap_width(pokeball), al_get_bitmap_height(pokeball), 450, 450, 50, 50, 0);
	al_draw_scaled_bitmap(plasma, 0, 0, al_get_bitmap_width(plasma), al_get_bitmap_height(plasma), 520, 430, 110, 130, 0);
	al_draw_text(font2, WHITE, 470, 540, 0, "lvl.60");
	
	al_flip_display();
	al_destroy_bitmap(rocket);
	al_destroy_bitmap(magma);
	al_destroy_bitmap(aqua);
	al_destroy_bitmap(plasma);
	al_destroy_bitmap(galaxy);
	al_destroy_bitmap(tournament);

	
}