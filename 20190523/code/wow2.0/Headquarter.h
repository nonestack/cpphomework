#ifndef __HEADQUARTER_H__
#define __HEADQUARTER_H__

#include "Warrior.h"
#include "Arm.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

struct WarriorNum{
	string man;
	int num;
};

class Headquarter{
	public:
		Headquarter(int, int);
		~Headquarter();
		int getFlag();
		void factory(int, int);
		void makeWarrior(int, const char *, int, int, int, int, int);
		int getKind(const char *);
		void print();
		static void init();
		static void initOrder();
		static void initWeaponStore();
		//void setOrder();
	private:
		int _camp;
		int _initStrength;
		int _closeFlag;
		int _totalWarriors;
		vector<WarriorNum> _num;
		int _record;
		static vector<string> _redOrder;
		static vector<string> _blueOrder;
		static vector<Arm> _weaponStore;
};


#endif
