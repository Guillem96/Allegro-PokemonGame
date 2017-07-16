#include "savedata.h"

void SaveTrainers(Tlist tl,Trainer T){
	FILE *f;
	int found = 0;
	fopen_s(&f,"Trainers.bin", "wb+");
	if (f == NULL){
		printf("\nError saving trainers.");
	}
	else{
		tl = Tlist_start(tl);
		while (!Tlist_final(tl) && !found){
			if (strcmp(T.name, Tlist_consult(tl).name)==0){
				found = 1;
				tl = Tlist_delete(tl);
				tl = Tlist_insert(tl, T);
			}
			else{
				tl = Tlist_forward(tl);
			}	
		}
		if (found == 0){
			tl = Tlist_insert(tl, T);
		}
		tl = Tlist_start(tl);
		while (!Tlist_final(tl)){
			T = Tlist_consult(tl);
			fwrite(&T, sizeof(Trainer), 1, f);
			tl = Tlist_forward(tl);
		}
		fclose(f);
	}
}