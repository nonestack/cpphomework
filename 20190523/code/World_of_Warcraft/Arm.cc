#include "Arm.h"

#include <cstring>

#include <iostream>

using std::cout;
using std::endl;

Arm::Arm(const char *name, int id)
:_name(new char[strlen(name) + 1]()), _id(id)
{
	strcat(_name, name);
#if 1
	cout << "Arm(const char *, int)" << endl;
#endif
}

Arm::Arm(const Arm &arm)
:_name(new char[strlen(arm._name) + 1]()), _id(arm._id)
{
	strcat(_name, arm._name);
#if 1
	cout << "Arm(const Arm &)" << endl;
#endif
}

Arm::~Arm(){
	delete [] _name;
#if 1
	cout << "~Arm()" << endl;
#endif
}

void Arm::getName(){
	cout << _name << endl;
}
