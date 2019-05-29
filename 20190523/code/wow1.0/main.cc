#include "Headquarter.h"
#include "Warrior.h"

#include <cstdlib>

#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(int argc, char *argv[]){
	int i;
	vector<int> ivec;
	for(i = 1; i < 6; ++i){
		ivec.push_back(i);
	}
	Warrior::setStrength(ivec);
	//Warrior::print();
	//cout << "ok? " << endl;
	Headquarter red(1, 20);
	Headquarter blue(2, 20);
	
	int now = 0, id = 1;
	while(1){
		red.makeWarrior(id, now);
		blue.makeWarrior(id, now);
		if(red.getFlag() == 1 && blue.getFlag() == 1){
			break;
		}
		sleep(1);
		++id;
		++now;
	}

	return 0;
}
