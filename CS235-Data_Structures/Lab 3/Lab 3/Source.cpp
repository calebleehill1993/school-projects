/*
Caleb Hill, Section 2, calebleehill1993@gmail.com

Purpose: To help consumers purchase the car they want according to whether they want a car to save on fuel or to be cost effiecient.

Input: 
The estimated miles driven per year:
The estimated price of a gallon of gas during the 5 years of ownership:
The initial cost of a hybrid car:
The efficiency of the hybrid car in miles per gallon:
The estimated resale value (a dollar amount) for a hybrid after 5 years:
The initial cost of a non-hybrid car:
The efficiency of the non-hybrid car in miles per gallon:
The estimated resale value (a dollar amount) for a non-hybrid after 5 years:
The user's buying criterion, either minimized gas consumption or total cost (enter Gas or Total):

Output: 
For the Hybrid Car:
The total gallons of fuel consumed over 5 years:
The total cost of owning the car for 5 years:

For the NON-Hybrid Car:
The total gallons of fuel consumed over 5 years:
The total cost of owning the car for 5 years:

Which car is better to fit their needs based on Gas consumption or Total Cost

TEST CASES

Test 1

Input: 
The estimated miles driven per year: 20000
The estimated price of a gallon of gas during the 5 years of ownership: 2.50
The initial cost of a hybrid car: 34995
The efficiency of the hybrid car in miles per gallon: 54
The estimated resale value (a dollar amount) for a hybrid after 5 years: 15999
The initial cost of a non-hybrid car: 24995
The efficiency of the non-hybrid car in miles per gallon: 26
The estimated resale value (a dollar amount) for a non-hybrid after 5 years: 9995
The user's buying criterion, either minimized gas consumption or total cost (enter Gas or Total): Total

Output: 
For the Hybrid Car:
The total gallons of fuel consumed over 5 years: 1851.85
The total cost of owning the car for 5 years: 23625.63

For the NON-Hybrid Car:
The total gallons of fuel consumed over 5 years: 3846.15
The total cost of owning the car for 5 years: 24615.38

** The HYBRID Car is better than the NON-HYBRID Car when "Total" is the user's primary objective.

Test 2

Input:
The estimated miles driven per year: 5000
The estimated price of a gallon of gas during the 5 years of ownership: 3.49
The initial cost of a hybrid car: 44000
The efficiency of the hybrid car in miles per gallon: 61
The estimated resale value (a dollar amount) for a hybrid after 5 years: 39000
The initial cost of a non-hybrid car: 5000
The efficiency of the non-hybrid car in miles per gallon: 25
The estimated resale value (a dollar amount) for a non-hybrid after 5 years: 2000
The user's buying criterion, either minimized gas consumption or total cost (enter Gas or Total): Total

Output:
For the Hybrid Car:
The total gallons of fuel consumed over 5 years: 409.84
The total cost of owning the car for 5 years: 6430.33

For the NON-Hybrid Car:
The total gallons of fuel consumed over 5 years: 1000.00
The total cost of owning the car for 5 years: 6490.00

** The HYBRID Car is better than the NON-HYBRID Car when "Total" is the user's primary objective.

Test 3

Input:
The estimated miles driven per year: 50000
The estimated price of a gallon of gas during the 5 years of ownership: 2.10
The initial cost of a hybrid car: 60000
The efficiency of the hybrid car in miles per gallon: 50
The estimated resale value (a dollar amount) for a hybrid after 5 years: 10000
The initial cost of a non-hybrid car: 10000
The efficiency of the non-hybrid car in miles per gallon: 24
The estimated resale value (a dollar amount) for a non-hybrid after 5 years: 2500
The user's buying criterion, either minimized gas consumption or total cost (enter Gas or Total): Gas

Output:
For the Hybrid Car:
The total gallons of fuel consumed over 5 years: 5000.00
The total cost of owning the car for 5 years: 60500.00

For the NON-Hybrid Car:
The total gallons of fuel consumed over 5 years: 10416.67
The total cost of owning the car for 5 years: 29375.00

** The HYBRID Car is better than the NON-HYBRID Car when "Gas" is the user's primary objective.

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	//CONSTANTS
	const int YEARS_OF_CAR_OWNERSHIP = 5;

	//VARIABLES
	double miles_driven = 0;
	double price_of_gas_per_gallon = 0;
	double initial_cost_of_hybrid = 0;
	double hybrid_miles_per_gallon = 0;
	double hybrid_resale_value = 0;
	double initial_cost_of_nonhybrid = 0;
	double nonhybrid_miles_per_gallon = 0;
	double nonhybrid_resale_value = 0;
	double hybrid_total_fuel = 0;
	double nonhybrid_total_fuel = 0;
	double hybrid_total_cost = 0;
	double nonhybrid_total_cost = 0;
	string buying_criterion = "";
	


	//START
	cout << "The estimated miles driven per year: ";

	cin >> miles_driven;

	while (miles_driven < 1)
	{
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter: ";

		cin >> miles_driven;
	}

	cout << "The estimated price of a gallon of gas during the 5 years of ownership: ";

	cin >> price_of_gas_per_gallon;


	while (price_of_gas_per_gallon < 1)
	{
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter: ";

		cin >> price_of_gas_per_gallon;
	}

	cout << "The initial cost of a hybrid car: ";

	cin >> initial_cost_of_hybrid;


	while (initial_cost_of_hybrid < 1)
	{
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter: ";

		cin >> initial_cost_of_hybrid;
	}

	cout << "The efficiency of the hybrid car in miles per gallon: ";

	cin >> hybrid_miles_per_gallon;

	while (hybrid_miles_per_gallon < 1)
	{
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter: ";

		cin >> hybrid_miles_per_gallon;
	}

	cout << "The estimated resale value (a dollar amount) for a hybrid after 5 years: ";

	cin >> hybrid_resale_value;

	while (hybrid_resale_value < 1)
	{
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter: ";

		cin >> hybrid_resale_value;
	}

	cout << "The initial cost of a non-hybrid car: ";

	cin >> initial_cost_of_nonhybrid;

	while (initial_cost_of_nonhybrid < 1)
	{
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter: ";

		cin >> initial_cost_of_nonhybrid;
	}

	cout << "The efficiency of the non-hybrid car in miles per gallon: ";

	cin >> nonhybrid_miles_per_gallon;

	while (nonhybrid_miles_per_gallon < 1)
	{
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter: ";

		cin >> nonhybrid_miles_per_gallon;
	}

	cout << "The estimated resale value (a dollar amount) for a non-hybrid after 5 years: ";

	cin >> nonhybrid_resale_value;

	while (nonhybrid_resale_value < 1)
	{
		cout << "I'm sorry, you must enter a value bigger than zero. Please try again. Please enter: ";

		cin >> nonhybrid_resale_value;
	}

	cout << "The user's buying criterion, either minimized gas consumption or total cost (enter Gas or Total): ";

	cin >> buying_criterion;

	cout << setprecision(2) << fixed;

	hybrid_total_fuel = (miles_driven * YEARS_OF_CAR_OWNERSHIP) / hybrid_miles_per_gallon;

	hybrid_total_cost = hybrid_total_fuel * price_of_gas_per_gallon + initial_cost_of_hybrid - hybrid_resale_value;

	nonhybrid_total_fuel = (miles_driven * YEARS_OF_CAR_OWNERSHIP) / nonhybrid_miles_per_gallon;

	nonhybrid_total_cost = nonhybrid_total_fuel * price_of_gas_per_gallon + initial_cost_of_nonhybrid - nonhybrid_resale_value;

	cout << endl << "For the Hybrid Car: " << endl;

	cout << "The total gallons of fuel consumed over 5 years: " << hybrid_total_fuel << endl;

	cout << "The total cost of owning the car for 5 years: " << hybrid_total_cost << endl << endl;

	cout << "For the NON-Hybrid Car:" << endl;

	cout << "The total gallons of fuel consumed over 5 years: " << nonhybrid_total_fuel << endl;

	cout << "The total cost of owning the car for 5 years: " << nonhybrid_total_cost << endl << endl;

	if ((buying_criterion == "Total" && hybrid_total_cost < nonhybrid_total_cost) || (buying_criterion == "Gas" && hybrid_total_fuel < nonhybrid_total_fuel))
	{
		cout << "** The HYBRID Car is better than the NON-HYBRID Car when \"" << buying_criterion << "\" is the user's primary objective." << endl;
	}
	else
	{
		cout << "** The NON-HYBRID Car is better than the HYBRID Car when \"" << buying_criterion << "\" is the user's primary objective." << endl;
	}

	cout << endl;

	system("pause");

	return 0;
}