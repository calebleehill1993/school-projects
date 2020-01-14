#include "Property.h"
#include <sstream>




Property::Property()
{

}



Property::~Property()
{
}

string Property::ToString() const
{
	ostringstream ss;
	return ss.str();
}