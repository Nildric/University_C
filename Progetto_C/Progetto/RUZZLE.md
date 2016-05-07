# Modalità Offline
* Leggere da file uno schema di ruzzle e un vocabolario.
* Ricercare le parole del vocabolario all'interno dello schema e calcolare il punteggio massimo ottenibile per ciascuna parola.
* Salvare su file il punteggio massimo calcolato per ciascuna parola e le mose effettuate per realizzare il punteggio.

# Modalità Interattiva
* Richiedere l'inserimento da testiera dei dati relativi allo schema di Ruzzle:
    * Dimensione
    * Lettere presenti
    * Bonus associati alle caselle
* Fino a quando l'utente non chiede di uscire dal programma, dovrà leggere in input una parola e stampare a schrmo tutte le possibili sequenze di mosse che possono essere fatte per comporre la parola con il relativo punteggio, ordinate per punteggio in ordine decrescente.

```c
// Avvio del programma in modalità interattiva
./ruzzle

// Avvio del programma in modalità offline
./ruzzle <dizionario> <schema> <output>
int main(int argc, char *argv[]);
```

# Ruzzle
In Ruzzle è presente una matrice di dimensione _n x n_ contenente lettere dell'alfabeto inglese, possibilmente con ripetizione. Utilizzando le lettere presenti all'interno dello schema, il giocatore deve trovare il maggior numero possibile di parole rispettando i seguenti vincoli:
* Ciascuna lettera è adiacente alla successiva in orizzontale, verticale o diagonale.
* Ciascuna posizione dello schema può essere attraversata al più una volta per comporre la parola.

A ciascuna parola è associato un punteggio che dipende dai punti assegnati alle lettere e dai bonus presenti nelle caselle utilizzate. I punti base attribuiti a ciascuna lettera sono riportati nella tabella sottostante:

|      LETTERE     | PUNTEGGIO |
|:----------------:|:---------:|
|    J, Q, W, X    |     10    |
|      G, H, Z     |     8     |
| B, D, F, K, P, V |     5     |
|         Y        |     4     |
|    L, M, N, U    |     3     |
|    C, R, S, T    |     2     |
|    A, E, I, O    |     1     |

Ad alcune caselle dello schema può essere attribuito uno tra i seguenti bonus:
* _Double Letter_ (DL): Il punteggio base attribuito alla lettera presente nella casella è duplicato.
* _Triple Letter_ (TL): Il punteggio base attribuito alla lettera presente nella casella è triplicato.
* _Double Word_ (DW): Il punteggio attribuito alla parola è duplicato.
* _Triple Word_ (TW) : Il punteggio attribuito alla parola è triplicato.

Nel calcolo del punteggio devono essere essere applicati prima i bonus relativi alle lettere, poi quelli relativi alle parole. I bonus sono cumulabili.

# File di Input
Il programma dovrà leggere due file, lo schema di Ruzzle e il dizionario. In tutti i file che saranno utilizzati possono essere presenti alcune righe vuote che vanno ignorate. Inoltre viene utilizzata la convenzione Unix dove il ritorno a capo è codificato dal carattere \n.

## Schema di Ruzzle
Il file inizia con una riga contenente un numero intero positivo n che rappresenta il numero di righe e colonne dello schema. Seguono n righe di n caratteri ciascuna contenenti le lettere (in maiuscolo) che compongono lo schema. Infine sono presenti n righe di n caratteri ciascuna che indicano i bonus presenti nelle caselle:

| LETTERE | BONUS |
|:-------:|:-----:|
|    d    |   DL  |
|    t    |   TL  |
|    D    |   DW  |
|    T    |   TW  |
|    .    |   /   |

Un possibile file che rappresenta uno schema è il seguente:

```
4

OZAE
REST
RUAT
TIIP

..t.
..tT
..Dd
D...
```

## Dizionario
Il file contiene, in ciascuna riga, una parola composta esclusivamente da lettere, maiuscole o minuscole. Ai fini della ricerca di una parola, il fatto che una lettera sia maiuscola o minuscola non è rilevante. Potete assumere che non siano presenti duplicati all’interno del file.

Un possibile file che rappresenta un dizionario è il seguente:

```
Pasta
esatta
raTTi
zeRo
```

# File di Output
Quando avviato in modalità offline, il programma dovrà produrre in output un file dove, per ogni parola del dizionario trovata all’interno dello schema, è presente una riga in cui vengono riportati la parola, il punteggio e la sequenza di mosse nel formato (R, C)->(R, C)->...->(R, C), dove R e C sono gli indici di riga e colonna delle caselle attraversate. Se per una certa parola esistono più sequenze di mosse che permettono di ottenere il punteggio massimo, si scriva nel file solo una di esse. Le parole devono occorrere nel file di output nello stesso ordine in cui appaiono nel dizionario.

Un possibile file che rappresenta un output è il seguente:

```
Pasta 102 (3 ,3) ->(2 ,2) ->(1 ,2) ->(1 ,3) ->(0 ,2)
esatta 102 (0, 3) ->(1 , 2) ->(0 ,2) ->(1 ,3) ->(2 ,3) ->(2 ,2)
zeRo 12 (0 ,1) ->(1 ,1) ->(1 ,0) ->(0 ,0)
```

# Funzionalità Extra
Siete liberi di implementare altre funzionalità, ad esempio la gestione degli errori nei file di input o l’implementazione di un’interfaccia grafica particolare per la modalità interattiva usando librerie come ncurses. Non modificate le regole di base del gioco e per il calcolo dei punteggi.
