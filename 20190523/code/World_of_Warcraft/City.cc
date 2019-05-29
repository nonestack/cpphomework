#include "City.h"

#include <cstring>

#include <iostream>
#include <string>
#include <vector>
#include <iterator>


using std::cout;
using std::endl;
using std::string;
using std::vector;

//City class
/***************************************/

City::City(int strength)
:_strength(strength)
{
	//cout << "City(int)" << endl;
}

int City::getNowStrength(){
	return _strength;
}

void decreaseStrength(int num){
	_strength -= num;
}

City::~City(){
	//cout << "City()" << endl;
}
/***************************************/
//Arm class
/***************************************/

Arm::Arm(const char *name, int id)
:_name(new char[strlen(name) + 1]()), _id(id)
{
	strcat(_name, name);
	//cout << "Arm(const char *, int)" << endl;
}

Arm::Arm(const Arm &arm)
:_name(new char[strlen(arm._name) + 1]()), _id(arm._id)
{
	strcat(_name, arm._name);
	//cout << "Arm(const Arm &)" << endl;
}

Arm::~Arm(){
	delete [] _name;
	//cout << "~Arm()" << endl;
}

void Arm::getName(){
	cout << "name is " <<  _name << ", id is " << _id << endl;
}
/***************************************/

//Headquarter class
/***************************************/
int Headquarter::_armId = 0;

Headquarter::Headquarter(int strength)
:City(strength), _count(0)
{
	//cout << "Headquarter(int)" << endl;
}

void Headquarter::addArm(const char *armName){
	Arm tmp(armName, _armId++);
	_armStore.push_back(tmp);
}

void Headquarter::addCount(){
	++_count;
}

void setOrder(int *A, int size){
	if(size > 5){
		cout << "size of array is more large" << endl;
		return;
	}
	int i;
	for(i = 0; i < 5; ++i){
		_orderWarrior[i] = 0;
	}
	for(i = 0; i < size; ++i){
		_orderWarrior[i] = A[i];
	}
}

int Headquarter::getCount(){
	return _count;
}

//void Headquarter::addWrrior(const Warrior &originWarrior, int flag){
//	Headquarter::WarriorInfo tmp(
//}

void Headquarter::dealFun(int tmpTime, int num){
	switch(num){
		case 1: deal
	}
}

void Headquarter::printArm(){
	vector<Arm>::iterator iter = _armStore.begin();
	for(; iter != _armStore.end(); ++iter){
		iter->getName();
	}
}

Headquarter::~Headquarter(){
	//cout << "~Headquarter()" << endl;
}
/***************************************/
