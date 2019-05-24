#ifndef __CIRCLE_H__
#define __CIRCLE_H__

class Circle{
	public:
		Circle();
		Circle(double);
		~Circle();
		double getRadius();
		double getArea();
		double getPerimeter();
		void show();
	private:
		double _r;
};



#endif
