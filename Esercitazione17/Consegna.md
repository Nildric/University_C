ESERCITAZIONE 17

In questa esercitazione (l'ultima esercitazione settimanale dell'anno) dovete implementare delle funzioni che operano su liste di stringhe. Il tipo lista, analogo a quanto visto a lezione per le liste di interi, è definito nel file es17.h come segue:

struct nodoS {
    char *str;
    struct nodoS *next;
};
typedef struct nodoS* ListaS;
Se ne avete bisogno, potete usare le funzioni definite in string.h.

 

Esercizio 1

Scrivere una funzione ordinata che, data una lista di stringhe, restituisce 1 se la lista di stringhe è ordinata secondo l'ordine alfabetico in modo crescente, 0 altrimenti. La firma della funzione è la seguente:

int ordinata(ListaS l)
Esempi:

ordinata([]) restituisce 1;
ordinata(["cane", "gatto", "zebra"]) restituisce 1;
ordinata(["cane", "gatto", "elefante", "zebra"]) restituisce 0;
ordinata(["cane", "cane"]) restituisce 1.
 

Esercizio 2

Scrivere una funzione inserisci che modifica la lista ordinata ricevuta in input inserendo un nuovo nodo contenente la stringa passata come parametro. La lista modificata deve essere a sua volta ordinata. La firma della funzione è la seguente:

void inserisci(ListaS *l, char *s)
Esempi:

data l = [], dopo la chiamata inserisci(&l, "cane"), si ha l = ["cane"];
data l = ["cane"], dopo la chiamata inserisci(&l, "gatto"), si ha l = ["cane", "gatto"];
data l = ["cane", "gatto"], dopo la chiamata inserisci(&l, "elefante"), si ha l = ["cane", "elefante", "gatto"];
 

Esercizio 3

Scrivere una funzione rimuovi_duplicati che, data una lista ordinata di stringhe, rimuove i duplicati presenti in essa. La lista modificata deve preservare l'ordinamento. La firma della funzione è la seguente:

void rimuovi_duplicati(ListaS l)
Esempi:

data l = [], dopo la chiamata rimuovi_duplicati(l) si ha l = [];
data l = ["cane", "elefante", "gatto"], dopo la chiamata rimuovi_duplicati(l) si ha l = ["cane", "elefante", "gatto"];
data l = ["cane", "cane", "elefante", "gatto", "gatto", "gatto"], dopo la chiamata rimuovi_duplicati(l) si ha l = ["cane", "elefante", "gatto"].