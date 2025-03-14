#include "Initialize_Game.h"

void initalizeGame() { // initialize all values used for this game

	gameOver, score, replayYN = 0;

	snakeLength = 1;

	x = width / 2;
	y = height / 2;

	fruitx = rand() % width; // set the initial fruit position
	fruity = rand() % height;

	for (int i = 0; i < MAX_LENGTH; i++) {
		snakeTailX[i] = -1;
		snakeTailY[i] = -1;
	}
	snakeTailX[0] = x; // First tail section starts at the head's position
	snakeTailY[0] = y;
}

