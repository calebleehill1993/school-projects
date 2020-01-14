/*
Caleb Hill, Section 2, calebleehill1993@gmail.com

Purpose:  Simulate a Hot Plate with numbers

Input:

NONE

Output:

Starting Hot Plate

Hot Plate after one run through the function

Final Hot Plate

Create a .csv to show that 3D version of the Hot Plate
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void print(double array[20][20], int PRECISION, int WIDTH, int SIZE)
{
	cout << setprecision(PRECISION) << fixed;

	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			cout << setw(WIDTH) << array[x][y];
		}
		if (x != SIZE - 1)
		{
			cout << endl << endl;
		}
	}
}

void print1(double array[20][20], int PRECISION, int SIZE)
{
	ofstream my_file;

	my_file.open("my_file.csv");

	my_file << setprecision(PRECISION) << fixed;

	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			my_file << array[x][y];

			if (y < SIZE - 1)
			{
				my_file << ",";
			}
		}
		if (x != SIZE - 1)
		{
			my_file << endl;
		}
	}
	my_file.close();
}

int main()
{
	// CONSTANTS
	int const NUMBER_OF_ADJACENT = 4;
	int const SIZE = 20;
	int const PRECISION = 4;
	int const WIDTH = 10;
	double const GREATEST_ALLOWED_CHANGE = .1;
	double const SIDE_TEMPERATURES = 0;
	double const TOP_AND_BOTTOM_TEMPERATURES = 100;

	// VARIABLES AND ARRAYS
	double array[20][20];
	double second_array[20][20];
	double greatest_change = 1;
	double point_change = 0;

	cout << "Hotplate Simulator" << endl << endl << endl << "Printing initial plate..." << endl << endl;

	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if ((x == 0 || x == SIZE - 1) || (y > 0 && y < SIZE - 1))
			{
				array[y][x] = SIDE_TEMPERATURES;
			}
			else
			{
				array[y][x] = TOP_AND_BOTTOM_TEMPERATURES;
			}
		}
	}
	print(array, PRECISION, WIDTH, SIZE);

	cout << endl << endl << endl << "Printing plate after one iteration..." << endl << endl;

	for (int y = 1; y < SIZE - 1; y++)
	{
		for (int x = 1; x < SIZE - 1; x++)
		{
			second_array[y][x] = (array[y - 1][x] + array[y][x + 1] + array[y + 1][x] + array[y][x - 1]) / NUMBER_OF_ADJACENT;
		}
	}
	for (int y = 1; y < SIZE - 1; y++)
	{
		for (int x = 1; x < SIZE - 1; x++)
		{
			array[y][x] = second_array[y][x];
		}
	}
	print(array, PRECISION, WIDTH, SIZE);

	cout << endl << endl << endl << "Printing final plate..." << endl << endl;

	while (greatest_change > GREATEST_ALLOWED_CHANGE) // keep running until greatest change < .1
	{
		greatest_change = 0;

		for (int y = 1; y < SIZE - 1; y++)
		{
			for (int x = 1; x < SIZE - 1; x++)
			{
				second_array[y][x] = (array[y - 1][x] + array[y][x + 1] + array[y + 1][x] + array[y][x - 1]) / NUMBER_OF_ADJACENT;
			}
		}
		for (int y = 1; y < SIZE - 1; y++)
		{
			for (int x = 1; x < SIZE - 1; x++)
			{
				point_change = second_array[y][x] - array[y][x];

				if (greatest_change < point_change)
				{
					greatest_change = point_change;
				}
			}
		}
		for (int y = 1; y < SIZE - 1; y++)
		{
			for (int x = 1; x < SIZE - 1; x++)
			{
				array[y][x] = second_array[y][x];
			}
		}
	}
	print(array, PRECISION, WIDTH, SIZE);

	cout << endl << endl;

	system("PAUSE");

	print1(array, PRECISION, SIZE);

	cout << endl << endl << endl << "Writing values to .csv file...";

	return 0;
}