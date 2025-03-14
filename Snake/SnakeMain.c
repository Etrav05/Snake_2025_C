#include "SnakeMain.h"
#include "Highscore.h"
#include "GameSpace.h"
#include "Menus.h"
#include "Logic.h"

// todo: 
// -> Save multiple highscores given inputted usernames
// -> Allow for grid resize when replaying
// -> ...
// -> etc..

// bugs:
// -> fruit can spawn on snakes body
// ->

int main() {
    hideCursor();

    while (1) {
        startMenuChoice = 0;

        while (startMenuChoice != 1) {
            menuSelect();

            initalizeGame();
            clearScreen();

            while (1) {
                printGrid();
                input();
                paused();
                logic();
                Sleep(100);

                if (gameOver) {
                    gameOverScreen();
                    highscore();

                    if (replay()) {
                        return 0;
                    }

                    else {
                        initalizeGame();
                        clearScreen();
                        gameOver = 0;
                    }
                }
            }
        }
    }
    return 0;
}