#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "es16.h"

/*
 * Per compilare usare il comando:
 *   gcc -std=gnu89 -Wall -pedantic -o es16 es16.c es16_main.c
 */
int main()
{
	int index = 0;

	/* Esercizio 1 (leggi_parole) - Variables declaration 01 */
	int vector_dim_leggi_parole_01 = 25;
	char *path_leggi_parole_01 = "es16_esercizio_1_file_01.txt";
	struct frequenze *leggi_parole_output_01 = leggi_parole(path_leggi_parole_01, &vector_dim_leggi_parole_01);

	/* Esercizio 1 (leggi_parole) - Variables declaration 02 */
	int vector_dim_leggi_parole_02 = 25;
	char *path_leggi_parole_02 = "es16_esercizio_1_file_02.txt";
	struct frequenze *leggi_parole_output_02 = leggi_parole(path_leggi_parole_02, &vector_dim_leggi_parole_02);

	printf("*** Esercizio 1 (leggi_parole) ***\n\n");

	/* Esercizio 1 (leggi_parole) - Printing Algorithm 01 */
	printf("Desiderato:\t{(il, 4), (cane, 2), (e, 2), (gatto, 2), (dormono, 1), (sotto, 1), (un, 1), (albero, 1), (sono, 1), (animali, 1), (domestici, 1)} --- Dim: 11\nRitorna:\t");
	printf("{");
	for(index = 0; index < vector_dim_leggi_parole_01; index++)
	{
		if(index == (vector_dim_leggi_parole_01 - 1))
		{
			printf("(%s, %d)", leggi_parole_output_01[index].parola, leggi_parole_output_01[index].occorrenze);
		}
		else
		{
			printf("(%s, %d), ", leggi_parole_output_01[index].parola, leggi_parole_output_01[index].occorrenze);
		}
	}
	printf("} --- Dim: %d", vector_dim_leggi_parole_01);

	/* Esercizio 1 (leggi_parole) - Printing Algorithm 02 */
	printf("\n\nDesiderato:\t| Pointer: NULL - Dimension: 0 |");
	printf("\nRitorna:\t| ");
	if(leggi_parole_output_02 == NULL)
	{
		printf("Pointer: NULL - ");
	}
	printf("Dimension: %d |", vector_dim_leggi_parole_02);

	printf("\n\n\n*** Esercizio 2 (scrivi_parole) *** !!! ALWAYS CHECK THE TEMPLATE FILE !!!\n\n");

	/* Esercizio 2 (scrivi_parole) - Variables declaration 01 */
	int vector_dim_scrivi_parole_01 = 0;
	char *path_scrivi_parole_01 = "es16_esercizio_2_file_01.txt";
	struct frequenze *scrivi_parole_output_01 = leggi_parole(path_leggi_parole_01, &vector_dim_scrivi_parole_01);
	int scrivi_parole_check_01 = scrivi_parole(path_scrivi_parole_01, scrivi_parole_output_01, vector_dim_scrivi_parole_01);

	/* Esercizio 2 (scrivi_parole) - Printing Algorithm 01*/
	vector_dim_scrivi_parole_01 = 0;
	scrivi_parole_output_01 = leggi_parole(path_scrivi_parole_01, &vector_dim_scrivi_parole_01);
	printf("Desiderato:\t{(il, 1), (cane, 1), (e, 1), (gatto, 1), (albero, 1), (animali, 1), (domestici, 1), (dormono, 1), (sono, 1), (sotto, 1), (un, 1)} --- Dim: 11\nRitorna:\t");
	if(scrivi_parole_check_01)
	{
		printf("{");
		for(index = 0; index < vector_dim_scrivi_parole_01; index++)
		{
			if(index == (vector_dim_scrivi_parole_01 - 1))
			{
				printf("(%s, %d)", scrivi_parole_output_01[index].parola, scrivi_parole_output_01[index].occorrenze);
			}
			else
			{
				printf("(%s, %d), ", scrivi_parole_output_01[index].parola, scrivi_parole_output_01[index].occorrenze);
			}
		}
		printf("} --- Dim: %d", vector_dim_scrivi_parole_01);
	}

	/* Esercizio 2 (scrivi_parole) - Variables declaration 02 */
	int scrivi_parole_check_02 = scrivi_parole("read_only_folder/wrong_path.txt", NULL, 0);

	/* Esercizio 2 (scrivi_parole) - Printing algorithm 02 */
	printf("\n\nDesiderato:\t0");
	printf("\nRitorna:\t%d", scrivi_parole_check_02);

	/* Esercizio 2 (scrivi_parole) - Variables declaration 03 */
	int scrivi_parole_check_03 = scrivi_parole("es16_esercizio_2_file_null_vector.txt", NULL, 0);
	printf("\n\nDesiderato:\t0 (in caso il file non venga creato) - 1 (in caso il file venga creato)");
	printf("\nRitorna:\t%d", scrivi_parole_check_03);

    return EXIT_SUCCESS;
}
