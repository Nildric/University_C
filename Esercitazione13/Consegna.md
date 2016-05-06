ESERCITAZIONE 13

Lo scopo dell'esercitazione di oggi è di familiarizzare con la ricorsione in C. Tutti gli esercizi devono essere svolti esclusivamente usando la ricorsione. L'utilizzo di costrutti iterativi (for, while, do-while) non è consentito, pena una valutazione errata del relativo esercizio. È consentito (e talvolta necessario) la definizione ed implementazione di funzioni ausiliarie.

Esercizio 1

Scrivere una funzione ricorsiva ricerca che, dati un vettore di interi v, distinti tra loro e ordinati in ordine decrescente, un intero val e due indici inf e sup, utilizza l'algoritmo di ricerca dicotomica per verificare se esiste un indice k, dove inf = k = sup, tale per cui v[k]=val. La funzione deve restituire l'indice k, se esiste, oppure -1.

L'algoritmo funziona come segue:

se sup < inf, l'indice cercato non esiste;
altrimenti, sia m = (inf + sup) / 2:
se v[m] = val, restituisci m;
altrimenti cerca ricorsivamente in una delle due metà del vettore (da inf a m-1 oppure da m+1 a sup), in base al fatto che val sia maggiore o minore di v[m].
La firma della funzione è la seguente:

int ricerca(int v[], int val, int inf, int sup)
Esempi:

ricerca({10, 8, 6, 4, 1, -3}, 6, 0, 5) restituisce 2;
ricerca({10, 8, 6, 4, 1, -3}, 2, 0, 5) restituisce -1;
ricerca({10, 8, 6, 4, 1, -3}, 1, 0, 0) restituisce -1;
ricerca({10, 8, 6, 4, 1, -3}, 1, 4, 4) restituisce 4.
Esercizio 2

Data una stringa s contenente lettere minuscole e spazi, scrivere una funzione che restituisce 1 se la stringa è palindroma, 0 altrimenti. Eventuali spazi presenti all'interno della stringa devono essere ignorati. Potete utilizzare la funzione strlen definita in string.h per calcolare la lunghezza di s. La firma è la seguente:

int palindroma(char *s)
Esempi:

palindroma("anna") restituisce 1;
palindroma("i topi non avevano nipoti") restituisce 1;
palindroma("") restituisce 1;
palindroma("cane") restituisce 0.
Esercizio 3

Dati un vettore che contiene i pesi di n oggetti e la capienza p = 0 di uno zaino, scrivere una funzione che restituisce 1 se esiste un sottoinsieme di oggetti la cui somma dei pesi è uguale a p, 0 altrimenti. La firma della funzione è la seguente:

int zaino(int pesi[], int n, int p)
Esempi:

zaino({3, 6, 2, 8, 11}, 5, 14) restituisce 1;
zaino({3, 6, 2, 8, 11}, 5, 30) restituisce 1;
zaino({3, 6, 2, 8, 11}, 5, 7) restituisce 0;
zaino({3, 6, 2, 8, 11}, 5, 6) restituisce 1;
zaino({3, 6, 2, 8, 11}, 5, 0) restituisce 1.