#include <iostream>

using namespace std;

template <class T>
class Singleton{
	public:
		template <class... T1>
		static T *getInstance(const T1&...);
		static void destory();
	private:
		Singleton();
		~Singleton();
	private:
		static	T *_obj;
};
//
template <class T>
T *Singleton<T>::_obj = nullptr;


template <class T>
Singleton<T>::Singleton(){
	cout << "Singleton()" << endl;
}

template <class T>
Singleton<T>::~Singleton(){
	cout << "~Singleton()" << endl;
}

template <class T>
template <class... T1>
T *Singleton<T>::getInstance(const T1&... t){
	if(_obj == nullptr){
		_obj = new T(t...);
	}
	else{
		_obj->change(t...);
	}
	return _obj;
}

template <class T>
void Singleton<T>::destory(){
	if(_obj != nullptr){
		delete _obj;
		_obj = nullptr;
	}
}


class Point{
	public:
		Point(int x, int y): _x(x), _y(y){}
		void print(){
			cout << "x = " << _x << ", y = " << _y << endl;
		}
		void change(int x, int y){
			_x = x;
			_y = y;
		}
	private:
		int _x;
		int _y;
};


int main(){
	Point *p1 = Singleton<Point>::getInstance(1,2);
	p1->print();
	Point *p2 = Singleton<Point>::getInstance(3, 4);
	p1->print();
	//Point::destory();
	//Point::destory();
	return 0;
}
