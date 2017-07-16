#ifndef _LOAD_H_
#define _LOAD_H_

#include "types.h"
#include "fkmlist.h"
#include "allegroguillem.h"
#include "atklist.h"
#include "trainerlist.h"
#include "objectslist.h"

void LoadFKM(Flist fl);

void LoadT(Tlist tl);

void LoadAtk(Atklist al);

void LoadPrize(Prize *P);

void LoadFoe(Flist foel);

void LoadMart(Olist ol);

#endif