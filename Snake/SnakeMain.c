#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#define WIDTH		20
#define HEIGHT		10

int snakeTailX[100], snakeTailY[100];

int x, y, score, gameOver, key, snakeLength, fruitx, fruity;

void initalizeGame() {
	
	gameOver, score = 0;

	snakeLength = 1;

	x = WIDTH / 2;
	y = HEIGHT / 2;

	fruitx = rand() % WIDTH; // set the initial fruit position
	fruity = rand() % HEIGHT;
	
	while (fruitx == 0)
		fruitx = rand() % WIDTH;

	while (fruity == 0)
		fruity = rand() % HEIGHT;
}

void setCursorPosition(int x, int y) { // this is a function made by windows to set a position to redraw an output from
	COORD coord = { (SHORT)x, (SHORT)y };  // rather than completly clear and redraw it (fixes the flickering issue)
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void scoreDisplay() {

	score = snakeLength * 50 - 50;

	printf("Score: %d     Length: %d\n", score, snakeLength);
}

void printGrid() {
	setCursorPosition(0, 0); // this allows for the grid to replace itself rather than constantly print downward 

	for (int i = 0; i < WIDTH / 2 + 2; i++) { printf("[]"); }
	printf("\n");

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j <= WIDTH; j++) {

			if (j == 0 || j == WIDTH) {
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
							printf("~");
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

	for (int i = 0; i < WIDTH / 2 + 2; i++) { printf("[]"); }
	printf("\n");

	scoreDisplay();
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
			Sleep(50); // slow down speed of vertical movement
			y--; 
			break;
		case 2:  // a - left
			x--;
			break;
		case 3:  // s - down
			Sleep(50);
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

	for (int i = 1; i < snakeLength; i++) {
		if (snakeTailX[i] == x && snakeTailY[i] == y) { // gameover when hitting tail
			gameOver = 1;
		}
	}

	if (x == fruitx && y == fruity) {
		fruitx = rand() % WIDTH; // random position in the grid
		fruity = rand() % HEIGHT;

		while (fruitx == 0) // when teh fruit is collected, make a new one in a random place
			fruitx = rand() % WIDTH;

		// Generation of new fruit
		while (fruity == 0)
			fruity = rand() % HEIGHT;
		// score += 10;
		snakeLength += 2;
	}
}

void gameOverScreen() {

	printf("  ___   __   _  _  ____     __   _  _  ____  ____\n");
	printf(" / __) / _\\ ( \\/ )(  __)   /  \\ / )( \\(  __)(  _ \\ \n");
	printf("( (_ \\/    \\/ \\/ \\ ) _)   ( || )\\ \\/ / ) _)  )   /\n");
	printf(" \\___/\\_/\\_/\\_)(_/(____)   \\__/  \\__/ (____)(__\\_)\n");

}

void highscore() {
	char buff[100];
	int n = 8;

	FILE* highScore = fopen("Snake_Highscore.txt", "r");

	if (!highScore) {
		fprintf(stderr, "Error accessing file");
	}

	fgets(buff, n, highScore);
	
	if (atoi(buff) < score) {
		fclose(highScore);
		highScore = fopen("Snake_Highscore.txt", "w");

		fprintf(highScore, "%d", score);
	}


	fclose(highScore);
}

int main() {
	
	initalizeGame();

	while (!gameOver) {
		printGrid(); 
		input();
		logic();
		Sleep(100); // bug here: If you click a directional key, you are able to click another directional key after this -> before the sleep is finished
	}				//           making it possible to go directly back from the driection you came BEFORE the game moves the head the first direction
					//           This means your key value will be changed but the head will not have moved and you will gameover instantly  
	gameOverScreen();

	highscore();

	return 0;
}