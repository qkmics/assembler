#pragma once
#include <string>
#include <vector>
using namespace std;

class Parser
{
public:
	vector<vector<string>> parse(vector<string> lines);
	
private:
	vector<string> parseOneLine(string line);
};