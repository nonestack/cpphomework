#include <cstring>

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class String{
	public:
		String();
		String(const char *);
		String(const String &);
		String(String &&);
		String &operator=(String &&);
		~String();
	private:
		char *_str;
};

String::String()
:_str(NULL)
{
	cout << "String()" << endl;
}

String::String(const char *str)
:_str(new char[strlen(str) + 1]())
{
	strcpy(_str, str);
	cout << "String(const char *)" << endl;
}

String::String(const String &str)
:_str(new char[strlen(str._str) + 1]())
{
	strcpy(_str, str._str);
	cout << "String(const String &)" << endl;
}

String::String(String &&str)
:_str(str._str)
{
	str._str = NULL;
	cout << "String(String &&)" << endl;
}

String &String::operator=(String &&str){
	if(this != &str){
		if(_str != NULL){
			delete [] _str;
			_str = NULL;
		}
		_str = str._str;
		str._str = NULL;
	}
	cout << "operator=(String &&)" << endl;
}

String::~String(){
	if(_str != NULL){
		delete [] _str;
		_str = NULL;
	}
	cout << "~String()" << endl;
}


void test0(){
	vector<String> strs;
	strs.push_back("Hello");
	cout << "--------------------" << endl;

	String str1 = "World";

	strs.push_back(std::move(str1));

	String str2("woc");
	str2 = "nihao";

	cout << endl << "test std::move " << endl;
	
}


int main(){
	test0();
	return 0;
}
