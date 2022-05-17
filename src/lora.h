#pragma once
#include "echeancier.h"

/** La structure qui contient les variables de la simulation. */
typedef struct s_simulation
{
	/** L'échéancier des évènements. */
	Echeancier ech;
	/** Le nombre total d'émissions réussies dans chaque capteur. */
	int nbTotalEmissions[MAX_K];
	/** Le temps de simulation. */
	double T;
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

/**
 * Traite un événement.
 * @param sim La simulation.
 * @param e L'événement à traiter.
 */
void Traitement_Event(Simulation *sim, const Evenement *e);

/**
 * Traite une collision.
 * @param sim La simulation.
 * @param e1 L'événement à traiter.
 * @param e2 L'évènement à venir en collision.
 */
void Traitement_Collision(Simulation *sim, const Evenement *e1, Evenement *e2);

/**
 * Exécute une simulation.
 * @param sim La simulation.
 * @param showAll 0 pour n'afficher que la fin de la simulation, sinon affiche toutes les étapes.
 */
void Simulateur(Simulation *sim, int showAll);

/**
 * Initilise la simulation.
 * @param sim La structure de la simulation à initialiser.
 * @param K Le nombre de capteurs dans le réseau.
 */
void simulation_init(Simulation *sim, int K);

/**
 * Affiche l'état de la simulation.
 * @param sim La simulation à afficher.
*/
void simulation_print(const Simulation *sim);
