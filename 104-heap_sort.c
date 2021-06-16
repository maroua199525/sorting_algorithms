#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;
// Build max heap
	for (i = size / 2; i >= 0; i--)
		heapify(array, size, i, size);
	// Heap sort
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[i], &array[0]);
		if (i != 0)
			print_array(array, size);
		 // Heapify root element to get highest element at root again
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - Recursive function to sort binary tree
 * @array: array to be sorted as a binary 
 * @end: Last node in binary tree
 * @start: First node of binary tree
 * @size: Size of the array to sort
 * Return: void
 */
void heapify(int *array, int end, int i, size_t size)
{	
	// Find max among root, left and right
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (!array || size < 2)
		return;

	if (left < end && array[left] > array[max])
		max = left;

	if (right < end && array[right] > array[max])
		max = right;

	// Swap and continue heapifying if root is not max
	if (i != max)
	{
		swap(&array[i], &array[max]);
		print_array(array, size);
		heapify(array, end, max, size);
	}
}

/**
 * swap - swap function
 * @a: intger
 * @b: integer
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}
//check this link explains heap sort:
//https://medium.com/basecs/heapify-all-the-things-with-heap-sort-55ee1c93af82