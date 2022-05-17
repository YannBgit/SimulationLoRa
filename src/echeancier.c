#include <assert.h>
#include <float.h>
#include <stddef.h>
#include <stdio.h>
#include "echeancier.h"
#include "macros.h"

void echeancier_ajouter(Echeancier *e, TypeEvenement type, int k, int etat, double date)
{
	assert(e->n < MAX_EVENEMENTS);
	e->evenements[e->n].type = type;
	e->evenements[e->n].k = k;
	e->evenements[e->n].etat = etat;
	e->evenements[e->n].date = date;
	++e->n;
	//printf("echeancier_ajouter (%d)\n", e->n);
}

Evenement *echeancier_detecter_collision(Echeancier *e, double date)
{
	Evenement *collision = NULL;
	for (int i = 0; i < e->n; ++i)
		if (e->evenements[i].type == DE && e->evenements[i].date < date)
		{
			date = e->evenements[i].date;
			collision = e->evenements + i;
		}
	return collision;
}

Evenement echeancier_suivant(Echeancier *e)
{
	Evenement *ev = e->evenements;
	for (int i = 1; i < e->n; ++i)
		if (e->evenements[i].date < ev->date)
			ev = e->evenements + i;
	--e->n;
	SWAP(*ev, e->evenements[e->n]);
	//printf("echeancier_suivant (%d)\n", e->n);
	return e->evenements[e->n];
}

void echeancier_init(Echeancier *e)
{
	e->n = 0;
}

int echeancier_vide(const Echeancier *e)
{
	return !e->n;
}
