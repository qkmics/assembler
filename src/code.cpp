#include "code.h"
#include "symbolTable.h"

vector<string> Code::Translate(const vector<vector<string>>& fields,SymbolTable table)
{
	vector<string> codes;
	for (auto field : fields)
	{
		string code;
		if (field[0] == "A")		//"A" instruction
		{
			code.push_back('0');
			if (field[1][0] >= '0' && field[1][0] <= '9')			//follow a number
			{
				code += this->toBinary(stoi(field[1]));
			}
			else												//follow a symbol
			{
				code += this->toBinary(table.find(field[1]));
			}
		}
		else						//"C" instruction
		{
			code = "111";
			code += this->comp(field[1]);
			code += this->dest(field[2]);
			code += this->jump(field[3]);
		}
		codes.push_back(code);
	}
	return codes;
}

//convert a number to a string of length 15
string Code::toBinary(int number)
{
	string result;
	for (int i = 14; i >= 0; i--)
	{
		if (number & (1 << i))
			result.push_back('1');
		else
			result.push_back('0');
	}
	return result;
}
string Code::comp(string field)
{
	string result;
	result = compTable[field];
	return result;
}

string Code::dest(string field)
{
	string result;
	result = destTable[field];
	return result;
}

string Code::jump(string field)
{
	string result;
	result = jumpTable[field];
	return result;
}

//initialize three tables
void Code::initialize()
{
	compTable["0"] = "0101010";
	compTable["1"] = "0111111";
	compTable["-1"] = "0111010";
	compTable["D"] = "0001100";
	compTable["A"] = "0110000";
	compTable["!D"] = "0001111";
	compTable["!A"] = "0110001";
	compTable["-D"] = "0001111";
	compTable["-A"] = "0110011";
	compTable["D+1"] = "0011111";
	compTable["A+1"] = "0110111";
	compTable["D-1"] = "0001110";
	compTable["A-1"] = "0110010";
	compTable["D+A"] = "0000010";
	compTable["D-A"] = "0010011";
	compTable["A-D"] = "0000111";
	compTable["D&A"] = "0000000";
	compTable["D|A"] = "0010101";
	compTable["M"] = "1110000";
	compTable["!M"] = "1110001";
	compTable["-M"] = "1110011";
	compTable["M+1"] = "1110111";
	compTable["M-1"] = "1110010";
	compTable["D+M"] = "1000010";
	compTable["D-M"] = "1010011";
	compTable["M-D"] = "1000111";
	compTable["D&M"] = "1000000";
	compTable["D|M"] = "1010101";

	destTable[""] = "000";
	destTable["M"] = "001";
	destTable["D"] = "010";
	destTable["MD"] = "011";
	destTable["A"] = "100";
	destTable["AM"] = "101";
	destTable["AD"] = "110";
	destTable["AMD"] = "111";


	jumpTable[""] = "000";
	jumpTable["JGT"] = "001";
	jumpTable["JEQ"] = "010";
	jumpTable["JGE"] = "011";
	jumpTable["JLT"] = "100";
	jumpTable["JNE"] = "101";
	jumpTable["JLE"] = "110";
	jumpTable["JMP"] = "111";
}