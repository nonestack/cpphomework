#include "Wolf.h"

#include <iostream>

using std::cout;
using std::endl;

Wolf::Wolf(int strength)
:Warrior(strength)
{
#if 1
	cout << "Wolf(int)" << endl;
#endif
}

Wolf::~Wolf(){
#if 1
	cout << "~Wolf()" << endl;
#endif
}
