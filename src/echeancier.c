#include "echeancier.h"

void echeancier_ajouter(Echeancier *e, int type, double date, double duree)
{
	Evenement even;

	even.type = type;
	even.date = date;
	even.duree = duree;

	e->evenements[e->n] = even;
	e->n++;
}

Evenement *echeancier_detecter_collision(Echeancier *e, const Evenement *e1)
{
	Evenement even = NULL;
	double date = __DBL_MAX__;

	for(int i = 0; i < e->n; i++)
	{
		Evenement e2 = e->evenements[i];

		if
		(
			(((e1.date > e2.date) && ((e1.date + e1.duree) > (e2.date + e2.duree)))
			|| ((e1.date < e2.date) && ((e1.date + e1.duree) < (e2.date + e2.duree)))
			|| ((e1.date > e2.date) && ((e1.date + e1.duree) < (e2.date + e2.duree)))
			|| ((e1.date < e2.date) && ((e1.date + e1.duree) > (e2.date + e2.duree))))
			&& (e->evenements[i].date < date)
		)
		{
			even = e->evenements[i];
		}
	}

	return even;
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
