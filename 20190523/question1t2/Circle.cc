#include "Circle.h"

#include <iostream>

#define PI 3.1415

using std::cout;
using std::endl;



Circle::Circle()
:_r(0)
{
	cout << "Circle()" << endl;
}

Circle::Circle(double r)
:_r(r)
{
	cout << "Circle(double)" << endl;
}

Circle::~Circle(){
	cout << "~Circle()" << endl;
}

double Circle::getArea(){
	return _r * _r * PI;
}

double Circle::getPerimeter(){
	return 2 * PI * _r;
}

void Circle::show(){
	cout << "r = " << _r << endl
		<< "Perimeter = " << getPerimeter() << endl
		<< "Area = " << getArea() <<endl;
}

double Circle::getRadius(){
	return _r;
}
