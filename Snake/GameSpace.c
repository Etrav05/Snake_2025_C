#include "GameSpace.h"
#include "SnakeMain.h"

void setCursorPosition(int x, int y) { // this is a function made by windows to set a position to redraw an output from
	COORD coord = { (SHORT)x, (SHORT)y };  // rather than completly clear and redraw it (fixes the flickering issue)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printGrid() {
	setCursorPosition(0, 0); // this allows for the grid to replace itself rather than constantly print downward 

	for (int i = 0; i < width / 2 + 2; i++) { printf("[]"); }
	printf("\n");

	for (int i = 0; i < height; i++) {
		for (int j = 0; j <= width; j++) {

			if (j == 0 || j == width) {
				printf("[]");
			}

			if (j == x && i == y) {
				printf("O");
			}

			else if (i == fruity && j == fruitx)
				printf("*");

			else {
				int tailPtr = 0;
				for (int k = 0; k < snakeLength; k++) {
					if (snakeTailX[k] == j && snakeTailY[k] == i) { // if tails x is a value along the width, and the y is a value along the height
						if (k != snakeLength - 1) {
							printf("c");
							tailPtr = 1;
						}

						else {
							printf("o");
							tailPtr = 1;
						}
					}
				}
				if (!tailPtr) // print blank space if none of the above
					printf(" ");
			}

		}
		printf("\n");
	}

	for (int i = 0; i < width / 2 + 2; i++) { printf("[]"); }
	printf("\n");

	scoreDisplay();
	controls();
}

void scoreDisplay() { // display score under game space

	score = snakeLength * 50 - 50;

	printf("Score: %d     Length: %d\n", score, snakeLength);
}

void controls() {
	printf("\n\n            W        Pause - P\n");
	printf("Controls: A S D      Exit  - X\n");
}

void printHighscore() { // print the games score after gameovers

	if (highscore() == true) {
		printf("\n=== New highscore: %d ===\n", score);
	}

	else
		printf("\n--- Score: %d ---\n", score);
}

void gameOverScreen() { // game over

	printf("  ___   __   _  _  ____     __   _  _  ____  ____\n");
	printf(" / __) / _\\ ( \\/ )(  __)   /  \\ / )( \\(  __)(  _ \\ \n");
	printf("( (_ \\/    \\/ \\/ \\ ) _)   ( || )\\ \\/ / ) _)  )   /\n");
	printf(" \\___/\\_/\\_/\\_)(_/(____)   \\__/  \\__/ (____)(__\\_)\n");

	printHighscore();
}