#ifndef __ARM_H__
#define __ARM_H__

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

#endif
