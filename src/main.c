#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "lora.h"

static int print_error(const char *section, const char *message)
{
	fprintf(stderr, "error: %s: %s\n", section, message);
	return EXIT_FAILURE;
}

static int print_usage(char *bin)
{
	fprintf(stderr,
		"usage: %s [--all] [K]\n"
		"Format de sortie: K T P_collision1 ... P_collision7 T_emission1 T_emission2\n"
	, bin);
	return EXIT_FAILURE;
}

int main(int ac, char **av)
{
	// Validation des arguments
	if (ac < 2)
		return print_usage(*av);
	int all = 0;
	if (ac > 2)
	{
		all = !strcmp(av[1], "--all");
		if (!all)
			return print_usage(*av);
	}
	int K = atoi(av[1 + (ac > 2)]);
	if (K < 1 || K > MAX_K)
		return print_error(av[1], "K doit être compris entre 1 et MAX_K");

	srandom(time(NULL));
	Simulation sim;
	simulation_init(&sim, K);
	Simulateur(&sim, all);
	simulation_print(&sim);
}
