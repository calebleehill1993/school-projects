#include "Token.h"
#include <vector>
#include <fstream>
#include <iostream>
class LexicalAnalyzer
{
public:
	LexicalAnalyzer();
	LexicalAnalyzer(std::ifstream& inFile);
	~LexicalAnalyzer();
	std::vector<Token> tokens;
	void Print();
	void TokenTypeString(bool& tokenTypeString, std::string& line, unsigned int& i, unsigned int& l, std::string& s, std::string& carryString, unsigned int& carryNumber);
	void TokenTypeStringCont(bool& tokenTypeString, std::string& line, unsigned int& i, unsigned int& l, std::string& s, std::string& carryString, unsigned int& carryNumber);
	void TokenTypeComment(bool& tokenTypeComment, std::string& line, unsigned int& i, unsigned int& l, std::string& s, std::string& carryString, unsigned int& carryNumber);
	void TokenTypeCommentCont(bool& tokenTypeComment, std::string& line, unsigned int& i, unsigned int& l, std::string& s, std::string& carryString, unsigned int& carryNumber);
	void BlockComments(std::string& s, std::string& line, unsigned int& i, unsigned int& l, std::string& carryString, unsigned int& carryNumber, bool& tokenTypeComment, unsigned int& lineNumber);
	void Comment(std::string& line, unsigned int& lineNumber, unsigned int& i);
	void Comma(unsigned int& lineNumber);
	void Period(unsigned int& lineNumber);
	void QuestionMark(unsigned int& lineNumber);
	void LeftParen(unsigned int& lineNumber);
	void RightParen(unsigned int& lineNumber);
	void Colon(std::string& line, unsigned int& i, unsigned int& l, unsigned int& lineNumber);
	void Multiply(unsigned int& lineNumber);
	void Add(unsigned int& lineNumber);
	void String(std::string& s, std::string& line, unsigned int& i, unsigned int& l, std::string& carryString, unsigned int& carryNumber, bool& tokenTypeString, unsigned int& lineNumber);
	void ID(unsigned int& ascii, std::string& s, std::string& line, unsigned int& i, unsigned int& l, unsigned int& lineNumber);
	void AssembleID(unsigned int& ascii, std::string& s, std::string& line, unsigned int& i, unsigned int& l, unsigned int& lineNumber);
	void KeyWords(std::string& s, unsigned int& lineNumber);
	void Analyzer(std::string& line, unsigned int& lineNumber, std::string& carryString, unsigned int& carryNumber, bool& tokenTypeString, bool& tokenTypeComment, std::string& s, unsigned int& l, unsigned int& i);

};
