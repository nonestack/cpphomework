#include "MyString.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>

using std::cout;
using std::endl;

class MyString::MyStringImpl{
	public:
		MyStringImpl(const char *);
		~MyStringImpl();
		int strPrint() const;
	private:
		char *_str;
};

//member of function of MyStringImpl class
MyString::MyStringImpl::MyStringImpl(const char *str)
:_str(new char[strlen(str) + 1]())
{
	strcat(_str, str);
	printf("MyString::MyStringImpl()\n");
}

MyString::MyStringImpl::~MyStringImpl(){
	printf("MyString::~MyStringImpl()\n");
}

int MyString::MyStringImpl::strPrint() const{
	printf("%s\n", _str);
	return 0;
}

//construct and destruct class of MyString
MyString::MyString(const char *str)
:_myPImpl(new MyStringImpl(str))
{
	printf("MyString()\n");
}

MyString::~MyString(){
	if(_myPImpl){
		delete  _myPImpl;
	}
	printf("~MyString()\n");
}

int MyString::print() const{
	_myPImpl->strPrint();
	return 0;
}
