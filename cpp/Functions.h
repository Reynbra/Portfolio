#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Dealer.h"
using namespace std;

void readDlrsAndCars(ifstream &infile, int &currentSize, vector<Dealer> &d);
void displayDlrs(vector<Dealer> &d);
void displayCarsByDlrNum(ifstream &infile, int &currentSize, vector<Dealer> &d);
void addCarByDlrNum(ifstream &infile, int &currentSize, vector<Dealer> &d);
//void sortCarsByDlrNum(ifstream &infile, vector<Dealer> &d, Car carArray[]);
//void writeoutDlrsAndCars(ifstream &infile, ostream &outfile, int currentSize, vector<Dealer> &d, Car carArray[]);

void readDlrsAndCars(ifstream &infile, int &currentSize, vector<Dealer> &d)
{
	Dealer tempDealer;
	string dName = "", carVIN = "", make = "", model = "";
	int dNum = 0, numCars = 0, year = 0;
	double price = 0.0;
	Car *carArray;
	Car car;
	int dealers = 0;

	if (infile.fail())
	{
		cerr << "Unable to read from file. File.Open() failed\n";
		//output to make user aware of the error regarding opening the file and the filling array.
	}
	while (!infile.eof())
	//while (dealers < 3)
	{
		getline(infile, dName);
		infile >> dNum >> numCars;
		tempDealer.setDealerName(dName);
		tempDealer.setDealerNumber(dNum);
		tempDealer.setNumberOfCars(numCars);
		
		carArray = new Car[numCars];
		infile.ignore();

		for (int i = 0; i < numCars; i++)
		{
			getline(infile, carVIN);
			car.setVIN(carVIN);
			getline(infile, make);
			car.setMake(make);
			getline(infile, model);
			car.setModel(model);
			infile >> year;
			car.setYear(year);
			infile >> price;
			car.setPrice(price);
			carArray[i] = car;
			infile.ignore();
		}
		tempDealer.setCarArrayPtr(carArray);
		d.push_back(tempDealer);
		dealers++;
	}
}

void displayDlrs(vector<Dealer> &d)
{
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i];
	}
}

void displayCarsByDlrNum(ifstream &infile, int &currentSize, vector<Dealer> &d)
{
	int dNum = 0;
	
	cout << "Please enter the dealer number:\n" << endl;
	cin >> dNum;

	for (int i = 0; i < d.size(); i++)
	{
		if (d[i].getDealerNumber() == dNum)
		{
			for (int j = 0; j < d[i].getNumberOfCars(); j++)
			{
				cout << d[i].getCarArrayPtr()[j];
			}				
		}
	}//for loop
}

void addCarByDlrNum(ifstream &infile, int &currentSize, vector<Dealer> &d)
{
	//Function will allow user to add a car to the array of cars using the dealer number.
	string vin, make, model;
	int year;
	double price;
	Car carToAdd;
	int dNum = 0;
			
		cout << "Please enter the dealer number you would like to add a car to:\n" << endl;
		cin >> dNum;
		cin.ignore();
		cout << "Please enter the new car's VIN number:\n" << endl;
		getline(cin, vin);
		carToAdd.setVIN(vin);
		cout << "Please enter the new car's Make:\n" << endl;
		getline(cin, make);
		carToAdd.setMake(make);
		cout << "Please enter the new car's Model:\n" << endl;
		getline(cin, model);
		carToAdd.setModel(model);
		cout << "Please enter the new car's Year:\n" << endl;
		cin >> year;
		carToAdd.setYear(year);
		cout << "Please enter the new car's Price:\n" << endl;
		cin >> price;
		carToAdd.setPrice(price);
		
		for (int i = 0; i < d.size(); i++)
		{
			if (d[i].getDealerNumber() == dNum)
			{
				Car* c = d[i].getCarArrayPtr();
				Car* newCars;
				int numCars = d[i].getNumberOfCars();
				newCars = new Car[numCars + 1];
				
				for (int j = 0; j < numCars; j++)
				{
					newCars[j] = c[j];
				}

				newCars[numCars] = carToAdd;
				d[i].setCarArrayPtr(newCars);
				int newNumberOfCars = numCars + 1;
				d[i].setNumberOfCars(newNumberOfCars);
			}
		}
		//Print out of instructions to user and capturing input
}
//sortCarsByDlrNum(ifstream &infile, vector<Dealer> &d, Car carArray[]) //EXTRA CREDIT
//{
//	//Function will allow the users to sort the cars within the array by the dealer number.
//	int maxElement, index, arrayMaxElement, arrayIndex, makeOrModel;
//	Dealer tempDealer;
//
//
//	for (maxElement = carArray.size() - 1; maxElement > 0; maxElement--)
//	{
//		for (index = 0; index < maxElement; index++)
//		{
//			if (dealerVector[index].getDealerNumber() > dealerVector[index + 1].getDealerNumber())
//			{
//				tempDealer = dealerVector[index] = dealerVector[index + 1];
//				dealerVector[index + 1] = tempDealer;
//			}//if
//		}//for
//	}//for bubbleSort
//	int arrayMaxElement, arrayIndex;
//
//	cout << "Would like to sort the cars by make or model?\n"
//		<< "Enter 1 if you would like to sort by make:\n"
//		<< "Enter 2 if you would like to sort by model:\n" << end;
//	cin >> makeOrModel;
//
//	do
//	{
//		if (makeOrModel == 1)
//		{
//			for (arrayMaxElement = currentSize - 1; arrayMaxElement > 0; arrayMaxElement--)
//			{
//				for (arrayIndex = 0; arrayIndex < arrayMaxElement; arrayIndex++)
//				{
//					if (carArray[arrayIndex].vMake > carArray[arrayIndex + 1].vMake)
//						swap(carArray[arrayIndex].vMake, carArray[arrayIndex + 1].vMake);
//
//				}//for
//			}//for
//		}//if
//		else if (makeOrModel == 2)
//		{
//			for (arrayMaxElement = currentSize - 1; arrayMaxElement > 0; arrayMaxElement--)
//			{
//				for (arrayIndex = 0; arrayIndex < arrayMaxElement; arrayIndex++)
//				{
//					if (carArray[arrayIndex].vModel > carArray[arrayIndex + 1].vModel)
//						swap(carArray[arrayIndex].vModel, carArray[arrayIndex + 1].vModel);
//
//				}//for
//			}//for
//		}//if
//		else
//		{
//			cout << "Sorry, that's not a valid input.\n"
//				<< "Enter 1 if you would like to sort by make:\n"
//				<< "Enter 2 if you would like to sort by model:\n" << end;
//		}
//	} while (makeOrModel != 1 || makeOrModel != 2)
//
//	void swap(int&a, int &b)
//	{
//		int temp = a;
//		a = b;
//		b = temp;
//	}
//	void swap(string &a, string &b)
//	{
//		string temp = a;
//		a = b;
//		b = temp;
//	}
//}
//writeoutDlrsAndCars(ostream &outfile, int currentSize, vector<Dealer> &d, Car carArray[])
//{	
//	//Function will allow user to print the dealer and car information out to the designated output file
//	//using methods utilized by my PA2 program.
//	if (currentSize == 0)
//	{
//		infile.open("dealerInfo.txt");
//		readDlrsAndCars(infile, currentSize, dealerVector);
//	}//if statement ensures that the array has been properly filled for functionality
//
//	for (int i = 0; i < size.&d; i++)
//	{
//
//	}
//	for (int i = 0; i < currentSize; i++)
//	{
//		outfile << "Car Info: " << i << endl;
//		outfile << "\t" << carArray[i].vMake << endl;
//		outfile << "\t" << carArray[i].vModel << endl;
//		//for loop writes out the contents of the array of structs into the output.txt file.
//	}
//	outfile.close();
//	//closing of file
//	cout << "\nYour output file has now been created.\n" << endl;
//	//Print out to user to show that the function has completed successfully
//	break;
//	//break ensures infinite loop does not occur
//}
#endif