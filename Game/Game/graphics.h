#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "allegroguillem.h"
#include "arrowlogic.h"
#include "types.h"
#include "team.h"
#include "fkmlist.h"

void DrawTeam(FKM f[6]);

void Printlittlemenu(Arrow A);

void DrawTypes(FKM f,float x, float y);

void Draw_stats(FKM f, bool screen);

void DrawVs(Trainer T, Flist foe);

void DrawArena();

void Drawcondition(FKM f, FKM e);

void DrawHood(FKM f,Arrow a);

void AttackHood(FKM f, Arrow a);

void ShowLevelUp(FKM f, int *a, int lvl);

void DrawMart(Object *o, int max, Trainer T);

void DrawBag(Trainer T);

void ShowEnemiesOptions();


#endif