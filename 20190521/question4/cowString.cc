#include "cowString.h"

void CowString::initRef(){
	*(int *)(_pstr - 4) = 1;
}

void CowString::increaseRef(){
	++*(int *)(_pstr - 4);
}

void CowString::decreaseRef(){
	--*(int *)(_pstr - 4);
}

int CowString::print(){
	printf("count = %d\tstr = %s\n", *(int *)(_pstr - 4), _pstr);
}

CowString::CowString()
:_pstr(new char[4 + 1]() + 4)	//引用计数 + 空字符		count and '\0'
{
	initRef();
	printf("CowString()\n");
}

CowString::CowString(const char *str)
:_pstr(new char[4 + strlen(str) + 1]() + 4)
{
	initRef();
	strcat(_pstr, str);
	printf("CowString(const char *str)\n");
}

CowString::CowString(const CowString &str)
//:_pstr(new char[4 + str.size() + 1]())		//copy on write
:_pstr(str._pstr)
{
	increaseRef();
	printf("CowString(const CowString &str)\n");
}

//string of same memory decrease
void CowString::release(){
	decreaseRef();
	if(*(int *)(_pstr - 4) == 0){
		delete [] (_pstr - 4);
	}
	printf("delete a string refence\n");
}

//destruct function
CowString::~CowString(){
	release();
	printf("~CowString()\n");
}

//operator= function
CowString &CowString::operator=(const CowString &str){
	if(this != &str){
		release();
		_pstr = str._pstr;
		increaseRef();
	}
	return *this;
}

//operator[] function
char &CowString::operator[](int idx){
	if(idx > this->size() || idx < 0){
		printf("index error\n");
	}
	char *ptmp = new char[4 + this->size() + 1]() + 4;
	strcpy(ptmp, _pstr);
	release();
	_pstr = ptmp;
	initRef();
	return *(_pstr + idx);
}
