ESERCITAZIONE 12

Nell'esercitazione di questa settimana vedremo come utilizzare i puntatori per permettere ad un sottoprogramma di restituire più di un output alla funzione chiamante utilizzando i cosiddetti parametri di output. I parametri di output non sono inizializzati dalla funzione chiamante, quindi non potete fare alcuna assunzione sul loro valore iniziale.

Esercizio 1

Scrivere una funzione conta_segno che, dato il vettore di interi v contenente n elementi, calcola il numero di elementi positivi, negativi e zero presenti nel vettore: questi valori dovranno essere memorizzati, rispettivamente, nei parametri di output npos, nneg e nzero.

La firma della funzione deve essere la seguente:

void conta_segno(int v[], int n, int *npos, int *nneg, int *nzero)
Esercizio 2

Scrivere una funzione differenza_frazioni che riceve in input due frazioni e calcoli la differenza tra le due, ridotta ai minimi termini. Una frazione si dice ridotta ai minimi termini se il massimo comun divisore (MCD) tra il numeratore e il denominatore è uguale a 1.

La firma della funzione è la seguente:

void differenza_frazioni(int n1, int d1, int n2, int d2, int *ndiff, int *ddiff)
I parametri n1 e d1 sono il numeratore ed il denominatore della prima frazione, mentre n2 e d2 sono numeratore e denominatore della seconda. Nei parametri ndiff e ddiff devono essere inseriti il numeratore e il denominatore della frazione (ridotta ai minimi termini) ottenuta come differenza tra la prima e la seconda frazione.

I denominatori d1 e d2 sono interi positivi, mentre non ci sono restrizioni sui numeratori n1 e n2. Analogamente, il denominatore del risultato dovrà essere un numero positivo.

Esempi:

dopo la chiamata differenza_frazioni(5, 4, 3, 2, &n, &d) si ha n = -1 e d = 4;
dopo la chiamata differenza_frazioni(7, 12, 1, 4, &n, &d) si ha n = 1 e d = 3;
dopo la chiamata differenza_frazioni(5, 3, 10, 6, &n, &d) si ha n = 0 e d = 1.
Osservazione: se il numeratore della differenza è uguale a 0, allora d deve essere 1. Infatti MCD(0, d) = d, quindi l'unico modo per rispettare la definizione di frazione ridotta ai minimi termini è di porre d = 1.

Esercizio 3

Data una stringa s che rappresenta un numero decimale non negativo, scrivere una funzione str2dec che calcola i numeri interi non negativi i, d, e tali per cui



dove n è il numero decimale rappresentato dalla stringa s e che rispettano i seguenti vincoli:

i è la parte intera del numero n;
se d è diverso da 0 allora non è divisibile per 10.
Se n è un numero intero, si ha d = e = 0.

La stringa passata come parametro contiene:

una o più cifre che costituiscono alla parte intera del numero;
eventualmente il carattere . seguito da una o più cifre che costituiscono la parte decimale del numero.
La firma della funzione è la seguente:

void str2dec(char s[], int *i, int *d, int *e)
Esempi:

Dopo la chiamata str2dec("13.465", &i, &d, &e) si ha i = 13, d = 465, e = 3;
Dopo la chiamata str2dec("145", &i, &d, &e) si ha i = 145, d = e = 0;
Dopo la chiamata str2dec("0.123456", &i, &d, &e) si ha i = 0, d = 123456, e = 6.