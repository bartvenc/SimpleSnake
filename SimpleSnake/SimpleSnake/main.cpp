#include <iostream>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection eDir;

void Setup() {
	
	gameOver = false;
	eDir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitX = rand() % height;
	score = 0;
}

void Draw() {

	system("cls"); //Clears the screen
	//Top Border
	for (int i = 0; i < width; i++) {
		printf("#");
	}
	printf("\n");

	//The main map
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j = width-1) {
				printf("#");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}


	//Bottom Border
	for (int i = 0; i < width; i++) {
		printf("#");
	}
	printf("\n");

}

void Input() {

}

void Logic() {

}


int main() {

	Setup();

	while (!gameOver) {
		Draw();
		Input();
		Logic();

	}

	return 0;
}