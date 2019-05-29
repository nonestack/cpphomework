#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Warrior{
	public:
		Warrior(int, const char *, int);
		~Warrior();
		void print(int, const string &, int, int);
		//static void print();
		static void setStrength(vector<int> &);
		static int getLife(string &);
	private:
		int _camp; //red is 1, blue is 2;
		char *_kind;
		int _id;
		static vector<string> _name;
		static vector<int> _strength;
};

#endif
