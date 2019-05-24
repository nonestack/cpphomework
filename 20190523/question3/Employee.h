#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include "Person.h"

class Employee : public Person{
	public:
		Employee(const char *, int, const char *, int);
		~Employee();
		void display();
		int getSalary();
	private:
		char *_department;
		int _salary;
};

#endif
