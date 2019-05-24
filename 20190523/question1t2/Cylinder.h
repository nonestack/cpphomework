#ifndef __CYLINDER_H__
#define __CYLINDER_H__

#include "Circle.h"

class Cylinder : public Circle{
	public:
		Cylinder(double, double);
		Cylinder(Circle &, double);
		~Cylinder();
		double getVolume();
		void showVolume();
	private:
		double _h;
};

#endif
