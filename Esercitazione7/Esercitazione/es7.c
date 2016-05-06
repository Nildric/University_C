/*
 * 857179	Federico Longhin
 */

#include <stdio.h>
#include <math.h>

int main() {
	int menuEntry;

	do {
		printf("Choose the part to execute:\n\t1 \t: Part 1 (Fibonacci)\n\t2 \t: Part 2 (The answer)\n\t3 \t: Part 3 (Is prime?)\n\tother \t: Exit\n\n");
		scanf("%i", &menuEntry);

		if (menuEntry == 1) {
			int fibonacciInput;
			double fibonacciOutput;

			printf("Enter the index of the fibonacci sequence.\n");
			scanf("%i", &fibonacciInput);

			if (fibonacciInput <= 0) {
				printf("Index must be greater than 0.\n");
			} else {
				if (fibonacciInput == 1 || fibonacciInput == 2) {
					fibonacciOutput = 1;
				} else {
					int i;
					double auxiliar1 = 1, auxiliar2 = 1;

					for (i = 1; i <= fibonacciInput - 2; i++) {
						fibonacciOutput = auxiliar1 + auxiliar2;
						auxiliar2 = auxiliar1;
						auxiliar1 = fibonacciOutput;
					}
				}

				printf("Fibonacci(%d) = %.0f\n", fibonacciInput, fibonacciOutput);
			}
		}

		if (menuEntry == 2) {
			int flag = 0;
			double tolerance, result, inputNumber;

			printf("Enter the tollerance.\n");
			scanf("%lf", &tolerance);

			printf("Start entering numbers!\n");

			do {
				scanf("%lf", &inputNumber);

				if (!flag) {
					result = inputNumber;
					flag = 1;
				} else {
					result = ((result + inputNumber) / 2);
				}

				printf("Got %.3f\n...", result);
			} while (fabs(result - 42) > tolerance);

			printf("Yes! More or less 42\n");
		}

		if (menuEntry == 3) {
			int toCheckNumber;

			printf("Enter the number to be checked.\n");
			scanf("%i", &toCheckNumber);

			if (toCheckNumber <= 1) {
				printf("Cannot say that %d is prime.\n", toCheckNumber);
			} else {
				if (toCheckNumber % 2 == 0 && toCheckNumber != 2) {
					printf("%d is not prime.\n", toCheckNumber);
				} else {
					int flag = 1, i;

					for (i = 2; i < toCheckNumber && flag == 1; i++) {
						if (toCheckNumber % i == 0) {
							flag = 0;
						}
					}

					if (flag) {
						printf("%d is prime.\n", toCheckNumber);
					} else {
						printf("%d is not prime.\n", toCheckNumber);
					}
				}
			}
		}
	} while (menuEntry >= 1 && menuEntry <= 3);

	return 0;
}
