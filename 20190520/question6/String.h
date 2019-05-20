#ifndef __STRING_H__
#define __STRING_H__

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>

#define BUFSIZE 1024


namespace tsk{
using std::cout;
using std::endl;

class String{
	public:
		String();
		String(const char *);
		String(const String &);
		~String();
		String &operator=(const String &);
		String &operator=(const char *);

		String &operator+=(const String &);
		String &operator+=(const char *);

		char &operator[](std::size_t index);
		const char &operator[](std::size_t index) const;

		std::size_t size() const;
		const char *c_str() const;

		//测试函数
		int print();

	private:
		char *_pstr;

	//友元集中定义在类的开头或者结尾
	public:
		friend bool operator==(const String &, const String &);
		friend bool operator!=(const String &, const String &);

		friend bool operator<(const String &, const String &);
		friend bool operator>(const String &, const String &);
		friend bool operator<=(const String &, const String &);
		friend bool operator>=(const String &, const String &);

		friend std::ostream &operator<<(std::ostream &, const String &);
		friend std::istream &operator>>(std::istream &, String &);
};

//友元函数和类函数定义在一个头文件中
bool operator==(const String &, const String &);
bool operator!=(const String &, const String &);

bool operator<(const String &, const String &);
bool operator>(const String &, const String &);
bool operator<=(const String &, const String &);
bool operator>=(const String &, const String &);

std::ostream &operator<<(std::ostream &os, const String &s);
std::istream &operator>>(std::istream &is, String &s);


String operator+(const String &, const String &);
String operator+(const String &, const char *);
String operator+(const char *, const String &);
}

#endif
