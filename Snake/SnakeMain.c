#include "SnakeMain.h"
#include "Highscore.h"
#include "GameSpace.h"
#include "Menus.h"
#include "Logic.h"

// todo: 
// -> Save multiple highscores given inputted usernames
// -> Fix the multi-input bug
// -> Fix body sections spawning in the top left of the grid before being placed on the active body
// -> ...
// -> etc..

// bugs:
// -> Body parts spawn in the top left of the grid for a moment before attaching to the snake (they have collision)
// -> Multiple inputs can be placed in a single loop (100ms) meaning you can circumvent the key specific restrictions

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
				logic();
				Sleep(100); // bug here: If you click a directional key, you are able to click another directional key after this -> before the sleep is finished
			}				//           making it possible to go directly back from the direction you came BEFORE the game moves the head the first direction
							//           This means your key value will be changed but the head will not have moved and you will gameover instantly  
			gameOverScreen();

			highscore();
	}

	return 0;
}