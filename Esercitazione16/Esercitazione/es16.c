#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "es16.h"

int inserisci_parola(struct frequenze **vector, int vector_dim, char *word)
{
	int index = 0, found_word = 0;
	while(index < vector_dim && !found_word)
	{
		if(strcmp((*vector)[index].parola, word) == 0)
		{
			(*vector)[index].occorrenze += 1;
			found_word = 1;
		}

		index++;
	}

	if(!found_word)
	{
		struct frequenze auxiliar_struct;
		auxiliar_struct.parola = calloc((strlen(word) + 1), sizeof(char));
		strcpy(auxiliar_struct.parola, word);
		auxiliar_struct.occorrenze = 1;

		if(*vector == NULL)
		{
			*vector = calloc(1, sizeof(struct frequenze));
		}
		else
		{
			*vector = realloc(*vector, (sizeof(struct frequenze) * (vector_dim + 1)));
		}

		(*vector)[vector_dim] = auxiliar_struct;

		return 1;
	}

	return 0;
}

struct frequenze* leggi_parole(char *path, int *dim)
{
	FILE *file_stream = NULL;
	struct frequenze *return_vector = NULL;

	if(dim != NULL)
	{
		*dim = 0;
	}

	if(path == NULL)
	{
		return NULL;
	}

	file_stream = fopen(path, "r");
	if(file_stream)
	{
		size_t buffer_size = 0;
		char *buffer_reader = malloc(sizeof(char) * buffer_size);

		while(getline(&buffer_reader, &buffer_size, file_stream) != -1)
		{
			char *token = NULL;
			if(buffer_reader[strlen(buffer_reader) - 1] == '\n')
			{
				buffer_reader[strlen(buffer_reader) - 1] = '\0';
			}
			token = strtok(buffer_reader, " ");

			while(token != NULL)
			{
				*dim += inserisci_parola(&return_vector, *dim, token);
				token = strtok(NULL, " ");
			}
		}

		fclose(file_stream);
	}

    return return_vector;
}

int scrivi_parole(char *path, struct frequenze *v, int dim)
{
	FILE *file_stream = NULL;
	file_stream = fopen(path, "w");

	if(file_stream)
	{
		int index_alpha = 0, index_beta = 0;
		struct frequenze temporary;

		for(index_alpha = 0; index_alpha < (dim - 1); index_alpha++)
		{
			for(index_beta = 0; index_beta < (dim - index_alpha - 1); index_beta++)
			{
				if(v[index_beta].occorrenze < v[index_beta + 1].occorrenze || (v[index_beta].occorrenze == v[index_beta + 1].occorrenze && strcmp(v[index_beta].parola, v[index_beta + 1].parola) > 0))
				{
					temporary = v[index_beta + 1];
					v[index_beta + 1] = v[index_beta];
					v[index_beta] = temporary;
				}
			}
		}

		for(index_alpha = 0; index_alpha < dim; index_alpha++)
		{
			if(index_alpha == (dim - 1))
			{
				fprintf(file_stream, "%s", v[index_alpha].parola);
			}
			else
			{
				fprintf(file_stream, "%s\n", v[index_alpha].parola);
			}
		}

		fclose(file_stream);
		return 1;
	}

	return 0;
}
