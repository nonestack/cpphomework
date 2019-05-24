#include "Dragon.h"
#include "Arm.h"
#include "Ninja.h"
#include "Iceman.h"
#include "Lion.h"
#include "Wolf.h"
#include "Headquarter.h"

#include<cstdlib>

#include <iostream>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char *argv[]){
	//int num = atoi(argv[1]);
	//int HeadStrength = atoi(argv[2]);
	//int DragonStrength = atoi(argv[3]);
	//int NinjaStrength = atoi(argv[4]);
	//int IcemanStrength = atoi(argv[5]);
	//int LionStrength = atoi(argv[6]);
	//int WolfStrength = atoi(argv[7]);
	int i;
	vector<Arm> avec;
	avec.push_back(Arm("sword", 0));
	avec.push_back(Arm("bomb", 1));
	avec.push_back(Arm("arrow", 2));
	for(auto iter = avec.begin(); iter != avec.end(); ++iter){
		iter->getName();
	}

	//for(i = 0; i < num; ++i){

	//}
}

