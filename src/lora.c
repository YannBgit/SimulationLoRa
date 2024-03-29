#include <assert.h>
#include <stdio.h>
#include "lora.h"
#include "utils.h"

void Traitement_Event(Simulation *sim, const Evenement *e)
{
	if(e->type == DE)
	{
		double d = Expo_Duree(LAMBDA_E);
		sim->tempsEmission[e->etat] = d;
		Evenement *c = echeancier_detecter_collision(&sim->ech, e->date + d);
		if (c)
			Traitement_Collision(sim, e, c);
		else
			echeancier_ajouter(&sim->ech, FE, e->k, e->etat, e->date + d);
	}

	if(e->type == FE)
	{
		++sim->nbEmissions[e->etat];
		sim->tempsEmission[e->etat] = -1;
		echeancier_ajouter(&sim->ech, DE, e->k, 0, e->date + Expo_Duree(LAMBDA_I));
		if (++sim->nbTotalEmissions[e->k] == MIN_EMISSIONS)
			++sim->nbMinEmissions;
	}

	if(e->type == TC)
	{
		++sim->nbCollisions[e->etat];
		++sim->nbEmissions[e->etat];
		if (e->etat < MAX_ESSAIS)
			echeancier_ajouter(&sim->ech, DE, e->k, e->etat + 1, e->date + Expo_Duree(LAMBDA_W));
		else
			echeancier_ajouter(&sim->ech, DE, e->k, 0, e->date + Expo_Duree(LAMBDA_I));
	}
}

void Traitement_Collision(Simulation *sim, const Evenement *e1, Evenement *e2)
{
	sim->tempsEmission[e1->etat] -= e2->date - e1->date;
	echeancier_ajouter(&sim->ech, TC, e1->k, e1->etat, e2->date);
	e2->type = TC;
	sim->T = e2->date;
}

void Simulateur(Simulation *sim, int showAll)
{
	while (sim->nbMinEmissions < sim->K)
	{
		assert(!echeancier_vide(&sim->ech));
		Evenement e = echeancier_suivant(&sim->ech);
		sim->T = e.date;
		Traitement_Event(sim, &e);
		if (showAll)
			simulation_print(sim);
		for (int i = 0; i < 2; ++i)
			sim->tempsEmission[i] = -1;
	}
}

void simulation_init(Simulation *sim, int K)
{
	assert(K > 0 && K <= MAX_K);
	echeancier_init(&sim->ech);
	for (int i = 0; i < K; ++i)
	{
		echeancier_ajouter(&sim->ech, DE, i, 0, Expo_Duree(LAMBDA_I));
		sim->nbTotalEmissions[i] = 0;
	}
	sim->T = 0;
	sim->K = K;
	sim->nbMinEmissions = 0;
	for (int i = 0; i < MAX_ESSAIS; ++i)
	{
		sim->nbCollisions[i] = 0;
		sim->nbEmissions[i] = 0;
		sim->tempsEmission[i] = -1;
	}
}

void simulation_print(const Simulation *sim)
{
	printf("%d %g", sim->K, sim->T);
	for (int i = 0; i < MAX_ESSAIS; ++i)
		if (sim->nbEmissions[i])
			printf(" %g", (double)sim->nbCollisions[i] / sim->nbEmissions[i]);
		else
			printf(" 0");
	printf(" %g %g\n", sim->tempsEmission[0], sim->tempsEmission[1]);
}
