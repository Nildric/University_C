#include <stdlib.h>
#include <stdio.h>
#include "es14.h"

/*
 * Per compilare usate il comando:
 *   gcc -std=gnu89 -Wall -pedantic -o es14 es14.c es14_main.c
 */
int main() {
	int conta_combinazioni_v1[] = {5, 2, 1};
	int conta_combinazioni_v2[] = {7, 9, 3, 2};
	int conta_combinazioni_v3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

	int percorso_minimo_m1[4][4] = {{8, 5, 0, 7},
									{1, 8, 4, 9},
									{7, 1, 2, 0},
									{3, 0, 6, 8}};
	int percorso_minimo_m2[4][4] = {{4, 3, 1, 1},
									{7, 4, 6, 9},
									{0, 2, 7, 8},
									{1, 4, 1, 0}};
	int percorso_minimo_m3[4][4] = {{4, 3, 1, 1},
									{3, 3, 2, 2},
									{7, 7, 6, 6},
									{1, 2, 8, 8}};
	int percorso_minimo_m4[4][4] = {{4, 3, 1, 1},
									{3, 3, 2, 7},
									{2, 2, 2, 2},
									{9, 8, 7, 6}};

	/*
	int percorso_minimo_m5[20][20] = {{4, 3, 9, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {3, 3, 2, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {7, 7, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {1, 2, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	*/

	printf("\n");

	printf("*** Conta Combinazioni ***\n\n");
	printf("Restituisce: %d || Desiderato : 5\n", conta_combinazioni(conta_combinazioni_v1, 3, 6));
	printf("Restituisce: %d || Desiderato : 6\n", conta_combinazioni(conta_combinazioni_v1, 3, 7));
	printf("Restituisce: %d || Desiderato : 8\n", conta_combinazioni(conta_combinazioni_v2, 4, 16));
	/*printf("Restituisce: %d || Desiderato : 181274\n", conta_combinazioni(conta_combinazioni_v3, 20, 50));*/
	/*printf("Restituisce: %d || Desiderato : X\n", conta_combinazioni(conta_combinazioni_v3, 20, 130));*/

	printf("\n--------------------------------------------------\n\n");

	printf("*** Percorso Minimo ***\n\n");

	printf("Restituisce: %d || Desiderato : 20\n", percorso_minimo(percorso_minimo_m1, 4));
	printf("Restituisce: %d || Desiderato : 11\n", percorso_minimo(percorso_minimo_m2, 4));
	printf("Restituisce: %d || Desiderato : 21\n", percorso_minimo(percorso_minimo_m3, 4));
	printf("Restituisce: %d || Desiderato : 15\n", percorso_minimo(percorso_minimo_m4, 4));
	/*printf("Restituisce: %d || Desiderato : 10\n", percorso_minimo(percorso_minimo_m5, 20));*/

	printf("\n");

    return EXIT_SUCCESS;
}
