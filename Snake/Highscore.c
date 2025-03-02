#include "Highscore.h"
#include "SnakeMain.h"

bool highscore() {
	char buff[100];
	int n = 8;

	FILE* highScore = fopen("Snake_Highscore.txt", "r");

	if (!highScore) {
		fprintf(stderr, "Error accessing file");
		return false;
	}

	fgets(buff, n, highScore);

	if (atoi(buff) < score) {
		fclose(highScore);
		highScore = fopen("Snake_Highscore.txt", "w");

		fprintf(highScore, "%d", score);

		return true;
	}

	else
		return false;

	fclose(highScore);
}