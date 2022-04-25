// LIBRAIRIES
#include "lora.h"

// FONCTIONS
double Expo_Duree(double lambda)
{
	return -log((double)random() / RAND_MAX) / lambda;
}

void Traitement_Event(Evenement e, Echeancier ech)
{
	// Met à jour les variables de la simulation
}

void Traitement_Collision()
{
	// Traite une collisions, en particulier met à jour l'état des capteurs en collision
}

bool testArret(int *nbEmissions, int nbCapteurs)
{
	int arret = 0;

	for(int i = 0; i < nbCapteurs; i++)
	{
		if(nbEmissions[i] >= NB_MAX_EMISSIONS)
		{
			arret++;
		}
	}

	return !(arret >= nbCapteurs);
}

void Simulateur(Echeancier ech, int nbCapteurs, int *nbEmissions, double *tempsEmission, double tempsAttenteSucces,
double *tempsAttenteEchec, int *nbCollisions, double *probaCollision)
{
	while(testArret(nbEmissions, nbCapteurs))
	{
		// Simulation
	}
}