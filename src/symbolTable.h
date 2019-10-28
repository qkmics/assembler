#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace::std;
class SymbolTable
{
public:
	SymbolTable(vector<vector<string>>& fields);
	~SymbolTable();
	void insert(string symbol, int value);
	int find(string symbol);

private:
	unordered_map<string, int> table;
	int nextAvailable;
};