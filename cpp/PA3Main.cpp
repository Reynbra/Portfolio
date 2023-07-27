/* Name: Brandyn Reynolds
Class: CSCI 1411-002
Description: [This program allows the user to perform a multitude of funcitons regarding
			  lists of car dealers, their cars, and other pieces of information you'd expect
			  regarding a dealership.]
Lab Partner: Devon K.
Status: Does not sucessfully compile or run, is only a rough outline and with some functional elements.*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Dealer.h"
#include "Functions.h"
using namespace std;

int main()
{
	int menuChoice = 0, currentSize = 0;
	//Initialization/declaration of menu choice input

	bool done = false;

	//Initialization/declaration of the array's max size used when building it
	vector<Dealer> dealerVector(currentSize);
	
	ifstream infile("CarInfo.txt");	
	ofstream outfile("output.txt");
	
	cout << "\nBrandyn Reynolds 108963565\n";
	//Print out of name and student ID
	do
	{
		if (infile.is_open())
		{
			cout << "Error opening file" << endl;
		}
			//Validates that user would like to continue before
			//before giving a printout of menu choices and instructions
		
			cout << "\n Please enter the corresponding number "
				<< "for the option you wish to choose.\n"
				<< "\n1. Read Dealers and Cars from file\n"
				<< "\n2. Display Dealers\n"
				<< "\n3. Choose a Dealer Number, Display Cars\n"
				<< "\n4. Choose a Dealer Number, Add Car\n"
				<< "\n5. Choose a Dealer, Sort cars by VIN (EXTRA CREDIT)\n"
				<< "\n6. Write Dealers and Cars to file (EXTRA CREDIT)\n"
				<< "\n7. Quit and Exit\n"
				<< endl;
			cin >> menuChoice;
			//Print out of instructions
			//Stores user choice as menuChoice

			switch (menuChoice)
				{
				case 1:
					infile.open("E:/Spring 2018/CSCI 1410 Class/CarInfo.txt");
					//Call to function that sorts responses which will before 
					readDlrsAndCars(infile, currentSize, dealerVector);
					//call to readDlrsAndCars function
					break;

				case 2:
					displayDlrs(dealerVector);
					//call to displayDlrs function
					break;

				case 3:
					displayCarsByDlrNum(infile, currentSize, dealerVector);
					//call to displayDlrsByNum function
					break;

				case 4:
					addCarByDlrNum(infile, currentSize, dealerVector);
					//call to addCarByDlrNum function
					break;

				case 5: //Extra Credit
					//sortCarsByDlrNum(dealerVector, carArray, currentSize);
					//call to sortCarsByDlrNum function
				case 6: //Extra Credit
					//writeoutDlrsAndCars(outfile, currentSize);
					//call to writeoutDlrsAndCars function
				case 7: cout << "\nThank you for trying this program. Goodbye!\n" << endl;
					exit;
					break;

				default: cout << "\nSorry, that's not a valid input.\n" << endl;

				}//switch
			}//if menuChoice before switch
		} while (done != true);
	return 0;
}