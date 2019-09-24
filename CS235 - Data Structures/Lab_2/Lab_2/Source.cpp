/*
Caleb Hill, Section 2, calebleehill1993@gmail.com

Purpose: Calculate how much pizza to buy for BYUSA events

Input:

	Number of people eating

	how much tip to pay

Output:

	Number of large, medium, and small pizzas needed

	Total area of pizza for all guests

	Total area of pizza for each individual (average)

	Total cost including tip

TEST CASES

Test 1:

Input: People: 11, Tip: 10%

Expected Output: 1 large, 1 medium, 1 small, Sq in total: 628.318, Sq in per guest: 57.1198, Cost: $37

Actual Output: 1 large, 1 medium, 1 small, Sq in total: 628.318, Sq in per guest: 57.1198, Cost: $37

Test 2:

Input: People: 4, Tip: 0%

Expected Output: 0 large, 1 medium, 1 small, Sq in total: 314.159, Sq in per guest: 78.5397, Cost: $19

Actual Output: 0 large, 1 medium, 1 small, Sq in total: 314.159, Sq in per guest: 78.5397, Cost: $19

Test 3:

Input: People: 452, Tip: 15%

Expected Output: 64 large, 1 medium, 1 small, Sq in total: 20420.3, Sq in per guest: 45.1777, Cost: $1102

Actual Output: 64 large, 1 medium, 1 small, Sq in total: 20420.3, Sq in per guest: 45.1777, Cost: $1102
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	//CONSTANTS
	const int HEAD_COUNT_FOR_LARGE = 7;
	const int HEAD_COUNT_FOR_MEDIUM = 3;
	const int HEAD_COUNT_FOR_SMALL = 1;
	const int DIAMETER_OF_LARGE = 20;
	const int DIAMETER_OF_MEDIUM = 16;
	const int DIAMETER_OF_SMALL = 12;
	const double PI = 3.14159;
	const double LARGE_PIZZA_PRICE = 14.68;
	const double MEDIUM_PIZZA_PRICE = 11.48;
	const double SMALL_PIZZA_PRICE = 7.28;

	//VARIABLES
	int number_of_guests = 0;
	int number_of_large_pizzas = 0;
	int number_of_medium_pizzas = 0;
	int number_of_small_pizzas = 0;
	int total_cost = 0;
	double total_area_for_all_pizzas = 0;
	double area_per_guest = 0;
	double tip = 0;
	double total_cost_of_pizzas = 0;
	
	//START
	cout << "Please enter the number of guests: ";

	cin >> number_of_guests;

	number_of_large_pizzas = number_of_guests / HEAD_COUNT_FOR_LARGE;

	number_of_medium_pizzas = (number_of_guests % HEAD_COUNT_FOR_LARGE) / HEAD_COUNT_FOR_MEDIUM;

	number_of_small_pizzas = ((number_of_guests % HEAD_COUNT_FOR_LARGE) % HEAD_COUNT_FOR_MEDIUM) / HEAD_COUNT_FOR_SMALL;

	cout << endl << number_of_large_pizzas << " large pizza(s), ";

	cout << number_of_medium_pizzas << " medium pizza(s), and ";

	cout << number_of_small_pizzas << " small pizza(s) will be needed." << endl << endl;

	total_area_for_all_pizzas = PI * (pow(DIAMETER_OF_LARGE / 2, 2) * number_of_large_pizzas + pow(DIAMETER_OF_MEDIUM / 2, 2)
		* number_of_medium_pizzas + pow(DIAMETER_OF_SMALL / 2, 2) * number_of_small_pizzas);

	cout << "A total of " << total_area_for_all_pizzas << " square inches of pizza will be purchased (";

	area_per_guest = total_area_for_all_pizzas / number_of_guests;

	cout << area_per_guest << " per guest)." << endl << endl
		<< "Please enter the tip as a percentage (i.e. 10 means 10%): ";

	cin >> tip;

	total_cost_of_pizzas = number_of_large_pizzas * LARGE_PIZZA_PRICE + number_of_medium_pizzas * 
		MEDIUM_PIZZA_PRICE + number_of_small_pizzas * SMALL_PIZZA_PRICE;

	total_cost = (1 + tip / 100) * total_cost_of_pizzas + 0.5;

	cout << endl << "The total cost of the event will be: $" << total_cost << endl << endl;

	system("pause");

	return 0;
}