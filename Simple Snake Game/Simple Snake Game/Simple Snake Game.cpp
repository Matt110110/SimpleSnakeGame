// Simple Snake Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h> // Library used for console inputs.
#include <Windows.h> // Library used for the Sleep() function.

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score; // x, y for coordinates, fruitX, fruitY for fruit coordinates and score for score. 
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
// This is for tracking the direction. This is an enumeration. (https://msdn.microsoft.com/en-us/library/2dzy4k6e.aspx)/(https://docs.microsoft.com/en-us/cpp/cpp/enumerations-cpp)
eDirecton dir;

void randomFruitPlacement()
{
	// Fruit will be randomly generated somewhere.
	fruitX = rand() % width; //Creates a random number from 0 to width-1
	fruitY = rand() % height; //You get the point

}

void Setup()
{
	gameOver = false;
	dir = STOP;
	// The snake will start at the middle of the screen.
	x = width / 2;
	y = height / 2;

	randomFruitPlacement();

	score = 0; // Score should be initialized from zero for reasons known to everyone.
}

void Draw()
{
	// To clear the sceen before the drawing.
	system("cls"); // cls is the windows cmd and powerShell command for clear screen.
				   //system("clear"); // In linux terminal and windows powerShell this command should be used instead.

				   // Top border
	for (int i = 0; i < width + 1; i++)
	{
		cout << "#";
	}

	cout << endl;

	/*
	To display the map
	*/
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}
			else
			{
				if (i == x && j == y)
					cout << "O";  // Prints the head which is denoted by a big O
				else if (i == fruitX && j == fruitY)
					cout << "*";   // Prints the fruit which is an asterisk in this case
				else
					cout << " ";
			}
			if (j == width - 1)
			{
				cout << "#";
			}
		}
		cout << endl;
	}

	// Bottom border
	for (int i = 0; i < width + 1; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << score << endl;
}

void Input()
{
	if (_kbhit()) // _kbhit() returns a boolean value. If keyboard key is pressed it will return true or else false.
	{
		switch (_getch()) // _getch() returns the value of the character that was pressed.
		{
		case 'a':
			dir = UP;
			break;
		case 'd':
			dir = DOWN;
			break;
		case 'w':
			dir = LEFT;
			break;
		case 's':
			dir = RIGHT;
			break;
		case 'x':
			gameOver = true;
			break;
		default:
			break;
		} // This logic is not good. Somehow my coordinates system has been switched. X is Y and Y is X. Idk why. Will find out later.
	}
}

void Logic()
{

	switch (dir)
	{
	case STOP:
		break;
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
		y--;
		break;
	default:
		break;
	}
	
	if (x > width || x < 0 || y > height || y < 0)
		gameOver = true;

	if (x == fruitX && y == fruitY)
	{
		score++;
		// Fruit will be randomly generated somewhere.
		fruitX = rand() % width; //Creates a random number from 0 to width-1
		fruitY = rand() % height; //You get the point
	}
}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(100); // Requires the windows.h header file. 
		// Sleep function may be implemented in the future? Who know? Not me for sure.
	}
	// Return statement always bottom
	return 0;
}

