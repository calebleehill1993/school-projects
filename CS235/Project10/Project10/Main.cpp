
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Property.h"
#include <iomanip>
#include <sstream>

using namespace std;

void LoadFile(vector<Property*>& properties)
{
	ifstream InFile;
	string ResOrCom;
	string FileName;
	string NewAddress;
	string WholeLine;
	stringstream ss;
	int NewId = 0;
	double number = 0;
	cout << "What is the name for the file you'd like to load? ";
	cin >> FileName;
	InFile.open(FileName);
	if (InFile.fail())
	{
		cout << "That file was not found." << endl;
		system("pause");
	}
	else
	{
		while (getline(InFile, WholeLine))
		{
			cout << "Loading " << FileName << endl;
			cout << WholeLine;
			ss << WholeLine;
			ss >> ResOrCom;
			system("pause");
			if (ResOrCom == "Residential")
			{
				system("pause");
				ss >> NewId >> NewId >> NewId;
				getline(ss, NewAddress);
				cout << NewAddress;
				system("pause");
			}
			else
			{
				InFile >> NewId >> NewId >> NewId >> number;
				getline(ss, NewAddress);
				cout << NewAddress;
				system("pause");
			}
			ss.str("");
		}
	//	while (InFile >> NewAddress >> NewId)
	//	{
		//	properties.push_back(Property(NewAddress, NewId));
	//	}
	}
}

int main()
{
	vector<Property*> properties;
	LoadFile(properties);
	return 0;
}