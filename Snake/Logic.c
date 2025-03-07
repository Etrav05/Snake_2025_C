#include "Logic.h"

void logic() {

	switch (key) { // snake head movement 
	case 1:  // w - up
		y--;
		Sleep(50); // slow down speed of vertical movement
		break;
	case 2:  // a - left
		x--;
		break;
	case 3:  // s - down
		y++;
		Sleep(50);
		break;
	case 4:  // d - right
		x++;
		break;
	}

	int prevX = snakeTailX[0]; // initailize the previous body sections
	int prevY = snakeTailY[0];
	int prev2X, prev2Y; // buffers

	// This is the initial "tail" of the snake (overlaps the head)
	snakeTailX[0] = x; // set the tail to the tails to the current x, y from initalizeGame 
	snakeTailY[0] = y;

	for (int i = 1; i < snakeLength; i++) { // for everything (after the head (1)) till the total length of the snake
		prev2X = snakeTailX[i];
		prev2Y = snakeTailY[i];
		snakeTailX[i] = prevX;
		snakeTailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	if (x < 0 || x >= width || y < 0 || y >= height) { // gameover hitting walls
		gameOver = 1;
	}

	for (int i = 1; i < snakeLength; i++) {
		if (snakeTailX[i] == x && snakeTailY[i] == y) { // gameover when hitting tail
			gameOver = 1;
		}
	}

	if (x == fruitx && y == fruity) {
		fruitx = rand() % width; // random position in the grid
		fruity = rand() % height;

		while (fruitx == 0) // when teh fruit is collected, make a new one in a random place
			fruitx = rand() % width;

		// Generation of new fruit
		while (fruity == 0)
			fruity = rand() % height;
		// score += 10;
		snakeLength += 2;
	}
}

void initalizeGame() { // initialize all values used for this game

	gameOver, score, replayYN = 0;

	snakeLength = 1;

	x = width / 2;
	y = height / 2;

	fruitx = rand() % width; // set the initial fruit position
	fruity = rand() % height;

	while (fruitx == 0)
		fruitx = rand() % width;

	while (fruity == 0)
		fruity = rand() % height;

	for (int i = 0; i < MAX_LENGTH; i++) {
		snakeTailX[i] = -1;
		snakeTailY[i] = -1;
	}
	snakeTailX[0] = x; // First tail section starts at the head's position
	snakeTailY[0] = y;
}

int input() { // accept inputs and set them to a key value
	if (kbhit()) { // changed this to IF so it only checks once every cycle (fixing the issue of multi-input)
		switch (tolower(getch())) {
		case 'w':
			if (key != 3)
				key = 1;
			break;
		case 'a':
			if (key != 4)
				key = 2;
			break;
		case 's':
			if (key != 1)
				key = 3;
			break;
		case 'd':
			if (key != 2)
				key = 4;
			break;
		case 'x':
			gameOver = 1;
			break;
		case 'p':
			pause = 1 - pause;
			break;
		default:
			break; // ignore invalid inputs
		}
	}

	return key; // this value will be used to move a certain direction
}

void paused() {
	while (pause == 1) { // pauses when needed
		input();
		Sleep(100);
	}
}