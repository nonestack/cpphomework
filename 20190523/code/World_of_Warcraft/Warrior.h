#ifndef __WARRIOR_H__
#define __WARRIOR_H__

class Warrior{
	public:
		Warrior(int);
		~Warrior();
	private:
		static int _id;
		int _strength;
};

#endif
