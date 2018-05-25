// Simple Snake Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score; // x, y for coordinates, fruitX, fruitY for fruit coordinates and score for score. 
enum eDirection
{
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
// This is for tracking the direction. This is an enumeration. (https://msdn.microsoft.com/en-us/library/2dzy4k6e.aspx)
eDirection dir;

void Setup()
{
	gameOver = false;
	dir = STOP;
	// The snake will start at the middle of the screen.
	x = width / 2;
	y = height / 2;

	// Fruit will be randomly generated somewhere.
	fruitX = rand() % width; //Creates a random number from 0 to width-1
	fruitY = rand() % height; //You get the point

							  // Score should be initialized from zero for reasons known to everyone.
	score = 0;
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
}

void Input()
{

}

void Logic()
{

}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		// Sleep function may be implemented in the future? Who know? Not me for sure.
	}
	// Return statement always bottom
	return 0;
}

