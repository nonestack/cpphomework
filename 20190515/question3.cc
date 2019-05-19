#include <cstdio>
#include <cstdlib>
#include <cstring>

class Queue{
	public:
		Queue();
		Queue(const Queue&);
		Queue &operator=(const Queue &);
		void push(int);
		void pop();
		int  front();
		int  back();
		bool empty();
		bool full();
		~Queue();
	private:
		int _que[10];
		int _headQue;
		int _tailQue;
};

Queue::Queue()
:_headQue(0),_tailQue(0){
	memset(_que, 0, sizeof(_que));
	printf("Queue()\n");
}

Queue::Queue(const Queue &rhs)
:_headQue(rhs._headQue), _tailQue(rhs._tailQue){
	memset(_que, 0, sizeof(_que));
	int i;
	if(_tailQue > _headQue){
		for(i = _tailQue; i < sizeof(_que); ++i){
			_que[i] = rhs._que[i];
		}
		for(i = 0; i < _headQue; ++i){
			_que[i] = rhs._que[i];
		}
	}
	else{
		for(i = _tailQue; i < _headQue; ++i){
			_que[i] = rhs._que[i];
		}
	}
	printf("我是深拷贝\n");
}

Queue &Queue::operator=(const Queue &rhs){
	_headQue = rhs._headQue;
	_tailQue = rhs._tailQue;
	memset(_que, 0, sizeof(_que));
	int i;
	if(_tailQue > _headQue){
		for(i = _tailQue; i < sizeof(_que); ++i){
			_que[i] = rhs._que[i];
		}
		for(i = 0; i < _headQue; ++i){
			_que[i] = rhs._que[i];
		}
	}
	else{
		for(i = _tailQue; i < _headQue; ++i){
			_que[i] = rhs._que[i];
		}
	}
	return *this;
}
void Queue::push(int num){
	//a empty index to judge whether queue has full
	if((_headQue + 1) % 10 == _tailQue){
		printf("queue has full\n");
		return ;
	}
	_que[_headQue] = num;
	_headQue = (_headQue + 1) % 10;
}

void Queue::pop(){
	if(_headQue == _tailQue){
		printf("queue has empty\n");
		return ;
	}
	_tailQue = (_tailQue + 1) % 10;
}

int Queue::front(){
	if(_headQue == _tailQue){
		printf("queue has empty\n");
		return -1;
		
	}
	return _que[(_headQue - 1 + 10) % 10];
}

int Queue::back(){
	if(_headQue == _tailQue){
		printf("queue has empty\n");
		return -1;
	}
	return _que[_tailQue];
}

bool Queue::empty(){
	if(_headQue == _tailQue){
		//printf("queue has empty\n");
		return true;
	}	
	return false;
}

bool Queue::full(){
	if((_headQue + 1) % 10 == _tailQue){
		//printf("queue has full\n");
		return true;
	}
	return false;
}

Queue::~Queue(){
	printf("~Queue()\n");
}

int main(){
	Queue chu;
	int i;
	for(i = 0; i < 12; ++i){
		chu.push(i);
	}
	chu.pop();
	chu.pop();
	printf("front is %d\nback is %d\n", chu.front(), chu.back());
	return 0;
}
