#include "code.h"
#include "preprocessor.h"
#include "parser.h"
#include "symbolTable.h"

int main(int argc, char* argv[])
{
	string inputName, outputName;
	if(argc>1)
		inputName = argv[1];
	else
	{
		cout << "Command line parameter should be name of input file" << endl;
		return -1;
	}

	// calculate output file name
	outputName = inputName;
	outputName.pop_back();
	outputName.pop_back();
	outputName.pop_back();
	outputName += "hack";

	Preprocessor preprocessor;		
	vector<string> inLines = preprocessor.runFSM(inputName);		//preprocess input file
	Parser parser;
	vector<vector<string>> fields = parser.parse(inLines);			//parse
	SymbolTable symbolTable(fields);								//build symbol table
	Code code;
	code.initialize();												//build code tables
	vector<string> outLines = code.Translate(fields,symbolTable);	//do translation
	
	//output outLines to file
	ofstream outputFile;					
	outputFile.open(outputName);
	for (string line : outLines)
	{
		outputFile << line << endl;
	}
	outputFile.close();

	cout << "Output file is " << outputName << endl;
	
	return 0;
}