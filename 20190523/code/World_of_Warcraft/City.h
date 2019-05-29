#ifndef __CITY_H__
#define __CITY_H__

#include <vector>

using std::vector;

//City class
class City{
	public:
		City(int);
		int getNowStrength();
		virtual
			void decreaseStrength(int);
		~City();
	private:
		int _strength;
};


//Arm class
class Arm{
	public:
		Arm(const char *, int);
		Arm(const Arm &);
		void getName();
		~Arm();
	private:
		char *_name;
		int _id;
};


//Headquarter class
class Headquarter : public City{
	public:
		//class WarriorInfo{
		//	public:
		//		WarriorInfo(int flag, const Warrior &warrior)
		//		:_flag(flag), _originWarrior(warrior)//浅拷贝
		//		{
		//		}
		//		~WarriorInfo(){
		//		}
		//	private:
		//		int _flag;
		//		Warrior &_originWarrior;
		//};
	public:
		Headquarter(int);
		void addArm(const char *);
		void setOrder(int *, int);
		void printArm();
		void addCount();
		void dealFun(int);
		//void addWrrior(const Warrior &, int);
		~Headquarter();
	private:
		int _orderWarrior[5];
		static int _armId;
		vector<Arm> _armStore;
		int _count;
		//vector<WarriorInfo&> _warrior;
		//empty in now
};

#endif
