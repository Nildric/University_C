#include <stdlib.h>
#include <stdio.h>
#include "es12.h"

/*
 * Per compilare usate il comando
 *   gcc -std=gnu89 -Wall -pedantic -o es12 es12.c es12_main.c
 */
int main()
{
    #if 0
    int v[10] = {0, -5, -25, 1, -32, 24, 25, 26, -1, 0};
    int npos = 0, nneg = 0, nzero = 0;

    conta_segno(v, 10, &npos, &nneg, &nzero);

    printf("npos: %d - nneg: %d - nzero: %d", npos, nneg, nzero);
    #endif

    #if 0
    int ndiff = 0, ddiff = 0;

    differenza_frazioni(360, 12, 15, 360, &ndiff, &ddiff);

    printf("\n%d\n--\n%d\n", ndiff, ddiff);
    #endif

	#if 0
    int i = 0, d = 0, e = 0;

    str2dec("0.00000", &i, &d, &e);
    printf("Integer: %d\nDecimal: %d\nExponential: %d\n", i, d, e);
	#endif

    return EXIT_SUCCESS;
}
