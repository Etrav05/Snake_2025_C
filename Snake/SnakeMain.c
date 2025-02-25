#include <stdio.h>
#include <windows.h>
#define WIDTH		41
#define HEIGHT		20

int snakeTailX[100], snakeTailY[100];

int x, y, gameOver, key, snakeLength;

void initalizeGame() {
	
	gameOver = 0;

	x = WIDTH / 2;
	y = HEIGHT / 2;
}

void setCursorPosition(int x, int y) { // this is a function made by windows to set a position to redraw an output from
	COORD coord = { (SHORT)x, (SHORT)y };  // rather than completly clear and redraw it (fixes the flickering issue)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printGrid() {
	setCursorPosition(0, 0); // this allows for the grid to replace itself rather than constantly print downward 

	for (int i = 0; i < WIDTH / 2 + 1; i++) { printf("[]"); }
	printf("]");
	printf("\n");

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {

			if (j == 0 || j == WIDTH - 1) {
				printf("[]");
			}

			else if (j == x && i == y) {
				printf("O");
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

	for (int i = 0; i < WIDTH / 2 + 1; i++) { printf("[]"); }
	printf("]");
	printf("\n");
}

int input() { // accept inputs and set them to a key value
	while (kbhit()) {
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
		}
	}
	
	return key; // this value will be used to move a certain direction
}

void logic() {

	switch (key) { // snake head movement 
		case 1:  // w - up
			Sleep(30); // slow down sleep of vertical movement
			y--; 
			break;
		case 2:  // a - left
			x--;
			break;
		case 3:  // s - down
			Sleep(30);
			y++;
			break;
		case 4:  // d - right
			x++;
			break;
	}

	int prevX = snakeTailX[0]; // initailize the previous body sections
	int prevY = snakeTailY[0];
	int prev2X, prev2Y; // buffers

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
		
		printGrid(); 
		input();
		logic(); // continue developing this (specifically fruit)
		Sleep(100);
	}

	return 0;
}