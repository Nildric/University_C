ESERCITAZIONE 8 - FINE PRIMO SEMESTRE

Gli esercizi dovranno essere contenuti tutti in un unico file.

Il file deve permettere la scelta di quale esercizio eseguire (tramite la prima stringa)

Per quest'ultima esercitazione il primo esercizio vale 1 punto, il secondo invece 2 punti.

Esercizio 1:

Dato che si stanno avvicinando le vacanze invernali, anche noi volevamo addobbare un albero con luci e decorazioni, per questo vi chiediamo aiuto per scrivere una funzione che:

presa in input da tastiera la larghezza dell'albero, restituisca come output il disegno dell'albero decorato segondo le seguenti regole:

la larghezza deve essere sempre un numero dispari positivo (dovere saper gestire comunque tutti i numeri naturali, sia positivi che negativi. Nel caso non sia un numero valido dovete richiederlo.
La punta dell'albero è composta solo dal carattere *
Le successive righe dell'albero sono composte da un'alternanza di caratteri * e 0
Gli estremi di ogni riga sono i caratteri *
Ogni riga (tronco compreso) deve essere riempita da abbastanza spazi a destra e a sinistra in modo tale che sia lunga come la larghezza dell'albero presa in input
Ogni riga dell'albero ha dimensione crescente però solo con numeri dispari (1,3,5,7,...)
Il tronco dell'albero è composto da una serie di caratteri |
La larghezza del tronco è il roundf di (larghezza dell'albero diviso 4), nel caso sia un numero pari, prendere il numero dispari sucessivo
L'altezza del tronco è il ceil di (larghezza dell'albero diviso 10)
Ricordatevi che ogni riga dell'albero e del tronco va centrata sulla punta dell'albero che è esattamente in mezzo alla prima riga
Il valore di input è int.

Stringhe:

Le stringhe da usare per ottenere gli input sono:

"Insert the width of your tree (must be a odd number)\n"

 Le stringhe da usare per scrivere gli output sono:

"*"
"0"

"|"

Esempio:


input =

"Insert the width of your tree (must be a positive odd number)"

-> 0

"Insert the width of your tree (must be a positive odd number)"

-> 1
output =

"*"
"|"
input =

"Insert the width of your tree (must be a positive odd number)"

-> -3

"Insert the width of your tree (must be a positive odd number)"

-> 5
output =

"  *  "
" *0* "
"*0*0*"
"  |  "
input =

"Insert the width of your tree (must be a positive odd number)"

-> 7

output =

"   *   "
"  *0*  "
" *0*0* "
"*0*0*0*"
"  |||  "
input =

"Insert the width of your tree (must be a positive odd number)"

-> 23

output =

"           *           "
"          *0*          "
"         *0*0*         "
"        *0*0*0*        "
"       *0*0*0*0*       "
"      *0*0*0*0*0*      "
"     *0*0*0*0*0*0*     "
"    *0*0*0*0*0*0*0*    "
"   *0*0*0*0*0*0*0*0*   "
"  *0*0*0*0*0*0*0*0*0*  "
" *0*0*0*0*0*0*0*0*0*0* "
"*0*0*0*0*0*0*0*0*0*0*0*"
"        |||||||        "
"        |||||||        "
"        |||||||        "
Esercizio 2:

Dato il gioco del tris ( https://it.wikipedia.org/wiki/Tris_%28gioco%29 ), per concludere questo semestre vi chiediamo di scrivere una funzione che:

prese in input da tastiera la modalità di gioco (2 giocari o contro AI) e le mosse che il/i giocatori/e fanno, si fermi quando uno dei due giocatori vince o la partita è patta e restituisca come output dopo ogni mossa la griglia aggiornata e alla fine l'esito della partita.

Per inserire l'AI gestita dal computer dovete:

includere: #include <time.h>
usare srand(time(NULL) ad inizio del main per non avere sempre la stessa successione di mosse casuali
usare per la scelta delle mosse: (double)rand() / (double) RAND_MAX * 3;
Le coordinate x, y sono:

 0,0  
 0,1  
 0,2  
 1,0	 1,1	 1,2
 2,0	 2,1	 2,2
I giocatori sono:

Player1 (sempre umano) che usa x

Player2 che usa o

Dovete saper gestire le mosse non valide (comprese quelle dell'AI a cui però non dovete comunicare che ha fatto una mossa non valida).

La griglia di base è fatta nel seguente modo (%c per scrivere variabili char):

printf("\n");

" | | "
"-+-+-"
" | | "
"-+-+-"
" | | "
printf("\n");

I valori nelle caselle sono " " (spazi) nel caso non siano ancora state inserite mosse.

"x" se contengono una mossa del giocatore 1

"o" se contengono una mossa del giocatore 1

Le barre verticali sono il carattere "|"

Le barre orizzontali sono il carattere "-"

Gli incroci sono il carattere "+"

I valori di input sono int.

Stringhe:

Le stringhe da usare per ottenere gli input sono:

"Do you want to challenge the AI? (0=No, 1=Yes)\n"
"Player %d's turn...\n"
"Insert the x and y coordinates:\n"
"Bad coordinates, or location already filled\n"

 Le stringhe da usare per scrivere gli output sono:

"-+-+-\n"
"|"

" "

"x"

"o"
"Draw!\n"
"Player %d win!\n\n"

Esempio 1:

"Do you want to challenge the AI? (0=No, 1=Yes)"

-> 0

printf("\n");

" | | "
"-+-+-"
" | | "
"-+-+-"
" | | "
printf("\n");

"Player 1's turn..."

"Insert the x and y coordinates:"

-> 1 12

"Bad coordinates, or location already filled"

"Insert the x and y coordinates:"

-> 1 1

printf("\n");

" | | "
"-+-+-"
" |x| "
"-+-+-"
" | | "
printf("\n");

"Player 2's turn..."

"Insert the x and y coordinates:"

-> 1 1

"Bad coordinates, or location already filled"

"Insert the x and y coordinates:"

-> 0 1

printf("\n");

" |o| "
"-+-+-"
" |x| "
"-+-+-"
" | | "
printf("\n");

"Player 1's turn..."

"Insert the x and y coordinates:"

-> 1 2

printf("\n");

" |o| "
"-+-+-"
" |x|x"
"-+-+-"
" | | "
printf("\n");

"Player 2's turn..."

"Insert the x and y coordinates:"

-> 1 0

printf("\n");

" |o| "
"-+-+-"
"o|x|x"
"-+-+-"
" | | "
printf("\n");

"Player 1's turn..."

"Insert the x and y coordinates:"

-> 2 2

printf("\n");

" |o| "
"-+-+-"
"o|x|x"
"-+-+-"
" | |x"
printf("\n");

"Player 2's turn..."

"Insert the x and y coordinates:"

-> 0 2

printf("\n");

" |o|o"
"-+-+-"
"o|x|x"
"-+-+-"
" | |x"
printf("\n");

"Player 1's turn..."

"Insert the x and y coordinates:"

-> 0 0

printf("\n");

"x|o|o"
"-+-+-"
"o|x|x"
"-+-+-"
" | |x"
printf("\n");

"Player 1 win!"

Esempio 2:

"Do you want to challenge the AI? (0=No, 1=Yes)"

-> 0

printf("\n");

" | | "
"-+-+-"
" | | "
"-+-+-"
" | | "
printf("\n");

"Player 1's turn..."

"Insert the x and y coordinates:"

-> 1 12

"Bad coordinates, or location already filled"

"Insert the x and y coordinates:"

-> 1 1

printf("\n");

" | | "
"-+-+-"
" |x| "
"-+-+-"
" | | "
printf("\n");

"Player 2's turn..."

"Insert the x and y coordinates:"

-> 1 1

"Bad coordinates, or location already filled"

"Insert the x and y coordinates:"

-> 0 1

printf("\n");

" |o| "
"-+-+-"
" |x| "
"-+-+-"
" | | "
printf("\n");

"Player 1's turn..."

"Insert the x and y coordinates:"

-> 1 2

printf("\n");

" |o| "
"-+-+-"
" |x|x"
"-+-+-"
" | | "
printf("\n");

"Player 2's turn..."

"Insert the x and y coordinates:"

-> 1 0

printf("\n");

" |o| "
"-+-+-"
"o|x|x"
"-+-+-"
" | | "
printf("\n");

"Player 1's turn..."

"Insert the x and y coordinates:"

-> 0 0

printf("\n");

"x|o| "
"-+-+-"
"o|x|x"
"-+-+-"
" | | "
printf("\n");

"Player 2's turn..."

"Insert the x and y coordinates:"

-> 2 2

printf("\n");

"x|o| "
"-+-+-"
"o|x|x"
"-+-+-"
" | |o"
printf("\n");

"Player 1's turn..."

"Insert the x and y coordinates:"

-> 0 2

printf("\n");

"x|o|x"
"-+-+-"
"o|x|x"
"-+-+-"
" | |o"
printf("\n");

"Player 2's turn..."

"Insert the x and y coordinates:"

-> 2 0

printf("\n");

"x|o|x"
"-+-+-"
"o|x|x"
"-+-+-"
"o| |o"
printf("\n");

"Player 1's turn..."

"Insert the x and y coordinates:"

-> 2 1

printf("\n");

"x|o|x"
"-+-+-"
"o|x|x"
"-+-+-"
"o|x|o"
printf("\n");

"Draw!"

Stringhe:

string.txt