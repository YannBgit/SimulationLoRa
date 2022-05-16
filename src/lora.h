#pragma once
#include "echeancier.h"

/** Un capteur du réseau LoRa. */
typedef struct s_capteur
{
	/** L'état du capteur. */
	int etat;
} Capteur;


typedef struct s_simulation
{
	
} Simulation;

void Traitement_Event(Evenement e, Echeancier ech);
void Traitement_Collision();
void Simulateur(Echeancier ech, int *nbEmissions, double *tempsEmission, double tempsAttenteSucces,
double *tempsAttenteEchec, int *nbCollisions, double *probaCollision);
