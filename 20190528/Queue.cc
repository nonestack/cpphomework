#include <iostream>
#include <vector>

using namespace std;

template <class T> //, int QueueSize = 10>
class Queue{
	public:
		Queue(int num = 10);
		~Queue();
		void input(T);
		void output();
		T getHead();
		T getTail();
		void printHead();
		void printTail();
		bool isEmpty();
		bool isFull();
	private:
		int _Head;
		int _Tail;
		int _size;
		T *_Queue;
};

template <class T>
void Queue<T>::input(T data){
	if(this->isFull()){
		cout << "Queue is full" << endl;
		return ;
	}
	//cout << data  << endl;
	*(_Queue + _Head) = data;
	_Head = (_Head + 1) % _size;
}

template <class T>
void Queue<T>::output(){
	if(this->isEmpty()){
		cout << "Queue is empty" << endl;
		return ;
	}
	_Tail = (_Tail + 1) % _size;
}

template <class T>
void Queue<T>::printHead(){
	if(!this->isEmpty()){
		cout << *(_Queue + _Head - 1) << endl;
		return;
	}
	cout << *_Queue << endl;
}

template <class T>
void Queue<T>::printTail(){
	cout << *(_Queue + _Tail) << endl;
}

template <class T>
T Queue<T>::getHead(){
	if(!this->isEmpty()){
		return *(_Queue + _Head - 1);
	}
	return *_Queue;
}

template <class T>
T Queue<T>::getTail(){
	return *(_Queue + _Tail);
}


template <class T>
bool Queue<T>::isEmpty(){
	if((_Tail + 1) % _size == _Head){
		return true;
	}
	return false;
}

template <class T>
bool Queue<T>::isFull(){
	if((_Head + 1) % _size == _Tail){
		return true;
	}
	return false;
}

template <class T> //, int QueueSize = 10>
Queue<T>::Queue(int num)
:_Queue(new T[num]())
,_Head(0)
,_Tail(0)
,_size(num)
{
	cout << "Queue()" << endl;
}

template <class T> //, int QueueSize = 10>
Queue<T>::~Queue(){
	delete [] _Queue;
	cout << "~Queue()" << endl;
}

int main(){
	Queue<int> que1(11);
	
	int i;
	for(i = 0; i < 12; ++i){
		que1.input(i);
	}
	que1.printHead();
	que1.output();
	que1.printTail();
	//cout << que1.getHead() << endl;
	//cout << que1.getTail() << endl;
	return 0;
}
