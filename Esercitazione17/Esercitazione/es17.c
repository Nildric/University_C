#include <stdlib.h>
#include <string.h>
#include "es17.h"

int ordinata(ListaS l)
{
	int is_ordered = 1;

	if(l)
	{
		while(l->next != NULL && is_ordered)
		{
			if(strcmp(l->str, l->next->str) > 0)
			{
				is_ordered = 0;
			}

			l = l->next;
		}
	}

	return is_ordered;
}

int prepend_strng(ListaS *list, char *string)
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

void inserisci(ListaS *l, char *s)
{
	if(*l)
	{
		ListaS pc = *l;
		int flag = 1;

		while(pc && flag)
		{
			if(strcmp(pc->str, s) > 0)
			{
				prepend_strng(l, s);
				flag = 0;
			}
			else
			{
				if(pc->next == NULL)
				{
					prepend_strng(&(pc->next), s);
					flag = 0;
				}
				else
				{
					if(strcmp(pc->next->str, s) > 0)
					{
						ListaS temporary = pc->next;

						prepend_strng(&(pc->next), s);
						pc->next->next = temporary;
						flag = 0;
					}
				}
			}

			pc = pc->next;
		}
	}
	else
	{
		prepend_strng(l, s);
	}
}

void rimuovi_duplicati(ListaS l)
{
	if(l)
	{
		ListaS pc = l;
		while(pc->next)
		{
			if(strcmp(pc->str, pc->next->str) == 0)
			{
				ListaS temporary = pc->next->next;

				free(pc->next);
				pc->next = temporary;
			}
			else
			{
				pc = pc->next;
			}
		}
	}
}
