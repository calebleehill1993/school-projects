/*
The Set class works very well, but then I got to the Map class and things just went downhill.
The maps for pokemon and moves work fine, but I couldn't figure out the Sets.
*/

#include <fstream>
#include <sstream>

#include "Set.h"
#include "Map.h"
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

int main(int argc, char* argv[]) {

	VS_MEM_CHECK

	ifstream in(argv[1]);
	ofstream out(argv[2]);

	Map<string, string> pokemon;
	Map<string, string> moves;
//	Map<string, Set<string>> effectivities;
//	Map<string, Set<string>> ineffectivities;

	string line;
	string subLine;
	string tempLine;

	getline(in, line);
	if (line == "Pokemon:") {
		out << "Pokemon:" << endl;
		while (line != "") {
			getline(in, line);
			subLine = line.substr(0, line.find(" "));
			tempLine = line.substr(line.find(" ") + 1);
			pokemon[subLine] = tempLine;
		}
	}
	out << pokemon << endl;
	getline(in, line);
	if (line == "Moves:") {
		out << "Moves:" << endl;
		while (line != "") {
			getline(in, line);
			subLine = line.substr(0, line.find(" "));
			tempLine = line.substr(line.find(" ") + 1);
			moves[subLine] = tempLine;
		}
	}
	out << moves << endl;
	/*getline(in, line);
	if (line == "Effectivities:") {
		while (line != "") {
			
		}
	}
	getline(in, line);
	if (line == "Ineffectivities:") {
		while (line != "") {
			
		}
	}
	getline(in, line);
	if (line == "Battle:") {
		while (!in.eof()) {
			
		}
	}*/


	in.close();
	out.close();

	return 0;
}