#include <iostream>
#include <conio.h> 
#include "windows.h"

using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection eDir;

void Setup() {
	
	gameOver = false;
	eDir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw() {

	system("cls"); //Clears the screen
	//Top Border
	for (int i = 0; i < width+2; i++) {
		printf("#");
	}
	printf("\n");

	//The main map
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0) {
				printf("#");
			}
			if (i == y && j == x) {
				printf("O");
			}
			else if (i == fruitY && j == fruitX) {
				printf("F");
			}
			else {
				bool print = false;
				for (int k = 0; k < nTail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						printf("o");
						print = true;
					}
				}
				if (!print) {
					printf(" ");
				}
			}
			if (j == width - 1) {
				printf("#");
			}
		}
		printf("\n");
	}

	//Bottom Border
	for (int i = 0; i < width+2; i++) {
		printf("#");
	}
	printf("\n Score: %d \n", score);
	

}

void Input() {

	if (_kbhit()) {
		
		switch (_getch()) {

		case 'a':
			eDir = LEFT;
			break;
		case 'd':
			eDir = RIGHT;
			break;
		case 'w':
			eDir = UP;
			break;
		case 's':
			eDir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}	
	}
}

void Logic() {

	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < nTail; i++) {

		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (eDir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	if (x > width || x < 0 || y > height || y < 0) {
		gameOver = true;
	}
	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y) {
			gameOver = true;
		}
	}
	if (x == fruitX && y == fruitY) {
		
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}

}


int main() {

	Setup();

	while (!gameOver) {
		Draw();
		Input();
		Logic();
		Sleep(100);

	}

	return 0;
}