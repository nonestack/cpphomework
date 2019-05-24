#ifndef __ICEMAN_H__
#define __ICEMAN_H__

#include "Warrior.h"
#include "Arm.h"

class Iceman : public Warrior{
	public:
		Iceman(int, const Arm &);
		~Iceman();
	private:
		Arm _arm;
};

#endif
