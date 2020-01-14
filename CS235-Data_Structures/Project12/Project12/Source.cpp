#include<iostream>
#include<vector>
#include<iomanip>
#include<ios>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
	ofstream outFS;
	ifstream inFS;
	int fileNum = 0;
	const int ARRAY_DIMENSIONS = 10;
	double plateTemperatures[ARRAY_DIMENSIONS][ARRAY_DIMENSIONS] = { 0.0 };
	double newPlateTemperatures[ARRAY_DIMENSIONS][ARRAY_DIMENSIONS];
	double importPlateTemperatures[ARRAY_DIMENSIONS][ARRAY_DIMENSIONS];
	int k = 0;
	int i = 0;
	int j = 0;
	int temperaturePrecisionValue = 4;
	int widthValue = 10;
	double changeTemp = 0;
	const int INITIAL_VALUE = 100;
	const int NUM_UPDATES = 3;

	cout << "Hotplate simulator" << endl << endl;
	cout << "Printing initial plate..." << endl;
	cout << fixed << setprecision(temperaturePrecisionValue) << right;

	//creates the first array and prints it
	for (i = 0; i < ARRAY_DIMENSIONS; ++i) {
		j = 0;
		cout << setw(widthValue) << plateTemperatures[i][j];

		for (j = 1; j < ARRAY_DIMENSIONS; ++j) {
			if ((i == 0 || i == ARRAY_DIMENSIONS - 1) && j > 0 && j < ARRAY_DIMENSIONS - 1) {
				plateTemperatures[i][j] = 100.0;
			}
			cout << "," << setw(widthValue) << plateTemperatures[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Printing plate after one iteration..." << endl;

	//copies original array into new one
	for (i = 0; i < ARRAY_DIMENSIONS; ++i) {
		for (j = 0; j < ARRAY_DIMENSIONS; ++j) {
			newPlateTemperatures[i][j] = plateTemperatures[i][j];
		}
	}

	//changes values in the new array after 1 iteration
	for (i = 1; i < ARRAY_DIMENSIONS - 1; ++i) {
		for (j = 1; j < ARRAY_DIMENSIONS - 1; ++j) {
			newPlateTemperatures[i][j] = (plateTemperatures[i - 1][j] + plateTemperatures[i + 1][j]
				+ plateTemperatures[i][j - 1] + plateTemperatures[i][j + 1]) / 4;
		}
	}

	//prints the first iteration
	for (i = 0; i < ARRAY_DIMENSIONS; ++i) {
		j = 0;
		cout << setw(widthValue) << newPlateTemperatures[i][j];

		for (j = 1; j < ARRAY_DIMENSIONS; ++j) {
			cout << "," << setw(widthValue) << newPlateTemperatures[i][j];
		}
		cout << endl;
	}

	//copies new array into original new one
	for (i = 0; i < ARRAY_DIMENSIONS; ++i) {
		for (j = 0; j < ARRAY_DIMENSIONS; ++j) {
			plateTemperatures[i][j] = newPlateTemperatures[i][j];
		}
	}
	cout << endl;

	changeTemp = INITIAL_VALUE;
	while (changeTemp > 0.1) {
		changeTemp = 0;
		for (i = 1; i < ARRAY_DIMENSIONS - 1; ++i) {
			for (j = 1; j < ARRAY_DIMENSIONS - 1; ++j) {
				newPlateTemperatures[i][j] = (plateTemperatures[i - 1][j] + plateTemperatures[i + 1][j]
					+ plateTemperatures[i][j - 1] + plateTemperatures[i][j + 1]) / 4;
				if (fabs(newPlateTemperatures[i][j] - plateTemperatures[i][j]) > changeTemp) {
					changeTemp = (newPlateTemperatures[i][j] - plateTemperatures[i][j]);
				}
			}
		}
		for (i = 0; i < ARRAY_DIMENSIONS; ++i) {
			for (j = 0; j < ARRAY_DIMENSIONS; ++j) {
				plateTemperatures[i][j] = newPlateTemperatures[i][j];
			}
		}
	}

	//prints final plate
	cout << "Printing final plate..." << endl;
	for (i = 0; i < ARRAY_DIMENSIONS; ++i) {
		j = 0;
		cout << setw(widthValue) << newPlateTemperatures[i][j];
		for (j = 1; j < ARRAY_DIMENSIONS; ++j) {
			cout << "," << setw(widthValue) << newPlateTemperatures[i][j];
		}
		cout << endl;
	}
	cout << endl;

	cout << "Outputting final plate to file \"Hotplate.csv\"..." << endl << endl;
						// Open file
		outFS.open("Hotplate.csv");

		if (!outFS.is_open()) {
			cout << "Could not open file Hotplate.csv." << endl;
			return 1;
		}
		outFS << fixed << setprecision(temperaturePrecisionValue);
		for (i = 0; i < ARRAY_DIMENSIONS; ++i) {
			j = 0;
			outFS << setw(widthValue) << newPlateTemperatures[i][j];
			for (j = 1; j < ARRAY_DIMENSIONS; ++j) {
				outFS << "," << setw(widthValue) << newPlateTemperatures[i][j];
			}
			outFS << endl;
		}

	
		// Done with file, so close it
		outFS.close();

		inFS.open("Inputplate.txt");

		for (i = 0; i < ARRAY_DIMENSIONS; ++i) {
			for (j = 0; j < ARRAY_DIMENSIONS; ++j) {
				inFS >> importPlateTemperatures[i][j];
			}
		}
		
		for (k = 0; k < NUM_UPDATES; ++k) {
			changeTemp = 0;
			for (i = 1; i < ARRAY_DIMENSIONS - 1; ++i) {
				for (j = 1; j < ARRAY_DIMENSIONS - 1; ++j) {
					plateTemperatures[i][j] = (importPlateTemperatures[i - 1][j] + importPlateTemperatures[i + 1][j]
						+ importPlateTemperatures[i][j - 1] + importPlateTemperatures[i][j + 1]) / 4;
				}
			}
			for (i = 0; i < ARRAY_DIMENSIONS; ++i) {
				for (j = 0; j < ARRAY_DIMENSIONS; ++j) {
					importPlateTemperatures[i][j] = plateTemperatures[i][j];
				}
			}
		}
		cout << "Printing input plate after " << NUM_UPDATES << " updates..." << endl;
		for (i = 0; i < ARRAY_DIMENSIONS; ++i) {
			j = 0;
			cout << setw(widthValue) << importPlateTemperatures[i][j];
			for (j = 1; j < ARRAY_DIMENSIONS; ++j) {
				cout << "," << setw(widthValue) << importPlateTemperatures[i][j];
			}
			cout << endl;
		}

		outFS.close();

		system("PAUSE");

	return 0;
}