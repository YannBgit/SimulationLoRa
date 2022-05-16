#include <float.h>
#include <stddef.h>
#include "echeancier.h"

void echeancier_ajouter(Echeancier *e, TypeEvenement type, double date)
{
	Evenement even;

	even.type = type;
	even.date = date;

	e->evenements[e->n] = even;
	e->n++;
}

Evenement *echeancier_detecter_collision(Echeancier *e, double date)
{
	Evenement *collision = NULL;

	for (int i = 0; i < e->n; ++i)
		if (e->evenements[i].type == FE && e->evenements[i].date < date)
		{
			date = e->evenements[i].date;
			collision = e->evenements + i;
		}
	return collision;
}

Evenement echeancier_suivant(Echeancier *e)
{
	Evenement even = e->evenements[0];

	for(int i = 1; i < e->n; i++)
	{
		if(e->evenements[i].date < even.date)
		{
			even = e->evenements[i];
		}
	}

	SWAP(even, e->evenements[--e->n]);

	return even;
}

void echeancier_init(Echeancier *e)
{
	e->n = 0;
}

int echeancier_vide(Echeancier *e)
{
	if(e->n == 0)
	{
		return 1;
	}

	return 0;
}
