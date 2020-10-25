/* Brandyn:
Class: CSCI 1411-00X
Description: [This program is intented to prompt the user to enter information regarding their name and desired pay, then prints this information. Afterwards, it calculates their inputted information to produce a gross pay amount and their net pay after taxes have been accounted for, then also prints this information for the user.]

Lab Partner: Nicholas Stanford
Status: sucessfully compiled and run on csegrid */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Initialization of variables used in out, algorithms, and user inputted first/last name
	double hourlyPayRate, weekOneHours, weekTwoHours, grossPay;
	double socialSecTax, fedIncomTax, stateIncomTax, netPay;
	string firstName, lastName;

	//Prompting user to enter information necessary for output and algorithms
	cout << "Enter your first name." << endl;
	cin >> firstName;
	cout << "Enter your last name." << endl;
	cin >> lastName;
	cout << "Enter your hourly pay rate." << endl;
	cin >> hourlyPayRate;
	cout << "Enter your hours worked for week one." << endl;
	cin >> weekOneHours;
	cout << "Enter your hours worked for week two." << endl;
	cin >> weekTwoHours;

	//Outputing input information to user with proper formatting
	cout << firstName << " " << lastName << ", your hourly pay rate is\t\t\t" 
	<< hourlyPayRate << " " << "\tdollars";
	cout << "\nYour hours worked for week one are\t\t\t\t" << weekOneHours << " " << "\thours\n";
	cout << "Your hours worked for week two are\t\t\t\t" << weekTwoHours << " " << "\thours" << endl; 
	
	//Beginning of tax algorithms with subsequent pay outputs
	grossPay = (hourlyPayRate * weekOneHours) + (hourlyPayRate * weekTwoHours);
	cout << "Your gross pay is\t\t\t\t\t\t" << grossPay << " " << "\tdollars" << endl;
	
	socialSecTax = grossPay - (grossPay * 0.06);
	cout << "Your net pay after Social Security tax has been removed is\t" 
	<< socialSecTax << " " << "\tdollars" << endl; 
	
	fedIncomTax = grossPay - (grossPay * 0.14);
	cout << "Your net pay after Federal Income Tax has been removed is\t" 
	<< fedIncomTax << " " << "\tdollars" << endl;
	
	stateIncomTax = grossPay - (grossPay * 0.05);
	cout << "Your net pay after State Income Tax has been removed is\t\t" 
	<< stateIncomTax << " " << "\tdollars" <<  endl;
	
	netPay = grossPay - (grossPay * 0.25);
	cout << "Your net-take-home-pay is\t\t\t\t\t" << netPay << " " << "\tdollars" << endl;
	
	return 0;
} 
