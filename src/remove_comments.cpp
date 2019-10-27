﻿#include <iostream>
#include <string>
#include <fstream>
using namespace::std;
class finiteStateMachine
{
private:
	ifstream inputFile;
	ofstream outputFile;

public:
	bool runFSM(string inputFileName, string outputFileName) // use finite automaton
	{
		//open the input file and output file
		inputFile.open(inputFileName);
		outputFile.open(outputFileName);

		if (inputFile.is_open())
		{
			int state = 0;
			string inputLine;
			string outputLine;

			while (getline(inputFile, inputLine))  //get a line from the input file
			{
				outputLine = "";
				if (state == 2)       //handle one line comments
					state = 0;
				for (char ele : inputLine)
				{
					switch (state)     //the automaton has 5 states
					{
					case 0:
						if (ele == '/')						//it might be the start of a commemt
							state = 1;
						else if (ele != ' ' && ele != '\t')
							outputLine.push_back(ele);
						break;

					case 1:
						if (ele == '/')						//one line comment
							state = 2;
						else if (ele == '*')				//could be a comment
							state = 3;
						else
						{
							state = 0;
							outputLine.push_back('/');
							outputLine.push_back(ele);
						}
						break;

					case 2:						//the whole line is an one line comment, so do nothing 
						break;

					case 3:
						if (ele == '*')
							state = 4;
						break;

					case 4:
						if (ele == '/')
							state = 0;
						else if (ele != '*')
							state = 3;
						break;
					}

				}
				
				if (outputLine.size() > 1)	//this input line is not part of a comment
				{
					outputFile << outputLine << endl;
				}
			}
		}
		else
		{
			return false;
		}
		//close the input file and output file
		inputFile.close();
		outputFile.close();
		return true;
	}

public:
};
int main(void)
{
	finiteStateMachine mc;

	string inputName, outputName;
	cout << "Please input the input file name with the full path: ";
	getline(cin, inputName);

	// get output file name
	outputName = inputName;
	outputName.pop_back();
	outputName.pop_back();
	outputName += "out";

	while (!mc.runFSM(inputName, outputName))   //input error handling
	{
		cout << "Input file does not exists, please input another file: ";
		getline(cin, inputName);
	}
	cout << "Success" << endl;
	cout << "Output file is " << outputName << endl;
	return 0;
}