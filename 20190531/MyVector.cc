#include <iostream>
#include <memory>

using namespace std;

template <class T>
class MyVector{
	public:
		typedef T value_type;
		typedef T * pointer;
		typedef T * iterator;
		typedef const T * const_iterator;
	public:
		//construct function
		MyVector()
		:_start(nullptr)
		,_finish(nullptr)
		,_end_of_storage(nullptr)
		{
			cout << "MyVector()" << endl;
		}
		//destruct function
		~MyVector(){
		}

		//other function that get object attribute
		iterator begin(){
			return _start;
		}
		iterator end(){
			return _finish;
		}
		size_t size(){
			return _finish - _start;
		}
		size_t capacity(){
			return _end_of_storage - _start;
		}

		T &operator[](size_t num){
			return _start[num];
		}
		

		//function that change object status
		void push_back(const T &);
		void pop_back();
		void clear();
		iterator insert(iterator, const T &);
	private:
		void reallocate();
	private:
		static allocator<T> _alloc;
		T *_start;
		T *_finish;
		T *_end_of_storage;
};

template <class T>
allocator<T> MyVector<T>::_alloc;

template <class T>
void MyVector<T>::push_back(const T &val){
	if(size() == capacity()){
		reallocate();
	}
	_alloc.construct(_finish, val);
	++_finish;
}

template <class T>
void MyVector<T>::pop_back(){
	if(size() > 0){
		_alloc.destory(_finish--);
		//_alloc.deallocate(_finish, 1);
	}
}


template <class T>
void MyVector<T>::reallocate(){
	size_t OldStore = capacity();
	size_t NewStore;
	//if(capacity() > 0){
	//	NewStore = 2 * capacity();
	//}
	//else{
	//	NewStore = 1;
	//}
	capacity() == 0 ? NewStore = 1 : NewStore = capacity() * 2;
	T *tmp = _alloc.allocate(NewStore);
	if(_start){
		uninitialized_copy(_start, _finish, tmp);
		while(_start != _finish){
			_alloc.destroy(--_finish);
		}
		_alloc.deallocate(_start, OldStore);
	}
	_start = tmp;
	_finish = _start + OldStore;
	_end_of_storage = _start + NewStore;
}


int main(){
	MyVector<int> ivec;
	int i;
	for(i = 0; i < 10; ++i){
		ivec.push_back(i);
		cout << "ivec[" << i << "] = " << ivec[i] << "\t"
			 << "now size = " << ivec.size() << "\t"
			 << "now capacity = " << ivec.capacity() << endl;
	}
	return 0;
}
