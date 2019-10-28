#include "symbolTable.h"
//build the symbol table
SymbolTable::SymbolTable(vector<vector<string>>& fields)
{	
	nextAvailable = 16;

	table["SP"] = 0;
	table["LCL"] = 1;
	table["ARG"] = 2;
	table["THIS"] = 3;
	table["THAT"] = 4;
	for (int i = 0;i <= 15;i++)
	{
		table["R" + to_string(i)] = i;
	}
	table["SCREEN"] = 16384;
	table["KBD"] = 24576;

	for (int i = 0;i < fields.size();i++)
	{
		if (fields[i][0] == "symbol")
		{
			table[fields[i][1]] = i;
			fields.erase(fields.begin() + i);
			i--;						//because we deleted one line
		}
	}
}

SymbolTable::~SymbolTable()
{
	
}
void SymbolTable::insert(string symbol, int value)
{
	table[symbol] = value;
}
int SymbolTable::find(string symbol)
{
	if (!table.count(symbol))
	{
		table[symbol] = nextAvailable;
		nextAvailable++;
	}
	return table[symbol];
	
	
}
