ESERCITAZIONE 10

A partire dall'esercitazione di oggi e fino alla fine del corso verrà adottata una nuova modalità per lo svolgimento delle esercitazioni. Consultate la sezione Istruzioni per la consegna nella pagina principale del corso!

Nell'esercitazione di oggi inizierete a familiarizzare con la suddivisione di un programma C in più funzioni. In particolare, in ogni esercizio dovrete utilizzare la funzione realizzata nell'esercizio precedente per risolvere il problema. Lo svantaggio è che un errore nella prima funzione (quasi sicuramente) implica errori nei risultati degli output delle funzioni successive, quindi fate attenzione!

Esercizio 1

Dato un numero intero n > 1, realizzare la funzione is_prime che restituisce 0 se il numero passato come parametro non è primo, un numero diverso da 0 altrimenti.

La firma della funzione è la seguente:

int is_prime(int n);
Esercizio 2

Dato un numero intero n > 1, realizzare la funzione next_prime che restituisce il più piccolo numero primo strettamente maggiore di n.

La firma della funzione è la seguente:

int next_prime(int n);
Esercizio 3

Scrivere una funzione print_factors che accetta come parametro un numero intero n > 1 e ne stampa la fattorizzazione in numeri primi secondo il formato

n=p1^x1*p2^x2*p3^x3*...*pk^xk

dove pi è un fattore primo, xi è l'esponente del fattore pi e pi < pi+1 per 0 < i < k (ovvero, i numeri primi devono apparire in ordine crescente). Se xi = 1 allora l'esponente non deve essere stampato.

La funzione non deve stampare nessun'altra stringa oltre a quella richiesta. Inoltre non devono essere presenti spazi o altri caratteri non necessari, pena una valutazione errata dell'esercizio.

La firma della funzione è la seguente:

void print_factors(int n);
Seguono alcuni output di esempio per gli input 13, 45 e 50:

13=13
45=3^2*5
50=2*5^2