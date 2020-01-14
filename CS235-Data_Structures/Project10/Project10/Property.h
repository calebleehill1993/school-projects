#pragma once
#include <iostream>
#include <string>
using namespace std;

class Property
{
public:
	Property();
	~Property();
	string ToString() const;

protected:
	string address;
	int id;

};

