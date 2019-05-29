#include "Headquarter.h"
#include "Warrior.h"

#include <cstring>
#include <cstdio>

#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::iterator;

string sred[] = {"Iceman", "Lion", "Wolf", "Ninja", "Dragon"};
vector<string> Headquarter::_redOrder(sred, sred + 5);

string sblue[] = {"Lion", "Dragon", "Ninja", "Iceman", "Wolf"};
vector<string> Headquarter::_blueOrder(sblue, sblue + 5);
//vector<WarriorNum> Headquarter::_num;

Headquarter::Headquarter(int camp, int initStrength)
:_camp(camp)
, _initStrength(initStrength)
, _closeFlag(0)
, _totalWarriors(0)
, _record(0)
{
	//setOrder();
	int i;
	int len = _redOrder.size();
	WarriorNum tmp;
	if(camp == 1){
		for(i = 0; i < len; ++i){
			tmp.man = _redOrder[i];
			tmp.num = 0;
			_num.push_back(tmp);
		}
	}
	else{
		for(i = 0; i < len; ++i){
			tmp.man = _blueOrder[i];
			tmp.num = 0;
			_num.push_back(tmp);
		}
	}
}

void Headquarter::print(){
	char camp[5] = {0};
	if(_camp == 1){
		strcat(camp, "red");
	}
	else{
		strcat(camp, "blue");
	}
	cout << "I'm " << camp << ", I have "
		 << _initStrength << " strength "
		 << ", now have " << _totalWarriors
		 << "warrior(s)" << endl;
	cout << "order is ";
	int i, len = _redOrder.size();
	for(i = 0; i < len; ++i){
		cout << _redOrder[i] << ", ";
	}
	cout << endl;
}

Headquarter::~Headquarter(){
}

//void Headquarter::setOrder(vector<string> &svec){
//	int i;
//	int len = svec.size();
//	for(; i < len; ++i){
//		_order.push_back(svec[i]);
//	}
//}

int Headquarter::getFlag(){
	return _closeFlag;
}

void Headquarter::makeWarrior(int id, int now){
	if(_closeFlag == 1){
		//cout << "not enough strength" << endl;
		return;
	}
	string s1(_num[_record].man);
	int warriorLife = Warrior::getLife(s1);
	if(warriorLife < _initStrength){
		_initStrength -= warriorLife;
		_record = (_record + 1) % 5;
		Warrior soldier(_camp, s1.c_str(), id);
		++_num[_record].num;
		soldier.print(now, s1, _num[_record].num, warriorLife);
		return;
	}
	else{
		int sig = (_record + 1) % 5;
		while(sig != _record){
			s1 = _num[sig].man;
			if( (warriorLife = Warrior::getLife(s1)) < _initStrength){
				_initStrength -= warriorLife;
				_record = (sig + 1) % 5;
				Warrior soldier(_camp, s1.c_str(), id);
				++_num[sig].num;
				//soldier.print(now);
				soldier.print(now, s1, _num[_record].num, warriorLife);
				break;
			}
			else{
				sig = (sig + 1) % 5;
				continue;
			}
		}
		if(sig == _record){
			_closeFlag = 1;
			return ;
		}
	}
}
