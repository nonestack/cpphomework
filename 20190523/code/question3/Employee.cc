#include "Employee.h"

#include <cstring>

#include <iostream>

using std::cout;
using std::endl;

Employee::Employee(const char *name, int age, const char *department, int salary)
:Person(name, age)
,_department(new char[strlen(department) + 1]())
,_salary(salary)
{
	strcat(_department, department);
	cout << "Employee()" << endl;
}

Employee::~Employee(){
	delete [] _department;
	cout << "~Employee()" << endl;
}

void Employee::display(){
	Person::display();
	cout << "My department is " << _department << endl
		 << "My salary is "		<< _salary 	   << endl;
}

int Employee::getSalary(){
	return _salary;
}
