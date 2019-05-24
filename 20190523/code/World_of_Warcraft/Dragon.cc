#include "Dragon.h"
#include "Arm.h"

#include <iostream>

using std::cout;
using std::endl;

Dragon::Dragon(int strength, const Arm &arm, double morale)
:Warrior(strength), _arm(arm), _morale(morale)
{
#if 1
	cout << "Dragon(int, const Arm &, double)" << endl;
#endif
}

Dragon::~Dragon(){
#if 1
	cout << "~Dragon()" << endl;
#endif
}
