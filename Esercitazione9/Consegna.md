ESERCITAZIONE 9 - SECONDO SEMESTRE

Lo scopo dell'esercitazione è realizzare un programma che consenta di giocare ad una versione semplificata di Blackjack.

Nel gioco si utilizzano due mazzi di carte francesi (senza i jolly), per un totale di 104 carte. Ciascun mazzo è formato da quattro semi e vi sono 13 carte per seme: le carte da 1 (asso) a 10, il fante, la donna e il re. Il punteggio di ogni carta e la codifica per la stampa delle carte a video è indicato nelle seguenti tabelle:

Carta	Punteggio	Codifica per
la stampa
Asso	1 o 11	1
N (2=N=10)	N	N
Fante	10	J
Donna	10	Q
Re	10	K 
Seme	Codifica per
la stampa
Cuori	H
Quadri	D
Fiori	C
Picche	S
Lo scopo del gioco è di pescare carte dal mazzo in modo da avvicinarsi il più possibile al punteggio 21, ma senza superarlo. La partita si svolge come segue:

si inizia con una carta scoperta, il cui valore rappresenta il punteggio del giocatore;
il giocatore può decidere di estrarre una nuova carta o fermarsi;
nel caso abbia deciso di pescare, il valore della nuova carta viene sommato al punteggio precedente per determinare il nuovo punteggio;
ritorna al punto 2.
Nel calcolo del punteggio, all'asso viene assegnato valore 1 o 11 in base alla situazione più favorevole per il giocatore. La partita termina se il giocatore:

con punteggio < 21, decide di fermarsi;
raggiunge il punteggio 21;
supera il punteggio 21 (sconfitta).
Il programma deve permettere di giocare una partita come descritto sopra, ovvero:

propone al giocatore una carta scelta causalmente dal mazzo con probabilità uniforme e la stampa sulla console insieme al punteggio attuale;
chiede al giocatore se ne vuole pescare un'altra. Le risposte valide sono s (sì) e n (no): in caso di input non valido, deve essere ripetuta la domanda;
in caso di risposta negativa, termina il programma;
in caso di risposta positiva, stampa sulla console la carta pescata, ricalcola e stampa il punteggio e:
se il punteggio è uguale a 21, stampa il messaggio "Congratulazioni, hai vinto!" e termina;
se è superiore a 21, stampa il messaggio "Hai perso..." e termina;
se è minore di 21, ritorna al punto 2.
Quando scegliete in maniera casuale la carta da estrarre, dovete verificare che non sia uscita più di due volte nel corso della stessa partita.

Semplificazione: Gli assi estratti valgono tutti 1 o tutti 11.

Seguono alcuni esempi di esecuzione del programma, dove in corsivo sono indicati gli input dell'utente. Per facilitare la correzione, fate in modo che l'output del vostro programma sia strutturato allo stesso modo.

*-* Blackjack *-*

Hai pescato: 9H
Punteggio: 9
Vuoi continuare? a
Vuoi continuare? s

Hai pescato: 1D
Punteggio: 20
Vuoi continuare? s

Hai pescato: 8C
Punteggio: 18
Vuoi continuare? s

Hai pescato: 5C
Punteggio: 23
Hai perso...
*-* Blackjack *-*

Hai pescato: 1S
Punteggio: 11
Vuoi continuare? s

Hai pescato: 9D
Punteggio: 20
Vuoi continuare? n
Scaricate il template dell'esercitazione (file es9.c), scrivete il codice dove indicato e fare l'upload esclusivamente di quel file (non sono ammessi archivi zip, rar, etc). Come per le esercitazioni di C del primo semestre, usate le flag -std=gnu89 -pedantic -Wall quando compilate.