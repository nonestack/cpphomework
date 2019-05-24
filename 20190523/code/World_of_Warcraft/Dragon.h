#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "Warrior.h"
#include "Arm.h"

class Dragon : public Warrior{
	public:
		Dragon(int, const Arm &, double);
		~Dragon();
	private:
		Arm _arm;
		double _morale;
};

#endif
