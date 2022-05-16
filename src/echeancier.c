void echeancier_ajouter(Echeancier *e, int type, double date, double duree)
{
	Evenement even;

	even.type = type;
	even.date = date;
	even.duree = duree;

	e->evenements[e->n] = even;
	e->n++;
}

Evenement echeancier_suivant(Echeancier *e)
{
	Evenement even = e->evenement[0];

	for(int i = 1; i < e->n; i++)
	{
		if(e->evenement[i].date < even.date)
		{
			even = e->evenement[i];
		}
	}

	SWAP(even, e->evenement[n]);
	e->n--;

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