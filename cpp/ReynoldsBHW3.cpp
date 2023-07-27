#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Grid 
{
private:
	int rowSize;
	int columnSize;
	int randomFill;
	//private member variables used for 2D vector sizing
public:
	int getRowSize(int tempRowSize) 
		{ 
			rowSize = tempRowSize; 
			return rowSize;
		}
	//Accessor/mutator member function for rowSize variable
	int getColumnSize(int tempColumnSize) 
		{ 
			rowSize = tempColumnSize; 
			return columnSize; 
		}
	//Accessor/mutator member function for columnSize variable

	vector< int > *vecA;
	vector< int > *vecB;
	vector< int > *vecC;
	//vector initialized with pointers for dynamic memory allocation
};

int main()
{
	srand(time(NULL));
	//seeding of random number generation
	Grid g;
	//Grid class object for accessing Grid class members
	int rowSize = 0, columnSize = 0;
	//initialization and declaration of X and Y grid values

	cout << "Please enter the X value for grid sizing: " << endl;
	cin >> rowSize;
	cout << "Please enter the Y value for grid sizing: " << endl;
	cin >> columnSize;
	//Prompting user to enter the row and column size for grid and capturing inputs for both

	g.getRowSize(rowSize);
	g.getColumnSize(columnSize);
	//setting and getting row/column sizes for use with grid class and vectors

	g.vecA = new vector < int >[rowSize];
	g.vecB = new vector < int >[rowSize];
	g.vecC = new vector < int >[rowSize];
	//Dynamic allocation of vectors using grid class object and rowsize variable to establish 1D vector sizing for each

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			g.vecA[i].push_back(0);
			g.vecB[i].push_back(0);
			g.vecC[i].push_back(0);
		}

	}
	//Using nested for loops to push back second dimension into each vector. Vectors are also being initialized with zeros.

	int randomFill = ((rowSize*columnSize) / 3);
	//Establishing one third of the size of the vector, which will then be the amount to which the vectors are filled with randomly generated numbers between 1 or 0.

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
	//Filling 1/3 of A and B vectors with randomly generated 1s or 0s based on modulus of row and column sizes for X and Y values.


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
	//Using nested for loops with if/else statement to fill C vector with values of 1 where they are found to have corresponding postions within A and B vectors indicies.

	cout << "Grid A: " << endl;

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			cout << g.vecA[i][j] <<  " ";
	
		}
		cout << endl;
	}

	cout << "Grid B: " << endl;

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			cout << g.vecB[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Grid C: " << endl;
	
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			cout << g.vecC[i][j] << " ";
		}
		cout << endl;
	}
	//Nested for loops print out each vector with formatting including which vector(grid) it is and ensuring that grids
	//are displayed in matrix style for ease of understanding contents of each and overlap of 1 values.

	return 0;
}