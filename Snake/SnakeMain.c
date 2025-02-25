#include <stdio.h>
#define WIDTH		21
#define HEIGHT		10

int snakeTailX[100], snakeTailY[100];

int x, y, gameOver, key, snakeLength;

void initalizeGame() {

	gameOver = 0;

	x = WIDTH / 2;
	y = HEIGHT / 2;
}

void printGrid() {
	system("cls");

	for (int i = 0; i < WIDTH; i++) { printf("="); }
	printf("\n");

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {

			if (j == 0 || j == WIDTH - 1) {
				printf("=");
			}

			else if (j == x && i == y) {
				printf("#");
			}

			else {
				int tailPtr = 0;
				for (int k = 0; k < snakeLength; k++) {
					if (snakeTailX[k] == j && snakeTailY[k] == i) { // if tails x is a value along the width, and the y is a value along the height
						printf("*");
						tailPtr = 1;
					}
				}
				if (!tailPtr) // print blank space if none of the above
					printf(" ");
			}
			
		}
		printf("\n");
	}

	for (int i = 0; i < WIDTH; i++) { printf("="); }
	printf("\n");
}

int input() { // accept inputs and set them to a key value
	while (kbhit()) {
		switch (tolower(getch())) {
		case 'w':
			if (key != 3);
			key = 1;
			break;
		case 'a':
			if (key != 4);
			key = 2;
			break;
		case 's':
			if (key != 1);
			key = 3;
			break;
		case 'd':
			if (key != 2);
			key = 4;
			break;
		case 'x':
			gameOver = 1;
			break;
		}
	}
	
	return key; // this value will be used to move a certain direction
}

void logic() {

	switch (key) { // snake head movement 
		case 1:  // w - up
			Sleep(10); // slow down sleep of vertical movement
			y--; 
			break;
		case 2:  // a - left
			x--;
			break;
		case 3:  // s - down
			Sleep(10);
			y++;
			break;
		case 4:  // d - right
			x++;
			break;
	}

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) { // gameover hitting walls
		gameOver = 1;
	}

	for (int i = 0; i < snakeLength; i++) {
		if (snakeTailX[i] == x && snakeTailY[i] == y) { // gameover when hitting tail
			gameOver = 1;
		}
	}
}

int main() {
	
	initalizeGame();

	while (!gameOver) {
		
		printGrid(); // find how to fix the blinking issue
		input(); // fix the ability of going straight backward
		logic(); // continue developing this (specifically fruit)
		Sleep(50);
	}

	return 0;
}