#include <iostream>
#include <vector>
#include "ReynoldsBHW3_GridClass.h"
using namespace std;

Grid::Grid()
{
	_rowSize = 0;
	_columnSize = 0;
	_randomFill = 0;
}

//Grid::Grid(int rSize, int cSize) 
//{
//	this -> setRowSize(rSize);
//	this ->	setColumnSize(cSize);
//}
