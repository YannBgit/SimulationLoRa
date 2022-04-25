// LIBRAIRIES
#include "lora.h"

// MAIN
int main()
{
    // Initialisation des variables
    Echeancier ech;									// Echéancier
    int nbCapteurs = 5;                             // Nombre de capteurs K
	int nbEmissions[nbCapteurs];    				// Nombre d'émissions pour chaque capteur
    double tempsEmission[NB_MAX_ESSAIS];            // Graines du temps d'émission par état ej
    double tempsAttenteSucces = 0.1;                // Graine du temps d'attente en cas d'émission réussie i
    double tempsAttenteEchec[NB_MAX_ESSAIS - 1];    // Graines du temps d'attente en cas d'échec (collision) par wj (wait)
    int nbCollisions[NB_MAX_ESSAIS];                // Nombre de collisions par état
    double probaCollision[NB_MAX_ESSAIS];           // Probabilités qu'une collision ait lieu en moyenne pour chaque état

    ech.etatsCapteurs = malloc(sizeof(int) * nbCapteurs);

    for(int i = 0; i < nbCapteurs; i++)
    {
        nbEmissions[i] = 0;
    }
    
    for(int i = 0; i < NB_MAX_ESSAIS; i++)
    {
        tempsEmission[i] = 10;
    }

	for(int i = 0; i < (NB_MAX_ESSAIS - 1); i++)
    {
		tempsAttenteEchec[i] = 0.25;
    }
    
    // Calculs
    void Simulateur(ech, nbCapteurs, nbEmissions, tempsEmission, tempsAttenteSucces,
    tempsAttenteEchec, nbCollisions, probaCollision);

    // Fin
    exit(0);
}