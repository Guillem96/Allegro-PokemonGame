#ifndef _ALLEGROGUILLEM_H_
#define _ALLEGROGUILLEM_H_

#include <allegro5\allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/timer.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

void inicia_allegro(ALLEGRO_DISPLAY *DISPLAY);
void Draw_Background();
void Draw_regionBackground();
void Draw_MenuBackground();
void Draw_TeamBackground();
void DrawMartBckg();
void Draw_TournamentBackground();

#endif