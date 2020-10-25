#ifndef REYNOLDSHW3_FUNCTIONS_H
#define REYNOLDSHW3_FUNCTIONS_H
#include <vector>
#include <iostream>
#include "ReynoldsBHW3_GridClass.h"
using namespace std;

void fillVectors(vector< int > &vecA, vector< int > &vecB, vector< int > &vecC, int rowSize, int columnSize);
void compareVectors(vector< int > &vecA, vector< int > &vecB, vector< int > &vecC, int rowSize, int columnSize);
void displayVectors(vector< int > &vecA, vector< int > &vecB, vector< int > &vecC, int rowSize, int columnSize);
void displayGrid();
void displayInstructions();

void fillVectors(vector< int > &vecA, vector< int > &vecB, vector< int > &vecC, int rowSize, int columnSize)
{
	Grid g;
	g.vecA = new vector < int >[rowSize];
	g.vecB = new vector < int >[rowSize];
	g.vecC = new vector < int >[rowSize];

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			g.vecA[i].push_back(0);
			g.vecB[i].push_back(0);
			g.vecC[i].push_back(0);
		}
	}
}

void compareVectors(vector< int > &vecA, vector< int > &vecB, vector< int > &vecC, int rowSize, int columnSize)
{
	Grid g;
	g.vecA = new vector < int >[rowSize];
	g.vecB = new vector < int >[rowSize];
	g.vecC = new vector < int >[rowSize];

	int randomFill = ((rowSize*columnSize) / 3);
	
	for (int i = 0; i < randomFill; i++)
	{
		int fillValA = rand() % rowSize;
		int fillValB = rand() % columnSize;
		g.vecA[fillValA][fillValB] = 1;
	}

	for (int i = 0; i < randomFill; i++)
	{
		int fillValA = rand() % rowSize;
		int fillValB = rand() % columnSize;
		g.vecB[fillValA][fillValB] = 1;
	}


	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			if ((g.vecA[i][j] == 1 && g.vecB[i][j]) == 1)
			{
				g.vecC[i][j] = 1;
			}

			else
				g.vecC[i][j] = 0;
		}
	}

	//displayVectors(vecA, vecB, vecC, rowSize, columnSize);
}

void displayVectors(vector< int > &vecA, vector< int > &vecB, vector< int > &vecC, int rowSize, int columnSize)
{
	Grid g;
	g.vecA = new vector < int >[rowSize];
	g.vecB = new vector < int >[rowSize];
	g.vecC = new vector < int >[rowSize];

	//displaying vector contents
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			cout << g.vecA[i][j] << " ";
		
		}
		cout << endl;
	}

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			cout << g.vecB[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			cout << g.vecC[i][j] << " ";
		}
		cout << endl;
	}
}

void displayGrid()
{
	//Displays structure of grid to users to visualize the game board.
	cout
		<< "     A   B   C   D   E   F   G   H   I   J  \n"
		<< "   _________________________________________\n"
		<< " 1 |   |   |   |   |   |   |   |   |   |   |\n"
		<< "   -----------------------------------------\n"
		<< " 2 |   |   |   |   |   |   |   |   |   |   |\n"
		<< "   -----------------------------------------\n"
		<< " 3 |   |   |   |   |   |   |   |   |   |   |\n"
		<< "   -----------------------------------------\n"
		<< " 4 |   |   |   |   |   |   |   |   |   |   |\n"
		<< "   -----------------------------------------\n"
		<< " 5 |   |   |   |   |   |   |   |   |   |   |\n"
		<< "   -----------------------------------------\n"
		<< " 6 |   |   |   |   |   |   |   |   |   |   |\n"
		<< "   -----------------------------------------\n"
		<< " 7 |   |   |   |   |   |   |   |   |   |   |\n"
		<< "   -----------------------------------------\n"
		<< " 8 |   |   |   |   |   |   |   |   |   |   |\n"
		<< "   -----------------------------------------\n"
		<< " 9 |   |   |   |   |   |   |   |   |   |   |\n"
		<< "   -----------------------------------------\n"
		<< "10 |   |   |   |   |   |   |   |   |   |   |\n"
		<< "   -----------------------------------------\n"
		<< endl;
}
void displayInstructions()
{
	cout
		<< "\n|---------------------------------------------Instructions---------------------------------------------|\n"
		<< "First, a print out of the game board to show you where you can place your pieces.\n\n"
		<< "Each player is provided with two boards: One showing your pieces and one for your guesses.\n"
		<< "The pieces you can use are:\n"
		<< "Carrier    (occupies 5 squares)\n"
		<< "Battleship (occupies 4 squares)\n"
		<< "Cruiser    (occupies 3 squares)\n"
		<< "Submarine  (occupies 3 squares)\n"
		<< "Destroyer  (occupies 2 squares)\n\n"
		<< "These pieces can be placed horizontally or vertically on the 10 by 10 grid.\n"
		<< "Each turn, the player will have their boards shown.\n"
		<< "You will then choose the location you'd like to attack. A hit or miss will be displayed and recorded.\n"
		<< "The winner will be determined when they have destroyed all of the other player's ships.\n"
		<< endl;
}

#endif
