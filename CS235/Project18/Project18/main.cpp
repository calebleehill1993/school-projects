
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK ;
#endif
#include <fstream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Map.h"
#include "Set.h"

using namespace std;

int main(int argc, const char * argv[]) {
    VS_MEM_CHECK;
    ifstream inFile;
    ofstream outFile;
    //using the arguments to define the in file and the out file
    string inFileName = argv[1];
    string outFileName = argv[2];
    string line;
    string type;
    string name;
    string move_type;
    string command_line;
    
    Map<string, string> pokemon;
    Map<string, string> moves;
    Map<string, Set<string>> effectivities;
    Map<string, Set<string>> ineffectivities;

    
    inFile.open(inFileName);
    if(!inFile.is_open())
    {
        cerr << "error: unable to open file" << endl;
    }
    outFile.open(outFileName);
    if (!outFile)
    {
        cerr << "Unable to open " << argv[2] << " for output";
    }
    getline(inFile, line);
    while(!inFile.eof()) {
        if (line.empty()) {
            break;
        }
        // parsing pokemon into a map
        else if (line == "Pokemon:") {
            inFile >> name;
            while (name != "Moves:") {
                inFile >> type;
                pokemon[name] = type;
                inFile >> name;
                if (name.empty()) {
                    break;
                }
            }
            line = name;
            outFile << "Pokemon:" << endl << pokemon.toString();
        }
        // parsing moves into a map
        else if (line == "Moves:") {
            inFile >> name;
            while (name != "Effectivities:") {
                inFile >> type;
                moves[name] = type;
                inFile >> name;
                if (name.empty()) {
                    break;
                }
            }
            line = name;
            outFile << endl << "Moves:" << endl << moves.toString();
        }
        //parsing effectivites into a map
        else if (line == "Effectivities:") {
            getline(inFile, command_line);
            while (command_line != "Ineffectivities:") {
                std::stringstream ss;
                ss << command_line;
                ss >> type;
                effectivities[type];
                while (!ss.eof()) {
                    ss >> move_type;
                    effectivities[type].insert(move_type);
                }
                getline(inFile, command_line);
                if (command_line.empty()) {
                    break;
                }
            }
            line = type;
            outFile << endl << "Effectivities:" << endl << effectivities.toString();
        }
        
        //parsing effectivites into a map
        else if (line == "Ineffectivities:") {
            getline(inFile, command_line);
            while (command_line != "Ineffectivities:") {
                std::stringstream ss;
                ss << command_line;
                ss >> type;
                effectivities[type];
                while (!ss.eof()) {
                    ss >> move_type;
                    ineffectivities[type].insert(move_type);
                }
                getline(inFile, command_line);
                if (command_line.empty()) {
                    break;
                }
            }
            line = type;
            outFile << endl <<"Ineffectivities:" << endl << ineffectivities.toString();
        }
        //parses in battles and runs them.
        else if (line == "Battles:" ) {
            outFile << endl << "Battles:" << endl;
            string pokemon_1;
            string pokemon_2;
            string move_1;
            string move_2;
            //int score_1 = 0;
            //int score_2 = 0;
            getline(inFile, command_line);
            while(!inFile.eof()) {
                
                std::stringstream ss;
                ss << command_line;
                ss >> pokemon_1 >> move_1 >> pokemon_2 >> move_2;
                outFile << pokemon_1 << " (" << move_1 << ") vs " << pokemon_2 << " (" << move_2 << ") : ";
                //tests for Ineffectivities  and Effectivities in pokemon 
                if (effectivities[pokemon[pokemon_1 + ":"]].find(pokemon[pokemon_2])) {
                    if (effectivities[pokemon[pokemon_2 + ":"]].find(pokemon[pokemon_1])) {
                        outFile << "Tie!" << endl;
                    }
                    else {
                        outFile << pokemon_1 << " wins!" << endl;
                    }
                }
                else if (ineffectivities[pokemon[pokemon_1 + ":"]].find(pokemon[pokemon_2])) {
                    if (ineffectivities[pokemon[pokemon_2 + ":"]].find(pokemon[pokemon_1])){
                        outFile << "Tie!" << endl;
                    }
                    else {
                        outFile << pokemon_2 << " wins!" << endl;
                    }
                }
                else if (effectivities[pokemon[pokemon_2 + ":"]].find(pokemon[pokemon_1])){
                    outFile << pokemon_2 << " wins!" << endl;
                }
                else if (ineffectivities[pokemon[pokemon_2 + ":"]].find(pokemon[pokemon_1])) {
                    outFile << pokemon_1 << " wins!" << endl;
                }
                else {
                    outFile << "Tie!" << endl;
                }
                getline(inFile, command_line);
            }
                
        }
        else {
            getline(inFile, line);
        }
    }
    
    //closing files.
    inFile.close();
    outFile.close();
    return 0;
}

