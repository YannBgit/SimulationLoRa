#include "lora.h"
#include "utils.h"

void Traitement_Event(Evenement *e, Echeancier *ech)
{
	(void)e;
	(void)ech;
	// Met à jour les variables de la simulation
}

void Traitement_Collision()
{
	// Traite une collisions, en particulier met à jour l'état des capteurs en collision
}

void Simulateur(Simulation *sim, Echeancier *ech)
{
	while (sim->nbMinEmissions < K)
	{
		// Simulation
	}
}

void simulation_init(Simulation *sim)
{
	
}
