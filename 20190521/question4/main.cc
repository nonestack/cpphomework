#include "cowString.h"

int main(){
	//CowString str1("HellO");
	//CowString str2(str1);
	CowString str3("World");
	str3[1] = 'T';
	//str1.print();
	//str2.print();
	str3.print();
	//str2 = str3;

	cout << str3[3] << endl;
	//printf("%c\n", str3[4]);
	//str1.print();
	//str2.print();
	//str3.print();
	return 0;
}
