#include <stdlib.h>
#include <stdio.h>
#include "es10.h"

int is_prime(int n)
{
    int is_prime_flag = 1, divider = 2;

    while (is_prime_flag && divider <= (n / 2))
    {
        if (n % divider == 0)
        {
            is_prime_flag = 0;
        }

        divider++;
    }

    return is_prime_flag;
}

int next_prime(int n)
{
    n++;

    while (!is_prime(n))
    {
        n++;
    }

    return n;
}

void print_factors(int n)
{
    int divider = 2, counter = 0;

    printf("%d=", n);

    while (n >= 1)
    {
        if (n % divider == 0)
        {
            counter++;
            n /= divider;
        }
        else
        {
            if (counter > 0)
            {
                printf("%d", divider);

                if (counter > 1)
                {
                    printf("^%d", counter);
                }

                if (n > 1)
                {
                	printf("*");
                }
                else
                {
                	/*
                	 * Istruzione utilizzata per evitare un break all'interno del ciclo.
                	 * Si potrebbe ovviare al problema ponendo il ciclo while con condizione (n > 1)
                	 * questo comporterebbe, però, ad una ripetizione delle istruzioni utili alla stampa
                	 * dopo la conclusione del ciclo stesso.
                	 */
                	n = 0;
                }
            }

            counter = 0;
            divider = next_prime(divider);
        }
    }

    printf("\n");
}
