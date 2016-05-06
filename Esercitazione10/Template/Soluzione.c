#include <stdlib.h>
#include <stdio.h>
#include "es10.h"

int is_prime(int n) {
	int d = 3;

	if (n % 2 == 0)
		return n == 2;
	while (d * d <= n && n % d != 0)
		d += 2;
	return d * d > n;
}

int next_prime(int n) {
	int np;

	np = n + 1 + n % 2;
	while (!is_prime(np))
		np += 2;
	return np;
}

void print_factors(int n) {
	int cnt, d = 2;

	printf("%d=", n);
	while (n != 1) {
		cnt = 0;
		while (n % d == 0) {
			n /= d;
			cnt++;
		}
		if (cnt != 0) {
			printf("%d", d);
			if (cnt > 1)
				printf("^%d", cnt);
			if (n != 1)
				printf("*");
		}
		d = next_prime(d);
	}
	printf("\n");
}
