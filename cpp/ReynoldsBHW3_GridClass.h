#ifndef REYNOLSDBW3_GRIDCLASS_H
#define REYNOLSDBW3_GRIDCLASS_H
#include <iostream>
#include <vector>
using namespace std;

class Grid
{
private:

	int _rowSize;
	int _columnSize;
	int _randomFill;

public:

	Grid();
	/*Grid(int rSize, int cSize);*/

	void setRowSize(int &rowSize) { _rowSize = rowSize; }
	void setColumnSize(int &columnSize) { _columnSize = columnSize; }

	int getRowSize() { return _rowSize; }
	int getColumnSize() { return _columnSize; }

	vector< int > *vecA;
	vector< int > *vecB;
	vector< int > *vecC;
};

#endif