#pragma once

/** Le nombre de capteurs. */
#define K 5

/** Lambda de la durée d'émission d'un paquet. */
#define LAMBDA_E 10

/** Lambda du temps d'attente après une émission réussie. */
#define LAMBDA_I 0.1

/** Lambda du temps d'attente en cas d'échec. */
#define LAMBDA_W 0.25

/** Le nombre maximum d'essais d'émission avant que le paquet soit perdu. */
#define MAX_ESSAIS 7

/** Le nombre maximum d'évènements dans l'échéancier. */
#define MAX_EVENEMENTS 1000

/**
 * Le nombre minimum de messages correctement émis par chaque capteur avant
 * que la simulation soit terminée.
 */
#define MIN_EMISSIONS 1e3
