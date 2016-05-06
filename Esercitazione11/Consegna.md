ESERCITAZIONE 11

Oggi si gioca a Poker! La rappresentazione delle carte, rappresentata nelle tabelle seguenti, è lievemente modificata rispetto a quella utilizzata nell'esercitazione 9 per semplificare lo svolgimento del primo esercizio.

Carta	Valore	Codifica per
la stampa
Asso	1	A
N (2=N=9)	N	N
Dieci	10	T
Fante	11	J
Donna	12	Q
Re	13	K 
Seme	Codifica per
la stampa
Cuori	H
Quadri	D
Fiori	C
Picche	S
Ogni funzione riceve in input (almeno) una stringa di caratteri che rappresenta la mano di un giocatore. Le stringhe sono del tipo "VS VS VS VS VS", dove V è il tipo di carta e S il seme in accordo alla codifica riportata nelle tabelle. Assumete che le stringhe date in input siano valide, ovvero:

non sono presenti caratteri invalidi;
tra la codifica di una carta e la successiva è presente esattamente uno spazio;
come al solito, sono terminate dal carattere nullo.
Tutte le costanti riportate nel testo degli esercizi sono dichiarate nel file es11.h.

Esercizio 1

Data una stringa di caratteri che rappresenta la mano di un giocatore, scrivere la funzione str2vet che inserisce in due vettori passati come parametri il valore (numero) e il seme (carattere) delle carte. L'ordine di inserimento nei vettori è rilevante, ovvero nella posizione 0 devono essere presenti valore e seme della prima carta e così via. La firma dev'essere la seguente (dove SIZE è una costante di valore 5):

void str2vet(char mano[], int valori_carte[SIZE], char semi[SIZE])
Esempio. Data in input la stringa "AH 8C TH JD 3S", i vettori dei valori e dei semi delle carte dovranno essere rispettivamente {1, 8, 10, 11, 3} e {'H', 'C', 'H', 'D', 'S'}.

Esercizio 2

Data una stringa che rappresenta la mano di un giocatore, scrivere la funzione punteggio_mano che restituisce il punteggio della mano (usando le costanti CARTA_ALTA, COPPIA, DOPPIA_COPPIA, TRIS, SCALA, COLORE, FULL, POKER, SCALA_COLORE). Potete trovare le regole per l'assegnamento dei punteggi su Wikipedia. La firma della funzione è la seguente:

int punteggio_mano(char mano[])
Esempi:

punteggio_mano("AH 8C AC JD 3S") restituisce COPPIA;
punteggio_mano("AS 8S 8D 8H 3H") restituisce TRIS;
punteggio_mano("TS JS QS KS AS") restituisce SCALA_COLORE.
Esercizio 3

Date due stringhe che rappresentano le mani di due giocatori, scrivere la funzione vincitore che restituisce:

1 se vince il primo giocatore;
2 se vince il secondo giocatore;
0 in caso di pareggio.
Assumere per semplicità che due giocatori con mani aventi lo stesso punteggio pareggiano (ovvero, se due giocatori hanno entrambi doppia coppia pareggiano indipendentemente dalle carte che hanno in mano). La firma della funzione è la seguente:

int vincitore(char m1[], char m2[])
Esempi:

vincitore("AH 8C AC JD 3S", "AS 8S QD 2H 3H") restituisce 1;
vincitore("AH 8C AC JD 3S", "AS 8S 8D 2H 3H") restituisce 0;
vincitore("AH 8C AC JD 3S", "AS 8S 8D 8H 3H") restituisce 2.