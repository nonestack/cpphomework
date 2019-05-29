#ifndef __ARM_H__
#define __ARM_H__

#include <string>

using std::string;

class Arm{
	public:
		Arm(string , int, int);
		Arm(const Arm &);
		const char *getName();
		~Arm();
	private:
		string _name;
		int _damage;
		int _initDamage;
		int _id;
};


#endif
