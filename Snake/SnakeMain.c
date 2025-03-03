#include "SnakeMain.h"
#include "Highscore.h"
#include "GameSpace.h"
#include "Menus.h"
#include "Logic.h"

// todo: 
// -> Save multiple highscores given inputted usernames
// -> Fix the multi-input bug
// -> Fix body sections spawning in the top left of the grid before being placed on the active body
// -> Create a traversable initial menu with: "start", "exit", "highscores", and "grid size"
//		-> Make sure the "Snake" title card deletes after options are selected
//		-> Have functional start, gridcsize, and exit options
// -> etc..

int main() {

	initalizeGame();

	while (startMenuChoice != 1) {
		displayStartMenu();
	}

	if (startMenuChoice == 1) { // if the player chooses "start" then begin the game
			while (!gameOver) {
				printGrid();
				input();
				logic();
				Sleep(100); // bug here: If you click a directional key, you are able to click another directional key after this -> before the sleep is finished
			}				//           making it possible to go directly back from the direction you came BEFORE the game moves the head the first direction
							//           This means your key value will be changed but the head will not have moved and you will gameover instantly  
			gameOverScreen();

			highscore();
	}

	return 0;
}