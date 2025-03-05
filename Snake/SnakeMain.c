#include "SnakeMain.h"
#include "Highscore.h"
#include "GameSpace.h"
#include "Menus.h"
#include "Logic.h"

// todo: 
// -> Save multiple highscores given inputted usernames
// -> Fix body sections spawning in the top left of the grid before being placed on the active body
// -> ...
// -> etc..

// bugs:
// -> Body parts spawn in the top left of the grid for a moment before attaching to the snake (they have collision)

int main() {

	while (startMenuChoice != 1) {
		menuSelect();
	}

	initalizeGame();
	clearScreen();

	if (startMenuChoice == 1) { // if the player chooses "start" then begin the game
		while (!gameOver) {
			printGrid();
			input();
			paused();
			logic();
			Sleep(100);
		}

		gameOverScreen();
		highscore();
	}

	return 0;
}