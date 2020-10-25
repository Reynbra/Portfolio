#include <iostream>
#include <string>
#include "Dealer.h"
using namespace std;

Dealer::Dealer()
{
	_dealerName = "";
	_dealerNumber = 0;
	_numberOfCars = 0;
}

Dealer::Dealer(string dName, int dNumber)
{
	this -> setDealerName(dName);
	this -> setDealerNumber(dNumber);
}

Car::Car()
{
	string _VIN = "";
	string _make = "";
	string _model = "";
	int _year = 0;
	double _price = 0.0;
}

Car::Car(string vVIN, string vMake, string vModel, int vYear, double vPrice)
{
	this -> setVIN(vVIN);
	this -> setMake(vMake);
	this -> setModel(vModel);
	this -> setYear(vYear);
	this -> setPrice(vPrice);
}
	
ostream & operator<<(ostream & out, Dealer _dealer)
{
	out << "Dealer Name: " << "\t\t" << _dealer._dealerName << endl;
	out << "Dealer Number: " << "\t\t" << _dealer._dealerNumber << endl;
	out	<< "Number of Cars: " << "\t" << _dealer._numberOfCars << "\n" << endl;
	return out;
}

ostream & operator<<(ostream & out, Car _car)
{
	out << "VIN: " << "\t" << _car._VIN << endl;
	out << "Make: " << "\t" << _car._make << endl;
	out	<< "Model: " << "\t" << _car._model << endl;
	out	<< "Year: " << "\t" << _car._year << endl;
	out	<< "Price: " << "\t" << _car._price << "\n" << endl;
	return out;
}

