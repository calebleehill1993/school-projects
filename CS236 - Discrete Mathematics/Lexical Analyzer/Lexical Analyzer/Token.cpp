#include "Token.h"



Token::Token(std::string a, std::string b, unsigned int c)
{
	type = a;
	string = b;
	number = c;
}


Token::~Token()
{
}

void Token::Print()
{
	std::cout << "(" << type << "," << string << "," << number << ")" << std::endl;
}
