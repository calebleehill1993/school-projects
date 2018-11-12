#include "LexicalAnalyzer.h"
#include <ctype.h>


LexicalAnalyzer::LexicalAnalyzer()
{
}

LexicalAnalyzer::LexicalAnalyzer(std::ifstream& inFile)
{
	std::string line; //the line of input
	unsigned int lineNumber = 1; //keeps track of the line number
	std::string carryString = ""; //String used for multiple lines.
	unsigned int carryNumber = 0; //To keep track of line number when token on multiple lines.
	bool tokenTypeString = false; //for multi line strings
	bool tokenTypeComment = false; //for multi line comments
	while (getline(inFile, line)) //loops continuously grabbing a new line until all input is read
	{
		std::string s = "";
		unsigned int l = line.length() - 1;
		if (!line.length() && (tokenTypeString || tokenTypeComment)) //new line character
		{
			carryString += "\n";
		}
		for (unsigned int i = 0; i < line.length(); i++)
		{
			Analyzer(line, lineNumber, carryString, carryNumber, tokenTypeString, tokenTypeComment, s, l, i);
		}
		lineNumber++;
	}
	if (carryString != "")
	{
		Token t = Token("UNDEFINED", "\"" + carryString + "\"", carryNumber);
		tokens.push_back(t);
	}
	Token t = Token("EOF", "\"\"", lineNumber);
	tokens.push_back(t);
}

void LexicalAnalyzer::Analyzer(std::string& line, unsigned int& lineNumber, std::string& carryString, unsigned int& carryNumber, bool& tokenTypeString, bool& tokenTypeComment, std::string& s, unsigned int& l, unsigned int& i)
{
	char c = line.at(i);
	unsigned int subStrBC = 2; //length of block comment substr
	unsigned int ascii = (unsigned int)line.at(i); //Gets the ascii number for the character
	if (tokenTypeString)
	{
		TokenTypeString(tokenTypeString, line, i, l, s, carryString, carryNumber);
	}
	else if (tokenTypeComment)
	{
		TokenTypeComment(tokenTypeComment, line, i, l, s, carryString, carryNumber);
	}
	else if (i < l && line.substr(i, subStrBC) == "#|")
	{
		BlockComments(s, line, i, l, carryString, carryNumber, tokenTypeComment, lineNumber);
	}
	else
	{
		switch (c)
		{
			case '#':
				Comment(line, lineNumber, i);
				break;
			case ',':
				Comma(lineNumber);
				break;
			case '.':
				Period(lineNumber);
				break;
			case '?':
				QuestionMark(lineNumber);
				break;
			case '(':
				LeftParen(lineNumber);
				break;
			case ')':
				RightParen(lineNumber);
				break;
			case ':':
				Colon(line, i, l, lineNumber);
				break;
			case '*':
				Multiply(lineNumber);
				break;
			case '+':
				Add(lineNumber);
				break;
			case '\'':
				String(s, line, i, l, carryString, carryNumber, tokenTypeString, lineNumber);
				break;
			default:
				ID(ascii, s, line, i, l, lineNumber);
				break;
		}
	}
}

void LexicalAnalyzer::Comma(unsigned int& lineNumber)
{
	Token t = Token("COMMA", "\",\"", lineNumber);
	tokens.push_back(t);
}

void LexicalAnalyzer::Period(unsigned int& lineNumber)
{
	Token t = Token("PERIOD", "\".\"", lineNumber);
	tokens.push_back(t);
}

void LexicalAnalyzer::QuestionMark(unsigned int& lineNumber)
{
	Token t = Token("Q_MARK", "\"?\"", lineNumber);
	tokens.push_back(t);
}

void LexicalAnalyzer::LeftParen(unsigned int& lineNumber)
{
	Token t = Token("LEFT_PAREN", "\"(\"", lineNumber);
	tokens.push_back(t);
}

void LexicalAnalyzer::RightParen(unsigned int& lineNumber)
{
	Token t = Token("RIGHT_PAREN", "\")\"", lineNumber);
	tokens.push_back(t);
}

void LexicalAnalyzer::Multiply(unsigned int& lineNumber)
{
	Token t = Token("MULTIPLY", "\"*\"", lineNumber);
	tokens.push_back(t);
}

void LexicalAnalyzer::Add(unsigned int& lineNumber)
{
	Token t = Token("ADD", "\"+\"", lineNumber);
	tokens.push_back(t);
}

void LexicalAnalyzer::Colon(std::string& line, unsigned int& i, unsigned int& l, unsigned int& lineNumber)
{
	unsigned int subStrCD = 2; //length of subStr colon dash
	if (i < l && line.substr(i, subStrCD) == ":-")
	{
		Token t = Token("COLON_DASH", "\":-\"", lineNumber);
		i++;
		tokens.push_back(t);
	}
	else
	{
		Token t = Token("COLON", "\":\"", lineNumber);
		tokens.push_back(t);
	}
}

void LexicalAnalyzer::ID(unsigned int& ascii, std::string& s, std::string& line, unsigned int& i, unsigned int& l, unsigned int& lineNumber)
{
	unsigned int asciiA = 65;
	unsigned int asciiZ = 90;
	unsigned int asciia = 97;
	unsigned int asciiz = 122;
	if ((ascii >= asciiA && ascii <= asciiZ) || (ascii >= asciia && ascii <= asciiz)) //Finds any letter
	{
		AssembleID(ascii, s, line, i, l, lineNumber);
		KeyWords(s, lineNumber);
		i--;
	}
	else if (isspace(line.at(i))) {}
	else
	{
		Token t = Token("UNDEFINED", "\"" + line.substr(i, 1) + "\"", lineNumber);
		tokens.push_back(t);
	}
}

void LexicalAnalyzer::AssembleID(unsigned int& ascii, std::string& s, std::string& line, unsigned int& i, unsigned int& l, unsigned int& lineNumber)
{
	unsigned int ascii0 = 48;
	unsigned int ascii9 = 57;
	unsigned int asciiA = 65;
	unsigned int asciiZ = 90;
	unsigned int asciia = 97;
	unsigned int asciiz = 122;
	s = "";
	do
	{
		s += line.at(i);
		i++;
		if (i <= l)
		{
			ascii = (unsigned int)line.at(i);
		}
		else
		{
			ascii = 0;
		}
	} while ((ascii >= ascii0 && ascii <= ascii9) || (ascii >= asciiA && ascii <= asciiZ) || (ascii >= asciia && ascii <= asciiz)); //Finds letters and numbers
}

void LexicalAnalyzer::KeyWords(std::string& s, unsigned int& lineNumber)
{
	if (s == "Schemes")
	{
		Token t = Token("SCHEMES", "\"Schemes\"", lineNumber);
		tokens.push_back(t);
	}
	else if (s == "Facts")
	{
		Token t = Token("FACTS", "\"Facts\"", lineNumber);
		tokens.push_back(t);
	}
	else if (s == "Rules")
	{
		Token t = Token("RULES", "\"Rules\"", lineNumber);
		tokens.push_back(t);
	}
	else if (s == "Queries")
	{
		Token t = Token("QUERIES", "\"Queries\"", lineNumber);
		tokens.push_back(t);
	}
	else
	{
		Token t = Token("ID", "\"" + s + "\"", lineNumber);
		tokens.push_back(t);
	}
}

void LexicalAnalyzer::String(std::string& s, std::string& line, unsigned int& i, unsigned int& l, std::string& carryString, unsigned int& carryNumber, bool& tokenTypeString, unsigned int& lineNumber)
{
	unsigned int subStrDS = 2; // length of subStr double string
	s = "";
	char character = line.at(i);
	do
	{
		s += line.at(i);
		i++;
		while (i < l && line.substr(i, subStrDS) == "\'\'")
		{
			s += "\'\'";
			i += subStrDS;
		}
		if (i <= l)
		{
			character = line.at(i);
		}
		else
		{
			character = '0';
			carryString = s + "\n";
			carryNumber = lineNumber;
			tokenTypeString = true;
			break;
		}
	} while (character != '\'');
	if (!tokenTypeString)
	{
		Token t = Token("STRING", "\"" + s + "\'\"", lineNumber);
		tokens.push_back(t);
	}
}

void LexicalAnalyzer::TokenTypeString(bool& tokenTypeString, std::string& line, unsigned int& i, unsigned int& l, std::string& s, std::string& carryString, unsigned int& carryNumber)
{
	unsigned int subStrDS = 2; //length of subStr double string
	if (line.at(i) == '\'')
	{
		while (i < l && line.substr(i, subStrDS) == "\'\'")
		{
			s += "\'\'";
			i += subStrDS;
		}
	}
	if (i <= l && line.at(i) == '\'')
	{
		Token t = Token("STRING", "\"" + carryString + s + "\'\"", carryNumber);
		tokens.push_back(t);
		tokenTypeString = false;
		carryString = "";
		carryNumber = 0;
	}
	else if (i <= l)
	{
		TokenTypeStringCont(tokenTypeString, line, i, l, s, carryString, carryNumber);
	}
	else
	{
		carryString += s + "\n";
	}
}

void LexicalAnalyzer::TokenTypeStringCont(bool& tokenTypeString, std::string& line, unsigned int& i, unsigned int& l, std::string& s, std::string& carryString, unsigned int& carryNumber)
{
	unsigned int subStrDS = 2; //length of subStr double string
	char character = line.at(i);
	do
	{
		s += line.at(i);
		i++;
		while (i < l && line.substr(i, subStrDS) == "\'\'")
		{
			s += "\'\'";
			i += subStrDS;
		}
		if (i <= l)
		{
			character = line.at(i);
		}
		else
		{
			character = '0';
			carryString += s + "\n";
			tokenTypeString = true;
			break;
		}
	} while (character != '\'');
	if (character != '0')
	{
		Token t = Token("STRING", "\"" + carryString + s + "\'\"", carryNumber);
		tokens.push_back(t);
		tokenTypeString = false;
		carryString = "";
		carryNumber = 0;
	}
}

void LexicalAnalyzer::Comment(std::string& line, unsigned int& lineNumber, unsigned int& i)
{
	Token t = Token("COMMENT", "\"" + line.substr(i) + "\"", lineNumber);
	tokens.push_back(t);
	i = line.length();
}

void LexicalAnalyzer::BlockComments(std::string& s, std::string& line, unsigned int& i, unsigned int& l, std::string& carryString, unsigned int& carryNumber, bool& tokenTypeComment, unsigned int& lineNumber)
{
	unsigned int subStrBC = 2; //length of subStr Block Comments
	s = "#";
	i++;
	char character = line.at(i);
	std::string substring = ""; //to check for closing of block comment
	do
	{
		s += character;
		i++;
		if (i < l)
		{
			substring = line.substr(i, subStrBC);
		}
		if (i <= l)
		{
			character = line.at(i);
		}
		else
		{
			character = '0';
			carryString = s + "\n";
			carryNumber = lineNumber;
			tokenTypeComment = true;
			break;
		}
	} while (substring != "|#");
	if (!tokenTypeComment)
	{
		Token t = Token("COMMENT", "\"" + s + "|#\"", lineNumber);
		tokens.push_back(t);
		i++;
	}
}

void LexicalAnalyzer::TokenTypeComment(bool& tokenTypeComment, std::string& line, unsigned int& i, unsigned int& l, std::string& s, std::string& carryString, unsigned int& carryNumber)
{
	unsigned int subStrBC = 2; //length of subStr Block Comments
	if (i < l && line.substr(i, subStrBC) == "|#")
	{
		Token t = Token("COMMENT", "\"" + carryString + "|#\"", carryNumber);
		tokens.push_back(t);
		tokenTypeComment = false;
		carryString = "";
		carryNumber = 0;
		i++;
	}
	else
	{
		TokenTypeCommentCont(tokenTypeComment, line, i, l, s, carryString, carryNumber);
	}
}

void LexicalAnalyzer::TokenTypeCommentCont(bool& tokenTypeComment, std::string& line, unsigned int& i, unsigned int& l, std::string& s, std::string& carryString, unsigned int& carryNumber)
{
	unsigned int subStrBC = 2; //length of subStr Block Comments
	s = "";
	tokenTypeComment = false;
	char character = line.at(i);
	std::string substring = ""; //to look for the end of the block comment
	do
	{
		s += character;
		i++;
		if (i < l)
		{
			substring = line.substr(i, subStrBC);
		}
		if (i <= l)
		{
			character = line.at(i);
		}
		else
		{
			character = '0';
			carryString += s + "\n";
			tokenTypeComment = true;
			break;
		}
	} while (substring != "|#");
	if (!tokenTypeComment)
	{
		Token t = Token("COMMENT", "\"" + carryString + s + "|#\"", carryNumber);
		tokens.push_back(t);
		i++;
		carryString = "";
		carryNumber = 0;
	}
}

LexicalAnalyzer::~LexicalAnalyzer()
{
}

void LexicalAnalyzer::Print()
{
	for (unsigned int i = 0; i < tokens.size(); i++)
	{
		tokens.at(i).Print();
	}
	std::cout << "Total Tokens = " << tokens.size() << std::endl;
}
