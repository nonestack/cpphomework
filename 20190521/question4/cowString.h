#ifndef __COWSTRING_H__
#define __COWSTRING_H__

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>

using std::cout;
using std::endl;

class CowString{
	private:
		class RetChar{
			public:
				RetChar(int idx, CowString &str)
				:_idx(idx), _str(str)
				{
					printf("RetChar()\n");
				}
				~RetChar(){
					printf("~RetChar()\n");
				}
				char &operator=(char ch);
				operator char(){
					return this->_str._pstr[_idx];
				}
			private:
				int _idx;
				CowString &_str;
		};
	public:
		//构造函数 init function
		CowString();
		CowString(const char *);
		CowString(const CowString &);
		//析构函数	destruct function
		~CowString();
		//引用计数的操作函数	function of count refence 
		void initRef();
		void increaseRef();
		void decreaseRef();
		void release();
		//size function
		std::size_t size(){
			return strlen(_pstr);
		}
		//c_pstr function
		const char *c_pstr(){
			return _pstr;
		}
		//print function
		int print();
		//operator= function
		CowString &operator=(const CowString &);
		//operator[] funtion
		RetChar &operator[](int);
	private:
		char *_pstr;		//一个int指针引用计数 + 后面的字符串(最短应该是5个字节)	_pstr contain refence count and string
};

#endif
