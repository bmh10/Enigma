
/*
	plugboard.cpp - implements plugboard functionality
*/

#include "plugboard.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib> // for exit function

using namespace std;

Plugboard::Plugboard(char* filename)
{
// Read in file 'filename' and add each pair to map

	ifstream indata;
	int x, y;
	indata.open(filename);

	// Error if file could not be opened
	if(!indata)	
	{ 
    	cerr << "Error: plugboard file could not be opened" << endl;
    	exit(1);
	}

	indata >> x;
	indata >> y;
	 // Keep reading until end-of-file
	while ( !indata.eof() )
	{
			plugboardMap.insert(pair<int, int>(x, y));
			indata >> x;
			indata >> y;
	}	
	indata.close();
}


Plugboard::~Plugboard()
{

}

/*
*  Searches for key/value x in map if found returns corresponding value/key from pair 
*/
int Plugboard::MapInput(int x)
{
	map<int,int>::iterator iter = plugboardMap.begin();
	for (iter = plugboardMap.begin(); iter != plugboardMap.end(); ++iter)
	{
		if (iter->first == x)
			return iter->second;
		else if (iter->second == x)
			return iter->first;
	}
        return x;
}

