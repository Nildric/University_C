#ifndef ES17_H
#define ES17_H

struct nodoS {
    char *str;
    struct nodoS *next;
};
typedef struct nodoS* ListaS;

int ordinata(ListaS l);
void inserisci(ListaS *l, char *s);
void rimuovi_duplicati(ListaS l);

#endif
