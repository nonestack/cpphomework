#include <cstdio>
#include <cstdlib>
#include <cstring>

class Stack{
	public:
		Stack();
		Stack(const Stack &);
		Stack &operator=(const Stack &);
		void push(int);
		void pop();
		int top();
		bool empty();
		bool full();
		~Stack();
	private:
		int _number[10];
		int _topptr;
};


Stack::Stack()
:_topptr(0){
	memset(_number, 0, sizeof(_number));
}

Stack::Stack(const Stack &rhs)
:_topptr(rhs._topptr){
	memset(_number, 0, sizeof(_number));
	int i;
	for(i = 0; i < _topptr; ++i){
		_number[i] = rhs._number[i];
	}
	printf("我是深拷贝\n");
}

Stack &Stack::operator=(const Stack &rhs){
	_topptr = rhs._topptr;
	memset(_number, 0, sizeof(_number));
	int i;
	for(i = 0; i < _topptr; ++i){
		_number[i] = rhs._number[i];
	}
return *this;
}

void Stack::push(int num){
	if(this->_topptr > 10){
		printf("stack is full\n");
		return ;
	}
	this->_number[this->_topptr] = num;
	++this->_topptr;
}

void Stack::pop(){
	if(this->_topptr == 0){
		printf("stack is empty\n");
		return ;
	}
	--this->_topptr;
}

int Stack::top(){
	if(this->_topptr == 0){
		printf("stack is empty\n");
		return -1;
	}
	return this->_number[this->_topptr - 1];
}

bool Stack::empty(){
	if(this->_topptr == 0){
		return true;
	}
	return false;
}

bool Stack::full(){
	if(this->_topptr == 11){
		return true;
	}
	return false;
}

Stack::~Stack(){
	printf("~Stack()\n");
}

int main(){
	Stack n1;
	n1.push(10);
	n1.push(12);
	n1.push(14);
	printf("%d\n", n1.top());
	n1.pop();
	printf("%d\n", n1.top());
	Stack n2 = n1;
	printf("%d\n", n2.top());
	return 0;
}
