#include <cstdio>
#include <cstdlib>
#include <cstring>


class Cat{
	public:
		Cat(const char *kind, int age)
		:_kind(new char[strlen(kind) + 1]()), _age(age)
		{
			strcpy(_kind, kind);
			printf("Cat\nkind is %s, age is %d\n", _kind, _age);
		}

#if 0
		//深拷贝是将拷贝对象的值复制给调用对象
		//两个对象指向不同地址
		Cat(const Cat &c)
		:_kind(new char[strlen(c._kind) + 1]()), _age(c._age)
		{
			strcpy(_kind, c._kind);
			printf("我是深拷贝\n");
		}
#endif
		//浅拷贝是将要拷贝的对象的地址赋给调用对象
		//结束时会产生double free的core dumped
		Cat(const Cat &c)
		:_kind(c._kind), _age(c._age)
		{
			printf("我是浅拷贝\n");
		}

		int reset(const char *kind, int x){
			delete [] _kind;
			_kind = new char[strlen(kind) + 1]();
			strcpy(_kind, kind);
			_age = x;
		}

		int print(){
			printf("I'm %s, now is %d\n", _kind, _age);
			return 0;
		}



		~Cat(){
			delete [] _kind;
			printf("~Cat\n");
		}
	private:
		char *_kind;
		int _age;
};


int main(){
	Cat c1("bosicat", 3);
	Cat c2(c1);
	c1.print();
	c2.print();
	c2.reset("chaiquan", 5);
	printf("-------------------\n");
	c1.print();
	c2.print();
	return 0;
}
