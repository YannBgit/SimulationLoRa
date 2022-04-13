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

void Simulateur()
{
	Echeancier ech;									// Echéancier
	int nombreEmissions[NB_CAPTEURS];				// Nombre d'émissions pour chaque capteur
    double tempsEmission[NB_MAX_ESSAIS];            // Temps d'émission par état ej
    double tempsAttente[NB_MAX_ESSAIS - 1];         // Temps d'attente par attente (wait) wj
    double probabilitésCollision[NB_MAX_ESSAIS];    // Probabilités qu'une collision ait lieu en moyenne pour chaque état

    for(int i = 0; i < NB_CAPTEURS; i++)
    {
        nombreEmissions[i] = 0;
    }
    
    for(int i = 0; i < NB_MAX_ESSAIS; i++)
    {
        tempsEmission[i] = 10;
    }

	for(int i = 0; i < (NB_MAX_ESSAIS - 1); i++)
    {
		tempsAttente[i] = 0.25;
    }

	while(1)
	{
		for(int i = 0; i < NB_CAPTEURS; i++)
		{
			if(nombreEmissions[i] >= NB_MAX_EMISSIONS)
			{
				return;
			}
		}
	}
}