#include "es14.h"

int conta_combinazioni(int v[], int n, int somma) {
    if (somma <= 0) {
        return somma == 0;
    } else if (n <= 0) {
        return 0;
    } else {
        int count1 = conta_combinazioni(v, n, somma - v[0]);
        int count2 = conta_combinazioni(v + 1, n - 1, somma);
        return count1 + count2;
    }
}

int percorso_aux(int m[N][N], int n, int r, int c) {
    if (r == n - 1 && c == n - 1) {
        return m[r][c];
    } else if (r == n - 1) {
        return m[r][c] + percorso_aux(m, n, r, c + 1);
    } else if (c == n - 1) {
        return m[r][c] + percorso_aux(m, n, r + 1, c);
    } else {
        int p[3], i, min;

        p[0] = percorso_aux(m, n, r, c + 1);
        p[1] = percorso_aux(m, n, r + 1, c + 1);
        p[2] = percorso_aux(m, n, r + 1, c);

        min = p[0];
        for (i = 1; i < 3; i++) {
            if (p[i] < min) {
                min = p[i];
            }
        }
        return m[r][c] + min;
    }
}

int percorso_minimo(int m[N][N], int n) {
    return percorso_aux(m, n, 0, 0);
}
