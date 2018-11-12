/*
Caleb Hill, Section 2, calebleehill1993@gmail.com, ONE LATE DAY

Purpose: Help Uncle Jimmy keep inventory of his cars and money.

Input: Menu options, name of cars, color of cars, price of cars, name of file to load, name of file to save

Output: List inventory of cars (name, color, price), Current balance, Ask for information about car to buy, Ask for information about car to sell,
	Ask for name of car to paint, Ask for name of car to save.

*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Car.h"
#include <iomanip>

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
	int CurrentNumber = 0;
	cout << "Input car information." << endl << "Name: ";
	cin >> NewName;
	if (inventory.size() == 0)
	{
		cout << "Color: ";
		cin >> NewColor;
		cout << "Price: ";
		cin >> NewPrice;
		if (NewPrice <= balance)
		{
			inventory.push_back(Car(NewName, NewColor, NewPrice));
			balance -= NewPrice;
			cout << NewName << " was purchased!" << endl;
		}
		else
		{
			cout << "The car costs too much too buy." << endl;
		}
	}
	else
	{
		CurrentNumber = inventory.size() - 1;
		for (int i = 0; i < inventory.size(); i++)
		{
			if (inventory[i].GetName() == NewName)
			{
				CurrentNumber -= 1;
				cout << "You already own that car." << endl;
			}
			else if (inventory[i].GetName() != NewName && CurrentNumber == i)
			{
				cout << "Color: ";
				cin >> NewColor;
				cout << "Price: ";
				cin >> NewPrice;
				if (NewPrice <= balance)
				{
					inventory.push_back(Car(NewName, NewColor, NewPrice));
					balance -= NewPrice;
					cout << NewName << " was purchased!" << endl;
				}
				else
				{
					cout << "The car costs too much too buy." << endl;
				}
			}
		}
	}
}

void SellCar(vector<Car>& inventory, double& balance)
{
	string CarToSell;
	bool CarSold = false;
	if (inventory.size() == 0)
	{
		cout << "You have no cars in your inventory." << endl;
	}
	else
	{
		cout << "Which car would you like to sell? ";
		cin >> CarToSell;
		for (int i = 0; i < inventory.size(); i++)
		{
			if (inventory[i].GetName() == CarToSell && !CarSold)
			{
				balance += inventory[i].GetPrice();
				cout << inventory[i].GetColor() << " " << CarToSell << " has been sold for $" << inventory[i].GetPrice() << "." << endl;
				inventory.erase(inventory.begin() + i);
				CarSold = true;
			}
		}
		if (!CarSold)
		{
			cout << "That car was not found." << endl;
		}
	}
}

void PaintCar(vector<Car>& inventory)
{
	string SelectedCar;
	string NewColor;
	cout << "Which car would you like to paint?" << endl;
	cin >> SelectedCar;
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i].GetName() == SelectedCar)
		{
			cout << "What color would you like your car painted?" << endl;
			cin >> NewColor;
			inventory[i].Paint(NewColor);
			cout << SelectedCar << " was painted " << NewColor << " and the value increased by $1000." << endl;
		}
		else
		{
			cout << "Car was not found." << endl;
		}
	}
}
void LoadFile(vector<Car>& inventory, double& balance)
{
	ifstream InFile;
	string FileName;
	double AddedBalance = 0;
	string NewName;
	string NewColor;
	double NewPrice = 0;
	cout << "What is the name for the file you'd like to load? ";
	cin >> FileName;
	InFile.open(FileName);
	if (InFile.fail())
	{
		cout << "That file was not found." << endl;
	}
	else
	{
		cout << "Loading " << FileName << endl;
		InFile >> AddedBalance;
		balance += AddedBalance;
		while (InFile >> NewName >> NewColor >> NewPrice)
		{
			inventory.push_back(Car(NewName, NewColor, NewPrice));
		}
	}
}

void SaveFile(vector<Car> inventory,double balance)
{
	ofstream OutFile;
	string FileName;
	cout << "What would you like to name your file? ";
	cin >> FileName;
	OutFile.open(FileName);
	OutFile << balance << endl;
	for (int i = 0; i < inventory.size(); i++)
	{
		OutFile << inventory[i].GetName() << " " << inventory[i].GetColor() << " " << inventory[i].GetPrice() << " " << endl;
	}
	cout << "File Saved as " << FileName << ".";
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
	const int SET_PRECISION = 2;
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
			cout << "$" << fixed << setprecision(SET_PRECISION) << balance << endl;
		}
		if (menu_option == BUY_A_CAR)
		{
			BuyCar(inventory, balance);
		}
		if (menu_option == SELL_A_CAR)
		{
			SellCar(inventory, balance);
		}
		if (menu_option == PAINT_A_CAR)
		{
			PaintCar(inventory);
		}
		if (menu_option == LOAD_FILE)
		{
			LoadFile(inventory, balance);
		}
		if (menu_option == SAVE_FILE)
		{
			SaveFile(inventory, balance);
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