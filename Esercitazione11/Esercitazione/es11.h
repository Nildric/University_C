#ifndef ES11_ES11_H
#define ES11_ES11_H

#define SIZE 5
#define CARTA_ALTA 0
#define COPPIA 1
#define DOPPIA_COPPIA 2
#define TRIS 3
#define SCALA 4
#define COLORE 5
#define FULL 6
#define POKER 7
#define SCALA_COLORE 8

void str2vet(char mano[], int valori_carte[SIZE], char semi[SIZE]);
int punteggio_mano(char mano[]);
int vincitore(char m1[], char m2[]);

#endif
