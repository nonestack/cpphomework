#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>

using namespace std;

template<class T, class Compare = less<T> >
class HeapSort{
	public:
		HeapSort(T *arr, int num)
		:A(arr), size(num)
		{
			flag = getFlag();
		}
		void MaxHeapify(int, int);
		
		void BuildMaxHeap(int);
		
		void Sort();
		
		void swap(T *, T *);

		bool getFlag();
	private:
		T *A;
		int size;
		bool flag;
};

template <class T, class Compare>
bool HeapSort<T, Compare>::getFlag(){
	return Compare()(A[0], A[1]) == less<T>()(A[0], A[1]);
}


int main(){
	int A[] = {3,9,4,6,1,7,5,78,34,12,99};
	int size = sizeof(A) / sizeof(A[0]);
	//HeapSort(A, size);
	HeapSort<int, greater<int>> hp(A, size);
	hp.Sort();
	int i;
	for(i = 0; i < size; ++i){
		printf("%d  ", A[i]);
	}
	printf("\n");
	return 0;
}
template<class T, class Compare>
//template <class T>
void HeapSort<T, Compare>::swap(T *a, T *b){
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

template<class T, class Compare>
//template <class T>
void HeapSort<T, Compare>::MaxHeapify(int size, int n){
	int left = 2 * n + 1;
	int right = 2 * n + 2;
	if(flag == 1){
		int largest = n;
		if(left <= size - 1 && A[left] > A[n]){
			largest = left;
		}
		if(right <= size - 1 && A[right] > A[largest]){
			largest = right;
		}
		if(largest != n){
			swap(A + largest, A + n);
			/**/
			MaxHeapify(size, largest);
		}
	}
	else{
		int min = n;
		if(left <= size - 1 && A[left] < A[n]){
			min = left;
		}
		if(right <= size - 1 && A[right] < A[min]){
			min = right;
		}
		if(min != n){
			swap(A + min, A + n);
			/**/
			MaxHeapify(size, min);
		}
	}
}

template<class T, class Compare>
//template <class T>
void HeapSort<T, Compare>::BuildMaxHeap(int size){
	int i;
	for(i = size / 2; i >= 0; --i){
		MaxHeapify(size, i);
	}
}

template<class T, class Compare>
//template <class T>
void HeapSort<T, Compare>::Sort(){
	int i;
	for(i = size; i > 0; --i){
		BuildMaxHeap(i);
		swap(A, A + i - 1);
	}
}
