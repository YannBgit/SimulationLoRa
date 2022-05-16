#include <stdlib.h>
#include "lora.h"

int main()
{
	// Initialisation des variables
	Echeancier ech;								// Echéancier
	int nbEmissions[K];   				// Nombre d'émissions pour chaque capteur
	double tempsEmission[MAX_ESSAIS];			// Graines du temps d'émission par état ej
	double tempsAttenteSucces = 0.1;			// Graine du temps d'attente en cas d'émission réussie i
	double tempsAttenteEchec[MAX_ESSAIS - 1];	// Graines du temps d'attente en cas d'échec (collision) par wj (wait)
	int nbCollisions[MAX_ESSAIS];				// Nombre de collisions par état
	double probaCollision[MAX_ESSAIS];			// Probabilités qu'une collision ait lieu en moyenne pour chaque état

	for(int i = 0; i < K; i++)
	{
		nbEmissions[i] = 0;
	}

	for(int i = 0; i < MAX_ESSAIS; i++)
	{
		tempsEmission[i] = 10;
	}

	for(int i = 0; i < (MAX_ESSAIS - 1); i++)
	{
		tempsAttenteEchec[i] = 0.25;
	}

	// Calculs
	Simulateur(ech, nbEmissions, tempsEmission, tempsAttenteSucces,
	tempsAttenteEchec, nbCollisions, probaCollision);
}
