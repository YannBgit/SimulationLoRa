#pragma once
#include "constantes.h"

typedef enum e_type_evenement
{
	/** Début émission */
	DE,
	/** Fin émission */
	FE,
	/** Traitement collision */
	TC
}	TypeEvenement;

/** Représente un évènement dans l'échéancier. */
typedef struct s_evenement
{
	/** Le type d'événement. */
	TypeEvenement type;
	/** L'état du capteur. */
	int etat;
	/** La date de l'événement. */
	double date;
} Evenement;

/** Représente un ensemble d'évènement en fonction de leur date. */
typedef struct s_echeancier
{
	/** Le stockage des événements. */
	Evenement evenements[MAX_EVENEMENTS];
	/** Le nombre d'événements actuellement dans l'échéancier. */
	int n;
} Echeancier;

/**
 * Ajoute un événement à l'échéancier.
 * @param e L'échéancier.
 * @param type Le type de l'événement.
 * @param date La date de l'événement.
 */
void echeancier_ajouter(Echeancier *e, TypeEvenement type, double date);

/**
 * Détecte si un évènement est en collision avec un autre dans l'échéancier.
 * @param e L'échéancier.
 * @param e1 L'évènement à tester.
 * @return L'évènement en collision avec e1, ou NULL si aucun évènement n'est en collision.
 */
Evenement *echeancier_detecter_collision(Echeancier *e, const Evenement *e1);

/**
 * Récupère le prochain événement de l'échéancier.
 * Cet évènement est supprimé de l'échéancier.
 * Le comportement est indéfini si l'échéancier est vide.
 * @param e L'échéancier.
 * @return Le prochain événement.
 * @see echeancier_vide
 */
Evenement echeancier_suivant(Echeancier *e);

/**
 * Initialise l'échéancier.
 * @param e L'échéancier.
 */
void echeancier_init(Echeancier *e);

/**
 * Vérifie si l'échéancier est vide.
 * @param e L'échéancier.
 * @return 1 si l'échéancier est vide, 0 sinon.
 */
int echeancier_vide(Echeancier *e);
