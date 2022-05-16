#pragma once
#include "echeancier.h"

/** Un capteur du réseau LoRa. */
typedef struct s_capteur
{
	/** Le nombre d'émissions ratées pour le paquet actuel. */
	int nbEchecs;
	/** Le nombre total d'émissions réussies. */
	int nbTotalEmissions;
} Capteur;

/** La structure qui contient les variables de la simulation. */
typedef struct s_simulation
{
	/** L'ensemble des capteurs du réseau LoRa. */
	Capteur capteurs[K];
	/** Nombre de capteurs qui ont atteint le minimum d'émissions réussies. */
	int nbMinEmissions;
} Simulation;

void Traitement_Event(Evenement *e, Echeancier *ech);
void Traitement_Collision();
void Simulateur(Simulation *sim, Echeancier *ech);

void simulation_init(Simulation *sim);
