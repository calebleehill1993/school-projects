#include <string>
#include <iostream>

class Token
{
public:
	Token(std::string a, std::string b, unsigned int c);
	~Token();
	std::string string;
	unsigned int number;
	std::string type;
	void Print();
};
