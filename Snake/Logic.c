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

	if (x == fruitx && y == fruity) { // if the snake overlaps with a fruit
		spawnFruit();
		snakeLength += 2;
	}
}