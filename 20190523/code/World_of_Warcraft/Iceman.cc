#include "Iceman.h"
#include "Arm.h"

#include <iostream>

using std::cout;
using std::endl;

Iceman::Iceman(int strength, const Arm &arm)
:Warrior(strength), _arm(arm)
{
#if 1
	cout << "Iceman(int, const Arm &)" << endl;
#endif
}

Iceman::~Iceman(){
#if 1
	cout << "~Iceman()" << endl;
#endif
}
