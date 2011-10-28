#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "mapper.h"
#include <map>
using std::map;

class Plugboard : public Mapper
{
	 map<int,int> plugboardMap;
	
	public:
		Plugboard(char* filename);
		~Plugboard();

		int	MapInput(int);
};
#endif
