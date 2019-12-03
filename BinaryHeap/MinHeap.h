#pragma once

class MinHeap
{
public:
	MinHeap(int cps)
	{
		heap_size = 0;
		capacity = cps;
		heap_arr = new int[cps];
	}

	// A recursive method to heapify a subtree with the root at given index. 
	// This method assumes that the subtrees are already heapified. 
	void min_heapify(int i, int heap_size);
	void insert(int key);

	// Decreases value of key at index 'i' to new_val.
	// It is assumed that new_val is smaller than heap_arr[i].
	void decrease(int i, int new_val);

	// Removes a root which is the min element.
	int extract_root();

	void remove(int i);

	int parent(int i) { return (i - 1) / 2; }
	int get_left(int i) { return 2 * i + 1; }
	int get_right(int i) { return 2 * i + 2; }
	int get_root() { return heap_arr[0]; }
	void print();
	void sort();

private:
	int* heap_arr; // Pointer to array of elements in heap.
	int capacity; // Maximum possible size of min heap.
	int heap_size; // Current number of elements in min heap.
};