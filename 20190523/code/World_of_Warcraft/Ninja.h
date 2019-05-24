#ifndef __NINJA_H__
#define __NINJA_H__

#include "Warrior.h"
#include "Arm.h"

class Ninja : public Warrior{
	public:
		Ninja(int, const Arm &, const Arm &);
		~Ninja();
	private:
		Arm _arm1;
		Arm _arm2;
};

#endif
