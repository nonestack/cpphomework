#include "Arm.h"

#include <cstring>

#include <iostream>

using std::cout;
using std::endl;

Arm::Arm(string name, int initDamage, int id)
:_name(name)
,_initDamage(initDamage)
,_id(id)
,_damage(initDamage)
{
}

Arm::Arm(const Arm &arm)
:_name(arm._name)
,_damage(arm._damage)
,_initDamage(arm._initDamage)
,_id(arm._id)
{
}

const char *Arm::getName(){
	return _name.c_str();
}

Arm::~Arm(){
	//cout << "~Arm()" << endl;
}
