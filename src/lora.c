#include "lora.h"
#include "utils.h"

void Traitement_Event(Evenement e, Echeancier ech)
{
	(void)e;
	(void)ech;
	// Met à jour les variables de la simulation
}

void Traitement_Collision()
{
	// Traite une collisions, en particulier met à jour l'état des capteurs en collision
}

int testArret(int *nbEmissions)
{
	int arret = 0;

	for(int i = 0; i < K; i++)
	{
		if(nbEmissions[i] >= MAX_ESSAIS)
		{
			arret++;
		}
	}

	return !(arret >= K);
}

void Simulateur(Echeancier ech, int *nbEmissions, double *tempsEmission, double tempsAttenteSucces,
double *tempsAttenteEchec, int *nbCollisions, double *probaCollision)
{
	(void)ech;
	(void)tempsEmission;
	(void)tempsAttenteSucces;
	(void)tempsAttenteEchec;
	(void)nbCollisions;
	(void)probaCollision;
	while(testArret(nbEmissions))
	{
		// Simulation
	}
}
