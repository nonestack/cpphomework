#include "Cylinder.h"

#include <iostream>

using std::cout;
using std::endl;

Cylinder::Cylinder(double r, double h)
:Circle(r), _h(h)
{
	cout << "Cylinder()" << endl;
}

Cylinder::Cylinder(Circle &c, double h)
:Circle(c.getRadius()), _h(h)
{
	cout << "Cylinder(const Circle &)" << endl;
}

Cylinder::~Cylinder(){
	cout << "~Cylinder()" << endl;
}

double Cylinder::getVolume(){
	return getArea() * _h;
}

void Cylinder::showVolume(){
	cout << "Volume of cylinder = " << getVolume() << endl;
}
