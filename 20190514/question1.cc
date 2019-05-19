/*************************************
  memory of kernel		
					2^48 - 1
  memory of stack 
  (dynamic increase toward bottom)


  memory of heap 
  (dynamic increase toward top)


  memory of changeable value 

  memory of const value
							0x400000

							0

   ************************************/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

int myGlobal = 10;

int text(){
	printf("HelloWorld\n");
	return 0;
}

int main(){
	int myStack = 5;
	int *myHeap = (int *)malloc(sizeof(int) * 1);
	*myHeap = 11;
	static int myStatic = 22;
	printf("address of stack is    %p\n", &myStack);
	printf("address of heap is     %p\n", myHeap);
	printf("address of global is   %p\n", &myGlobal);
	printf("address of function is %p\n", text);
	printf("address of static is   %p\n", &myStatic);
	free(myHeap);
	return 0;
}
