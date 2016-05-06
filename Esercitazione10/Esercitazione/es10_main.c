#include <stdlib.h>
#include <stdio.h>
#include "es10.h"

/*
 * Main di esempio. Per compilare, usare il seguente comando:
 *   gcc -o es10 es10.c es10_main.c
 */
int main(int argc, char *argv[]) {
	int n;

	do {
		printf("Inserisci un numero n > 1: ");
		scanf("%d", &n);
	} while (n <= 1);

	if (is_prime(n)) {
		printf("Il numero %d e' primo.\n", n);
	} else {
		printf("Il numero %d non e' primo.\nEcco la sua scomposizione in fattori primi:\n", n);
		print_factors(n);
	}
	
	return EXIT_SUCCESS;
}
