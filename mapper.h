#ifndef MAPPER_H
#define MAPPER_H

class Mapper
{
	public:
		// Rotor, reflector and plugboard all override this function to map input to output 
		virtual int MapInput(int) = 0;
};
#endif
