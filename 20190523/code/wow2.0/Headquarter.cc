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

//static Arm arm1("sword", 0, 0);
//static Arm arm2("bomb", 0, 1);
//static Arm arm3("arrow", 0, 2);

vector<string> Headquarter::_redOrder;

vector<string> Headquarter::_blueOrder;
//vector<WarriorNum> Headquarter::_num;
vector<Arm> Headquarter::_weaponStore;

void Headquarter::init(){
	Headquarter::initOrder();
	Headquarter::initWeaponStore();
	//_weaponStore.push_back(arm1);
	//_weaponStore.push_back(arm2);
	//_weaponStore.push_back(arm3);
}

void Headquarter::initOrder(){
	_redOrder.push_back("Iceman");
	_redOrder.push_back("Lion");
	_redOrder.push_back("Wolf");
	_redOrder.push_back("Ninja");
	_redOrder.push_back("Dragon");

	_blueOrder.push_back("Lion");
	_blueOrder.push_back("Dragon");
	_blueOrder.push_back("Ninja");
	_blueOrder.push_back("Iceman");
	_blueOrder.push_back("Wolf");
#if 0
	string sred[] = {"Iceman", "Lion", "Wolf", "Ninja", "Dragon"};
	string sblue[] = {"Lion", "Dragon", "Ninja", "Iceman", "Wolf"};
	int i;
	for(i = 0; i < 5; ++i){
		cout << "red is " << sred[i] << endl;
		cout << "blue is " << sblue[i] << endl;
		_redOrder.push_back(sred[i]);
		_blueOrder.push_back(sblue[i]);
	}
#endif
}

void Headquarter::initWeaponStore(){

	//_weaponStore.push_back(Arm("sword", 0, 0));
	//_weaponStore.push_back(Arm("bomb", 0, 1));
	//_weaponStore.push_back(Arm("arrow", 0, 2));
	Arm arm1("sword", 0, 0);
	Arm arm2("bomb", 0, 1);
	Arm arm3("arrow", 0, 2);
	_weaponStore.push_back(arm1);
	_weaponStore.push_back(arm2);
	_weaponStore.push_back(arm3);
}

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
	int i;
	for(i = 0; i < _weaponStore.size(); ++i){
		cout << _weaponStore[i].getName() << endl;
	}
#if 0
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
#endif
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


#if 1
void Headquarter::factory(int id, int now){
	if(_closeFlag == 1){
		//cout << "not enough strength" << endl;
		return;
	}
	int soldierNum = 0;
	string s1(_num[_record].man);
	int warriorLife = Warrior::getLife(s1);
	if(warriorLife < _initStrength){
		_initStrength -= warriorLife;
		_record = (_record + 1) % 5;
		soldierNum = _num[_record].num++;
		makeWarrior(_camp, s1.c_str(), id, now, soldierNum, warriorLife, _initStrength);
#if 0
		Warrior soldier(_camp, s1.c_str(), id);
		soldier.print(now, s1, _num[_record].num, warriorLife);
#endif
		return;
	}
	else{
		int sig = (_record + 1) % 5;
		while(sig != _record){
			s1 = _num[sig].man;
			if( (warriorLife = Warrior::getLife(s1)) < _initStrength){
				_initStrength -= warriorLife;
				_record = (sig + 1) % 5;
				soldierNum = _num[sig].num++;
				makeWarrior(_camp, s1.c_str(), id, now, soldierNum, warriorLife, _initStrength);
#if 0
				Warrior soldier(_camp, s1.c_str(), id);
				//soldier.print(now);
				soldier.print(now, s1, _num[_record].num, warriorLife);
#endif
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

void Headquarter::makeWarrior(int camp, const char *kind, int id, int now, int soldierNum, int soldierLife, int HeadStrength){
	int kindNum;
	kindNum = getKind(kind);
	Warrior *soldier;
	switch(kindNum){
		case 1 : {
					 Dragon dragon(camp, kind, id, _weaponStore[id % 3], HeadStrength);
					 soldier = &dragon;
					 break;
				 }
		case 2 : {
					Ninja ninja(camp, kind, id, _weaponStore[id % 3] , _weaponStore[(id + 1) % 3]);
					soldier = &ninja;
					break;
				 }
		case 3 : {
					 Iceman iceman(camp, kind, id, _weaponStore[id % 3]);
					 soldier = &iceman;
					 break;
				 }
		case 4 : {
					 Lion lion(camp, kind, id, HeadStrength);
					 soldier = &lion;
					 break;
				 }
		case 5 : {
					 Wolf wolf(camp, kind, id);
					 soldier = &wolf;
					 break;
				 }
	}
	soldier->print(now, kind, soldierNum, soldierLife);
}

int Headquarter::getKind(const char *kind){
	if(strcmp(kind, "Dragon") == 0){
		return 1;
	}
	if(strcmp(kind, "Ninja") == 0){
		return 2;
	}
	if(strcmp(kind, "Iceman") == 0){
		return 3;
	}
	if(strcmp(kind, "Lion") == 0){
		return 4;
	}
	if(strcmp(kind, "Wolf") == 0){
		return 5;
	}
}

#endif
