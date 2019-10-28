#include "parser.h"
vector<vector<string>> Parser::parse(vector<string> lines)
{
	vector<vector<string>> fields;
	for (int i = 0;i < lines.size();i++)
		fields.push_back(parseOneLine(lines[i]));
	return fields;
}
vector<string> Parser::parseOneLine(string line)
{
	vector<string> fields;  //underlying fields
	if (line[0] == '(')		//symbol declaration (symbol)
	{
		fields.push_back("symbol");
		string symbol=line.substr(1,line.size()-2);			//')' not included
		fields.push_back(symbol);
	}
	else if (line[0]=='@')	//'A' instruction
	{
		fields.push_back("A");
		fields.push_back(line.substr(1, line.size()));
	}
	else					//'C' instruction
	{
		fields.push_back("C");
		bool hasEqual = false;
		for (char c : line)
		{
			if (c == '=')
				hasEqual = true;
		}
		string dest, comp, jump;
		int pos = 0;
		if (hasEqual)
		{
			while (line[pos] != '=')
			{
				dest.push_back(line[pos]);
				pos++;
			}
			pos++;
		}
		while (pos < line.size() && line[pos] != ';')
		{
			comp.push_back(line[pos]);
			pos++;
		}
		pos++;
		while (pos < line.size())
		{
			jump.push_back(line[pos]);
			pos++;
		}
		fields.push_back(comp);
		fields.push_back(dest);
		fields.push_back(jump);

	}
	return fields;
}