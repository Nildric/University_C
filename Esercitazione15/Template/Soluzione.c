#include <stdlib.h>
#include "es15.h"

void aggiungi(struct insieme *pin, int v[], int n) {
    int i, j, k, cnt;
    char *aux;

    if (n <= 0) {
        return;
    }

    aux = calloc(n, sizeof(char));
    cnt = 0;
    for (i = 0; i < n; i++) {
        j = 0;
        while (j < pin->dimensione && pin->elementi[j] != v[i]) {
            j++;
        }
        if (j >= pin->dimensione) {
            k = 0;
            while (k < i && v[k] != v[i]) {
                k++;
            }
            if (k >= i) {
                aux[k] = 1;
                cnt++;
            }
        }
    }

    j = pin->dimensione;
    pin->dimensione += cnt;
    pin->elementi = realloc(pin->elementi, pin->dimensione);
    for (i = 0; i < n; i++) {
        if (aux[i]) {
            pin->elementi[j] = v[i];
            j++;
        }
    }
    free(aux);
}

struct insieme* unione(struct insieme in1, struct insieme in2) {
    struct insieme *ris = malloc(sizeof(struct insieme));
    ris->elementi = NULL;
    ris->dimensione = 0;
    aggiungi(ris, in1.elementi, in1.dimensione);
    aggiungi(ris, in2.elementi, in2.dimensione);
    return ris;
}

struct insieme* intersezione(struct insieme in1, struct insieme in2) {
    int i, j, cnt;
    char *comuni;
    struct insieme *ris;

    ris = malloc(sizeof(struct insieme));
    if (in1.dimensione == 0 || in2.dimensione == 0) {
        ris->elementi = NULL;
        ris->dimensione = 0;
        return ris;
    }

    comuni = calloc(in1.dimensione, sizeof(char));
    cnt = 0;
    for (i = 0; i < in1.dimensione; i++) {
        j = 0;
        while (j < in2.dimensione && in1.elementi[i] != in2.elementi[j]) {
            j++;
        }
        if (j < in2.dimensione) {
            comuni[i] = 1;
            cnt++;
        }
    }

    if (cnt == 0) {
        ris->elementi = NULL;
        ris->dimensione = 0;
    } else {
        ris->elementi = malloc(cnt * sizeof(int));
        ris->dimensione = cnt;
        j = 0;
        for (i = 0; i < in1.dimensione; i++) {
            if (comuni[i]) {
                ris->elementi[j] = in1.elementi[i];
                j++;
            }
        }
    }
    free(comuni);
    return ris;
}
