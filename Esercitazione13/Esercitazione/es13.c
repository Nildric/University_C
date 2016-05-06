#include <string.h>
#include "es13.h"

int ricerca(int v[], int val, int inf, int sup)
{
	int m = ((inf + sup) / 2);

	if(sup < inf)
	{
		return -1;
	}

	if(v[m] == val)
	{
		return m;
	}

	if(v[m] > val)
	{
		return ricerca(v, val, inf, (m - 1));
	}

	return ricerca(v, val, (m + 1), sup);
}

int palindroma_ricorsiva(int inizio, int fine, int dimensione, char *stringa)
{
    if(inizio >= fine)
    {
        return 1;
    }

    if(stringa[fine] == ' ' && fine > 0)
    {
        return palindroma_ricorsiva(inizio, (fine - 1), dimensione, stringa);
    }

    if(stringa[inizio] == ' ' && inizio < dimensione)
    {
        return palindroma_ricorsiva((inizio + 1), fine, dimensione, stringa);
    }

    if(stringa[inizio] != stringa[fine])
    {
        return 0;
    }

    return palindroma_ricorsiva((inizio + 1), (fine - 1), dimensione, stringa);
}

int palindroma(char *s)
{
    int dimensione = strlen(s);
    return palindroma_ricorsiva(0, (dimensione - 1), dimensione, s);
}

int zaino(int pesi[], int n, int p)
{
    if(p == 0)
    {
        return 1;
    }

    if(n == 0)
    {
        return 0;
    }

    if(pesi[n - 1] > p)
    {
        return zaino(pesi, (n - 1), p);
    }

    return zaino(pesi, (n - 1), p) || zaino(pesi, (n - 1), (p - pesi[n - 1]));
}
