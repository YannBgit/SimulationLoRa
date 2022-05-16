#pragma once

/** Le nombre de capteurs. */
#define K 5

/** Le nombre maximum d'essais d'émission avant que le paquet soit perdu. */
#define MAX_ESSAIS 7

/** Le nombre maximum d'évènements dans l'échéancier. */
#define MAX_EVENEMENTS 1000

/**
 * Le nombre minimum de messages correctement émis par chaque capteur avant
 * que la simulation soit terminée.
 */
#define MIN_EMISSIONS 1e3
