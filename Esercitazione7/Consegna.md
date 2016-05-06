ESERCITAZIONE 7

Gli esercizi dovranno essere contenuti tutti in un unico file.

Il file deve permettere la scelta di quale esercizio eseguire (tramite la prima stringa)

Esercizio 1:

Data la sucessione di Fibonacci (https://it.wikipedia.org/wiki/Successione_di_Fibonacci), si richiede di scrivere una funzione che:

preso in input da tastiera un numero n, restituisca come output il valore F( n ) della successione.

Il valore di input è int e il valore di output è double.

Stringhe:

Le stringhe da usare per ottenere gli input sono:

"Enter the index of the fibonacci sequence.\n"

 Le stringhe da usare per scrivere gli output sono:

"Index must be greater than 0.\n"

"Fibonacci(%d) = %.0f\n"


Esempio:


input = 0
output = "Index must be greater than 0."

input = 1

output = "Fibonacci(1) = 1"

input = 3

output = "Fibonacci(3) = 2"

Esercizio 2:

Data la formula  e data la risposta alla domanda fondamentale sulla vita, l'universo e tutto quanto (che è ben noto essere 42), si richiede di scrivere una funzione che:

presi in input da tastiera una tolleranza e una sequenza di numeri, si fermi solo quando il risultato della formula risulti essere 42 (a meno della tolleranza inserita).

Si usi la stringa "Got %.3f\n..." ogni volta che si ottiene un nuovo numero.

I valori di input e output sono double.

Stringhe:

Le stringhe da usare per ottenere gli input sono:

"Enter the tollerance.\n"
"Start entering numbers!\n"
"Got %.3f\n..."


 Le stringhe da usare per scrivere gli output sono:

"Yes! More or less 42\n"


Esempio:


input = 0.5; 42
output = "Yes! More or less 42"

input = 10; 39
output = "Yes! More or less 42"

input = 0.2; 41; 40; 43; 43; 41.5
output = "Yes! More or less 42"

Esercizio 3:

Data la definizione di numero primo (https://it.wikipedia.org/wiki/Numero_primo), si richiede di scrivere una funzione che:

preso in input da tastiera un numero (anche negativo), controlli se è o meno un numero primo.

I valori di input e output sono int.

Stringhe:

Le stringhe da usare per ottenere gli input sono:

"Enter the number to be checked.\n"


 Le stringhe da usare per scrivere gli output sono:

"Cannot say that %d is prime.\n"
"%d is prime.\n"
"%d is not prime.\n"

Esempio:


input = 1
output = "Cannot say that 1 is prime."

input = -1
output = "Cannot say that -1 is prime."

input = 0
output = "Cannot say that 0 is prime."

input = 3
output = "3 is prime"

input = 4
output = "4 is not prime."

Stringhe:

string.txt