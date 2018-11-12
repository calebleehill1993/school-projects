#include "Car.h"
#include <sstream>
#include <iostream>
using namespace std;
double PaintCost = 1000;


Car::Car(string NewName, string NewColor, double NewPrice)
{
	cout << "*";
	name = NewName;
	color = NewColor;
	price = NewPrice;
}

string Car::GetName() const
{
	return name;
}
string Car::GetColor() const
{
	return color;
}
double Car::GetPrice() const
{
	return price;
}
void Car::Paint(string NewColor)
{
	color = NewColor;
	price += PaintCost;
}
string Car::ToString() const
{
	ostringstream ss;
	ss << "Name: " << name << endl;
	ss << "Color: " << color << endl;
	ss << "Price: " << price << endl;
	return ss.str();
}
