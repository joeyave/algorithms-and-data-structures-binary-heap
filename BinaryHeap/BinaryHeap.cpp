#include <iostream> 

void max_heapify(int heap_arr[], int heap_size, int index)
{
	int largest = index;
	int l = 2 * index + 1;
	int r = 2 * index + 2;

	// If left child is larger than root.
	if (l < heap_size && heap_arr[l] > heap_arr[largest])
		largest = l;

	// If right child is larger than largest so far.
	if (r < heap_size && heap_arr[r] > heap_arr[largest])
		largest = r;

	// If largest is not root.
	if (largest != index)
	{
		std::swap(heap_arr[index], heap_arr[largest]);

		// Recursively max_heapify the affected sub-tree. 
		max_heapify(heap_arr, heap_size, largest);
	}
}

void sort(int heap_arr[], int heap_size)
{
	// Build heap.
	for (int i = heap_size / 2 - 1; i >= 0; i--)
		max_heapify(heap_arr, heap_size, i);

	for (int i = heap_size - 1; i >= 0; i--)
	{
		// Move current root to end.
		std::swap(heap_arr[0], heap_arr[i]);

		// Call max max_heapify on the reduced heap.
		max_heapify(heap_arr, i, 0);
	}
}

void print(int heap_arr[], int n)
{
	for (int i = 0; i < n; ++i)
		std::cout << heap_arr[i] << " ";
	std::cout << "\n";
}
 
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sort(arr, n);

	std::cout << "Sorted array is \n";
	print(arr, n);
}