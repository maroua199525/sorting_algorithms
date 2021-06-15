#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: the array
 * @size: size of the array
 * Return: void
 */
/*  using the Selection sort algorithm */
void selection_sort(int *array, size_t size)
{

	size_t i, j, jmin;
	int aux, min;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		jmin = i;
		for (j = i + 1; j < size; j++)
		if (array[j] < min)
		{
			/* found new minimum; remember its index */
			min = array[j];
			jmin = j;
		}

	if (jmin != i)
	{
		aux = array[i];
		array[i] = array[jmin];
		array[jmin] = aux;
		print_array(array, size);
	}
	}
}
