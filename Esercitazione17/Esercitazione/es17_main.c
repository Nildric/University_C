#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "es17.h"

/*
 * Per compilare usare il seguente comando:
 *   gcc -std=gnu89 -Wall -pedantic -o es17 es17.c es17_main.c
 */

int prepend_main(ListaS *list, char *string)
{
	ListaS new_cell = (ListaS) malloc(sizeof(struct nodoS));
	if(new_cell)
	{
		new_cell->next = *list;
		new_cell->str = calloc((strlen(string) + 1), sizeof(char));
		strcpy(new_cell->str, string);

		*list = new_cell;

		return 1;
	}

	return 0;
}

int append_main(ListaS *list, char *string)
{
	if(*list)
	{
		ListaS pc = *list;
		while(pc->next)
		{
			pc = pc->next;
		}

		return prepend_main(&(pc->next), string);
	}
	else
	{
		return prepend_main(list, string);
	}
}

void destroy_main(ListaS list)
{
	ListaS pc = list;
	while(pc)
	{
		list = pc->next;
		free(pc);
		pc = list;
	}
}

void print_main(ListaS list)
{
	if(list)
	{
		ListaS pc = list;

		printf("([");
		while(pc)
		{
			if(pc->next)
			{
				printf("\"%s\", ", pc->str);
			}
			else
			{
				printf("\"%s\"", pc->str);
			}
			pc = pc->next;
		}
		printf("])");
	}
	else
	{
		printf("()");
	}
}

int main()
{
	ListaS lista_esercizio_1 = NULL;
	ListaS lista_esercizio_2 = NULL;
	ListaS lista_esercizio_3 = NULL;

	printf("*** Esercizio 1 - ordinata(ListaS l) ***\n");

	printf("\nDesiderato:\t1\n");
	printf("Ritorna:\t%d\n", ordinata(lista_esercizio_1));

	append_main(&lista_esercizio_1, "cane");
	append_main(&lista_esercizio_1, "gatto");
	append_main(&lista_esercizio_1, "zebra");
	printf("\nDesiderato:\t1\n");
	printf("Ritorna:\t%d\n", ordinata(lista_esercizio_1));
	destroy_main(lista_esercizio_1);
	lista_esercizio_1 = NULL;

	append_main(&lista_esercizio_1, "cane");
	append_main(&lista_esercizio_1, "gatto");
	append_main(&lista_esercizio_1, "elefante");
	append_main(&lista_esercizio_1, "zebra");
	printf("\nDesiderato:\t0\n");
	printf("Ritorna:\t%d\n", ordinata(lista_esercizio_1));
	destroy_main(lista_esercizio_1);
	lista_esercizio_1 = NULL;

	append_main(&lista_esercizio_1, "cane");
	append_main(&lista_esercizio_1, "cane");
	printf("\nDesiderato:\t1\n");
	printf("Ritorna:\t%d\n", ordinata(lista_esercizio_1));
	destroy_main(lista_esercizio_1);
	lista_esercizio_1 = NULL;

	append_main(&lista_esercizio_1, "cane");
	append_main(&lista_esercizio_1, "CANE");
	printf("\nDesiderato:\t0\n");
	printf("Ritorna:\t%d\n", ordinata(lista_esercizio_1));
	destroy_main(lista_esercizio_1);
	lista_esercizio_1 = NULL;

	printf("\n*** Esercizio 2 - inserisci(ListaS *l, char *s) ***\n");

	printf("\nDesiderato:\t([\"cane\"])\n");
	printf("Ritorna:\t");
	inserisci(&lista_esercizio_2, "cane");
	print_main(lista_esercizio_2);
	printf("\n");

	printf("\nDesiderato:\t([\"cane\", \"gatto\"])\n");
	printf("Ritorna:\t");
	inserisci(&lista_esercizio_2, "gatto");
	print_main(lista_esercizio_2);
	printf("\n");

	printf("\nDesiderato:\t([\"cane\", \"elefante\", \"gatto\"])\n");
	printf("Ritorna:\t");
	inserisci(&lista_esercizio_2, "elefante");
	print_main(lista_esercizio_2);
	printf("\n");

	printf("\nDesiderato:\t([\"basilisco\", \"cane\", \"elefante\", \"gatto\"])\n");
	printf("Ritorna:\t");
	inserisci(&lista_esercizio_2, "basilisco");
	print_main(lista_esercizio_2);
	printf("\n");

	printf("\nDesiderato:\t([\"basilisco\", \"cane\", \"elefante\", \"fagiano\", \"gatto\"])\n");
	printf("Ritorna:\t");
	inserisci(&lista_esercizio_2, "fagiano");
	print_main(lista_esercizio_2);
	printf("\n");

	printf("\nDesiderato:\t([\"alpaca\", \"basilisco\", \"cane\", \"elefante\", \"fagiano\", \"gatto\"])\n");
	printf("Ritorna:\t");
	inserisci(&lista_esercizio_2, "alpaca");
	print_main(lista_esercizio_2);
	printf("\n");

	printf("\nDesiderato:\t([\"alpaca\", \"basilisco\", \"cane\", \"elefante\", \"fagiano\", \"gatto\", \"zebra\"])\n");
	printf("Ritorna:\t");
	inserisci(&lista_esercizio_2, "zebra");
	print_main(lista_esercizio_2);
	printf("\n");

	printf("\n*** Esercizio 3 - rimuovi_duplicati(ListaS l) ***\n");

	printf("\nDesiderato:\t()\n");
	printf("Ritorna:\t");
	rimuovi_duplicati(lista_esercizio_3);
	print_main(lista_esercizio_3);
	printf("\n");

	printf("\nDesiderato:\t([\"cane\", \"elefante\", \"gatto\"])\n");
	printf("Ritorna:\t");
	append_main(&lista_esercizio_3, "cane");
	append_main(&lista_esercizio_3, "elefante");
	append_main(&lista_esercizio_3, "gatto");
	rimuovi_duplicati(lista_esercizio_3);
	print_main(lista_esercizio_3);
	destroy_main(lista_esercizio_3);
	lista_esercizio_3 = NULL;
	printf("\n");

	printf("\nDesiderato:\t([\"cane\", \"elefante\", \"gatto\"])\n");
	printf("Ritorna:\t");
	append_main(&lista_esercizio_3, "cane");
	append_main(&lista_esercizio_3, "cane");
	append_main(&lista_esercizio_3, "elefante");
	append_main(&lista_esercizio_3, "gatto");
	append_main(&lista_esercizio_3, "gatto");
	append_main(&lista_esercizio_3, "gatto");
	rimuovi_duplicati(lista_esercizio_3);
	print_main(lista_esercizio_3);
	destroy_main(lista_esercizio_3);
	lista_esercizio_3 = NULL;

    return EXIT_SUCCESS;
}
