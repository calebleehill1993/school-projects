#include<iostream>

#include<string>

#include<sstream>

#include<vector>



using namespace std;

void OptionsPrint() {

	cout << "Please select one of the following options:" << endl << endl;

	cout << "quit - Quit the program" << endl;

	cout << "display - Display all restaurants" << endl;

	cout << "add - Add a restaurant" << endl;

	cout << "remove - Remove a restaurant" << endl;

	cout << "cut - \"Cut\" the list of restaurants" << endl;

	cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;

	cout << "battle - Begin the tournament" << endl;

	cout << "options - Print the options menu" << endl << endl;



	return;

}


void DisplayRestaurants(vector<string> restaurantVector) {

	cout << "Here are the current restaurants:" << endl << endl;

	for (int i = 0; i < restaurantVector.size(); ++i) {

		cout << "\t\"" << restaurantVector.at(i) << "\"" << endl;

	}

	cout << endl;



	return;

}

void MenuInputError(string errorMessage, int functionIdentifier, vector<string> restaurantVector) {
	cout << errorMessage;
	if (functionIdentifier == 4) {
		cout << "0 and " << restaurantVector.size() << endl;
	}
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
	}


	if (functionIdentifier == 1) {
		OptionsPrint();
	}



	return;

}


void GetLineNoNull(string& inpString) {



	getline(cin, inpString);

	if (inpString == "") {

		getline(cin, inpString);

	}

}



void AddRestaurant(vector<string>& restaurantVector) {

	string tempString = " ";

	string tempString2 = " ";

	bool exists = false;

	cout << "What is the name of the restaurant you want to add?" << endl;

	GetLineNoNull(tempString);

	for (int i = 0; i < restaurantVector.size(); ++i) {

		tempString2 = restaurantVector.at(i);

		if (tempString2.find(tempString) != string::npos) {

			exists = true;

		}

	}

	if (exists == false) {

		restaurantVector.push_back(tempString);

		cout << restaurantVector.at(restaurantVector.size() - 1) << "has been added." << endl;

	}

	else {

		cout << "That restaurant is already on the list, you can not add it again." << endl;

	}

	cout << endl;

	return;

}



void RemoveRestaurant(vector<string>& restaurantVector) {

	string tempString = " ";

	int tempVal = 0;

	string tempString2 = " ";

	bool exists = false;

	cout << "What is the name of the restaurant you want to remove?" << endl;

	GetLineNoNull(tempString);

	for (int i = 0; i < restaurantVector.size(); ++i) {

		tempString2 = restaurantVector.at(i);

		if (tempString2.find(tempString) != string::npos) {

			exists = true;

			tempVal = i;

		}

	}

	if (exists == true) {

		restaurantVector.erase(restaurantVector.begin() + tempVal);

		cout << tempString << "has been removed." << endl;

	}

	else {

		cout << "That restaurant is not on the list, you can not remove it." << endl;

	}

	cout << endl;

	return;

}



void CutVector(vector<string>& restaurantVector) {
	int functionIdentifier = 4;
	int cutValue = 0;
	int j = 0;
	vector<string> cutList;
	cutList = restaurantVector;
	string invalidInput = "The cut number must be between ";
	cout << "How many restaurants should be taken from the top and put on the bottom?" << endl;
	cin >> cutValue;

	while (cutValue < 0 || cutValue > restaurantVector.size() || cin.fail()) {
		MenuInputError(invalidInput, functionIdentifier, restaurantVector);
		cutValue = 0;
		cout << "How many restaurants should be taken from the top and put on the bottom?" << endl;
		cin >> cutValue;
	}
	j = 0;
	for (int i = cutList.size() - cutValue; i < cutList.size(); ++i) {
		cutList.at(i) = restaurantVector.at(j);
		++j;
	}
	j = cutValue;
	for (int i = 0; i < cutList.size() - cutValue; ++i) {
		cutList.at(i) = restaurantVector.at(j);
		++j;
	}
	/*   For checking the values.
	for (int i = 0; i < restaurantVector.size(); ++i) {
		cout << restaurantVector.at(i) << ", ";
	}
	cout << endl;

	for (int i = 0; i < cutList.size(); ++i) {
		cout << cutList.at(i) << ", ";
	}
	*/
	restaurantVector = cutList;

	return;

}



void ShuffleVector() {


	return;

}



void BattleStart() {

	cout << "B Test" << endl;



	return;

}



int main() {

	string menuSelection = " ";

	vector<string> restaurantVector;
	string menuErrorMessage = "Invalid Selection";

	cout << "Welcome to the restaurant battle! Enter \"options\" to see options." << endl << endl;

	cout << "Enter your selection: ";

	cin >> menuSelection;

	cout << endl;



	while (menuSelection != "quit") {

		if (menuSelection == "display") {

			DisplayRestaurants(restaurantVector);

		}



		if (menuSelection == "add") {

			AddRestaurant(restaurantVector);

		}



		if (menuSelection == "remove") {

			RemoveRestaurant(restaurantVector);

		}



		if (menuSelection == "cut") {

			CutVector(restaurantVector);

		}



		if (menuSelection == "shuffle") {

			ShuffleVector();

		}



		if (menuSelection == "battle") {

			BattleStart();

		}



		if (menuSelection == "options") {

			OptionsPrint();

		}



		if (menuSelection != "options" && menuSelection != "battle" && menuSelection != "shuffle" && menuSelection != "cut"

			&& menuSelection != "remove" && menuSelection != "add" && menuSelection != "display") {

			MenuInputError(menuErrorMessage, 1, restaurantVector);

		}

		cout << "Enter your selection: " << endl;

		cin >> menuSelection;

		cout << endl;

	}

	cout << "Goodbye!" << endl;

	return 0;

}