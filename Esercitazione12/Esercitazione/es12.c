#include "es12.h"
#include <stdlib.h>
#include <math.h>

void conta_segno(int v[], int n, int *npos, int *nneg, int *nzero)
{
    int index = 0;

    for(index = 0; index < n; index++)
    {
        if(v[index] > 0)
        {
            *npos += 1;
        }

        if(v[index] < 0)
        {
            *nneg += 1;
        }

        if(v[index] == 0)
        {
            *nzero += 1;
        }
    }
}

int min_tra_due(int n1, int n2)
{
    if(n1 < n2)
    {
        return n1;
    }

    return n2;
}

void differenza_frazioni(int n1, int d1, int n2, int d2, int *ndiff, int *ddiff)
{
    int auxiliar = 0;

    *ddiff = d1 * d2;
    *ndiff = ((*ddiff / d1) * n1) - ((*ddiff / d2) * n2);

    auxiliar = min_tra_due(abs(*ndiff), abs(*ddiff));

    while(auxiliar > 1)
    {
        if(*ndiff % auxiliar == 0 && *ddiff % auxiliar == 0)
        {
            *ndiff /= auxiliar;
            *ddiff /= auxiliar;

            auxiliar = min_tra_due(abs(*ndiff), abs(*ddiff)) + 1;
        }

        auxiliar--;
    }

    if(*ndiff == 0)
    {
        *ddiff = 1;
    }
}

void substr(char s[], int inizio, int fine, char return_string[])
{
    int index = 0;

    while(inizio < fine)
    {
        return_string[index] = s[inizio];

        inizio++;
        index++;
    }

    return_string[index] = '\0';
}

void str2dec(char s[], int *i, int *d, int *e)
{
    int index = 0, flag_punto = 0, prima_punto = 0, dopo_punto = 0;
    char char_i[100], char_d[100];

    while(s[index])
    {
        if(s[index] == '.')
        {
            flag_punto = 1;
            index++;
        }

        if(!flag_punto)
        {
            prima_punto++;
        }
        else
        {
            dopo_punto++;
        }

        index++;
    }

    *e = dopo_punto;

    substr(s, 0, (prima_punto), char_i);
    substr(s, (prima_punto + 1), (prima_punto + dopo_punto + 1), char_d);

    index = 0;
    while(prima_punto > 0)
    {
        *i += ((int)char_i[index] - (int)'0') * (pow(10, --prima_punto));
        index++;
    }

    index = 0;
    while(dopo_punto > 0)
    {
        *d += ((int)char_d[index] - (int)'0') * (pow(10, --dopo_punto));
        index++;
    }

    if(*d == 0)
    {
    	*e = 0;
    }
    else
    {
    	while((*d % 10) == 0)
		{
			*d /= 10;
			(*e)--;
		}
    }
}
