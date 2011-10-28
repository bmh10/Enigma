
/*
	rotor.cpp - implements rotor functionality
*/

#include "rotor.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // For exit function

using namespace std;


Rotor::Rotor(char* filename) : numRotations(0)
{
	// Read in file 'filename' and put into rotorVec deque/vector

	ifstream indata;
	int x;
	indata.open(filename);

	// Error if file could not be opened
	if(!indata)
	{
    	cerr << "Error: rotor file could not be opened - " << filename << endl;
    	exit(1);
	}
	
	indata >> x;
	int i=0;

	// Keep reading until end-of-file
	while ( !indata.eof() ) 
	{
		rotorFwd[i] = x-i;
		rotorRev[x] = i-x;
		// Sets EOF flag if no value found
		indata >> x; 
		++i;
	}	
	indata.close();
}


Rotor::~Rotor()
{
}

/*
* Returns true and resets rotation count if rotor has fully rotated
*/
bool Rotor::HasFullyRotated()
{
	if (numRotations == 26)
	{
		numRotations = 0;
		return true;
	}
	return false;
}


int Rotor::MapInput(int x)
{
	if (x < SIZE)
	{
		int retVal = x+rotorFwd[x];
		if (retVal < 0)
			return 26+(retVal%26); 
		else
			return retVal%26;
	}
	cerr << endl << "Rotor Mapping error (x = " << x << " rotorVec size = " << sizeof(rotorFwd) << ")" << endl;
}

int Rotor::InverseMapInput(int x)
{
	if (x < SIZE)
	{
		int retVal = x+rotorRev[x];
		if (retVal < 0)
			return 26+(retVal%26);
		else
			return retVal%26;
	}
	cerr << endl << "Rotor Inverse-Mapping error (x = " << x << " rotorVec size = " << SIZE << ")" << endl;
}

/*
*  Rotate rotor moving vector one position to the right and top element into first position
*/
void Rotor::Rotate()
{
	// Store last element
	int tmpF = rotorFwd[SIZE-1];
	int tmpR = rotorRev[SIZE-1];
	
	// Shift all elements one place to the right
	for (int i = SIZE-2; i >= 0; --i)
	{
		rotorFwd[i+1] = rotorFwd[i];
		rotorRev[i+1] = rotorRev[i]; 
	}
	
	// Put original last element at front
	rotorFwd[0] = tmpF;
	rotorRev[0] = tmpR;

	numRotations++;
}


