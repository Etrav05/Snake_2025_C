#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define WIDTH		20
#define HEIGHT		10

int snakeTailX[100], snakeTailY[100];

int x, y, score, gameOver, key, snakeLength, fruitx, fruity, startMenuChoice;