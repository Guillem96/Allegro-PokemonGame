#include "generate.h"

FKM Generatestadistics(FKM f){
	srand(time(NULL));
	f.s.fullhp = f.base.hp + f.lvl*((rand() % 4) + 1);
	f.s.atk = f.base.atk + f.lvl*((rand() % 4) + 1);
	f.s.def = f.base.def + f.lvl*((rand() % 4) + 1);
	f.s.spa = f.base.spa + f.lvl*((rand() % 4) + 1);
	f.s.spd = f.base.spd + f.lvl*((rand() % 4) + 1);
	f.s.speed = f.base.speed + f.lvl*((rand() % 4) + 1);
	f.s.hp = f.s.fullhp;
	return f;
}

FKM GiveAttacks(FKM f, Atklist al){
	int random = 0;
	int index = 0;
	int aux = 0;
	int trobat = 0;
	int pow = 0;

	srand(time(NULL));
	al = Atklist_start(al);
	if (f.lvl < 40) pow = 3000;
	if (f.lvl < 25) pow = 100;
	if (f.lvl < 20) pow = 80;
	if (f.lvl < 15) pow = 60;
	
	
	

	while (index < 4){
		aux = 0;
		random = rand() % 60;
		while (aux < random){
			al = Atklist_forward(al);
			if (Atklist_final(al)){
				al = Atklist_start(al);
			}
			aux++;
		}
		trobat = 0;
		while (!Atklist_final(al) && Atklist_consult(al).power < pow && !trobat){
			if (strcmp(f.first_type, Atklist_consult(al).type) == 0 || strcmp(f.second_type, Atklist_consult(al).type) == 0  || strcmp("NORMAL", Atklist_consult(al).type) == 0){
				trobat = 1;
				f.a[index] = Atklist_consult(al);
				f.a[index].leftpp = f.a[index].pp;
				index++;
			}
			else{
				al = Atklist_forward(al);
			}
		}
	}
	return f;
}