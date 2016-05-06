#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define DECK_SIZE 104

int main() {
	int i, score, card, card_value, card_seed, n_aces_11;
	char answer, selected_cards[DECK_SIZE];
	char seeds[] = {'H', 'D', 'C', 'S'};
	char figures[] = {'J', 'Q', 'K'};
	
	for (i = 0; i < DECK_SIZE; i++) {
		selected_cards[i] = 0;
	}

	srand(time(NULL));
	printf("*-* Blackjack *-*\n");
	
	score = n_aces_11 = 0;
	do {
		do {
			card = rand() % DECK_SIZE;
		} while (selected_cards[card]);
		selected_cards[card] = 1;

		card_value = card % 13 + 1;
		card_seed = (card / 13) % 4;
		
		printf("\nHai pescato: ");
		if (card_value == 1) {
			printf("1");
			score += 11;
			n_aces_11++;
		} else if (card_value >= 11) {
			printf("%c", figures[card_value - 11]);
			score += 10;
		} else {
			printf("%d", card_value);
			score += card_value;
		}
		printf("%c\n", seeds[card_seed]);

		while (score > 21 && n_aces_11 > 0) {
			score -= 10;
			n_aces_11--;
		}
		printf("Punteggio: %d\n", score);

		if (score < 21) {
			do {
				printf("Vuoi continuare? ");
				scanf(" %c", &answer);
			} while (answer != 'n' && answer != 's');
		} else if (score == 21) {
			printf("Congratulazioni, hai vinto!\n");
		} else {
			printf("Hai perso...\n");
		}
	} while (score < 21 && answer != 'n');

	return EXIT_SUCCESS;
}
