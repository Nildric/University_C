#include "es14.h"

int conta_combinazioni(int v[], int n, int somma)
{
    if(n == 0 || somma < 0)
    {
        return 0;
    }

    if(!somma)
    {
        return 1;
    }

    return conta_combinazioni(v, n, somma - v[n - 1]) + conta_combinazioni(v, n - 1, somma);
}

void inizializza_matrice(int matrice_ausiliaria[N][N], int r, int c)
{
    if(c >= N)
    {
        c = 0;
        r++;
    }

    if(r >= N)
    {
        return;
    }

    matrice_ausiliaria[r][c] = -1;
    inizializza_matrice(matrice_ausiliaria, r, c + 1);
}

int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }

    return b;
}

int percorso_minimo_ricorsivo(int matrice[N][N], int matrice_ausiliaria[N][N], int n, int r, int c)
{
    int percorso_lunghezza_minima = 0;

    if(matrice_ausiliaria[r][c] < 0)
    {
        if(r == (n - 1) && c == (n - 1))
        {
            percorso_lunghezza_minima = 0;
        }
        else if(c >= (n - 1))
        {
            percorso_lunghezza_minima = percorso_minimo_ricorsivo(matrice, matrice_ausiliaria, n, r + 1, c);
        }
        else if(r >= (n - 1))
        {
            percorso_lunghezza_minima = percorso_minimo_ricorsivo(matrice, matrice_ausiliaria, n, r, c + 1);
        }
        else
        {
            percorso_lunghezza_minima = min(percorso_minimo_ricorsivo(matrice, matrice_ausiliaria, n, r + 1, c + 1), min(percorso_minimo_ricorsivo(matrice, matrice_ausiliaria, n, r, c + 1), percorso_minimo_ricorsivo(matrice, matrice_ausiliaria, n, r + 1, c)));
        }

        matrice_ausiliaria[r][c] = matrice[r][c] + percorso_lunghezza_minima;
    }

    return matrice_ausiliaria[r][c];
}

int percorso_minimo(int m[N][N], int n)
{
    int matrice_ausiliaria[N][N];
    inizializza_matrice(matrice_ausiliaria, 0, 0);
    return percorso_minimo_ricorsivo(m, matrice_ausiliaria, n, 0, 0);
}
