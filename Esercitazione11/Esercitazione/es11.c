#include "es11.h"

void str2vet(char mano[], int valori_carte[SIZE], char semi[SIZE])
{
	int i = 0, j = 0;

	while(mano[i])
	{
		if((i % 3) == 0)
		{
			switch(mano[i])
			{
				case 'A':
				{
					valori_carte[j] = 1;
					break;
				}

				case 'T':
				{
					valori_carte[j] = 10;
					break;
				}

				case 'J':
				{
					valori_carte[j] = 11;
					break;
				}

				case 'Q':
				{
					valori_carte[j] = 12;
					break;
				}

				case 'K':
				{
					valori_carte[j] = 13;
					break;
				}

				default:
				{
					valori_carte[j] = ((int)mano[i] - (int)'0');
					break;
				}
			}
		}
		else
		{
			if(mano[i] != ' ')
			{
				semi[j] = mano[i];
				j++;
			}
		}

		i++;
	}
}

int punteggio_mano(char mano[])
{
    int valori_carte[SIZE];
    char semi[SIZE];

	int int_tmp = 0;
	char char_tmp;
	int i = 0, j = 0;

    str2vet(mano, valori_carte, semi);

    /* Array sort */
    for(i = 0; i < (SIZE - 1); i++)
    {
        for(j = 0; j < (SIZE - i - 1); j++)
        {
            if(valori_carte[j] > valori_carte[j + 1])
            {
                int_tmp = valori_carte[j];
                valori_carte[j] = valori_carte[j + 1];
                valori_carte[j + 1] = int_tmp;

                char_tmp = semi[j];
                semi[j] = semi[j + 1];
                semi[j + 1] = char_tmp;
            }
        }
    }

    if(semi[0] == semi[1] && semi[1] == semi[2] && semi[2] == semi[3] && semi[3] == semi[4])
    {
        if(((valori_carte[0] == 1 && valori_carte[1] == 10) || valori_carte[1] == (valori_carte[0] + 1)) && valori_carte[2] == (valori_carte[1] + 1) && valori_carte[3] == (valori_carte[2] + 1) && valori_carte[4] == (valori_carte[3] + 1))
        {
            return SCALA_COLORE;
        }

        return COLORE;
    }

    if(((valori_carte[0] == 1 && valori_carte[1] == 10) || valori_carte[1] == (valori_carte[0] + 1)) && valori_carte[2] == (valori_carte[1] + 1) && valori_carte[3] == (valori_carte[2] + 1) && valori_carte[4] == (valori_carte[3] + 1))
    {
        return SCALA;
    }

    if((valori_carte[0] == valori_carte[1] && valori_carte[1] == valori_carte[2] && valori_carte[2] == valori_carte[3]) || (valori_carte[1] == valori_carte[2] && valori_carte[2] == valori_carte[3] && valori_carte[3] == valori_carte[4]))
    {
        return POKER;
    }

    if((valori_carte[0] == valori_carte[1] && valori_carte[2] == valori_carte[3] && valori_carte[3] == valori_carte[4]) || (valori_carte[0] == valori_carte[1] && valori_carte[1] == valori_carte[2] && valori_carte[3] == valori_carte[4]))
    {
        return FULL;
    }

    if((valori_carte[0] == valori_carte[1] && valori_carte[1] == valori_carte[2]) || (valori_carte[1] == valori_carte[2] && valori_carte[2] == valori_carte[3]) || (valori_carte[2] == valori_carte[3] && valori_carte[3] == valori_carte[4]))
    {
        return TRIS;
    }

    if((valori_carte[0] == valori_carte[1] && valori_carte[2] == valori_carte[3]) || (valori_carte[0] == valori_carte[1] && valori_carte[3] == valori_carte[4]) || (valori_carte[1] == valori_carte[2] && valori_carte[3] == valori_carte[4]))
    {
        return DOPPIA_COPPIA;
    }

    if(valori_carte[0] == valori_carte[1] || valori_carte[1] == valori_carte[2] || valori_carte[2] == valori_carte[3] || valori_carte[3] == valori_carte[4])
    {
        return COPPIA;
    }

    return CARTA_ALTA;
}

int vincitore(char m1[], char m2[])
{
	int punteggio_mano_alpha = punteggio_mano(m1), punteggio_mano_beta = punteggio_mano(m2);

	if(punteggio_mano_alpha > punteggio_mano_beta)
	{
		return 1;
	}

	if(punteggio_mano_alpha < punteggio_mano_beta)
	{
		return 2;
	}

	return 0;
}
