#pragma once
#include "echeancier.h"

/** Un capteur du réseau LoRa. */
typedef struct s_capteur
{
	/** L'état du capteur. */
	int etat;
	/** Le nombre d'émissions réussies. */
	int nbEmissions;
} Capteur;

/** La structure qui contient les variables de la simulation. */
typedef struct s_simulation
{
	/** L'ensemble des capteurs du réseau LoRa. */
	Capteur capteurs[K];
	/** Nombre de capteurs qui ont atteint le minimum d'émissions réussies. */
	int nbMinEmissions;
	//int *nbEmissions, double *tempsEmission, double tempsAttenteSucces,
	//double *tempsAttenteEchec, int *nbCollisions, double *probaCollision
} Simulation;

void Traitement_Event(Evenement *e, Echeancier *ech);
void Traitement_Collision();
void Simulateur(Simulation *sim, Echeancier *ech);

void simulation_init(Simulation *sim);
