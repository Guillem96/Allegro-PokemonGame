#ifndef _FIRSTOPTIONS_H_
#define _FIRSTOPTIONS_H_

#include "trainerlist.h"
#include "fkmlist.h"
#include "allegroguillem.h"
#include "types.h"
#include "arrowlogic.h"
#include "menu.h"
#include "atklist.h"
#include "graphics.h"


bool StartGame(int *out);

Trainer ChooseTrainer(Trainer T, Tlist tl, Flist fl, Atklist al);

Trainer LoadTrainer(Trainer T, Tlist tl, Flist fl, Atklist al);

#endif