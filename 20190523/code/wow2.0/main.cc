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
	//over
	Headquarter red(1, 20);
	Headquarter blue(2, 20);
	Headquarter::init();	//initate Headquarter class
	//red.print();
	int now = 0, id = 1;
	//over
#if 1
	while(1){
		red.factory(id, now);	//have bug
		//bug on over
		cout << "ok? " << endl;
		blue.factory(id, now);
		if(red.getFlag() == 1 && blue.getFlag() == 1){
			break;
		}
		sleep(1);
		++id;
		++now;
	}
#endif

	return 0;
}
