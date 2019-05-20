#include "String.h"

//using tsk::String::operator=(const String &str);
//using tsk::String::operator=(const char *str);

using std::cout;
using std::endl;

int main(){
	tsk::String s1;
	tsk::String s2("Hello");
	//tsk::String s3(s2);
	tsk::String s3("world");
	//s3 = s2;
	//s3 += s2;
	//printf("%s\n", s3.c_str());
	//s3[3] = 'T';
	tsk::String s4 = s2 + s3;
	cout << s4 << endl;
	//s4.print();
	return 0;
}
