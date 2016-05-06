#include <stdlib.h>
#include <string.h>
#include "es17.h"

int ordinata(ListaS l) {
    if (l == NULL || l->next == NULL) {
        return 1;
    }
    while (l->next != NULL && strcmp(l->str, l->next->str) <= 0) {
        l = l->next;
    }
    return l->next == NULL;
}

int ordinata_r(ListaS l) {
    return (l == NULL || l->next == NULL) ? 1 : strcmp(l->str, l->next->str) <= 0 && ordinata_r(l->next);
}

void inserisci(ListaS *l, char *s) {
    ListaS iter, prec, nodo;

    nodo = malloc(sizeof(ListaS));
    nodo->str = malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(nodo->str, s);

    iter = *l;
    prec = NULL;
    while (iter != NULL && strcmp(s, iter->str) > 0) {
        prec = iter;
        iter = iter->next;
    }
    nodo->next = iter;
    if (prec == NULL) {
        *l = nodo;
    } else {
        prec->next = nodo;
    }
}

void inserisci_r(ListaS *l, char *s) {
    if (*l == NULL || strcmp(s, (*l)->str) <= 0) {
        ListaS nodo = malloc(sizeof(ListaS));
        nodo->str = malloc(sizeof(char) * (strlen(s) + 1));
        strcpy(nodo->str, s);
        nodo->next = *l;
        *l = nodo;
    } else {
        inserisci_r(&(*l)->next, s);
    }
}

void rimuovi_duplicati(ListaS l) {
    if (l != NULL) {
        while (l->next != NULL) {
            if (strcmp(l->str, l->next->str) == 0) {
                ListaS n = l->next;
                l->next = l->next->next;
                free(n->str);
                free(n);
            } else {
                l = l->next;
            }
        }
    }
}

void rimuovi_duplicati_r(ListaS l) {
    if (l != NULL && l->next != NULL) {
        rimuovi_duplicati_r(l->next);
        if (strcmp(l->str, l->next->str) == 0) {
            ListaS n = l->next;
            l->next = l->next->next;
            free(n->str);
            free(n);
        }
    }
}
