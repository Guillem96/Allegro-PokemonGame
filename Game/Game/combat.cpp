#include "combat.h"

void Start(FKM f){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	ALLEGRO_KEYBOARD_STATE kbdstate;

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);

	al_draw_textf(font, WHITE, 40, 570, 0, "A foe %s appeared!!!", f.name);
	al_flip_display();

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);

	al_get_keyboard_state(&kbdstate);
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
}

void Escape(){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	ALLEGRO_KEYBOARD_STATE kbdstate;

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "Got away safely!");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	
}

void CantEscape(){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	ALLEGRO_KEYBOARD_STATE kbdstate;

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "You can't escape, your pokemon is too slow!");
	al_flip_display();
	al_get_keyboard_state(&kbdstate);
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == false && al_key_down(&kbdstate, ALLEGRO_KEY_Z) == false){ al_get_keyboard_state(&kbdstate); }
	while (al_key_down(&kbdstate, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbdstate, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbdstate); }
	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_flip_display();
	al_destroy_font(font);
}

void FriendlyHit(FKM f, int attack){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "%s used %s.",f.name,f.a[attack].name);
	al_flip_display();
	al_rest(3);
	
}

void Showeffective(float effect){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	if (effect >= 2){
		al_draw_textf(font, WHITE, 40, 570, 0, "It's super effective!");
		al_flip_display();
		al_rest(3);
	}
	else{
		if (effect < 1 && effect > 0){
			al_draw_textf(font, WHITE, 40, 570, 0, "It 's not much effective...");
			al_flip_display();
			al_rest(3);
		}
		else{
			if (effect == -1){
				al_draw_textf(font, WHITE, 40, 570, 0, "The attack has failed!");
				al_flip_display();
				al_rest(3);
			}
			else{
				if (effect == 0){
					al_draw_textf(font, WHITE, 40, 570, 0, "It has no effect...");
					al_flip_display();
					al_rest(3);
				}
			}
		}
	}
}

int FoeHit(FKM f){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);
	int attack = -1;
	srand(time(NULL));
	attack = rand() % 4;
	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "%s used %s.", f.name, f.a[attack].name);
	al_flip_display();
	al_rest(3);
	return attack;
}

void Defeated(FKM f){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "You defeated %s.", f.name);
	al_flip_display();
	al_rest(3);
}

void DefeatedPKM(FKM f){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "Your %s has been defeated.", f.name);
	al_flip_display();
	al_rest(3);
}

void Comeon(FKM f){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "Come on %s you can do it!!!.", f.name);
	al_flip_display();
	al_rest(3);
}

int Turn(FKM *f, FKM *e, int attack, int action, Flist fl){
	float effect = -1;
	int end = 0;
	int foeattack = -1;
	Arrow a;
	a.x = 510;
	a.y = 570;

	if (action == 0){
		if ((*f).s.speed >= (*e).s.speed){
			FriendlyHit(*f, attack);
			int damage = DamageCalculator(*f, *e, (*f).a[attack], &effect);
			(*e).s.hp = (*e).s.hp - damage;
			if ((*e).s.hp <= 0){
				(*e).s.hp = 0;
				Drawcondition(*f, *e);
				(*f).a[attack].leftpp--;
				Showeffective(effect);
			}
			else{
				(*f).a[attack].leftpp--;
				Showeffective(effect);
				Drawcondition(*f, *e);
				foeattack = FoeHit(*e);
				damage = DamageCalculator(*e, *f, (*e).a[foeattack], &effect);
				(*f).s.hp = (*f).s.hp - damage;
				if ((*f).s.hp <= 0)(*f).s.hp = 0;
				Drawcondition(*f, *e);
				Showeffective(effect);
			}
		}
		else{
			foeattack = FoeHit(*e);
			int damage = DamageCalculator(*e, *f, (*e).a[foeattack], &effect);
			(*f).s.hp = (*f).s.hp - damage;
			if ((*f).s.hp <= 0){
				(*f).s.hp = 0;
				Drawcondition((*f), *e);
				Showeffective(effect);
			}
			else{
				Showeffective(effect);
				Drawcondition(*f, *e);
				FriendlyHit(*f, attack);
				damage = DamageCalculator(*f, *e, (*f).a[attack], &effect);
				(*e).s.hp = (*e).s.hp - damage;
				if ((*e).s.hp < 0)(*e).s.hp = 0;
				Drawcondition(*f, *e);
				(*f).a[attack].leftpp--;
				Showeffective(effect);
			}
		}
		if ((*e).s.hp == 0){
			end = 1;
			Defeated(*e);
			*f = GrowPKM(*f, *e, fl);
			printf("\n%d", (*f).exp);
		}
		if ((*f).s.hp == 0){
			end = 2;
			DefeatedPKM(*f);
		}
	}
	else{
		if (action == 2){
			DrawArena();
			DrawHood(*f, a);
			Drawcondition(*f, *e);
			Comeon(*f);
			
			foeattack = FoeHit(*e);
			int damage = DamageCalculator(*e, *f, (*e).a[foeattack], &effect);
			(*f).s.hp = (*f).s.hp - damage;
			if ((*f).s.hp <= 0){
				(*f).s.hp = 0;
				Drawcondition((*f), *e);
				Showeffective(effect);
			}
			else{
				Showeffective(effect);
				Drawcondition(*f, *e);
			}
		}
		if ((*f).s.hp == 0){
			end = 2;
			DefeatedPKM(*f);
		}
	}
	
	return end;
}

int NoPKM(FKM *f,int index){
	int pkm = 0;
	if (f[0].s.hp == 0 && f[1].s.hp == 0 && f[2].s.hp == 0 && f[3].s.hp == 0 && f[4].s.hp == 0 && f[5].s.hp == 0) pkm = 1;
	if (f[0].s.hp == 0 && strcmp(f[1].name, "NULL") == 0 && strcmp(f[2].name, "NULL") == 0 && strcmp(f[3].name, "NULL") == 0 && strcmp(f[4].name, "NULL") == 0 && strcmp(f[4].name, "NULL") == 0)pkm = 1;
	if (f[0].s.hp == 0 && f[1].s.hp == 0 && strcmp(f[2].name, "NULL") == 0 && strcmp(f[3].name, "NULL") == 0 && strcmp(f[4].name, "NULL") == 0 && strcmp(f[5].name, "NULL") == 0)pkm = 1;
	if (f[0].s.hp == 0 && f[1].s.hp == 0 && f[2].s.hp == 0 && strcmp(f[3].name, "NULL") == 0 && strcmp(f[4].name, "NULL") == 0 && strcmp(f[5].name, "NULL") == 0)pkm = 1;
	if (f[0].s.hp == 0 && f[1].s.hp == 0 && f[2].s.hp == 0 && f[3].s.hp == 0 && strcmp(f[4].name, "NULL") == 0 && strcmp(f[5].name, "NULL") == 0)pkm = 1;
	if (f[0].s.hp == 0 && f[1].s.hp == 0 && f[2].s.hp == 0 && f[3].s.hp == 0 && f[4].s.hp == 0 && strcmp(f[5].name, "NULL") == 0)pkm = 1;
	return pkm;
}

void NoMorePKM(Trainer T){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "%s you don't have more alife pokemon.", T.name);
	al_flip_display();
	al_rest(3);
}

void Congratulations(Trainer T){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "Congratulations %s you have defeated the ", T.name);
	al_draw_textf(font, WHITE, 40, 640, 0, "three foe pokemon and you have earned 100 $!!!");
	al_flip_display();
	al_rest(3);
}

void onbattle(FKM *f){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "This pokemon is already battling.");
	al_flip_display();
	al_rest(3);
	Draw_TeamBackground();
	DrawTeam(f);
}

void rip(FKM *f){
	ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR RED = al_map_rgb(170, 0, 0);

	ALLEGRO_FONT *font = al_load_ttf_font("Gecko_PersonalUseOnly.ttf", 40, 0);

	//requadre inferior
	al_draw_filled_rounded_rectangle(10, 550, 1060, 710, 20, 20, BLACK);
	al_draw_rounded_rectangle(15, 555, 1055, 705, 20, 20, RED, 4);
	al_draw_textf(font, WHITE, 40, 570, 0, "This pokemon is already defeated.");
	al_flip_display();
	al_rest(3);
	Draw_TeamBackground();
	DrawTeam(f);
}

int changePKM(FKM *f,FKM pkm,int p){
	int index = 0;
	Arrow A;
	A.x = 40;
	A.y = 10;
	int out = 0;
	ALLEGRO_KEYBOARD_STATE kbs;
	//Printem el fons
	Draw_TeamBackground();
	DrawTeam(f);
	A = ArrowTeam(A, f, &index);
	DrawArrowTeam(A, "ballcursor.png");
	while (out == 0){
		al_get_keyboard_state(&kbs);
		A = ArrowTeam(A, f, &index);
		if (al_key_down(&kbs, ALLEGRO_KEY_BACKSPACE)){
			out = 1;
			return p;
		}
		if (al_key_down(&kbs, ALLEGRO_KEY_ENTER) || al_key_down(&kbs, ALLEGRO_KEY_Z)){
			if (strcmp(f[index].name, pkm.name)!=0){
				out = 1;
			}else{
				if (f[index].s.hp == 0){
					rip(f);
				}
				else{
					onbattle(f);
				}
				
			}
		}
		
	}
	return index;
}

Trainer Combat(Trainer T, Flist foe, Flist fl){
	ALLEGRO_KEYBOARD_STATE kbd;

	FKM  e;
	int index = 0;
	Arrow a;
	Arrow Atk;
	Atk.x = 25;
	Atk.y = 570;
	a.x = 510;
	a.y = 570;
	int out = 0;
	int end = 0;
	int last = 0;
	int attack = -1;
	int action = -1; // 0->atacar	1->objecte	2->switch

	//Bucle General del combat;
	foe = Flist_start(foe);
	//Treiem un pokemon salvatge de la llista
	e = Flist_consult(foe);
	//Dibuixem el camp de batalla
	DrawArena();
	Drawcondition(T.team[index], e);
	//Mistage del pokemon salvatge que hem trobat.
	Start(e);
	while (!Flist_empty(foe) && !out){
		//Dibuixem el camp de batalla
		Comeon(T.team[index]);
		//Bucle del combat d' UN pkm
		end = 0;
		while (end == 0){
			end = 0;
			al_get_keyboard_state(&kbd);
			DrawHood(T.team[index], a);
			a = HoodLogic(a);
			
			//Seleccionar atac
			if ((al_key_down(&kbd, ALLEGRO_KEY_ENTER) || al_key_down(&kbd, ALLEGRO_KEY_Z)) && a.x == 510 && a.y == 570){
				AttackHood(T.team[index], Atk);
				int fi =0 ;
				while (attack==-1 && !fi){
					while (al_key_down(&kbd, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbd, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbd); }
					Atk = HoodAtkLogic(Atk, T.team[index]);
					
					al_get_keyboard_state(&kbd);
					//attac 0
					if ((al_key_down(&kbd, ALLEGRO_KEY_ENTER) || al_key_down(&kbd, ALLEGRO_KEY_Z)) && Atk.x == 25 && Atk.y == 570 && strcmp(T.team[index].a[0].name, "NULL") != 0 && T.team[index].a[0].leftpp > 0){
						attack = 0;
						action = 0;
						while (al_key_down(&kbd, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbd, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbd); }
					}

					//Atac 1
					if ((al_key_down(&kbd, ALLEGRO_KEY_ENTER) || al_key_down(&kbd, ALLEGRO_KEY_Z)) && Atk.x == 25 && Atk.y == 640 && strcmp(T.team[index].a[1].name, "NULL") != 0 && T.team[index].a[1].leftpp > 0){
						attack = 1;
						action = 0;
						while (al_key_down(&kbd, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbd, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbd); }

					}

					//Atac 2
					if ((al_key_down(&kbd, ALLEGRO_KEY_ENTER) || al_key_down(&kbd, ALLEGRO_KEY_Z)) && Atk.x == 475 && Atk.y == 570 && strcmp(T.team[index].a[2].name, "NULL") != 0 && T.team[index].a[2].leftpp > 0){
						attack = 2;
						action = 0;
						while (al_key_down(&kbd, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbd, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbd); }

					}
					//Atac 3
					if ((al_key_down(&kbd, ALLEGRO_KEY_ENTER) || al_key_down(&kbd, ALLEGRO_KEY_Z)) && Atk.x == 475 && Atk.y == 640 && strcmp(T.team[index].a[3].name, "NULL") != 0 && T.team[index].a[3].leftpp > 0){
						attack = 3;
						action = 0;
						while (al_key_down(&kbd, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbd, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbd); }
					}
					if (al_key_down(&kbd, ALLEGRO_KEY_BACKSPACE))fi = 1;
				}
				if (action > -1){
					end = Turn(&T.team[index], &e, attack, action,fl);
					if (end == 1){
						foe = Flist_delete(foe);
						if (Flist_empty(foe)){
							Congratulations(T);
							T.money += 100;
						}
						if(!Flist_empty(foe))e = Flist_consult(foe);
						DrawArena();
						Drawcondition(T.team[index], e);
						Start(e);
					}
					else{
						if (end == 2){
							if (NoPKM(T.team,index)){
								out = 1;
								NoMorePKM(T);
							}
							else{
								action = -1;
								index = changePKM(T.team,T.team[index],index);
								DrawArena();
								Drawcondition(T.team[index], e);
							}
						}
					}
					action = -1;
					attack = -1;
					Drawcondition(T.team[index], e);
				}
			}

			//Opcio bag
			if ((al_key_down(&kbd, ALLEGRO_KEY_ENTER) || al_key_down(&kbd, ALLEGRO_KEY_Z)) && a.x == 510 && a.y == 640){
				//ShowBag();
				while (al_key_down(&kbd, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbd, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbd); }

			}

			//Equip pokemon
			if ((al_key_down(&kbd, ALLEGRO_KEY_ENTER) || al_key_down(&kbd, ALLEGRO_KEY_Z)) && a.x == 755 && a.y == 570){
				action = 2;
				while (al_key_down(&kbd, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbd, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbd); }
				if (action > -1){
					last = index;
					index = changePKM(T.team, T.team[index],index);
					if (index != last){
						end = Turn(&T.team[index], &e, attack, action, fl);
					}
					else{
						DrawArena();
						DrawHood(T.team[index], a);
						if (end == 1){
							foe = Flist_delete(foe);
							if (Flist_empty(foe)){
								Congratulations(T);
								T.money += 100;
							}
							if (!Flist_empty(foe))e = Flist_consult(foe);
							DrawArena();
							Drawcondition(T.team[index], e);
							Start(e);
						}

						else{
							if (end == 2){
								if (NoPKM(T.team, index)){
									out = 1;
									NoMorePKM(T);
								}
								else{
									action = -1;
									index = changePKM(T.team, T.team[index], index);
									
								}
							}
						}
					}
					action = -1;
					attack = -1;
					Drawcondition(T.team[index], e);
				}

			}

			//Escape
			if ((al_key_down(&kbd, ALLEGRO_KEY_ENTER) || al_key_down(&kbd, ALLEGRO_KEY_Z)) && a.x == 755 && a.y == 640){
				if (T.team[index].s.speed >= e.s.speed){
					end = 1;
					out = 1;
					Escape();
				}
				else{
					CantEscape();
				}
				while (al_key_down(&kbd, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbd, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbd); }
			}
			while (al_key_down(&kbd, ALLEGRO_KEY_ENTER) == true || al_key_down(&kbd, ALLEGRO_KEY_Z) == true){ al_get_keyboard_state(&kbd); }
			

		}

	}

	return T;
}