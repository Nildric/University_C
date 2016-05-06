#ifndef ES16_H
#define ES16_H

struct frequenze {
    char *parola;
    int occorrenze;
};

struct frequenze* leggi_parole(char *path, int *dim);
int scrivi_parole(char *path, struct frequenze *v, int dim);

#endif
