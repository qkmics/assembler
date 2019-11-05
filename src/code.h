#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "symbolTable.h"
using namespace std;
class Code
{
public:
	vector<string> Translate(const vector<vector<string>>& fields, SymbolTable table);
	void initialize();
private:
	string toBinary(int number);
	string comp(string field);
	string dest(string field);
	string jump(string field);
	unordered_map<string,string> compTable;
	unordered_map<string, string> destTable;
	unordered_map<string, string> jumpTable;
};