#ifndef ROTOR_H
#define ROTOR_H

#include "mapper.h"
#include <string>
#include <vector>
using std::vector;

class Rotor : public Mapper
{
	static const int SIZE = 26;
	int rotorFwd [SIZE];
	int rotorRev [SIZE];
		

	public:
int numRotations;
		Rotor(char* filename);
		~Rotor();
		
		bool HasFullyRotated();
		int MapInput(int);
		int InverseMapInput(int);

		void Rotate();
};
#endif
