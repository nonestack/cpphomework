#include <cstdio>
#include <cstdlib>
#include <cstring>

class String{
	public:
		String();
		String(const char *pstr);
		String(const String &rhs);
		String &operator=(const String &rhs);
		~String();

		void print();

	private:
		char * _pstr;
};

String::~String(){
	delete [] _pstr;
}

String &String::operator=(const String &rhs){
	if(this != &rhs){
		delete [] this->_pstr;
		this->_pstr = new char[strlen(rhs._pstr) + 1]();
		strcat(this->_pstr, rhs._pstr);
	}
	return *this;
}

String::String(const String &rhs)
:_pstr(new char[strlen(rhs._pstr) + 1]())
{
	strcat(_pstr, rhs._pstr);
	printf("我是深拷贝我被调用了\n");
}

String::String(const char *pstr)
:_pstr(new char[strlen(pstr) + 1]())
{
	strcat(_pstr, pstr);
}

String::String(){
	_pstr = new char[5]();
	strcpy(_pstr, "NULL");
}

void String::print(){
	printf("%s\n", _pstr);
}


int main(){
	String str1;
	str1.print();

	String str2 = "Hello, world";
	String str3("wangdao");

	str2.print();
	str3.print();

	String str4 = str3;			//会调用深拷贝一次
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}
