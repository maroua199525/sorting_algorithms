#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *in ascending order using the Insertion sort algorithm
 * @list: the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *swap, *tmp;

	if (!list || !*list)
		return;
	current = *list;
	while ((current = current->next))
	{
		swap = current;
		while (swap->prev && swap->n < swap->prev->n)
		{
			tmp = swap->prev;
			if (swap->next)
				swap->next->prev = tmp;
			if (tmp->prev)
				tmp->prev->next = swap;
			else
				*list = swap;
			tmp->next = swap->next;
			swap->prev = tmp->prev;
			swap->next = tmp;
			tmp->prev = swap;
			print_list(*list);
		}
	}
}
