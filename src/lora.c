// LIBRAIRIES
#include "lora.h"

// FONCTIONS
double Expo_Duree(double lambda)
{
	return -log((double)random() / RAND_MAX) / lambda;
}

void Traitement_Event(Evenement e, Echeancier ech)
{

}

void Traitement_Collision()
{

}

void Simulateur(double *tempsEmissions, double *tempsAttente, double *probabilitésCollision)
{
	Echeancier ech;
	unsigned long int nbEmissions = 0;
	unsigned long int nbPaquetsPerdus = 0;

	while(nbEmissions < NB_MAX_EMISSIONS)
	{
		nbEmissions++;
	}
}