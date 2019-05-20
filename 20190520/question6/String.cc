#include "String.h"

namespace tsk{
	//构造函数
	String::String()
	:_pstr(NULL)	//gcc 5.4不默认支持c++11,为编译方便就直接写NULL, 此处应该为nullptr
	{
		printf("String()\n");
	}

	String::String(const char *str)
	:_pstr(new char[strlen(str) + 1]())
	{
		strcat(_pstr, str);
		printf("String(const char *)\n");
	}

	String::String(const String &str)
	:_pstr(new char[strlen(str._pstr) + 1]())
	{
		strcat(_pstr, str._pstr);
		printf("String(const String &)\n");
	}

	//析构函数
	String::~String(){
		delete [] _pstr;
		printf("~String()\n");
	}

	//重载=
	String &String::operator=(const String &str){
		//防止自复制
		if(_pstr != str._pstr){
			delete [] _pstr;
			_pstr = new char[strlen(str._pstr) + 1]();
			strcat(_pstr, str._pstr);
		}
		printf("operator=(const String &)\n");
		return *this;
	}

	String &String::operator=(const char *str){
		//类型不同，不会产生自复制
		if(_pstr != NULL){
			delete [] _pstr;
		}
		_pstr = new char[strlen(str) + 1]();
		strcat(_pstr, str);
		printf("operator=(const char *)\n");
		return *this;
	}

	//重载+=
	String &String::operator+=(const String &str){
		if(_pstr == NULL){
			_pstr = new char[strlen(str._pstr) + 1]();
			strcat(_pstr, str._pstr);
			return *this;
		}
		char *p = new char[strlen(_pstr) + 1]();
		strcat(p, _pstr);
		delete [] _pstr;
		_pstr = new char[strlen(_pstr) + strlen(str._pstr) + 1]();
		strcat(_pstr, p);
		delete [] p;
		strcat(_pstr, str._pstr);
		printf("operator+=(const String &)\n");
		return *this;
	}


	String &String::operator+=(const char *str){
		if(_pstr == NULL){
			_pstr = new char[strlen(str) + 1]();
			strcat(_pstr, str);
			return *this;
		}
		char *p = new char[strlen(_pstr) + 1]();
		strcat(p, _pstr);
		delete [] _pstr;
		_pstr = new char[strlen(_pstr) + strlen(str) + 1]();
		strcat(_pstr, p);
		delete [] p;
		strcat(_pstr, str);
		printf("operator+=(const char *)\n");
		return *this;
	}

	//重载[]
	char &String::operator[](std::size_t index){
		return _pstr[index];
	}

	const char &String::operator[](std::size_t index) const{
		return _pstr[index];
	}

	//size函数
	std::size_t String::size() const{
		if(_pstr == NULL){
			return 0;
		}
		return strlen(_pstr);
	}

	//c_str函数
	const char *String::c_str() const{
		return _pstr;
	}

	//重载比较运算符
	bool operator==(const String &s1, const String &s2){
		if(strcmp(s1._pstr, s2._pstr) == 0){
			return true;
		}
		return false;
	}

	bool operator!=(const String &s1, const String &s2){
		//直接调用重载的== 
		if(s1 == s2){
			return false;
		}
		return true;
	}

	bool operator<(const String &s1, const String &s2){
		if(strcmp(s1._pstr, s2._pstr) < 0){
			return true;
		}
		return false;
	}

	bool operator>(const String &s1, const String &s2){
		if(strcmp(s1._pstr, s2._pstr) > 0){
			return true;
		}
		return false;
	}

	bool operator>=(const String &s1, const String &s2){
		if(s1 < s2){
			return false;
		}
		return true;
	}

	bool operator<=(const String &s1, const String &s2){
		if(s1 > s2){
			return false;
		}
		return true;
	}

	//重载流运算符
	std::ostream &operator<<(std::ostream &os, const String &s){
		os << s._pstr << endl;
		return os;
	}

	std::istream &operator>>(std::istream &is, String &s){
		char buf[BUFSIZE] = {0};
		is >> buf;
		//输入正确时对进行操作，否则不进行操作
		if(is){
			if(s._pstr != NULL){
				delete [] s._pstr;
			}
			s._pstr = new char[strlen(buf) + 1]();
			strcat(s._pstr, buf);
		}
		return is;
	}

	//重载+
	String operator+(const String &s1, const String &s2){
		char *stmp = new char[s1.size() + s2.size() + 1]();
		strcat(stmp, s1.c_str());
		strcat(stmp, s2.c_str());
		String str(stmp);
		return str;
	}

	String operator+(const String &s1, const char *s2){
		char *stmp = new char[s1.size() + strlen(s2) + 1]();
		strcat(stmp, s1.c_str());
		strcat(stmp, s2);
		String str(stmp);
		return str;
	}

	String operator+(const char *s1, const String &s2){
		char *stmp = new char[s2.size() + strlen(s1) + 1]();
		strcat(stmp, s2.c_str());
		strcat(stmp, s1);
		String str(stmp);
		return str;
	}

	//测试函数
	int String::print(){
		printf("%s\n", _pstr);
		return 0;
	}	
}
