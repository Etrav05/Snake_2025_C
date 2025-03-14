#include "Replay_Game.h"

int replay() {
	hideCursor(1);

	while (true) {
		printf("\nPlay again? (yes/no): ");
		char playAgain[10];

		if (scanf_s("%9s", playAgain, (unsigned)_countof(playAgain)) != 1) { // "%9s" only stores 9/10 entered chars, then we save the actual countof playAgain
			fprintf(stderr, "Invalid input, please enter yes/no: \n");
			while (getchar() != '\n');
			continue; // restart the loop
		}

		for (int i = 0; playAgain[i]; i++) {
			playAgain[i] = tolower(playAgain[i]);
		}

		if (strcmp(playAgain, "yes") == 0) {
			key = 0;
			return false;
		}

		else if (strcmp(playAgain, "no") == 0)
			return true;

		else {
			fprintf(stderr, "Invaild input, please enter yes/no: \n");
			while (getchar() != '\n'); // discard remaining chars in the input buff
		}
	}
}