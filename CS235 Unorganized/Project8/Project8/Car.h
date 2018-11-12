#pragma once
#include <string>
using namespace std;
class Car
{
public:

	string GetName() const;
	string GetColor() const;
	double GetPrice() const;
	Car(string name, string color, double price);
	void Paint(string color);
	string ToString() const;
private:
	string name = 0;
	string color = 0;
	double price = 0;
};

