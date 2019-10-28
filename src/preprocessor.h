#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace::std;
class Preprocessor
{
public:
	vector<string> runFSM(string inputFileName); // use finite automaton

private:
	ifstream inputFile;
};
