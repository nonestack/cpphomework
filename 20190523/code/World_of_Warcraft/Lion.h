#ifndef __LION_H__
#define __LION_H__

#include "Warrior.h"

class Lion : public Warrior{
	public:
		Lion(int, int);
		~Lion();
	private:
		int _loyalty;
};

#endif
