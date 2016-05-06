ESERCITAZIONE 16

Lo scopo dell'esercitazione di oggi è familiarizzare con l'utilizzo dei file in C. Nell'implementazione degli esercizi dovrete usare il tipo struct frequenze che serve per contare il numero di occorrenze di una parola in un testo. Il tipo è definito come segue nel file es16.h:

struct frequenze {
    char *parola;
    int occorrenze;
};
Nello svolgimento degli esercizi ricordate di chiudere il file quando avete terminato di leggere o scrivere: se non lo fate potrebbero verificarsi degli errori in fase di correzione!

 

Esercizio 1

Scrivere la funzione leggi_parole che, dato il nome di un file, restituisce un vettore di elementi di tipo struct frequenze contenente tutte le parole presenti nel file e il numero di occorrenze di ciascuna di esse. La dimensione del vettore (allocato in memoria dinamica) dev'essere salvata nella variabile puntata da dim. L'ordine degli elementi del vettore rispecchiano l'ordine in cui le parole appaiono la prima volta all'interno del file. Se l'apertura del file fallisce, la funzione deve restituire NULL e impostare la dimensione del vettore a 0.

Il file passato, se esiste, contiene esclusivamente lettere minuscole, spazi e caratteri a capo '\n'. Una parola, che è costituita da una o più lettere, è separata dalle altre da uno o più spazi e/o a capo. La firma della funzione è la seguente:

struct frequenze* leggi_parole(char *path, int *dim)
Esempio: dato il file

il cane e il gatto dormono sotto un albero

il cane e il gatto sono animali domestici
il vettore restituito dalla funzione deve essere {(il, 4), (cane, 2), (e, 2), (gatto, 2), (dormono, 1), (sotto, 1), (un, 1), (albero, 1), (sono, 1), (animali, 1), (domestici, 1)} e la dimensione è 11.

 

Esercizio 2

Scrivere la funzione scrivi_frequenze che, dato un vettore di elementi di tipo struct frequenze, la sua dimensione e il nome di un file, scrive le parole nel file, una per riga, in ordine decrescente rispetto al numero di occorrenze. Se più parole hanno lo stesso numero di occorrenze, scriverle in ordine alfabetico (potete usare la funzione strcmp per confrontare due stringhe). Se l'apertura in scrittura del file specificato fallisce il valore di ritorno della funzione deve essere 0, altrimenti restituisce 1. La firma della funzione è la seguente:

int scrivi_parole(char *path, struct frequenze *v, int dim);
Esempio: dato il vettore {(il, 4), (cane, 2), (e, 2), (gatto, 2), (dormono, 1), (sotto, 1), (un, 1), (albero, 1), (sono, 1), (animali, 1), (domestici, 1)}, il file di output deve essere il seguente:

il
cane
e
gatto
albero
animali
domestici
dormono
sono
sotto
un