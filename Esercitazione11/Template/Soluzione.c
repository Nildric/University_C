#include "es11.h"

void str2vet(char mano[], int valori_carte[SIZE], char semi[SIZE]) {
    int i;
    char v;

    for (i = 0; i < SIZE; i++) {
        v = mano[3*i];
        if (v >= '2' && v <= '9') {
            valori_carte[i] = v - '0';
        } else if (v == 'A') {
            valori_carte[i] = 1;
        } else if (v == 'T') {
            valori_carte[i] = 10;
        } else if (v == 'J') {
            valori_carte[i] = 11;
        } else if (v == 'Q') {
            valori_carte[i] = 12;
        } else if (v == 'K') {
            valori_carte[i] = 13;
        }
        semi[i] = mano[3*i+1];
    }
}

int punteggio_mano(char mano[]) {
    int valori_carte[SIZE], occorrenze_valore[13];
    char semi[SIZE];
    int i, l, coppie, tris, poker, colore, scala;

    for (i = 0; i < 13; i++) {
        occorrenze_valore[i] = 0;
    }

    str2vet(mano, valori_carte, semi);
    for (i = 0; i < SIZE; i++) {
        occorrenze_valore[valori_carte[i]-1]++;
    }

    coppie = tris = poker = 0;
    for (i = 0; i < 13; i++) {
        if (occorrenze_valore[i] == 2) {
            coppie++;
        } else if (occorrenze_valore[i] == 3) {
            tris++;
        } else if (occorrenze_valore[i] == 4) {
            poker++;
        }
    }

    i = 1;
    while (i < SIZE && semi[0] == semi[i]) {
        i++;
    }
    colore = (i >= SIZE);

    l = 0;
    i = (occorrenze_valore[0] == 1 && occorrenze_valore[1] != 1) ? 1 : 0;
    while (occorrenze_valore[i] == 0) {
        i++;
    }
    while (l < SIZE && (i+l) <= 13 && occorrenze_valore[(i+l) % 13] == 1) {
        l++;
    }
    scala = (l == SIZE);

    if (scala && colore) {
        return SCALA_COLORE;
    } else if (poker) {
        return POKER;
    } else if (tris && coppie) {
        return FULL;
    } else if (colore) {
        return COLORE;
    } else if (scala) {
        return SCALA;
    } else if (tris) {
        return TRIS;
    } else if (coppie == 2) {
        return DOPPIA_COPPIA;
    } else if (coppie) {
        return COPPIA;
    } else {
        return CARTA_ALTA;
    }
}

int vincitore(char m1[], char m2[]) {
    int punteggio1, punteggio2;

    punteggio1 = punteggio_mano(m1);
    punteggio2 = punteggio_mano(m2);

    if (punteggio1 == punteggio2) {
        return 0;
    }
    return punteggio1 > punteggio2 ? 1 : 2;
}
