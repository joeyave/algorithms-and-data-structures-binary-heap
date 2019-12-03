#include<iostream> 
#include "MinHeap.h"

int main()
{
	MinHeap min_heap(11);
	
	min_heap.insert(3);
	min_heap.insert(2);
	min_heap.insert(15);
	min_heap.insert(5);
	min_heap.insert(4);
	min_heap.insert(45);

	min_heap.print();
	
	return 0;
}
