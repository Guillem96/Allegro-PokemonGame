#include "calculator.h"

float TypesChart(char *type, FKM f){
	float m = 1;
	if (strcmp(type, "NORMAL") == 0){
		if (strcmp(f.first_type, "GHOST") == 0 || strcmp(f.second_type, "GHOST") == 0)m = 0;
		if (strcmp(f.first_type, "ROCK") == 0 || strcmp(f.second_type, "ROCK") == 0)m = m*0.5;
		if (strcmp(f.first_type, "STEEL") == 0 || strcmp(f.second_type, "STEEL") == 0)m = m*0.5;
	}

	if (strcmp(type, "FIGHT") == 0){
		if (strcmp(f.first_type, "NORMAL") == 0 || strcmp(f.second_type, "NORMAL") == 0)m = m * 2;
		if (strcmp(f.first_type, "GHOST") == 0 || strcmp(f.second_type, "GHOST") == 0)m = m * 0;
		if (strcmp(f.first_type, "FLYING") == 0 || strcmp(f.second_type, "FLYING") == 0)m = m*0.5;
		if (strcmp(f.first_type, "POISON") == 0 || strcmp(f.second_type, "POISON") == 0)m = m*0.5;
		if (strcmp(f.first_type, "ROCK") == 0 || strcmp(f.second_type, "ROCK") == 0)m = m * 2;
		if (strcmp(f.first_type, "BUG") == 0 || strcmp(f.second_type, "BUG") == 0)m = m*0.5;
		if (strcmp(f.first_type, "STEEL") == 0 || strcmp(f.second_type, "STEEL") == 0)m = m * 2;
		if (strcmp(f.first_type, "ICE") == 0 || strcmp(f.second_type, "ICE") == 0)m = m * 2;
		if (strcmp(f.first_type, "PSYCHIC") == 0 || strcmp(f.second_type, "PSYCHIC") == 0)m = m*0.5;
		if (strcmp(f.first_type, "DARK") == 0 || strcmp(f.second_type, "DARK") == 0)m = m * 2;
	}
	if (strcmp(type, "FLYING") == 0){
		if (strcmp(f.first_type, "FIGHT") == 0 || strcmp(f.second_type, "FIGHT") == 0)m = m * 2;
		if (strcmp(f.first_type, "ROCK") == 0 || strcmp(f.second_type, "ROCK") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "BUG") == 0 || strcmp(f.second_type, "BUG") == 0)m = m * 2;
		if (strcmp(f.first_type, "STEEL") == 0 || strcmp(f.second_type, "STEEL") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "ELECTRIC") == 0 || strcmp(f.second_type, "ELECTRIC") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "GRASS") == 0 || strcmp(f.second_type, "GRASS") == 0)m = m * 2;
	}

	if (strcmp(type, "POISON") == 0){
		if (strcmp(f.first_type, "POISON") == 0 || strcmp(f.second_type, "POISON") == 0)m = m*0.5;
		if (strcmp(f.first_type, "GROUND") == 0 || strcmp(f.second_type, "GROUND") == 0)m = m*0.5;
		if (strcmp(f.first_type, "ROCK") == 0 || strcmp(f.second_type, "ROCK") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "GHOST") == 0 || strcmp(f.second_type, "GHOST") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "STEEL") == 0 || strcmp(f.second_type, "STEEL") == 0)m = m * 0;
		if (strcmp(f.first_type, "GRASS") == 0 || strcmp(f.second_type, "GRASS") == 0)m = m * 2;
	}

	if (strcmp(type, "ROCK") == 0){
		if (strcmp(f.first_type, "FLYING") == 0 || strcmp(f.second_type, "FLYING") == 0)m = m * 2;
		if (strcmp(f.first_type, "FIGHT") == 0 || strcmp(f.second_type, "FIGHT") == 0)m = m*0.5;
		if (strcmp(f.first_type, "GROUND") == 0 || strcmp(f.second_type, "GROUND") == 0)m = m*0.5;
		if (strcmp(f.first_type, "BUG") == 0 || strcmp(f.second_type, "BUG") == 0)m = m * 2;
		if (strcmp(f.first_type, "STEEL") == 0 || strcmp(f.second_type, "STEEL") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "FIRE") == 0 || strcmp(f.second_type, "FIRE") == 0)m = m * 2;
		if (strcmp(f.first_type, "ICE") == 0 || strcmp(f.second_type, "ICE" ) == 0)m = m * 2;
	}
	if (strcmp(type, "BUG") == 0){
		if (strcmp(f.first_type, "FIGHT") == 0 || strcmp(f.second_type, "FIGHT") == 0)m = m*0.5;
		if (strcmp(f.first_type, "FLYING") == 0 || strcmp(f.second_type, "FLYING") == 0)m = m*0.5;
		if (strcmp(f.first_type, "POISON") == 0 || strcmp(f.second_type, "POISON") == 0)m = m*0.5;
		if (strcmp(f.first_type, "GHOST") == 0 || strcmp(f.second_type, "GHOST") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "STEEL") == 0 || strcmp(f.second_type, "STEEL") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "FIRE") == 0 || strcmp(f.second_type, "FIRE") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "GRASS") == 0 || strcmp(f.second_type, "GRASS") == 0)m = m * 2;
		if (strcmp(f.first_type, "PSYCHIC") == 0 || strcmp(f.second_type, "PSYCHIC") == 0)m = m * 2;
		if (strcmp(f.first_type, "DARK") == 0 || strcmp(f.second_type, "DARK") == 0)m = m * 2;
	}
	if (strcmp(type, "GHOST") == 0){
		if (strcmp(f.first_type, "NORMAL") == 0 || strcmp(f.second_type, "NORMAL") == 0)m = m * 0;
		if (strcmp(f.first_type, "GHOST") == 0 || strcmp(f.second_type, "GHOST") == 0)m = m * 2;
		if (strcmp(f.first_type, "PSYCHIC") == 0 || strcmp(f.second_type, "PSYCHIC") == 0)m = m * 2;
		if (strcmp(f.first_type, "DARK") == 0 || strcmp(f.second_type, "DARK") == 0)m = m * 0.5;
	}
	if (strcmp(type, "STEEL") == 0){
		if (strcmp(f.first_type, "ROCK") == 0 || strcmp(f.second_type, "ROCK") == 0)m = m * 2;
		if (strcmp(f.first_type, "STEEL") == 0 || strcmp(f.second_type, "STEEL") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "FIRE") == 0 || strcmp(f.second_type, "FIRE") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "WATER") == 0 || strcmp(f.second_type, "WATER") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "ELECTRIC") == 0 || strcmp(f.second_type, "ELECTRIC") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "ICE") == 0 || strcmp(f.second_type, "ICE") == 0)m = m * 2;
	}
	if (strcmp(type, "FIRE") == 0){
		if (strcmp(f.first_type, "WATER") == 0 || strcmp(f.second_type, "WATER") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "ICE") == 0 || strcmp(f.second_type, "ICE") == 0)m = m * 2;
		if (strcmp(f.first_type, "STEEL") == 0 || strcmp(f.second_type, "STEEL") == 0)m = m * 2;
		if (strcmp(f.first_type, "ROCK") == 0 || strcmp(f.second_type, "ROCK") == 0)m = m *0.5;
		if (strcmp(f.first_type, "BUG") == 0 || strcmp(f.second_type, "BUG") == 0)m = m * 2;
		if (strcmp(f.first_type, "FIRE") == 0 || strcmp(f.second_type, "FIRE") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "GRASS") == 0 || strcmp(f.second_type, "GRASS") == 0)m = m * 2;
		if (strcmp(f.first_type, "DRAGON") == 0 || strcmp(f.second_type, "DRAGON") == 0)m = m * 0.5;
	}
	if (strcmp(type, "WATER") == 0){
		if (strcmp(f.first_type, "GRASS") == 0 || strcmp(f.second_type, "GRASS") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "DRAGON") == 0 || strcmp(f.second_type, "DRAGON") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "ROCK") == 0 || strcmp(f.second_type, "ROCK") == 0)m = m * 2;
		if (strcmp(f.first_type, "GROUND") == 0 || strcmp(f.second_type, "GROUND") == 0)m = m * 2;
		if (strcmp(f.first_type, "FIRE") == 0 || strcmp(f.second_type, "FIRE") == 0)m = m * 2;
		if (strcmp(f.first_type, "WATER") == 0 || strcmp(f.second_type, "WATER") == 0)m = m * 0.5;
	}
	if (strcmp(type, "GRASS") == 0){
		if (strcmp(f.first_type, "WATER") == 0 || strcmp(f.second_type, "WATER") == 0)m = m * 2;
		if (strcmp(f.first_type, "GROUND") == 0 || strcmp(f.second_type, "GROUND") == 0)m = m * 2;
		if (strcmp(f.first_type, "FIRE") == 0 || strcmp(f.second_type, "FIRE") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "FLYING") == 0 || strcmp(f.second_type, "FLYING") == 0)m = m*0.5;
		if (strcmp(f.first_type, "POISON") == 0 || strcmp(f.second_type, "POISON") == 0)m = m*0.5;
		if (strcmp(f.first_type, "ROCK") == 0 || strcmp(f.second_type, "ROCK") == 0)m = m * 2;
		if (strcmp(f.first_type, "BUG") == 0 || strcmp(f.second_type, "BUG") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "STEEL") == 0 || strcmp(f.second_type, "STEEL") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "GRASS") == 0 || strcmp(f.second_type, "GRASS") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "DRAGON") == 0 || strcmp(f.second_type, "DRAGON") == 0)m = m * 0.5;
	}
	if (strcmp(type, "ELECTRIC") == 0){
		if (strcmp(f.first_type, "GRASS") == 0 || strcmp(f.second_type, "GRASS") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "DRAGON") == 0 || strcmp(f.second_type, "DRAGON") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "GROUND") == 0 || strcmp(f.second_type, "GROUND") == 0)m = m * 0;
		if (strcmp(f.first_type, "FLYING") == 0 || strcmp(f.second_type, "FLYING") == 0)m = m * 2;
		if (strcmp(f.first_type, "WATER") == 0 || strcmp(f.second_type, "WATER") == 0)m = m * 2;
		if (strcmp(f.first_type, "ELECTRIC") == 0 || strcmp(f.second_type, "ELECTRIC") == 0)m = m * 0.5;
	}
	if (strcmp(type, "PSYCHIC") == 0){
		if (strcmp(f.first_type, "FIGHT") == 0 || strcmp(f.second_type, "FIGHT") == 0)m = m * 2;
		if (strcmp(f.first_type, "POISON") == 0 || strcmp(f.second_type, "POISON") == 0)m = m * 2;
		if (strcmp(f.first_type, "STEEL") == 0 || strcmp(f.second_type, "STEEL") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "PSYCHIC") == 0 || strcmp(f.second_type, "PSYCHIC") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "DARK") == 0 || strcmp(f.second_type, "DARK") == 0)m = m * 0;
	}
	if (strcmp(type, "ICE") == 0){
		if (strcmp(f.first_type, "FLYING") == 0 || strcmp(f.second_type, "FLYING") == 0)m = m * 2;
		if (strcmp(f.first_type, "GROUND") == 0 || strcmp(f.second_type, "GROUND") == 0)m = m * 2;
		if (strcmp(f.first_type, "STEEL") == 0 || strcmp(f.second_type, "STEEL") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "WATER") == 0 || strcmp(f.second_type, "WATER") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "FIRE") == 0 || strcmp(f.second_type, "FIRE") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "GRASS") == 0 || strcmp(f.second_type, "GRASS") == 0)m = m * 2;
		if (strcmp(f.first_type, "ICE") == 0 || strcmp(f.second_type, "ICE") == 0)m = m * 0.5;
		if (strcmp(f.first_type, "DRAGON") == 0 || strcmp(f.second_type, "DRAGON") == 0)m = m * 2;
	}
	if (strcmp(type, "DRAGON") == 0){
		if (strcmp(f.first_type, "DRAGON") == 0 || strcmp(f.second_type, "DRAGON") == 0)m = m * 2;
		if (strcmp(f.first_type, "STEEL") == 0 || strcmp(f.second_type, "STEEL") == 0)m = m * 0.5;

	}
	if (strcmp(type, "DARK") == 0){
		if (strcmp(f.first_type, "PSYCHIC") == 0 || strcmp(f.second_type, "PSYCHIC") == 0)m = m * 2;
		if (strcmp(f.first_type, "FIGHT") == 0 || strcmp(f.second_type, "FIGHT") == 0)m = m*0.5;
		if (strcmp(f.first_type, "GHOST") == 0 || strcmp(f.second_type, "GHOST") == 0)m = m * 2;
		if (strcmp(f.first_type, "DARK") == 0 || strcmp(f.second_type, "DARK") == 0)m = m*0.5;
	}
	
	return m;
}

int DamageCalculator(FKM f, FKM e, Attack a,float *effect){
	int damage = 0;
	bool attack = false;
	int possibility = 0;

	srand(time(NULL));
	if (a.accuracy >= 100){
		attack = true;
	}
	else{
		possibility = rand() % (a.accuracy / 10);
		if (possibility > 0){
			attack = true;
		}
	}

	if (attack = true){
		if (a.category = 'F')damage = floor((float)(f.s.atk + a.power - e.s.def) / 4);
		if (a.category = 'S')damage = floor((float)(f.s.spa + a.power - e.s.spd) / 4);
		if (strcmp(a.type, f.first_type) == 0 || strcmp(a.type, f.second_type) == 0)damage = damage*1.5;
		*effect = TypesChart(a.type, e);
		damage = damage*(*effect);
	}
	else{
		*effect = -1;
	}
	return damage;
}