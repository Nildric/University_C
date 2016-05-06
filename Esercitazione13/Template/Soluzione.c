#include <string.h>
#include "es13.h"

int ricerca(int v[], int val, int inf, int sup) {
    if (sup < inf) {
        return -1;
    } else {
        int m = (inf + sup) / 2;
        if (v[m] == val) {
            return m;
        } else if (v[m] < val) {
            return ricerca(v, val, inf, m - 1);
        } else {
            return ricerca(v, val, m + 1, sup);
        }
    }
}

int palindroma_aux(char *s, int inf, int sup) {
    if (sup < inf || s[inf] == '\0') {
        return 1;
    } else if (s[inf] == ' ') {
        return palindroma_aux(s, inf + 1, sup);
    } else if (s[sup] == ' ') {
        return palindroma_aux(s, inf, sup - 1);
    } else if (s[inf] != s[sup]) {
        return 0;
    } else {
        return palindroma_aux(s, inf + 1, sup - 1);
    }
}

int palindroma(char *s) {
    return palindroma_aux(s, 0, strlen(s) - 1);
}

int zaino(int pesi[], int n, int p) {
    if (p == 0) {
        return 1;
    } else if (n <= 0 || p < 0) {
        return 0;
    } else {
        return zaino(pesi + 1, n - 1, p - pesi[0]) ? 1 : zaino(pesi + 1, n - 1, p);
    }
}
