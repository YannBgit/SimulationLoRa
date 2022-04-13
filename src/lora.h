// DIRECTIVES
#ifndef LORA_H
#define LORA_H

// LIBRAIRIES
#include "constantes.h"
#include "echeancier.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// FONCTIONS
double Expo_Duree(double lambda);
void Traitement_Event();
void Traitement_Collision();
void Simulateur(unsigned short nbCapteurs, double *tempsEmissions, double *tempsAttente);

#endif