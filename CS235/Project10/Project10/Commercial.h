#pragma once
#include "Property.h"

class Commercial : public Property
{
public:
	Commercial(string NewAddress, int NewId);
	~Commercial();
};

