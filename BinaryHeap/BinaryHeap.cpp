#include <iostream>
#include "MinHeap.h"

int main()
{
	MinHeap min_heap(11);

	min_heap.insert(3);
	min_heap.insert(2);
	min_heap.remove(1);
	min_heap.insert(15);
	min_heap.insert(5);
	min_heap.insert(4);
	min_heap.insert(45);
	std::cout << min_heap.extract_root() << std::endl;
	std::cout << min_heap.get_root() << std::endl;
	min_heap.decrease(2, 1);
	std::cout << min_heap.get_root() << std::endl;
	
	min_heap.print();
	min_heap.sort();
	min_heap.print();

	return 0;
}

