#include <stdio.h>
#include "es12.h"

/* Esercizio 1 */
void conta_segno(int v[], int n, int *npos, int *nneg, int *nzero) {
    int i;

    *npos = *nneg = *nzero = 0;
    for (i = 0; i < n; i++) {
        if (v[i] > 0) {
            ++*npos;
        } else if (v[i] < 0) {
            ++*nneg;
        } else {
            ++*nzero;
        }
    }
}

/* Esercizio 2 */
int is_prime(int n) {
    int div = 3;

    if (n % 2 == 0)
        return n == 2;
    while (div * div <= n && n % div != 0)
        div += 2;
    return div * div > n;
}

int next_prime(int n) {
    int np;

    np = n + 1 + n % 2;
    while (!is_prime(np))
        np += 2;
    return np;
}

void differenza_frazioni(int n1, int d1, int n2, int d2, int *ndiff, int *ddiff) {
    int div, n, d;
    char is_neg;

    n = n1 * d2 - n2 * d1;
    d = d1 * d2;
    if (n < 0) {
        n = -n;
        is_neg = 1;
    } else {
        is_neg = 0;
    }

    div = 2;
    while (n >= div && d >= div) {
        while (n % div == 0 && d % div == 0) {
            n /= div;
            d /= div;
        }
        div = next_prime(div);
    }
    if (n == 0) {
        d = 1;
    }

    *ndiff = is_neg ? -n : n;
    *ddiff = d;
}

/* Esercizio 3 */
int parseint(char *s, int *len) {
    int j, n;

    n = j = 0;
    while (s[j] != '\0' && s[j] != '.') {
        n = n * 10 + s[j] - '0';
        j++;
    }
    *len = j;
    return n;
}

void str2dec(char s[], int *i, int *d, int *e) {
    int j;

    *i = parseint(s, &j);
    if (s[j] == '.') {
        *d = parseint(s + j + 1, e);
        while (*d % 10 == 0 && *e > 0) {
            *d /= 10;
            --*e;
        }
    } else {
        *d = *e = 0;
    }
}

/* Esercizio 3 - versione pro */
void str2dec_pro(char s[], int *i, int *d, int *e) {
    int idx1, idx2;

    if (sscanf(s, "%d.%n%d%n", i, &idx1, d, &idx2) == 2) {
        *e = idx2 - idx1;
        while (*d % 10 == 0 && *e > 0) {
            *d /= 10;
            --*e;
        }
    } else {
        *d = *e = 0;
    }
}
