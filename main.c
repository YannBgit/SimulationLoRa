#include <stdio.h>
#include <stdlib.h>

int main()
{
	srandom(87235);
	double r; long i = 0;
	do {
		r = (double)random() / RAND_MAX;
		++i;
	}	while (r);
	printf("%g en %ld itérations\n", r, i);
}
