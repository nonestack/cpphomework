#include "Warrior.h"

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

int Warrior::getLife(string &name){
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

