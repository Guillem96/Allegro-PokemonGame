#ifndef _ARROWLOGIC_H_
#define _ARROWLOGIC_H_

#include "types.h"
#include "allegroguillem.h"
#include "menu.h"
#include "team.h"

Arrow arrowprincipalmenu(Arrow a);

Arrow ArrowPM(Arrow a,Trainer T);

void DrawArrow(Arrow A, char *name);

Arrow ArrowTeam(Arrow a, FKM f[6], int *index);

void DrawArrowTeam(Arrow A, char *name);

Arrow Arrowlittlemenu(Arrow a);

Arrow Arrowswitchmenu(Arrow a, FKM f[6],int *index);

Arrow HoodLogic(Arrow a);

Arrow HoodAtkLogic(Arrow a,FKM f);

Arrow MartArrow(Arrow a,int *index_o);

Arrow ObjectLogic(Arrow A,Object *o, int *index);

Arrow Enemies_arrow(Arrow a);

void Draw_enemiesarrow(Arrow a);


#endif