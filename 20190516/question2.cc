#include <cstdio>
#include <cstdlib>
#include <cstring>

class Food{
	public:
		Food(const char *, int);
		void print(){
			printf("I'm %s, price is %d\n", _kind, _price);
		}
		void destory(){
			//delete [] this->_kind;
			delete this;
		}
		void *operator new(size_t sz){
			printf("I'm not new of system\n");
			return malloc(sz);
		}
		void operator delete(void *ret){
			free(ret);
			printf("I'm not new of system\n");
		}
	private:
		~Food();
	private:
		char *_kind;
		int _price;
};

Food::Food(const char *kind, int price)
:_kind(new char[strlen(kind) + 1]()), _price(price){
	strcat(_kind, kind);
	printf("Food()\n");
}

Food::~Food(){
	delete [] _kind;
	printf("~Food()\n");
}

int main(){
	//Food Kele("kele", 3);
	Food *Hanbao = new Food("hanbao", 5);
	Hanbao->print();
	Hanbao->destory();
	return 0;
}
