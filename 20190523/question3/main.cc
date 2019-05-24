#include "Person.h"
#include "Employee.h"

#include <iostream>

using std::cout;
using std::endl;

int main(){
	Employee IronMan("Tony.Stark", 64, "The Avengers", 2000000);
	Employee Thor("Thor.Odinson", 36, "The Avengers", 0);
	Employee AmericaCaptain("Steven.Rogers", 38, "The Avengers", 0);
	cout << "-----------------------------" << endl;
	IronMan.display();
	cout << "-----------------------------" << endl;
	Thor.display();
	cout << "-----------------------------" << endl;
	AmericaCaptain.display();
	cout << "-----------------------------" << endl;
	cout << "average salary is " << (IronMan.getSalary() + Thor.getSalary() + AmericaCaptain.getSalary() ) / 3 << endl;
	return 0;
}
