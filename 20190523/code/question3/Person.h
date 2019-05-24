#ifndef __PERSON_H__
#define __PERSON_H__

class Person{
	public:
		Person(const char *, int);
		~Person();
		void display();
	private:
		char *_name;
		int _age;
};

#endif
