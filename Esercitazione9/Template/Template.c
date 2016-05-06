#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
	/* Dichiarazione delle variabili necessarie. */

	/* Imposta il seed del generatore di numeri pseudocasuali. La
	 * funzione dev'essere chiamata solo una volta (tipicamente
	 * all'inizio del programma). */
	srand(time(NULL));

	printf("*-* Blackjack *-*\n");
	
	/* Inserire il vostro codice qui...
	 *
	 * Per generare dei numeri in modo casuale, usare la funzione rand().
	 * Ad esempio, per generare numeri casuali compresi tra 0 (incluso) e
	 * 52 (escluso), usare:
	 * 
	 *   random_number = rand() % 52;
	 * 
	 * Per ulteriori informazioni sulla funzione rand, consultare il
	 * manuale disponibile digitando il seguente comando in un terminale:
	 * 
	 *   man 3 rand
	 */

	return EXIT_SUCCESS;
}
