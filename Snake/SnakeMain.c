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
                        break;
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