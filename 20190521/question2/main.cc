//自动回收类的测试
#if 0
#include "Singleton1.h"

int main(){
	Singleton1 *s1 = Singleton1::getInstance();
	Singleton1 *s2 = Singleton1::getInstance();
	return 0;
}
#endif

//atexit函数进行main函数结束时进行调用destory 的测试
#if 0
#include "Singleton2.h"

int main(){
	Singleton2 *s1 = Singleton2::getInstance();
	Singleton2 *s2 = Singleton2::getInstance();
	//Singleton2::destory();
	//Singleton2::destory();
	return 0;
}

#endif

//atexit + pthread_once 对对象只初始化一次并在main结束时自动调用destory
#if 1
#include "Singleton3.h"

int main(){
	Singleton3 *s1 = Singleton3::getInstance();
	Singleton3 *s2 = Singleton3::getInstance();
	return 0;
}

#endif 
