#include "Person.h"

#include <cstring>

#include <iostream>

using std::cout;
using std::endl;

Person::Person(const char *name, int age)
:_name(new char[strlen(name) + 1]()), _age(age)
{
	strcat(_name, name);
	cout <<  "Person()" << endl;
}

Person::~Person(){
	delete [] _name;
	cout << "~Person()" << endl;
}

void Person::display(){
	cout << "My name is " << _name << endl
		 << "I'm already " 	  << _age  << endl;
}
