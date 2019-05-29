#include "Warrior.h"
#include "Arm.h"

#include <cstdio>
#include <cstring>

#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::iterator;

//Warrior
/**********************************************************/
string s1[] = {"Dragon", "Ninja", "Iceman", "Lion", "Wolf"};
vector<string> Warrior::_name(s1, s1 + 5);
vector<int> Warrior::_strength;

Warrior::Warrior(int camp,  const char *kind, int id)
:_camp(camp), _kind(new char[strlen(kind) + 1]()), _id(id)
{
	strcat(_kind, kind);
}

void Warrior::setStrength(vector<int> &ivec){
	int i;
	for(i = 0; i < ivec.size(); ++i){
		_strength.push_back(ivec[i]);
	}
}

int Warrior::getLife(const string &name){
	int i;
	for(i = 0; i < _name.size(); ++i){
		if(name == _name[i]){
			return _strength[i];
		}
	}
	return -1;
}

void Warrior::print(int now, const string &kind, int num, int strength){
	char camp[5] = {0};
	if(_camp == 1){
		strcat(camp, "red");
	}
	else{
		strcat(camp, "blue");
	}
	printf("%03d %s %s %d born with strength %d, %d %s in %s headquarter\n", now, camp, kind.c_str(), _id, strength, num, kind.c_str(), camp);
}


#if 0
void Warrior::print(){
	int i, len = _name.size();
	for(i = 0; i < len; ++i){
		cout << _name[i] << " is " << _strength[i] << endl;
	}
}
#endif

Warrior::~Warrior(){
	delete [] _kind;
}
/**********************************************************/

//Dragon
/**********************************************************/
Dragon::Dragon(int camp, const char *kind, int id, Arm &arm, int HeadStrength)
: Warrior(camp, kind, id)
, _arm(arm)
, _morale((double)HeadStrength / Warrior::getLife(kind))
{
}

void Dragon::print(int now, const string &kind, int num, int strength){
	Warrior::print(now, kind, num, strength);
	printf("It has a %s, and it's morale is %.2lf.\n", _arm.getName(),  _morale);
}

Dragon::~Dragon(){
}

/**********************************************************/
//Ninja
/**********************************************************/
Ninja::Ninja(int camp, const char *kind, int id, Arm &arm1, Arm &arm2)
:Warrior(camp, kind, id)
,_larm(arm1)
,_rarm(arm2)
{
}

void Ninja::print(int now, const string &kind, int num, int strength){
	Warrior::print(now, kind, num, strength);
	printf("It has a %s and a %s.\n", _larm.getName(), _rarm.getName());
}

Ninja::~Ninja(){
}
/**********************************************************/
//Iceman
/**********************************************************/
Iceman::Iceman(int camp, const char *kind, int id, Arm &arm1)
:Warrior(camp, kind, id)
,_arm(arm1)
{
}

void Iceman::print(int now, const string &kind, int num, int strength){
	Warrior::print(now, kind, num, strength);
	printf("It has a %s.\n", _arm.getName());
}

Iceman::~Iceman(){
}
/**********************************************************/
//Lion
/**********************************************************/
Lion::Lion(int camp, const char *kind, int id, int HeadStrength)
:Warrior(camp, kind, id)
,_loyalty(HeadStrength - Warrior::getLife(kind))
{
}

void Lion::print(int now, const string &kind, int num, int strength){
	Warrior::print(now, kind, num, strength);
	printf("It's loyalty is %d.\n", _loyalty);
}

Lion::~Lion(){
}
/**********************************************************/
//Wolf
/**********************************************************/
Wolf::Wolf(int camp, const char *kind, int id)
:Warrior(camp, kind, id)
{
}

void Wolf::print(int now, const string &kind, int num, int strength){
	Warrior::print(now, kind, num, strength);
}

Wolf::~Wolf(){
}
/**********************************************************/
