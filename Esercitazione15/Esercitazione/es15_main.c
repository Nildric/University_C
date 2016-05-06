#include <stdlib.h>
#include <stdio.h>
#include "es15.h"

/*
 * Per compilare usare il comando:
 *   gcc -std=gnu89 -Wall -pedantic -o es15 es15.c es15_main.c
 */
int main()
{
	int i = 0;

	/* Aggiungi 01 - Variables declaration */
	struct insieme *struct_aggiungi_1 = malloc(sizeof(struct insieme));
	int vector_aggiungi_1[3] = {3, 7, 1};

	/* Aggiungi 02 - Variables declaration */
	struct insieme *struct_aggiungi_2 = malloc(sizeof(struct insieme));
	int vector_aggiungi_2[4] = {-1, 7, -1, 1};

	/* Aggiungi 03 - Variables declaration */
	struct insieme *struct_aggiungi_3 = malloc(sizeof(struct insieme));
	int vector_aggiungi_3[4] = {-1, 7, -1, 1};

	/* Unione 01 - Variables declaration */
	struct insieme *struct_unione_1_a = malloc(sizeof(struct insieme));
	int vector_unione_1_a[3] = {1, 3, 4};
	struct insieme *struct_unione_1_b = malloc(sizeof(struct insieme));
	int vector_unione_1_b[2] = {2, 3};
	struct insieme *struct_unione_result_1 = malloc(sizeof(struct insieme));

	/* Unione 02 - Variables declaration */
	struct insieme *struct_unione_2_a = malloc(sizeof(struct insieme));
	int vector_unione_2_a[3] = {1, 2, 3};
	struct insieme *struct_unione_2_b = malloc(sizeof(struct insieme));
	int vector_unione_2_b[3] = {1, 2, 3};
	struct insieme *struct_unione_result_2 = malloc(sizeof(struct insieme));

	/* Intersezione 01 - Variables declaration */
	struct insieme *struct_intersezione_1_a = malloc(sizeof(struct insieme));
	int vector_intersezione_1_a[3] = {1, 3, 4};
	struct insieme *struct_intersezione_1_b = malloc(sizeof(struct insieme));
	int vector_intersezione_1_b[2] = {2, 3};
	struct insieme *struct_intersezione_result_1 = malloc(sizeof(struct insieme));

	/* Intersezione 02 - Variables declaration */
	struct insieme *struct_intersezione_2_a = malloc(sizeof(struct insieme));
	int vector_intersezione_2_a[3] = {1, 3, 4};
	struct insieme *struct_intersezione_2_b = malloc(sizeof(struct insieme));
	int vector_intersezione_2_b[1] = {2};
	struct insieme *struct_intersezione_result_2 = malloc(sizeof(struct insieme));

	printf("\n***** Aggiungi *****\n\n");

	/* Aggiungi 01 - Printing algorithm */
	struct_aggiungi_1->dimensione = 5;
	struct_aggiungi_1->elementi = malloc(sizeof(int) * struct_aggiungi_1->dimensione);
	for(i = 0; i < struct_aggiungi_1->dimensione; i++)
	{
		struct_aggiungi_1->elementi[i] = (i + 1);
	}
	aggiungi(struct_aggiungi_1, vector_aggiungi_1, 3);

	printf("Desiderato:\t{1, 2, 3, 4, 5, 7}\n");
	printf("Ritorna:   \t");
	printf("{");
	for(i = 0; i < struct_aggiungi_1->dimensione; i++)
	{
		if(i == (struct_aggiungi_1->dimensione - 1))
		{
			printf("%d", struct_aggiungi_1->elementi[i]);
		}
		else
		{
			printf("%d, ", struct_aggiungi_1->elementi[i]);
		}
	}
	printf("}\n\n");

	/* Aggiungi 02 - Printing algorithm */
	struct_aggiungi_2->dimensione = 5;
	struct_aggiungi_2->elementi = malloc(sizeof(int) * struct_aggiungi_2->dimensione);
	for(i = 0; i < struct_aggiungi_2->dimensione; i++)
	{
		struct_aggiungi_2->elementi[i] = (i + 1);
	}
	aggiungi(struct_aggiungi_2, vector_aggiungi_2, 4);

	printf("Desiderato:\t{1, 2, 3, 4, 5, -1, 7}\n");
	printf("Ritorna:   \t");
	printf("{");
	for(i = 0; i < struct_aggiungi_2->dimensione; i++)
	{
		if(i == (struct_aggiungi_2->dimensione - 1))
		{
			printf("%d", struct_aggiungi_2->elementi[i]);
		}
		else
		{
			printf("%d, ", struct_aggiungi_2->elementi[i]);
		}
	}
	printf("}\n\n");

	/* Aggiungi 03 - Printing algorithm */
	struct_aggiungi_3->dimensione = 0;
	struct_aggiungi_3->elementi = NULL;
	aggiungi(struct_aggiungi_3, vector_aggiungi_3, 4);

	printf("Desiderato:\t{-1, 7, 1}\n");
	printf("Ritorna:   \t");
	printf("{");
	for(i = 0; i < struct_aggiungi_3->dimensione; i++)
	{
		if(i == (struct_aggiungi_3->dimensione - 1))
		{
			printf("%d", struct_aggiungi_3->elementi[i]);
		}
		else
		{
			printf("%d, ", struct_aggiungi_3->elementi[i]);
		}
	}
	printf("}\n\n");

	printf("\n***** Unione *****\n\n");

	/* Unione 01 - Printing Algorithm */
	struct_unione_1_a->dimensione = 0;
	struct_unione_1_a->elementi = NULL;
	aggiungi(struct_unione_1_a, vector_unione_1_a, 3);

	struct_unione_1_b->dimensione = 0;
	struct_unione_1_b->elementi = NULL;
	aggiungi(struct_unione_1_b, vector_unione_1_b, 2);

	struct_unione_result_1 = unione(*struct_unione_1_a, *struct_unione_1_b);

	printf("Desiderato:\t{1, 3, 4, 2}\n");
	printf("Ritorna:   \t");
	printf("{");
	for(i = 0; i < struct_unione_result_1->dimensione; i++)
	{
		if(i == (struct_unione_result_1->dimensione - 1))
		{
			printf("%d", struct_unione_result_1->elementi[i]);
		}
		else
		{
			printf("%d, ", struct_unione_result_1->elementi[i]);
		}
	}
	printf("}\n\n");

	/* Unione 02 - Printing Algorithm */
	struct_unione_2_a->dimensione = 0;
	struct_unione_2_a->elementi = NULL;
	aggiungi(struct_unione_2_a, vector_unione_2_a, 3);

	struct_unione_2_b->dimensione = 0;
	struct_unione_2_b->elementi = NULL;
	aggiungi(struct_unione_2_b, vector_unione_2_b, 2);

	struct_unione_result_2 = unione(*struct_unione_2_a, *struct_unione_2_b);

	printf("Desiderato:\t{1, 2, 3}\n");
	printf("Ritorna:   \t");
	printf("{");
	for(i = 0; i < struct_unione_result_2->dimensione; i++)
	{
		if(i == (struct_unione_result_2->dimensione - 1))
		{
			printf("%d", struct_unione_result_2->elementi[i]);
		}
		else
		{
			printf("%d, ", struct_unione_result_2->elementi[i]);
		}
	}
	printf("}\n\n");

	printf("\n***** Intersezione *****\n\n");

	/* Intersezione 01 - Printing Algorithm */
	struct_intersezione_1_a->dimensione = 0;
	struct_intersezione_1_a->elementi = NULL;
	aggiungi(struct_intersezione_1_a, vector_intersezione_1_a, 3);

	struct_intersezione_1_b->dimensione = 0;
	struct_intersezione_1_b->elementi = NULL;
	aggiungi(struct_intersezione_1_b, vector_intersezione_1_b, 2);

	struct_intersezione_result_1 = intersezione(*struct_intersezione_1_a, *struct_intersezione_1_b);

	printf("Desiderato:\t{3}\n");
	printf("Ritorna:   \t");
	printf("{");
	for(i = 0; i < struct_intersezione_result_1->dimensione; i++)
	{
		if(i == (struct_intersezione_result_1->dimensione - 1))
		{
			printf("%d", struct_intersezione_result_1->elementi[i]);
		}
		else
		{
			printf("%d, ", struct_intersezione_result_1->elementi[i]);
		}
	}
	printf("}\n\n");

	/* Intersezione 02 - Printing Algorithm */
	struct_intersezione_2_a->dimensione = 0;
	struct_intersezione_2_a->elementi = NULL;
	aggiungi(struct_intersezione_2_a, vector_intersezione_2_a, 3);

	struct_intersezione_2_b->dimensione = 0;
	struct_intersezione_2_b->elementi = NULL;
	aggiungi(struct_intersezione_2_b, vector_intersezione_2_b, 1);

	struct_intersezione_result_2 = intersezione(*struct_intersezione_2_a, *struct_intersezione_2_b);

	printf("Desiderato:\t{}\n");
	printf("Ritorna:   \t");
	printf("{");
	for(i = 0; i < struct_intersezione_result_2->dimensione; i++)
	{
		if(i == (struct_intersezione_result_2->dimensione - 1))
		{
			printf("%d", struct_intersezione_result_2->elementi[i]);
		}
		else
		{
			printf("%d, ", struct_intersezione_result_2->elementi[i]);
		}
	}
	printf("}");

    return EXIT_SUCCESS;
}
