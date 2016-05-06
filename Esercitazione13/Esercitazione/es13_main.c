#include <stdlib.h>
#include <stdio.h>
#include "es13.h"

/*
 * Per compilare usare il comando
 *   gcc -std=gnu89 -Wall -pedantic -o es13 es13.c es13_main.c
 */
int main()
{
	int ricerca_v[] = {10, 8, 6, 4, 1, -3};

	int zaino_v[] = {3, 6, 2, 8, 11};

	printf("\n");

	printf("*** Ricerca ***\n\n");
	printf("Restituisce: +%d || Desiderato : +2\n", ricerca(ricerca_v, 6, 0, 5));
	printf("Restituisce: %d || Desiderato : -1\n", ricerca(ricerca_v, 2, 0, 5));
	printf("Restituisce: %d || Desiderato : -1\n", ricerca(ricerca_v, 1, 0, 0));
	printf("Restituisce: +%d || Desiderato : +4\n", ricerca(ricerca_v, 1, 4, 4));

	printf("\n--------------------------------------------------\n\n");

	printf("*** Palindroma ***\n\n");
	printf("Restituisce: %d || Desiderato : 1\n", palindroma("anna"));
	printf("Restituisce: %d || Desiderato : 1\n", palindroma("i topi non avevano nipoti"));
	printf("Restituisce: %d || Desiderato : 1\n", palindroma(""));
	printf("Restituisce: %d || Desiderato : 0\n", palindroma("cane"));
	printf("Restituisce: %d || Desiderato : 1\n", palindroma("   i   topi   non   avevano   nipoti   "));
	printf("Restituisce: %d || Desiderato : 1\n", palindroma("                                         "));

	printf("\n--------------------------------------------------\n\n");

	printf("*** Zaino ***\n\n");
	printf("Restituisce: %d || Desiderato : 1\n", zaino(zaino_v, 5, 14));
	printf("Restituisce: %d || Desiderato : 1\n", zaino(zaino_v, 5, 30));
	printf("Restituisce: %d || Desiderato : 0\n", zaino(zaino_v, 5, 7));
	printf("Restituisce: %d || Desiderato : 1\n", zaino(zaino_v, 5, 6));
	printf("Restituisce: %d || Desiderato : 1\n", zaino(zaino_v, 5, 0));
	printf("Restituisce: %d || Desiderato : 0\n", zaino(zaino_v, 5, 100));

	printf("\n");

    return EXIT_SUCCESS;
}
