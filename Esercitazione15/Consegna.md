ESERCITAZIONE 15

Lo scopo dell'esercitazione di questa settimana è di familiarizzare con l'allocazione dinamica della memoria. Dovrete implementare alcune operazioni sulla struttura dati insieme definita nel file es15.h come segue:

struct insieme {
    int *elementi;
    int dimensione;
}
Il campo elementi è un puntatore al primo elemento di un vettore allocato in memoria dinamica contenente gli elementi dell'insieme ed il campo dimensione contiene il numero di elementi. Negli insiemi che rappresentiamo il vettore deve avere la dimensione minima necessaria per contenere gli elementi e, come nella controparte matematica, tutti gli elementi dell'insieme sono distinti e l'ordine non è rilevante. Per indicare l'insieme vuoto il puntatore è NULL e la dimensione è 0. Per semplicità, potete assumere che l'allocazione di memoria usando malloc o simili vada sempre a buon fine. Se volete, potete usare la funzione realloc (digitare man realloc su terminale per maggiori informazioni).

NB. Consegne che non compilano secondo lo standard gnu89 saranno considerate nulle. Consegne che non soddisfano le richieste descritte nella pagina principale (ad es. consegna di un archivio zip anziché il solo file es15.c) saranno penalizzate.

 

Esercizio 1

Scrivere una funzione aggiungi che modifica l'insieme passato come parametro pin inserendo al suo interno gli n elementi presenti nel vettore v. L'insieme modificato deve soddisfare le proprietà descritte sopra. Si noti inoltre che il vettore v può contenere dei duplicati. La firma della funzione è la seguente:

void aggiungi(struct insieme *pin, int v[], int n)
Ecco alcuni esempi dove con le parentesi graffe sono indicati gli insiemi e con le quadre i vettori:

dopo la chiamata aggiungi({1, 2, 3, 4, 5}, [3, 7, 1], 3), l'insieme diventa {1, 2, 3, 4, 5, 7};
dopo la chiamata aggiungi({1, 2, 3, 4, 5}, [-1, 7, -1, 1], 4), l'insieme diventa {1, 2, 3, 4, 5, -1, 7}.
 

Esercizio 2

Scrivere la funzione unione che riceve in input due insiemi e restituisce un nuovo insieme, allocato in memoria dinamica, che rappresenta l'unione dei due. La firma della funzione è la seguente:

struct insieme* unione(struct insieme in1, struct insieme in2);
Esempi:

la chiamata unione({1, 3, 4}, {2, 3}) restituisce {1, 3, 4, 2};
la chiamata unione({1, 2, 3}, {1, 2, 3}) restituisce {1, 2, 3}.
 

Esercizio 3

Scrivere la funzione intersezione che riceve in input due insiemi e restituisce un nuovo insieme, allocato in memoria dinamica, che rappresenta l'intersezione dei due. La firma della funzione è la seguente:

struct insieme* intersezione(struct insieme in1, struct insieme in2);
Esempi:

la chiamata intersezione({1, 3, 4}, {2, 3}) restituisce {3};
la chiamata intersezione({1, 3, 4}, {2}) restituisce {}.