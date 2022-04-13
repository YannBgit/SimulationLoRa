// DIRECTIVES
#ifndef ECHEANCIER_H
#define ECHEANCIER_H

// LIBRAIRIES
#include "constantes.h"

// STRUCTURES
typedef struct evenement
{
	int numeroCapteur;
	int etat;
} Evenement;

typedef struct echeancier
{
	Evenement T[(int)NB_MAX_EMISSIONS];
} Echeancier;

#endif