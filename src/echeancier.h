// DIRECTIVES
#ifndef ECHEANCIER_H
#define ECHEANCIER_H

// LIBRAIRIES
#include "constantes.h"

// STRUCTURES
typedef struct evenement
{
	int type;
	double date;
	double duree;
} Evenement;

typedef struct echeancier
{
	int *etatsCapteurs;
	Evenement prochainEvenement;
} Echeancier;

#endif