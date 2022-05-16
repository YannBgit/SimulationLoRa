#include <assert.h>
#include <math.h>
#include <stdlib.h>

/**
 * Génère un nombre aléatoire entre 0 et 1.
 * @return Le nombre tirée aléatoirement.
 */
static double rand_double()
{
	return (double)random() / RAND_MAX;
}

double Expo_Duree(double lambda)
{
	assert(lambda > 0);
	double r;
	do
		r = rand_double();
	while (!r || r == 1);
	return -log(r) / lambda;
}
