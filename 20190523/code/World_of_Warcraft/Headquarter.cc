#include "Headquarter.h"

#include <iostream>

using std::cout;
using std::endl;

Headquarter::Headquarter(int strength)
:City(strength)
{
#if 1
	cout << "Headquarter(int)" << endl;
#endif
}

Headquarter::~Headquarter(){
#if 1
	cout << "~Headquarter()" << endl;
#endif
}
