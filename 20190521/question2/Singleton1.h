#ifndef __SINGLETON1_H__
#define __SINGLETON1_H__

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>

using std::cout;
using std::endl;

class Singleton1{
	public:
		class AutoDel{
			public:
				AutoDel(){
					printf("AutoDel()\n");
				}
				~AutoDel(){
					if(_pInstance != NULL){
						delete _pInstance;
						_pInstance = NULL;
					}
					printf("~AutoDel()\n");
				}
		};
	public:
		static Singleton1 *getInstance();
		static int destory();
	private:
		Singleton1();
		~Singleton1();
	private:
		static Singleton1 *_pInstance;
		static AutoDel _autoDel;
};

Singleton1 *Singleton1::_pInstance = NULL;
Singleton1::AutoDel _autoDel;

Singleton1::Singleton1(){
	printf("Singleton1()\n");
}

Singleton1::~Singleton1(){
	printf("~Singleton1()\n");
}

Singleton1 *Singleton1::getInstance(){
	if(_pInstance == NULL){
		_pInstance = new Singleton1();
	}
	return _pInstance;
}

int Singleton1::destory(){
	if(_pInstance != NULL){
		delete _pInstance;
		_pInstance = NULL;
	}
	return 0;
}


#endif
