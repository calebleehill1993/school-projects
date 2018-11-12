#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif
#include <fstream>
#include <string>
#include <iostream>
#include "QuickSort.h"
#include <sstream>
using namespace std;

int main(int argc, char * argv[])
{
	VS_MEM_CHECK;
	ifstream in;
	in.open(argv[1]);
	ofstream out;
	out.open(argv[2]);
	string input;
	int number = 0;
	size_t left = 0;
	size_t right = 0;
	size_t pivot = 0;
	QuickSort<int> quickSort;
	while (in >> input)
	{
		if (input == "QuickSort")
		{
			in >> number;
			quickSort.createArray(number);
			out << input << " " << number << " OK";
		}
		if (input == "Capacity")
		{
			out << input << " " << quickSort.capacity();
		}
		if (input == "Clear")
		{
			quickSort.clear();
			out << input << " OK";
		}
		if (input == "AddToArray")
		{
			out << input << " ";
			getline(in, input);
			stringstream s;
			s << input;
			if (s >> number)
			{
				out << number;
				quickSort.addElement(number);
			}
			while (s >> number)
			{
				quickSort.addElement(number);
				out << "," << number;
			}
			out << " OK";
		}
		if (input == "Size")
		{
			out << input << " " << quickSort.size();
		}
		if (input == "PrintArray")
		{
			out << input << " " << quickSort.toString();
		}
		if (input == "MedianOfThree")
		{
			in >> left >> right;
			out << input << " " << left << "," << right << " = " << quickSort.medianOfThree(left, right);
		}
		if (input == "Partition")
		{
			in >> left >> right >> pivot;
			out << input << " " << left << "," << right << "," << pivot << " = " << quickSort.partition(left, right, pivot);
		}

		out << endl;
	}
	return 0;
}