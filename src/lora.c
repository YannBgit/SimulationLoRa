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

void Simulateur(unsigned short nbCapteurs)
{
	FILE *F;
	F = fopen("mm1.data", "w");
	if(!F) exit(1);

	Echeancier ech;
	unsigned long int nbEmissions = 0;

	while(nbEmissions < NB_MAX_EMISSIONS)
	{
		nbEmissions++;
	}
}