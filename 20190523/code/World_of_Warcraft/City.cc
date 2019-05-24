#include "City.h"

#include <iostream>

using std::cout;
using std::endl;

City::City(int strength)
:_strength(strength)
{
#if 1
	cout << "City(int)" << endl;
#endif
}

City::~City(){
#if 1
	cout << "City()" << endl;
#endif
}
