#include "Ninja.h"
#include "Arm.h"

#include <iostream>

using std::cout;
using std::endl;

Ninja::Ninja(int strength, const Arm &arm1, const Arm &arm2)
:Warrior(strength), _arm1(arm1), _arm2(arm2)
{
#if 1
	cout << "Ninja(int, const Arm &, const Arm &)" << endl;
#endif
}

Ninja::~Ninja(){
#if 1
	cout << "~Ninja()" << endl;
#endif
}
