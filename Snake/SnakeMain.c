#include "SnakeMain.h"
#include "Highscore.h"
#include "GameSpace.h"
#include "Menus.h"
#include "Logic.h"

// todo: 
// -> Save multiple highscores given inputted usernames
// -> Allow for "replay" option rather than instantly ending the process
// -> ...
// -> etc..

// bugs:
// -> ...

int main() {
	hideCursor();

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