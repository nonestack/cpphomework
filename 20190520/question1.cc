#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>

using std::cout;
using std::endl;

//友元是允许类的非公有成员被其他的函数或者类访

class People;


class Animal{
	public:
		Animal(const char *, int);
		int print();
		~Animal();
	private:
		//存在形式1
		//友元函数并非类中的成员，不受类中控制关键字private和public的影响
		//普通函数通过friend关键字可以访问类中的非公有成员
		friend void cmpAnimal(const Animal &, const Animal &);
		//存在形式2
		//友元类内的成员都可以访问和修改该类的非公有成员
		friend class People;
	private:
		char *_kind;
		int _count;
};

void cmpAnimal(const Animal &a1, const Animal &a2){
	if(strcmp(a1._kind, a2._kind) == 0){
		printf("These animals are same\n");
	}
	else{
		printf("These animals are different\n");
	}
}

Animal::Animal(const char *kind, int count)
:_kind(new char[strlen(kind) + 1]())
,_count(count)
{
	strcat(_kind, kind);
	printf("Animal()\n");
}

int Animal::print(){
	printf("I'm %s\tI have %d\n", _kind, _count);
	return 0;
}


Animal::~Animal(){
	delete [] _kind;
	printf("~Animal()\n");
}

class People{
	public:
		People(const char *);
		~People();
		int print();
		int buyPet(Animal &);
	private:
		char *_name;
		int _petNum;
};

People::People(const char *name)
:_name(new char[strlen(name) + 1])
,_petNum(0)
{
	strcat(_name, name);
	printf("People()\n");
}

People::~People(){
	delete [] _name;
	printf("~People()\n");
}

int People::buyPet(Animal &a){
	++_petNum;
	--a._count;
	return 0;
}

int People::print(){
	printf("My name is %s\tI have %d animal(s)\n", _name, _petNum);
	return 0;
}

int main(){
	Animal dog1("erha", 5);
	Animal cat("bosicat", 6);
	Animal dog2("erha", 5);
	cmpAnimal(dog1, cat);
	cmpAnimal(dog1, dog2);
	People man1("Tony");
	man1.buyPet(dog1);
	man1.print();
	dog1.print();
	return 0;
}
