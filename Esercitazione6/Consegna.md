ESERCITAZIONE 6

ATTENZIONE!
Le istruzioni di consegna sono cambiate! Leggete bene le istruzioni di consegna per la parte di C.

Gli esercizi dovranno essere contenuti tutti in un unico file.

Il file deve permettere la scelta di quale esercizio eseguire (tramite la prima stringa)

Esercizio 1:

Dati due punti, si richiede di scrivere una funzione che:

prese in input da tastiera le coordinate dei due punti (x1,y1) e (x2,y2), restituisca come output il valore della retta passante per quei due punti (espressa come y=mx+q).

I valori di input e output sono double.

Stringhe:

Le stringhe da usare per ottenere gli input sono:

"Enter the value of x1:\n"
"Enter the value of y1:\n"
"Enter the value of x2:\n"
"Enter the value of y2:\n"

 Le stringhe da usare per scrivere gli output sono:

"The given points are equals.\n"
"The line is vertical.\n"
"The equation of the line is constant: y = %.3f\n"
"The equation of the line goes through the origin: y = %.3f * x\n"
"The equation of the line is: y = %.3f*x + %.3f\n"

Esempio:


input = 1; 1; 2; 2
output = "The equation of the line goes through the origin: y = 1.000 * x"

input = 1; 1; 1; 2

output = "The line is vertical."

input = 1; 1; 1; 1

output = "The given points are equals."

input = 1; 1; 2; 1
output = "The equation of the line is constant: y = 1.000"

input = 0; 1; 2; 2
output = "The equation of the line is: y = 0.500*x + 1.000"

Esercizio 2:

Dati un punto e una retta, si richiede di scrivere una funzione che:

presi in input da tastiera le coordinate del punto (x1,y1) e i coefficenti della retta m e q (espressa come y=mx+q), restituisca come output il valore della distanza tra il punto e la retta.

I valori di input e output sono double.

Stringhe:

Le stringhe da usare per ottenere gli input sono:

"Enter the coefficient 'm' of the line:\n"
"Enter the coefficient 'q' of the line:\n"

"Enter the value of x1:\n"
"Enter the value of y1:\n"


 Le stringhe da usare per scrivere gli output sono:

"The distance is %.3f\n"

Esempio:


input = 1; 3; 0; 1
output = "The distance is 1.414"

input = 2; 3; 4; 5
output = "The distance is 2.683"

input = 0; 1; 0; 0
output = "The distance is 1.000"

input = 0; 0; 0; 0
output = "The distance is 0.000"

Esercizio 3:

Dati tre punti, si richiede di scrivere una funzione che:

presi in input da tastiera le coordinate dei tre punti (x1,y1), (x2,y2) e (x3,y3), controlli se i tre punti formano un triangolo e nel caso restituisca come output il valore del perimetro e dell'area del triangolo.

I valori di input e output sono double.

Stringhe:

Le stringhe da usare per ottenere gli input sono:

"Enter the value of x1:\n"
"Enter the value of y1:\n"
"Enter the value of x2:\n"
"Enter the value of y2:\n"
"Enter the value of x3:\n"
"Enter the value of y3:\n"

 Le stringhe da usare per scrivere gli output sono:

"Triangle perimeter is: %.3f\n"
"Triangle area is: %.3f\n"
"The input triangle is not valid.\n"

Esempio:


input = 1; 1; 2; 2; 3; 3
output = "The input triangle is not valid."

input = 1; 1; 2; 1; 2; 2
output = "Triangle perimeter is: 3.414"
"Triangle area is: 0.500"

Stringhe:

string.txt