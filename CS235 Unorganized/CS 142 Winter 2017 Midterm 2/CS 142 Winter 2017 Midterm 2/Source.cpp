/*
CS 142 Winter 2017 Midterm 2
Caleb Hill, Section 2, calebleehill1993@gmail.com

input: side length, starting value

output: magic square (for odds less than 100 greater than 0), Row sums, Column sums, Diagonal sums, quit if input is 0. Otherwise, give error.
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void menu(int& sideLength, const int QUIT, const int MAX_SIDE, int& start)
{
	bool goodValue = false;
	const int EVEN = 2;
	while (!goodValue)
	{
		cout << "Enter odd square length (0 to exit): ";
		cin >> sideLength;
		if (sideLength < QUIT)
		{
			cout << "Must be above 0." << endl;
		}
		else if (sideLength > MAX_SIDE)
		{
			cout << "Must be less than 100." << endl;
		}
		else if (sideLength == QUIT) 
		{
			goodValue = true;
		}
		else if (sideLength % EVEN == QUIT)
		{
			cout << "Must be an odd number." << endl;
		}
		else
		{
			goodValue = true;
			cout << "enter the starting value: ";
			cin >> start;
		}
	}
}

void printSquare(int square[][99], int sideLength)
{
	int const WIDTH = 5;
	for (int x = 0; x < sideLength; x++)
	{
		for (int y = 0; y < sideLength; y++)
		{
			cout << setw(WIDTH) << square[x][y];
		}
		if (x != sideLength - 1)
		{
			cout << endl << endl;
		}
	}
	cout << endl << endl;
}

void verifyRows(int square[][99], int sideLength)
{
	int const WIDTH = 5;
	int sum = 0;
	cout << "Verifying Row Sums..." << endl;
	for (int i = 0; i < sideLength; i++)
	{
		cout << setw(WIDTH) << i;
	}
	cout << endl;
	for (int y = 0; y < sideLength; y++)
	{
		for (int x = 0; x < sideLength; x++)
		{
			sum += square[y][x];
		}
		cout << setw(WIDTH) << sum;
		sum = 0;
	}
	cout << endl << endl;
}
void verifyColumns(int square[][99], int sideLength)
{
	int const WIDTH = 5;
	int sum = 0;
	cout << "Verifying Column Sums..." << endl;
	for (int i = 0; i < sideLength; i++)
	{
		cout << setw(WIDTH) << i;
	}
	cout << endl;
	for (int y = 0; y < sideLength; y++)
	{
		for (int x = 0; x < sideLength; x++)
		{
			sum += square[x][y];
		}
		cout << setw(WIDTH) << sum;
		sum = 0;
	}
	cout << endl << endl;
}
void verifyDiagonals(int square[][99], int sideLength)
{
	int z = 0;
	int sum = 0;
	cout << "Verifying Diagonal Sums..." << endl;
	for (int i = 0; i < sideLength; i++)
	{
		sum += square[i][i];
	}
	cout << "TL to BR sum: " << sum << endl;
	sum = 0;
	for (int x = sideLength - 1; x >= 0; x--)
	{
		sum += square[z][x];
		z += 1;
	}
	cout << "BL to TR sum: " << sum << endl << endl;
}

int main()
{
	int start = 0;
	int sideLength = 1;
	const int QUIT = 0;
	const int MAX_SIDE = 99;
	int square[99][99];
	const int EVEN = 2;
	const int ODD = 1;
	int row = 0;
	int column = 0;
	int k = 0;
	while (sideLength != QUIT)
	{
		menu(sideLength, QUIT, MAX_SIDE, start);
		if (sideLength == QUIT){}
		else
		{
			row = sideLength - ODD;
			column = sideLength / EVEN;
			k = start;
			for (int i = 0; i < sideLength; i++)
			{
				for (int j = 0; j < sideLength; j++)
				{
					square[row][column] = k;
					if (row < sideLength - ODD)
					{
						row += ODD;
					}
					else
					{
						row = QUIT;
					}
					if (column < sideLength - ODD)
					{
						column += ODD;
					}
					else
					{
						column = QUIT;
					}
					k += ODD;
				}
				if (column == QUIT)
				{
					column = sideLength - ODD;
				}
				else
				{
					column -= ODD;
				}
				if (row == QUIT)
				{
					row = sideLength - EVEN;
				}
				else if (row == ODD)
				{
					row = sideLength - ODD;
				}
				else
				{
					row -= EVEN;
				}
			}
			printSquare(square, sideLength);
			verifyRows(square, sideLength);
			verifyColumns(square, sideLength);
			verifyDiagonals(square, sideLength);
		}
	}
	return 0;
	
}