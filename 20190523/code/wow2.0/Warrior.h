#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "Arm.h"

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

//Warrior
/******************************************************/
class Warrior{
	public:
		Warrior(int, const char *, int);
		virtual ~Warrior();
		virtual void print(int, const string &, int, int);
		//virtual void printTrait() = 0;
		//static void print();
		static void setStrength(vector<int> &);
		static int getLife(const string &);
	private:
		int _camp; //red is 1, blue is 2;
		char *_kind;
		int _id;
		static vector<string> _name;
		static vector<int> _strength;
};
/******************************************************/


//Dragon
/******************************************************/
class Dragon : public Warrior{
	public:
		Dragon(int, const char *, int, Arm &, int);
		virtual void print(int ,const string &, int, int);
		virtual ~Dragon();
	private:
		Arm &_arm;
		double _morale;
};
/******************************************************/
//Ninja
/******************************************************/
class Ninja : public Warrior{
	public:
		Ninja(int, const char *, int, Arm &, Arm &);
		virtual void print(int, const string &, int, int);
		virtual ~Ninja();
	private:
		Arm &_larm;
		Arm &_rarm;
};
/******************************************************/
//Iceman
/******************************************************/
class Iceman : public Warrior{
	public:
		Iceman(int, const char *, int, Arm &);
		virtual void print(int, const string &, int, int);
		virtual ~Iceman();
	private:
		Arm &_arm;
};
/******************************************************/
//Lion
/******************************************************/
class Lion : public Warrior{
	public:
		Lion(int, const char *, int, int);
		virtual void print(int, const string &, int, int);
		virtual ~Lion();
	private:
		int _loyalty;
};
/******************************************************/
//Wolf
/******************************************************/
class Wolf : public Warrior{
	public:
		Wolf(int, const char *, int);
		virtual void print(int, const string &, int, int);
		~Wolf();
	private:
		//nothing
};
/******************************************************/
#endif

