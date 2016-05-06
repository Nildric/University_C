#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define DIM 104

int main()
{
	/* Dichiarazione delle variabili necessarie. */
	char user_input = 's';

	int black_jack_cards[DIM];
	int ace_counter = 0, player_score = 0, player_score_no_aces = 0;

	int i, tmp, random_number;

	/* Imposta il seed del generatore di numeri pseudocasuali. La
	 * funzione dev'essere chiamata solo una volta (tipicamente
	 * all'inizio del programma). */
	srand(time(NULL));

	printf("*-* Blackjack *-*\n");

	/* Inserire il vostro codice qui...
	 *
	 * Per generare dei numeri in modo casuale, usare la funzione rand().
	 * Ad esempio, per generare numeri casuali compresi tra 0 (incluso) e
	 * 52 (escluso), usare:
	 *
	 *   random_number = rand() % 52;
	 *
	 * Per ulteriori informazioni sulla funzione rand, consultare il
	 * manuale disponibile digitando il seguente comando in un terminale:
	 *
	 *   man 3 rand
	 */

	for (i = 0; i < DIM; i++)
	{
		if (i >= 52)
		{
			black_jack_cards[i] = (i - 52);
		}
		else
		{
			black_jack_cards[i] = i;
		}
	}

	/*
	 * Mescolando il mazzo di carte si ottiene lo stesso risultato che
	 * pescando una carta casuale da un mazzo non mescolato. Rendendo
	 * sequenziale l'estrazione dal mazzo e quindi più efficiente.
	 */
	for (i = 0; i < DIM; i++)
	{
		random_number = (rand() % 104);

		tmp = black_jack_cards[random_number];
		black_jack_cards[random_number] = black_jack_cards[i];
		black_jack_cards[i] = tmp;
	}

	i = 0;

	do
	{
		tmp = (black_jack_cards[i] % 13);

		printf("Hai pescato: ");

		switch (tmp)
		{
			case 0:
			{
				ace_counter++;

				printf("1");
				break;
			}

			case 10:
			{
				player_score_no_aces += 10;

				printf("J");
				break;
			}

			case 11:
			{
				player_score_no_aces += 10;

				printf("Q");
				break;
			}

			case 12:
			{
				player_score_no_aces += 10;

				printf("K");
				break;
			}

			default:
			{
				player_score_no_aces += (tmp + 1);

				printf("%d", (tmp + 1));
				break;
			}
		}

		player_score = player_score_no_aces;

		if (ace_counter > 0)
		{
			if ((player_score + 11 + (ace_counter - 1)) <= 21)
			{
				player_score += (11 + (ace_counter - 1));
			}
			else
			{
				player_score += ace_counter;
			}
		}

		switch ((black_jack_cards[i] / 13))
		{
			case 0:
			{
				printf("H");
				break;
			}
			case 1:
			{
				printf("D");
				break;
			}
			case 2:
			{
				printf("C");
				break;
			}
			case 3:
			{
				printf("S");
				break;
			}
		}

		printf("\nPunteggio: %d\n", player_score);

		if (player_score < 21)
		{
			do
			{
				printf("Vuoi continuare? ");
				scanf(" %c", &user_input);
			} while (user_input != 's' && user_input != 'n');

			i++;
		}
		else if (player_score == 21)
		{
			printf("Congratulazioni, hai vinto!\n");
			user_input = 'n';
		}
		else
		{
			printf("Hai perso...\n");
			user_input = 'n';
		}
	} while (i < DIM && user_input == 's');

	return EXIT_SUCCESS;
}
