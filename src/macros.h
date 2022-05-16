#pragma once

/**
 * Echange le contenu de deux variables.
 * @param A La première variable.
 * @param B La seconde variable.
 */
#define SWAP(A, B) \
	do { \
		typeof(A) C = (A); \
		(A) = (B); \
		(B) = C; \
	} while (0)
