#ifndef __HEADQUARTER_H__
#define __HEADQUARTER_H__

#include "Warrior.h"

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
		void makeWarrior(int, int);
		void print();
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
};


#endif
