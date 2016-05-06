#include <stdlib.h>
#include "es15.h"

void aggiungi(struct insieme *pin, int v[], int n)
{
	int i = 0, j = 0, found_duplicate = 0;

	for(i = 0; i < n; i++)
	{
		found_duplicate = 0;

		for(j = 0; j < pin->dimensione; j++)
		{
			if(v[i] == pin->elementi[j])
			{
				found_duplicate = 1;
			}
		}

		if(!found_duplicate)
		{
			pin->dimensione += 1;

			if(pin->elementi == NULL)
			{
				pin->elementi = (int*)calloc(pin->dimensione, sizeof(int));
			}
			else
			{
				pin->elementi = (int*)realloc(pin->elementi, (pin->dimensione * sizeof(int)));
			}

			pin->elementi[(pin->dimensione - 1)] = v[i];
		}
	}

}

struct insieme* unione(struct insieme in1, struct insieme in2)
{
	struct insieme *struct_return = (struct insieme*)malloc(sizeof(struct insieme));
	*struct_return = in1;

	aggiungi(struct_return, in2.elementi, in2.dimensione);

	return struct_return;
}

struct insieme* intersezione(struct insieme in1, struct insieme in2)
{
	struct insieme *struct_return = (struct insieme*)malloc(sizeof(struct insieme));
	int i = 0, j = 0;

	struct_return->dimensione = 0;
	struct_return->elementi = NULL;

	for(i = 0; i < in1.dimensione; i++)
	{
		for(j = 0; j < in2.dimensione; j++)
		{
			if(in1.elementi[i] == in2.elementi[j])
			{
				aggiungi(struct_return, &(in1.elementi[i]), 1);
			}
		}
	}

	return struct_return;
}
