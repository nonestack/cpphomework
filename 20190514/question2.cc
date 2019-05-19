#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using std::cout;
using std::endl;


//编译器会自动生成默认构造函数和默认析构函数
//构造函数会在class对象创建的时候自动调用，为对象初始化
//析构函数会在class对象销毁时自动调用，释放对象的内存
class Pointer{
	public:
#if 0
		Pointer(){	//automatic produce by class
		}
#endif
		int getPointer();
#if 0
		~Pointer(){	//automatic produce by class
		}
#endif

	private:
		int _ix;
		int _iy;
};


int main(){

	return 0;
}
