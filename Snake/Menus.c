#include "Menus.h"

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



}