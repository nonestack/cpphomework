#include "Lion.h"

#include <iostream>

using std::cout;
using std::endl;

Lion::Lion(int strength, int loyalty)
:Warrior(strength), _loyalty(loyalty)
{
#if 1
	cout << "Lion(int, int)" << endl;
#endif
}

Lion::~Lion(){
#if 1
	cout << "~Lion()" << endl;
#endif
}
