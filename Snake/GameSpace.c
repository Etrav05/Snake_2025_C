#include "GameSpace.h"
#include "SnakeMain.h"

void setCursorPosition(int x, int y) { // this is a function made by windows to set a position to redraw an output from
	COORD coord = { (SHORT)x, (SHORT)y };  // rather than completly clear and redraw it (fixes the flickering issue)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor(int tf) { // another windows made function to hide the cursor while redrawing the terminal
	// Get the handle to the standard output (console)
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Define the cursor info structure
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);

	// Set the cursor visibility to false (hide the cursor)
	cursorInfo.bVisible = tf; // 0 = false, 1 = true

	// Apply the changes
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}


void printGrid() {
	hideCursor(0);
	setCursorPosition(0, 0); // this allows for the grid to replace itself rather than constantly print downward 

	for (int i = 0; i < width / 2 + 2; i++) { printf("[]"); }
	printf("\n");

	for (int i = 0; i < height; i++) {
		for (int j = 0; j <= width; j++) {

			if (j == 0 || j == width) {
				printf("[]"); // walls
			}

			if (j == x && i == y) {
				printf("O"); // snake head
			}

			else if (i == fruity && j == fruitx)
				printf("*"); // fruit

			else {
				int tailPtr = 0; // flag to check if a tail section was printed (to prevent the snake parts, which were just made, from printing in the top left)
				for (int k = 0; k < snakeLength; k++) {
					if (snakeTailX[k] != -1 && snakeTailY[k] != -1) { // check if the tail section is on-screen
						if (snakeTailX[k] == j && snakeTailY[k] == i) { // check if the current grid position (j, i) matches a tail section
							if (k != snakeLength - 1) {
								printf("c"); // snake body
							}
							else {
								printf("o"); // snake tail
							}
							tailPtr = 1; // set flag to indicate a tail section was printed
							break; // exit the loop once a tail section is found
						}
					}
				}
				if (!tailPtr) { // if no tail section was printed, print a blank space
					printf(" ");
				}
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