#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "City.h"

//Warrior class
class Warrior{
	public:
		Warrior(int, int);
		~Warrior();
	private:
		//static int _id;// In my opinion, every id of warrior should be diffient
		int _id;
		int _strength;
};

// Dragon is 1, ninja is 2, iceman is 3, lion is 4, wolf is 5

//Dragon class
class Dragon : public Warrior{
	public:
		Dragon(int, const Arm &, double);
		~Dragon();
	private:
		Arm _arm;
		double _morale;
		static int _flag;
};

//Iceman class 
class Iceman : public Warrior{
	public:
		Iceman(int, const Arm &);
		~Iceman();
	private:
		Arm _arm;
		static int _flag;
};


//Ninja class
class Ninja : public Warrior{
	public:
		Ninja(int, const Arm &, const Arm &);
		~Ninja();
	private:
		Arm _arm1;
		Arm _arm2;
		static int _flag;
};


//Lion class
class Lion : public Warrior{
	public:
		Lion(int, int);
		~Lion();
	private:
		int _loyalty;
		static int _flag;
};


//Wolf class
class Wolf : public Warrior{
	public:
		Wolf(int);
		~Wolf();
	private:
		//have not anything trait
		static int _flag;
};

#endif
