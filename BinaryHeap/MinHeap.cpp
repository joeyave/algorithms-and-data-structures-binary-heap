#include "MinHeap.h"
#include <iostream>

void MinHeap::min_heapify(int i, int heap_size)
{
	int l = get_left(i);
	int r = get_right(i);
	int smallest = i;
	
	if (l < heap_size && heap_arr[l] < heap_arr[smallest])
		smallest = l;
	
	if (r < heap_size && heap_arr[r] < heap_arr[smallest])
		smallest = r;
	
	if (smallest != i)
	{
		std::swap(heap_arr[i], heap_arr[smallest]);
		min_heapify(smallest, heap_size);
	}
}

void MinHeap::insert(int key)
{
	if (heap_size == capacity)
	{
		std::cout << "\nOverflow: Could not insert a key!\n";
		return;
	}

	// Insert a new key at the end.
	heap_size++;
	int i = heap_size - 1;
	heap_arr[i] = key;

	// Fix the min heap property if it is violated 
	while (i != 0 && heap_arr[parent(i)] > heap_arr[i])
	{
		std::swap(heap_arr[i], heap_arr[parent(i)]);
		i = parent(i);
	}
}
 
void MinHeap::decrease(int i, int new_val)
{
	heap_arr[i] = new_val;
	while (i != 0 && heap_arr[parent(i)] > heap_arr[i])
	{
		std::swap(heap_arr[i], heap_arr[parent(i)]);
		i = parent(i);
	}
}

int MinHeap::extract_root()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return heap_arr[0];
	}

	const int root = heap_arr[0];
	heap_arr[0] = heap_arr[heap_size - 1];
	heap_size--;
	min_heapify(0, heap_size);

	return root;
}


// This function deletes key at index i.
void MinHeap::remove(int i)
{
	decrease(i, INT_MIN);
	extract_root();
}

void MinHeap::print()
{
	for (int i = 0; i < heap_size; ++i)
		std::cout << heap_arr[i] << " ";
	std::cout << std::endl;
}

// main function to do heap sort 
void MinHeap::sort()
{
	// One by one extract an element from heap 
	for (int i = heap_size - 1; i >= 0; i--) 
	{
		// Move current root to end 
		std::swap(heap_arr[0], heap_arr[i]);

		// call max heapify on the reduced heap 
		min_heapify(0, i);
	}
}
