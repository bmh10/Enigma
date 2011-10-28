
/*
	reflector.cpp - implements reflector functionality
*/

#include "reflector.h"

using namespace std;


Reflector::Reflector()
{
}

Reflector::~Reflector()
{
}

int Reflector::MapInput(int x)
{
	return (x + 13) % 26;
}
