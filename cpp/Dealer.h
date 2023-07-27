#ifndef DEALER_H
#define DEALER_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Car
{
private:
	string _VIN;
	string _make;
	string _model;
	int _year;
	double _price;

public:
	Car();
	Car(string vVIN, string vMake, string vModel, int vYear, double vPrice);
	string getVIN() { return _VIN; }
	string getMake() { return _make; }
	string getModel() { return _model; }
	int getYear() { return _year; }
	void setVIN(string &VIN) { _VIN = VIN; }
	void setMake(string &make) { _make = make; }
	void setModel(string &model) { _model = model; }
	void setYear(int &year) { _year = year; }
	void setPrice(double &price) { _price = price; }
	friend ostream &operator << (ostream &out, Car _car);
	//Print the VIN, Make, Model, Year, Price and Blank line for a specific car.
};

class Dealer
{
	private:
		string _dealerName;
		int _dealerNumber;
		Car* _carArrayPtr = nullptr;
		//pointer to a Dynamic Car Array
		//(Note : make sure this is set to nullptr)		
		int _numberOfCars;
		 
	public:
		Dealer();
		// Don’t forget to add a new car pointer when you use the Dealer default / constructor
		Dealer(string dName, int dNumber);		
		void setDealerName(string &dealerName) { _dealerName = dealerName; }
		void setDealerNumber(int &dealerNumber) { _dealerNumber = dealerNumber; }
		void setCarArrayPtr(Car *carArrayPtr) { _carArrayPtr = carArrayPtr; }
		//(This is where you use the new)
		void setNumberOfCars(int &numberOfCars) { _numberOfCars = numberOfCars; }
		//setter methods
		string getDealerName() { return _dealerName; }
		int getDealerNumber() { return _dealerNumber; }
		Car * getCarArrayPtr() { return _carArrayPtr; }
		int getNumberOfCars() { return _numberOfCars; }
		//getter methods
		friend ostream& operator << (ostream &out, Dealer _dealer);
		//Print the Dealer Name and Number and Blank line for a specific dealer.
};
#endif
