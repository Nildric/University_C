#include <stdlib.h>
#include <stdio.h>
#include "es11.h"

/* Scrivere il main di prova in questo file e compilare con il
 * seguente comando:
 *   gcc -std=gnu89 -Wall -pedantic -o es11 es11.c es11_main.c
 */
int main() {
	printf("\n");

	/* SCALA_COLORE - POKER - 1 */
	printf("Vincitore: %d\n\n", vincitore("AH 2H 3H 4H 5H", "AH AD AC AS 2H"));
	/* SCALA - FULL - 2 */
	printf("Vincitore: %d\n\n", vincitore("2H 3H 4H 5H 6D", "AH AD AC 2S 2H"));
	/* SCALA_COLORE - COLORE - 1 */
	printf("Vincitore: %d\n\n", vincitore("3H 4H 5H 6H 7H", "AH 3H 4H 5H 6H"));
	/* SCALA - TRIS - 1 */
	printf("Vincitore: %d\n\n", vincitore("4H 5H 6H 7H 8D", "3H 3D 3C 5S 6H"));
	/* SCALA_COLORE - DOPPIA_COPPIA - 1 */
	printf("Vincitore: %d\n\n", vincitore("5H 6H 7H 8H 9H", "2H 2D 3C 3S 6H"));
	/* SCALA - COPPIA - 1 */
	printf("Vincitore: %d\n\n", vincitore("6H 7H 8H 9H TD", "2H 2D 4C 7S TH"));
	/* SCALA_COLORE - CARTA_ALTA - 1 */
	printf("Vincitore: %d\n\n", vincitore("7H 8H 9H TH JH", "AH 2D 3C 4S 6H"));
	/* SCALA - POKER - 2 */
	printf("Vincitore: %d\n\n", vincitore("8H 9H TH JH QD", "AH AD AC AS 2H"));
	/* SCALA_COLORE - FULL - 1 */
	printf("Vincitore: %d\n\n", vincitore("9H TH JH QH KH", "AH AD AC 2S 2H"));
	/* SCALA - COLORE - 2 */
	printf("Vincitore: %d\n\n", vincitore("TH JH QH KH A2D", "AH 3H 4H 5H 6H"));
	/* DOPPIA_COPPIA - COPPIA - 1 */
	printf("Vincitore: %d\n\n", vincitore("2H 2D 3C 3S 4D", "2H 2D 3C 4S 5H"));

	printf("------------------------------------------------------------\n\n");

	/* SCALA_COLORE - SCALA_COLORE - 0 */
	printf("Vincitore: %d\n\n", vincitore("AH 2H 3H 4H 5H", "TH JH QH KH AH"));
	/* POKER - POKER - 0 */
	printf("Vincitore: %d\n\n", vincitore("AH AD AC AS 2H", "2H 2D 2C 2S 3H"));
	/* FULL - FULL - 0 */
	printf("Vincitore: %d\n\n", vincitore("AH AD AC 2S 2H", "2H 2D 2C 3S 3H"));
	/* COLORE - COLORE - 0 */
	printf("Vincitore: %d\n\n", vincitore("AH 3H 4H 5H 6H", "AD 3D 4D 5D 6D"));
	/* TRIS - TRIS - 0 */
	printf("Vincitore: %d\n\n", vincitore("3H 3D 3C 5S 6H", "4H 4D 4C 5S 6H"));
	/* DOPPIA_COPPIA - DOPPIA_COPPIA - 0 */
	printf("Vincitore: %d\n\n", vincitore("2H 2D 3C 3S 6H", "3H 3D 4C 4S 6H"));
	/* COPPIA - COPPIA - 0 */
	printf("Vincitore: %d\n\n", vincitore("2H 2D 4C 7S TH", "3H 3D 4C 7S TH"));
	/* CARTA_ALTA - CARTA_ALTA - 0 */
	printf("Vincitore: %d\n\n", vincitore("AH 2D 3C 4S 7H", "9H 2D 3C 4S 6H"));

    return EXIT_SUCCESS;
}
