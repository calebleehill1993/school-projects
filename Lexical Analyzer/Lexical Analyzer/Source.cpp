using namespace std;
#include <fstream>
#include "DataLogProgram.h"

int main(int argc, char *argv[])
{
	ifstream input;
	input.open(argv[1]);
	LexicalAnalyzer la = LexicalAnalyzer(input);
	la.Print();
	DataLogProgram dlp = DataLogProgram(la);
	return 0;
};
