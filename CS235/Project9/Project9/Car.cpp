#include "Car.h"
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const double PAINT_COST = 1000;


Car::Car(string NewName, string NewColor, double NewPrice)
{
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
	price += PAINT_COST;
}
string Car::ToString() const
{
	const int SET_PRECISION = 2;
	ostringstream ss;
	ss << "Name: " << name << endl;
	ss << "Color: " << color << endl;
	ss << "Price: $" << fixed << setprecision(SET_PRECISION) << price << endl;
	return ss.str();
}
