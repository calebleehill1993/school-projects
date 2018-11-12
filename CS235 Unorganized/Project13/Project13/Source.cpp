/*
Skyler Hill, Section 2, skylerjhill@gmail.com

*used Visual Studios

Description: This program simulates a game of Plinko and calculates the winnings.  The user can select
either to drop a single chip or multiple chips at the same time.

Test case 1:
Input: Test the possible errors that could occur with negative numbers. (-1, 1, -1, 2 -1, 2, 1, -1, 4)

Expected output: The program should output the error messages and exit.

Result: Passed

Test case 2:
Input: (using fixed seed of 42) 1, 4, 1, 6, 4

Expected output:
Path: [4.0, 3.5, 3.0, 3.5, 4.0, 3.5, 3.0, 3.5, 3.0, 3.5, 4.0, 3.5, 4.0]
Winnings: $10000.00
Path: [6.0, 6.5, 6.0, 5.5, 5.0, 4.5, 4.0, 3.5, 4.0, 4.5, 4.0, 4.5, 5.0]
Winnings: $0.00

Result: Passed

Test case 3:
Input: (using fixed seed of 42) 2, 50, 4, 4

Expected output:
Total winnings on 50 chips: $144200.00
Average winnings per chip: $2884.00

Result: Passed
*/

#include <iostream>
#include <cstdlib>
#include <ios>
#include <iomanip>
#include <vector>

using namespace std;

const int slotMoney[5]{ 0, 100, 500, 1000, 10000 };
const int Y_LIMIT = 11;
const int SINGLE_CHIP_PLAY = 1;
const int MULTIPLE_CHIP_PLAY = 2;
const int SHOW_OPTIONS = 4;
const int QUIT_PROGRAM = 5;
const int SEQUENTIAL_DROP = 3;
const int MAX_SLOT = 8;


double ComputeWinnings(int slot) {
	double totalWinnings = 0;

	if (slot == 3 || slot == 5) {
		totalWinnings = slotMoney[0];
	}
	if (slot == 0 || slot == 8) {
		totalWinnings = slotMoney[1];
	}
	if (slot == 1 || slot == 7) {
		totalWinnings = slotMoney[2];
	}
	if (slot == 2 || slot == 6) {
		totalWinnings = slotMoney[3];
	}
	if (slot == 4) {
		totalWinnings = slotMoney[4];
	}

	return totalWinnings;
}

bool ErrorCheck(const int userSelection, const int numChips = 1, const int slotSelection = 0) {
	bool noError = false;
	if ((userSelection == SINGLE_CHIP_PLAY) || (userSelection == MULTIPLE_CHIP_PLAY) ||
		(userSelection == SHOW_OPTIONS) || (userSelection == QUIT_PROGRAM) || (userSelection == SEQUENTIAL_DROP)) {
		if (numChips > 0) {
			if (slotSelection >= 0 && slotSelection <= MAX_SLOT) {
				noError = true;
			}
		}
	}
	return noError;
}

void PlinkoMachine(const int userSelection, const int numChips, const int slotSelection, double& winnings) {
	double chipPath = 0.0;
	int landing = 0;
	const double CHIP_OFFSET = 0.5;
	const int RANDOM_RANGE = 2;
	const double RANDOM_OFFSET = 0.5;

	for (int i = 0; i < numChips; i++) {

		chipPath = slotSelection;

		if (userSelection == SINGLE_CHIP_PLAY) {
			cout << "Path: [" << chipPath;
		}
		for (int yAxisPosition = Y_LIMIT; yAxisPosition >= 0; yAxisPosition--) {
			if (userSelection == SINGLE_CHIP_PLAY) {
				cout << ", ";
			}
			if (chipPath == 0) {
				chipPath = chipPath + CHIP_OFFSET;
			}
			else if (chipPath == MAX_SLOT) {
				chipPath = chipPath - CHIP_OFFSET;
			}
			else {
				chipPath = chipPath + ((rand() % RANDOM_RANGE) - RANDOM_OFFSET);
			}
			if (userSelection == SINGLE_CHIP_PLAY) {
				cout << chipPath;
			}
		}
		landing = chipPath;
		winnings = winnings + ComputeWinnings(landing);
	}
	if (userSelection == SINGLE_CHIP_PLAY) {
		cout << "]" << endl;
	}
	return;
}


int main() {
	int slot = 0;
	int userSelection = 0;
	int slotSelection = 0;
	double averageWinnings = 0.0;
	int numChips = 0;
	double winnings = 0;
	bool errorCheck = false;
	const int PRECISION_VALUE = 1;
	const int PRECISION_MONEY = 2;

	
	const int SEED_VALUE = 42;

	srand(SEED_VALUE);

	cout << "Welcome to the Plinko simulator! Enter 4 to see options." << endl << endl;
	cout << "Enter your selection now: ";
	cin >> userSelection;
	cout << endl << endl;

	while (userSelection != QUIT_PROGRAM) {
		//prohibits the input of number that isn't a choice
		errorCheck = false;
		while (errorCheck == false) {
			errorCheck = ErrorCheck(userSelection);
			if (errorCheck == false) {
				cin.clear();
				cin.ignore(1000, '\n');
				userSelection = 0;
				cout << "Invalid selection.  Enter 4 to see options." << endl << endl;
				cout << "Enter your selection now: ";
				cin >> userSelection;
			}
		}
		//Starts Single chip play
		if (userSelection == SINGLE_CHIP_PLAY) {
			numChips = 1;
			cout << fixed << setprecision(PRECISION_VALUE);
			cout << "*** Drop a single chip ***" << endl << endl;
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> slotSelection;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				slotSelection = -1;
			}
			cout << endl;
			errorCheck = false;
			while (errorCheck == false) {
				errorCheck = ErrorCheck(userSelection, numChips, slotSelection);
				if (errorCheck == false || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000, '\n');
					}
					slotSelection = -1;
					cout << "Invalid slot." << endl << endl;
					cout << "Which slot do you want to drop the chip in (0-8)? " << endl << endl;
					cin >> slotSelection;
				}
			}
			cout << "*** Dropping chip into slot " << slotSelection << " ***" << endl;
			winnings = 0;
			PlinkoMachine(userSelection, numChips, slotSelection, winnings);
			cout << fixed << setprecision(PRECISION_MONEY);
			cout << "Winnings: $" << winnings << endl;
			cout << endl;
		}

		//Multi Chip Play
		if (userSelection == MULTIPLE_CHIP_PLAY) {
			cout << fixed << setprecision(PRECISION_VALUE);
			cout << "*** Drop multiple chips ***" << endl << endl;
			cout << "How many chips do you want to drop (>0)? ";
			cin >> numChips;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				numChips = 0;
			}
			cout << endl;
			errorCheck = false;
			while (errorCheck == false) {
				errorCheck = ErrorCheck(userSelection, numChips);
				if (errorCheck == false) {
					cin.clear();
					cin.ignore(1000, '\n');
					numChips = 0;
					cout << "Invalid number of chips." << endl << endl;
					cout << "How many chips do you want to drop (>0)? " << endl << endl;
					cin >> numChips;
				}
			}
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> slotSelection;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				slotSelection = -1;
			}
			cout << endl;
			errorCheck = false;
			while (errorCheck == false) {
				errorCheck = ErrorCheck(userSelection, numChips, slotSelection);
				if (errorCheck == false) {
					cin.clear();
					cin.ignore(1000, '\n');
					slotSelection = -1;
					cout << "Invalid slot." << endl << endl;
					cout << "Which slot do you want to drop the chip in (0-8)? ";
					cin >> slotSelection;
				}
			}
			winnings = 0;
			PlinkoMachine(userSelection, numChips, slotSelection, winnings);
			cout << fixed << setprecision(PRECISION_MONEY);
			cout << "Total winnings on " << numChips << " chips: $" << winnings << endl;
			averageWinnings = winnings / numChips;
			cout << "Average winnings per chip: $" << averageWinnings << endl;
			cout << endl;
		}

		//Show Options
		if (userSelection == SHOW_OPTIONS) {
			cout << "Menu: Please select one of the following options : " << endl;
			cout << endl;
			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;
			cout << "3 - Drop multiple chips into each slot" << endl;
			cout << "4 - Show the options menu" << endl;
			cout << "5 - Quit the program" << endl;

			cout << endl;
		}
		//Sequential Drop
		if (userSelection == SEQUENTIAL_DROP) {
			cout << "*** Sequentially drop multiple chips ***" << endl << endl;
			cout << "How many chips do you want to drop (>0)?";
			cin >> numChips;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				numChips = 0;
			}
			cout << endl << endl;
			errorCheck = false;
			while (errorCheck == false) {
				errorCheck = ErrorCheck(userSelection, numChips);
				if (errorCheck == false) {
					cin.clear();
					cin.ignore(1000, '\n');
					numChips = 0;
					cout << "Invalid number of chips." << endl << endl;
					cout << "How many chips do you want to drop (>0)? " << endl << endl;
					cin >> numChips;
				}
			}
			for (int j = 0; j <= MAX_SLOT; ++j) {
				winnings = 0;
				PlinkoMachine(userSelection, numChips, slotSelection, winnings);
				cout << fixed << setprecision(PRECISION_MONEY);
				cout << "Total winnings on slot " << j << " chips: " << winnings << endl;
				averageWinnings = winnings / numChips;
				cout << "Average winnings per chip: " << averageWinnings << endl;
				cout << endl;
			}
		}
		if (userSelection != 5) {
			cout << "Enter your selection now: ";
			cin >> userSelection;
			cout << endl;
		}
	}
	cout << "Goodbye!" << endl;

	return 0;
}