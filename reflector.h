#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "mapper.h"

class Reflector : public Mapper
{
	public:
		Reflector();
		~Reflector();
		
		int MapInput(int);
};
#endif
