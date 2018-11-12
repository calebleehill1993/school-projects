#pragma once
#include <string>
using namespace std;
class Car
{
public:
	Car(string name, string color, double price);
	string GetName() const;
	string GetColor() const;
	double GetPrice() const;
	void Paint(string color);
	string ToString() const;
private:
	string name;
	string color;
	double price;
};

