// cin.ignore(); - this skips one character of the input (n/)

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

void PrintMenu()
{
	cout << "Menu: " << endl;
	cout << "0 - Quit the tournament" << endl << "1 - Display all restaurants" << endl << "2 - Add a restaurant" << endl << "3 - Remove a restaurant" << endl 
		<< "4 - Shuffle the vector" << endl << "5 - Load a File" << endl << "6 - Begin the tournament" << endl;
}

void Display(vector<string>& restaurants)
{
	for (int i = 0; i < restaurants.size(); i++)
	{
		cout << restaurants[i];
		if (i != restaurants.size() - 1)
		{
			cout << ", ";
		}
		else
		{
			cout << endl;
		}
	}
}
void Add(vector<string>& restaurants)
{
	string new_restaurant = "";
	bool not_used = true;
	cout << "What restaurant would you like to add?" << endl;
	cin >> ws;
	getline(cin, new_restaurant);
	for (int i = 0; i < restaurants.size(); i++)
	{
		if (new_restaurant == restaurants[i])
		{
			not_used = false;
		}
	}
	if (not_used)
	{
		restaurants.push_back(new_restaurant);
		cout << "Restaurant was added" << endl;
	}
	else
	{
		cout << "Restaurant already exists" << endl;
	}
}
void Remove(vector<string>& restaurants)
{
	int index = 0;
	string restaurant = "";
	bool used = false;
	cout << "Which restaurant would you like to remove?" << endl;
	cin >> ws;
	getline(cin, restaurant);
	for (int i = 0; i < restaurants.size(); i++)
	{
		if (restaurant == restaurants[i])
		{
			used = true;
			index = i;
		}
	}
	if (used)
	{
		restaurants.erase(restaurants.begin() + index);
		cout << "Restaurant was removed" << endl;
	}
	else
	{
		cout << "Restaurant not found" << endl;
	}
}
void Shuffle(vector<string>& restaurants)
{


	/*
	Do not use any of the standard library functions (i.e. #include <algorithm>, vector swap). Random number generators are allowed (i.e. srand(), rand()).

Refer to the Notes at the bottom of the page for hints on how to shuffle a vector.

Once the vector has been shuffled, output "Restaurants are shuffled"

You must create a function to shuffle the restaurants.

You will not receive points for this section if you use any standard library functions or do not have a shuffle function.
	*/
}
void Load(vector<string>& restaurants)
{
	ifstream in_file;
	string name;
	cout << "Name?" << endl;
	cin >> name;
	in_file.open(name);
	if (in_file.fail())
	{
		cout << "File not found" << endl;
	}
	else
	{
		cout << "Opening..." << endl;
		restaurants.clear();
		cin.ignore();
		while (getline(in_file, name))
		{
			restaurants.push_back(name);
		}
	}

}
void Tournament(vector<string>& restaurants)
{
	vector<string> temp;
	int size = restaurants.size();
	int choice = 0;
	bool valid = false;
	for (int i = 0; i < size; i++)
	{
		if (pow(2, i) == restaurants.size())
		{
			valid = true;
		}
	}
	if (valid)
	{
		while (restaurants.size() > 1)
		{
			for (int i = 0; i < restaurants.size(); i += 2)
			{
				cout << "pick one" << endl;
				cout << restaurants[i] << " or " << restaurants[i + 1];
				cin >> choice;
				if (choice == 1)
				{
					temp.push_back(restaurants[i]);
				}
				else if (choice == 2)
				{
					temp.push_back(restaurants[i + 1]);
				}
				else
				{
					cout << "invalid" << endl;
					i = i - 2;
				}
			}
			restaurants = temp;
			temp.clear();
		}
		cout << "winner: " << restaurants[0] << endl;
		system("pause");
	}
}
int main()
{
	vector<string> restaurants = { "McDonald's", "Burger King", "Wendy's", "Chicken Express", "Ruby's", "China Buffet", "Waffle House", "Dairy Queen" };
	int menu_option = 1;
	const enum MENU{QUIT, DISPLAY, ADD, REMOVE, SHUFFLE, LOAD, TOURNAMENT};
	while (menu_option != QUIT)
	{
		// restaurants.push_back("name");
		//restaurants.erase(restaurants.begin() + numberLocatedInVector);
		//restaurants.at(i) OR restaurants[1] accessing at spot i
		//restaurants.size() = 
		PrintMenu();
		cin >> menu_option;
		if(menu_option == DISPLAY)
		{
			Display(restaurants);
		}
		else if (menu_option == ADD)
		{
			Add(restaurants);
		}
		else if (menu_option == REMOVE)
		{
			Remove(restaurants);
		}
		else if (menu_option == SHUFFLE)
		{
			Shuffle(restaurants);
		}
		else if (menu_option == LOAD)
		{
			Load(restaurants);
		}
		else if (menu_option == TOURNAMENT)
		{
			Tournament(restaurants);
			menu_option = 0;
		}
		else
		{
			cout << "Invalide input" << endl;
		}
	} 
	return 0;
}