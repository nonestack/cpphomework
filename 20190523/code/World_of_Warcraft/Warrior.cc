#include "Warrior.h"

#include <iostream>

using std::cout;
using std::endl;

Warrior::Warrior(int strength)
:_strength(strength)
{
	++_id;
#if 1
	cout << "Warrior()" << endl;
#endif
}

Warrior::Warrior(){
#if 1
	cout << "~Warrior()" << endl;
#endif 
}

int Warrior::_id = 0;
