#include "Circle.h"
#include "Cylinder.h"

#include <iostream>

using std::cout;
using std::endl;

int main(){
	Circle cir(2.0);
	Cylinder cyl(2.0, 3.0);
	cout << "circle is " << endl;
	cir.show();
	cout << "--------------------------------" << endl << endl;
	cout << "cylinder is " << endl;
	cyl.show();
	cyl.showVolume();
	return 0;
}
