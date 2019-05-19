#include <cstdlib>
#include <iostream>
#include <fstream>

using std::cout;
using std::string;
using std::ifstream;
using std::cin;
using std::endl;


int main(int argc, char *argv[]){
	ifstream in;
	in.open(argv[1]);
	string stmp;
	while(in >> stmp){
		cout << stmp << endl;
	}
	in.close();
	return 0;
}
