#include <cstdio>
#include <cstdlib>
#include <cstring>

//only stack

class Person{
	public:
		Person(const char *, int);
		~Person();
	private:
	
		void *operator new(size_t sz){
			printf("I'm not new of system\n");
			return malloc(sz);
		}
		void operator delete(void *ret){
			free(ret);
		}
	private:
		char *_name;
		int _age;
};

Person::Person(const char *name, int age)
:_name(new char[strlen(name) + 1]()), _age(age){
	strcat(_name, name);
	printf("Person()\n");
}

Person::~Person(){
	delete [] _name;
	printf("~Person()\n");
}

int main(){
	Person man1("Xingyangyang", 6);
	Person *man2 = new Person("huitailang", 8);//error
	return 0;
}
