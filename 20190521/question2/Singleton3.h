#ifndef __SINGLETON3_H__
#define __SINGLETON3_H__


#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>

#include <pthread.h>

using std::cout;
using std::endl;

class Singleton3{
	public:
		static Singleton3 *getInstance();
		static void destory();
		static void init();
	private:
		Singleton3();
		~Singleton3();
	private:
		static Singleton3 *_pInstance;
		static pthread_once_t _once;
};

Singleton3 *Singleton3::_pInstance = NULL;
pthread_once_t Singleton3::_once = PTHREAD_ONCE_INIT;

Singleton3::Singleton3(){
	printf("Singleton3()\n");
}

Singleton3::~Singleton3(){
	printf("~Singleton3()\n");
}

Singleton3 *Singleton3::getInstance(){
	pthread_once(&_once, init);
	return _pInstance;
}

void Singleton3::init(){
	if(_pInstance == NULL){
		_pInstance = new Singleton3();
	}
	atexit(destory);
}

void Singleton3::destory(){
	if(_pInstance != NULL){
		delete _pInstance;
		_pInstance = NULL;
	}
}

#endif
