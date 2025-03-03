#include "Menus.h"

int* pHeight = &height;
int* pWidth = &width;

void menuSelect() {

	displayStartMenu();

	switch (startMenuChoice) {
		case 1:
			break; // continue with the game function given an input of 1 (start) 
		case 2:
			gridSize();
			break;
		case 3:
			gameOver = 1;
			break;
	}
}

int displayStartMenu() {

	printf(" ____  __ _   __   __ _  ____\n");
	printf("/ ___)(  ( \\ / _\\ (  / )(  __)\n");
	printf("\\___ \\/    //    \\ )  (  ) _)\n");
	printf("(____/\\_)__)\\_/\\_/(__\\_)(____)\n");

	printf("\n       1 -> Start\n       2 -> Grid size\n       3 -> Exit\n\n       Enter choice: ");

	if (scanf_s("%d", &startMenuChoice) == 1 && startMenuChoice > 0 && startMenuChoice <= 3) {
		return startMenuChoice;
	}

	else
		fprintf(stderr, "Invalid option (Type 1-3): "); // make this recursive
}

int gridSize() {

	printf("  ___  ____  ____  ____\n");
	printf(" / __)(  - \\(_  -)(  _ \\\n");
	printf("( (_-. )   / _)(_  )(_) )\n");
	printf(" \\___/(_)\\_)(____)(____/\n");

	printf("\n       1 -> 5x10\n       2 -> 10x10\n       3 -> 20x20\n\n       Enter choice: "); // allow for rectangles lol

	while (true) {
		if (scanf_s("%d", &gridChoice) == 1 && gridChoice > 0 && gridChoice <= 3) {
			return true, gridChoice;
		}

		else {
			fprintf(stderr, "Invalid option (Type 1-3): "); // make this recursive
			return false;
		}
	}

	switch (gridChoice) { // bug here (values not actual changing)
		case 1: // 5x10
			return height = 20;
			return width = 5;
			break;
		case 2: // 10x10
			return height = 20;
			return width = 10;
			break;
		case 3: // 20x20
			return height = 40;
			return width = 20;
			break;
	}

	displayStartMenu();
}