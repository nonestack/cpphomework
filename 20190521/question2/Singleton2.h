#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>

using std::cout;
using std::endl;

class Singleton2{
	public:
		static Singleton2 *getInstance();
		static void destory();
	private:
		Singleton2();
		~Singleton2();
	private:
		static Singleton2 *_pInstance;
};

Singleton2 *Singleton2::_pInstance = NULL;

Singleton2::Singleton2(){
	printf("Singleton2()\n");
}

Singleton2::~Singleton2(){
	printf("~Singleton2()\n");
}

Singleton2 *Singleton2::getInstance(){
	if(_pInstance == NULL){
		_pInstance = new Singleton2();
		atexit(destory); //destory函数会在程序结束时进行调用，而且每个被atexit注册的函数只会被执行一次
	}
	return _pInstance;
}

void Singleton2::destory(){
	if(_pInstance != NULL){
		delete _pInstance;
		_pInstance = NULL;
	}
}

#endif
