#include <cstdio>
#include <cstdlib>
#include <cstring>

class Singleton{
	public:
		static Singleton *getInstance();
		static void destoryInstance();

	private:
		Singleton(){
			printf("I'm Singleton()\n");
		}
		~Singleton(){
			printf("I'm ~Singleton()\n");
		}
	private:
		static Singleton * _pInstance;
};

Singleton *Singleton::_pInstance = NULL;

Singleton *Singleton::getInstance(){
	if(_pInstance == NULL){
		_pInstance = new Singleton();
	}
	return _pInstance;
}

void Singleton::destoryInstance(){
	if(_pInstance){
		delete _pInstance;
	}
}

int main(){
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();
	printf("p1 = %p\np2 = %p\n", p1, p2);
	Singleton::destoryInstance();
	return 0;
}
