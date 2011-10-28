/*
*	enigma.cpp - entry point to program
*/

#include "mapper.h"
#include "plugboard.h"
#include "rotor.h"
#include "reflector.h"
#include <ctype.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;


// Forward method declarations
char EncryptChar(char);
void RotateRotors();
int MapCharToInt(char);
char MapIntToChar(int);
bool CheckValidPbFile(char*);

Plugboard* plugboard;
Reflector* reflector;
vector<Rotor> rotors;
bool debug = false;
bool polyalphaEncoding = true;

int main(int numArgs, char** args )
{

	if (debug)
		cout << "Number of args into main: " << numArgs << endl;

	if (numArgs < 2)
	{
		cout << "Please run program using command form ./enigma <[rotor file.rot]> <plugboard file.pb>" << endl;
		cout << "Rotors are optional and you may use any number of them" << endl;
		return 1;
	}


	// Get rotors (all but first and last arg)
	for (int i = 1; i < numArgs-1; ++i)
	{
		Rotor* r = new Rotor(args[i]);
		rotors.push_back(*r);
		if (debug)
			cout << "Rotor " << args[i] << " added to rotors vector" << endl;
	}


	if (debug)
		cout << "Number of rotors: " << rotors.size() << endl;

	// Get plugboard config (last arg)
	if (CheckValidPbFile(args[numArgs-1]))
	{
		plugboard = new Plugboard(args[numArgs-1]);	
		if (debug)
			cout << "Plugboard " << args[numArgs-1] << " created" << endl;
	}
	else
	{
		cout << ".pb file expected for plugboard configuration" << endl;
		return 1;
	}

	reflector = new Reflector();

	if (debug)
		cout << "Enigma setup complete..." << endl;


	// Read in char by char from standard input until EOF reached
	char curr;

	while (cin)
	{
		curr = cin.get();
		if (isupper(curr))
		{
			cout << EncryptChar(curr);
		}
		else if (isspace(curr))
			cout << curr;
		else
			continue;
	}


	cout << endl;

	if (debug)
		cout << endl << "Exiting main..." << endl;

	return 0;
}

/*
* Simulates the encryption process in enigma machine
*/
char EncryptChar(char c)
{
	int n = MapCharToInt(c);
	
	// First pass through plugboard
	n = plugboard->MapInput(n);
	
	// Pass through rotors in order
	for (int i = 0; i < rotors.size(); ++i)
		n = rotors[i].MapInput(n);

	// Pass through reflector at end
	n = reflector->MapInput(n);

	// Pass through rotors in reverse order
	for (int i = rotors.size()-1; i >= 0; --i)
		n = rotors[i].InverseMapInput(n);

	// Second pass through plugboard
	n = plugboard->MapInput(n);

	// For polyalphabetic encoding, rotate rotors ready for next char to be encrypted
	if (rotors.size() > 0 && polyalphaEncoding)
		RotateRotors();

	return MapIntToChar(n); //?? do later
}

/*
* Manages rotation of all rotors
*/
void RotateRotors()
{
	// Rotor in first position is always rotated
	rotors[0].Rotate();

	// If HasFullyRotated is true it internally resets rotation count to 0
	for (int i = 0; i < rotors.size(); ++i)
	{
		if (rotors[i].HasFullyRotated())
		{
			// Check there is a 'higher' rotor to rotate
			if (i+1 < rotors.size())
				rotors[i+1].Rotate();
		}
	}
}

/*
* Map upper case char to its index in alphabet (a=0, z=25)
*/
int MapCharToInt(char c)
{
	return c - 'A';
}

/*
* Map int to its corresponding upper case letter in alphabet (0=a, 25=z)
*/
char MapIntToChar(int i)
{
    return (i % 26) + 'A';
}

/*
* Checks that a file name is a valid plugboard file (i.e. ends in .pb)
*/
bool CheckValidPbFile(char* filename)
{
	if (filename[strlen(filename)-3] == '.' &&
		filename[strlen(filename)-2] == 'p' &&
		filename[strlen(filename)-1] == 'b')
		return true;

	return false;
}
