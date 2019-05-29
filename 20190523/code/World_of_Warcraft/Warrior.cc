#include "Warrior.h"

#include <iostream>

using std::cout;
using std::endl;

//Warrior class
/*****************************************/
Warrior::Warrior(int id, int strength)
:_id(id),_strength(strength)
{
	//cout << "Warrior()" << endl;
}

Warrior::~Warrior(){
	//cout << "~Warrior()" << endl;
}

//int Warrior::_id = 0;

/*********************************************/

//Dragon class
/***********************************************/
int Dragon::_flag = 1;

Dragon::Dragon(int strength, const Arm &arm, double morale)
:Warrior(strength), _arm(arm), _morale(morale)
{
	//cout << "Dragon(int, const Arm &, double)" << endl;
}

Dragon::~Dragon(){
	//cout << "~Dragon()" << endl;
}
/***********************************************/

//Iceman class
/***********************************************/
int Iceman::_flag = 3;
Iceman::Iceman(int strength, const Arm &arm)
:Warrior(strength), _arm(arm)
{
	//cout << "Iceman(int, const Arm &)" << endl;
}

Iceman::~Iceman(){
	//cout << "~Iceman()" << endl;
}
/***********************************************/

//Ninja class
/***********************************************/
int Ninja::_flag = 2;

Ninja::Ninja(int strength, const Arm &arm1, const Arm &arm2)
:Warrior(strength), _arm1(arm1), _arm2(arm2)
{
	//cout << "Ninja(int, const Arm &, const Arm &)" << endl;
}

Ninja::~Ninja(){
	//cout << "~Ninja()" << endl;
}
/***********************************************/

//Lion class
/***********************************************/
int Lion::_flag = 4;

Lion::Lion(int strength, int loyalty)
:Warrior(strength), _loyalty(loyalty)
{
	//cout << "Lion(int, int)" << endl;
}

Lion::~Lion(){
	//cout << "~Lion()" << endl;
}
/***********************************************/

//Wolf class
/**********************************************/
int Wolf::_flag = 5;

Wolf::Wolf(int strength)
:Warrior(strength)
{
	//cout << "Wolf(int)" << endl;
}

Wolf::~Wolf(){
	//cout << "~Wolf()" << endl;
}
/**********************************************/
