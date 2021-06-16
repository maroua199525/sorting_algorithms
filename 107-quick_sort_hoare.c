#include "sort.h"
/**
*hoare_partition - This function takes first element as pivot, and places
* all the elements smaller than the pivot on the left side
* and all the elements greater than the pivot on
* the right side. It returns the index of the last element
* on the smaller side
*
* @array: an Array
* @low: int
* @high: int
* @size: size of array
* Return: index of pivote
*/
/*QuickSort using Hoare's partition scheme. */
int hoare_partition(int *array, int low, int high, size_t size)
{
/*pivot (Element to be placed at right position)*/
	int pivot = array[high];
/*Index of smaller element and indicates the */
/* right position of pivot found so far */
	int i = low - 1, j = high + 1, aux;

	while (1)
	{
		/* Find leftmost element greater than or equal to pivot */
		do {
			i++;
		} while (array[i] < pivot);
		/* Find rightmost element smaller than or equal to pivot */
		do {
			j--;
		} while (array[j] > pivot);
		if (i < j)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			print_array(array, size);
		}
		else
		{
			return (j);
		}
	}

}

/**
 * hoare_qsorting - Sorting Recursively an Array
 * @array: Array
 * @low: intger(minimum)
 * @high:integer(maximum)
 * @size: Size of The Array
 * Return: void
 */

/* Do the above process recursively to all the sub-arrays */
/* and sort the elements. */
void hoare_qsorting(int *array, int low, int high, size_t size)
{

	int index;

	if (low < high)
	{
		index = hoare_partition(array, low, high, size);
		hoare_qsorting(array, low, index - 1, size);
		hoare_qsorting(array, index + 1, high, size);
	}
}
/**
* quick_sort_hoare - quick sort Algorithme using partition
* @array: Array to sort
* @size: Size of The Array
* Return: (void)
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_qsorting(array, 0, size - 1, size);
}
