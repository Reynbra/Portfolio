#include <iostream>
#include <vector>
#include <time.h>
#include "ReynoldsBHW3_Functions.h"
#include "ReynoldsBHW3_GridClass.h"
using namespace std;

int main()
{
	srand(time(NULL));
	Grid g;	
	int rowSize = 0;
	int columnSize = 0;
	int menuChoice = 0;
	bool done = false;
	

	cout << "Brandyn Reynolds"
		<< "Welcome! This program simulates the tabletop game Battleship.\n"
		<< endl;

		do {
			if (done != true) {

				displayInstructions();

				cout << "\nHere is what the game board looks like.\n" << endl;
				displayGrid();

				cout << "Player 1, please place your pieces on the board:" << endl;

				//setUpBoard();
				//playGame();

				cout << "Would you like to play again? If yes, enter 1.\n"
					<< "If you would like to quit, please enter 2.\n"
					<< endl;
				cin >> menuChoice;

				switch (menuChoice) {
					case 1:
						displayInstructions();
						break;

					case 2:
						done = true;
						//setting exit boolean to true for ending program function
						break;

					default:
						cout << "\nSorry, that's not a valid input.\n" << endl;
						//switch default output to user indicating an invalid input

				}//end switch
			}//end if menuChoice
		} while (done != true); //end of do while to repeat menu info and functionality


	cout << "Please enter the X value size: " << endl;
	cin >> rowSize;
	cout << "Please enter the Y value size: " << endl;
	cin >> columnSize;

	g.setRowSize(rowSize);
	g.setColumnSize(columnSize);
	
	g.vecA = new vector < int >[rowSize];
	g.vecB = new vector < int >[rowSize];
	g.vecC = new vector < int >[rowSize];


	//function calls
	//fillVectors(g.vecA, g.vecB, g.vecC, rowSize, columnSize);
	//compareVectors(g.vecA, g.vecB, g.vecC, rowSize, columnSize);
	//displayVectors(g.vecA, g.vecB, g.vecC, rowSize, columnSize);

	system("pause");
	return 0;
}