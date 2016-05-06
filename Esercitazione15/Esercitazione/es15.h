#ifndef ES15_H
#define ES15_H

struct insieme {
    int *elementi;
    int dimensione;
};

void aggiungi(struct insieme *pin, int v[], int n);
struct insieme* intersezione(struct insieme in1, struct insieme in2);
struct insieme* unione(struct insieme in1, struct insieme in2);

#endif
