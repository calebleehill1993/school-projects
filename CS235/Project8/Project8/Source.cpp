#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Car.h"

using namespace std;

void PrintMenu()
{
	cout << endl << "MENU" << endl << "1 - Show Current Inventory" << endl << "2 - Show Current Balance" << endl << "3 - Buy a Car" << endl
		<< "4 - Sell a Car" << endl << "5 - Paint a Car" << endl << "6 - Load File" << endl << "7 - Save File" << endl << "8 - Quit Program" << endl;
}

void ShowInventory(vector<Car> inventory)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		cout << inventory[i].ToString();
	}
}

void BuyCar(vector<Car>& inventory, double& balance)
{
	string NewName;
	string NewColor;
	double NewPrice = 0;

	cin >> NewName >> NewColor >> NewPrice;
	cout << "^^^";
	Car myCar(NewName, NewColor, NewPrice);
	cout << "+";
	while (true) {};
	inventory.push_back(myCar);
	cout << "here";
}

int main()
{
	double balance = 10000;
	int cars = 0;
	int menu_option = 0;
	const int SHOW_CURRENT_INVENTORY = 1;
	const int SHOW_CURRENT_BALANCE = 2;
	const int BUY_A_CAR = 3;
	const int SELL_A_CAR = 4;
	const int PAINT_A_CAR = 5;
	const int LOAD_FILE = 6;
	const int SAVE_FILE = 7;
	const int QUIT_PROGRAM = 8;
	vector<Car> inventory;

	while (menu_option != QUIT_PROGRAM)
	{
		PrintMenu();
		cin >> menu_option;

		if (menu_option == SHOW_CURRENT_INVENTORY)
		{
			ShowInventory(inventory);
		}
		if (menu_option == SHOW_CURRENT_BALANCE)
		{
			cout << SHOW_CURRENT_BALANCE;
		}
		if (menu_option == BUY_A_CAR)
		{
			BuyCar(inventory, balance);
		}
		if (menu_option == SELL_A_CAR)
		{
			cout << SELL_A_CAR;
		}
		if (menu_option == PAINT_A_CAR)
		{
			cout << PAINT_A_CAR;
		}
		if (menu_option == LOAD_FILE)
		{
			cout << LOAD_FILE;
		}
		if (menu_option == SAVE_FILE)
		{
			cout << SAVE_FILE;
		}
		if (menu_option == QUIT_PROGRAM)
		{
			return 0;
		}
		if (menu_option < SHOW_CURRENT_INVENTORY || menu_option > QUIT_PROGRAM)
		{
			cout << "Not a good input. Try again" << endl;
		}
	}
}

/*
in_file >> NewBalance;
while (in_file >> NewName >> NewColor >> NewPrice
{
		inventory.push_back(Car());
}
*/