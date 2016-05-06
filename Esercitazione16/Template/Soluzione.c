#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "es16.h"

int cerca_parola(struct frequenze *v, int dim, char *s) {
    int i;

    for (i = 0; i < dim; i++) {
        if (strcmp(v[i].parola, s) == 0) {
            return i;
        }
    }
    return -1;
}

void conta_parola(struct frequenze **v, int *dim, char *s) {
    int pos;

    pos = cerca_parola(*v, *dim, s);
    if (pos != -1) {
        (*v)[pos].occorrenze++;
    } else {
        (*dim)++;
        *v = realloc(*v, sizeof(struct frequenze) * *dim);
        (*v)[*dim - 1].parola = malloc(sizeof(char) * (strlen(s) + 1));
        strcpy((*v)[*dim - 1].parola, s);
        (*v)[*dim - 1].occorrenze = 1;
    }
}

struct frequenze* leggi_parole(char *path, int *dim) {
    FILE *f;
    ssize_t len;
    struct frequenze *freqs = NULL;
    char *line = NULL;
    size_t bufsize = 0;

    *dim = 0;
    f = fopen(path, "r");
    if (f == NULL) {
        return NULL;
    }

    while (!feof(f)) {
        len = getline(&line, &bufsize, f);
        if (len > 0) {
            char *word = strtok(line, " \n");
            while (word != NULL) {
                conta_parola(&freqs, dim, word);
                word = strtok(NULL, " \n");
            }
        }
    }
    fclose(f);
    return freqs;
}

int confronta(const void *v1, const void *v2) {
    struct frequenze *f1 = v1;
    struct frequenze *f2 = v2;
    return (f1->occorrenze - f2->occorrenze != 0) ?
           f1->occorrenze - f2->occorrenze :
           strcmp(f1->parola, f2->parola);
}

int scrivi_parole(char *path, struct frequenze *v, int dim) {
    FILE *f;
    int i;

    f = fopen(path, "w");
    if (f == NULL) {
        return 0;
    }

    qsort(v, dim, sizeof(struct frequenze), confronta);
    for (i = 0; i < dim; i++) {
        if (i > 0) {
            fprintf(f, "\n");
        }
        fprintf(f, "%s", v[i].parola);
    }
    fclose(f);

    return 1;
}
