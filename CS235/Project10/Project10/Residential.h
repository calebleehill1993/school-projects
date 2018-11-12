#pragma once
#include "Property.h"

class Residential : public Property
{
public:
	Residential(string NewAddress, int NewId);
	~Residential();
};

