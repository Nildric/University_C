ESERCITAZIONE 14

Anche questa settimana lo scopo dell'esercitazione è di fare pratica con la ricorsione in C. Tutti gli esercizi devono essere svolti esclusivamente usando la ricorsione. L'utilizzo di costrutti iterativi (for, while, do-while) non è consentito, pena una valutazione errata del relativo esercizio. È consentita (e talvolta necessaria) la definizione ed implementazione di funzioni ausiliarie (sempre ricorsive).

Esercizio 1

Dato un vettore v contenente interi positivi distinti che rappresentano il valore di n tipi diversi di monete e un numero positivo somma, contare il numero di modi in cui si possono scegliere le monete per raggiungere la somma data. Assumete di avere a disposizione un numero illimitato di monete di ciascun tipo. Si noti che l’ordine di scelta delle monete non è rilevante. La firma della funzione è la seguente:

int conta_combinazioni(int v[], int n, int somma);
Esempi:

conta_combinazioni({5, 2, 1}, 3, 6) restituisce 5:
5+1
2+1+1+1+1
2+2+1+1
2+2+2
1+1+1+1+1+1
conta_combinazioni({5, 2, 1}, 3, 7) restituisce 6:
5+2
5+1+1
2+1+1+1+1+1
2+2+1+1+1
2+2+2+1
1+1+1+1+1+1+1
conta_combinazioni({7, 9, 3, 2}, 4, 16) restituisce 8:
7+7+2
7+9
7+3+3+3
7+3+2+2+2
9+3+2+2
3+3+3+3+2+2
3+3+2+2+2+2+2
2+2+2+2+2+2+2+2
Esercizio 2

Data una matrice di interi non negativi di dimensione n x n (con 1 = n = N), dire il peso minimo tra tutti i percorsi che congiungono la posizione (0, 0) alla posizione (n-1, n-1). Il peso di un percorso è dato dalla somma degli elementi presenti nelle caselle attraversate.

Partendo da una cella in posizione (r, c), le mosse tra cui è possibile scegliere sono:

spostamento in posizione (r, c+1), se c < n - 1 (spostamento a destra);
spostamento in posizione (r+1, c+1), se r < n - 1 e c < n - 1 (spostamento in diagonale basso-destra);
spostamento in posizione (r+1, c), se r < n - 1 (spostamento in basso).
La firma della funzione è la seguente, dove N è una costante definita nel file es14.h:

int percorso_minimo(int m[N][N], int n);
Esempi:

8	5	0	7
1	8	4	9
7	1	2	0
3	0	6	8 
Uno dei percorsi di peso minimo è (0, 0) - (1, 0) - (2, 1) - (2, 2) - (3, 3): la funzione restituisce 20.

4	3	1	1
7	4	6	9
0	2	7	8
1	4	1	0 
Il percorso di peso minimo è (0, 0) - (1, 1) - (2, 1) - (3, 2) - (3, 3): la funzione restituisce 11.