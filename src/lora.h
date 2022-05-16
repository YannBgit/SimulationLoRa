#pragma once
#include "echeancier.h"

/** Un capteur du réseau LoRa. */
typedef struct s_capteur
{
	/** Le nombre total d'émissions réussies. */
	int nbTotalEmissions;
} Capteur;

/** La structure qui contient les variables de la simulation. */
typedef struct s_simulation
{
	/** L'échéancier des évènements. */
	Echeancier ech;
	/** L'ensemble des capteurs du réseau LoRa. */
	Capteur capteurs[MAX_K];
	/** Le nombre de capteurs dans le réseau. */
	int K;
	/** Nombre de capteurs qui ont atteint le minimum d'émissions réussies. */
	long nbMinEmissions;
	/** Nombre de collisions dans chaque état. */
	long nbCollisions[MAX_ESSAIS];
	/** Nombre d'émissions totales dans chaque état. */
	long nbEmissions[MAX_ESSAIS];
	/** Temps d'émission observée dans chaque état. */
	double tempsEmission[MAX_ESSAIS];
} Simulation;

void Traitement_Event(Simulation *sim, const Evenement *e);
void Traitement_Collision(Simulation *sim, const Evenement *e1, Evenement *e2);
void Simulateur(Simulation *sim);

void simulation_init(Simulation *sim, int K);
void simulation_print(Simulation *sim);
