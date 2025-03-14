#include "Fruit.h"

void spawnFruit() {
	bool overlap;

	do {
		overlap = false;

		fruitx = rand() % width; // random position in the grid
		fruity = rand() % height;

		for (int i = 0; i < snakeLength; i++) {
			if (fruitx == snakeTailX[i] && fruity == snakeTailY[i]) {
				overlap = true;
				break;
			}
		}
	} while (overlap);

}