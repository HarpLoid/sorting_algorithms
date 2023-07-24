#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order
 * using the Insertion sort algorithm
 * @list: doubly linked list to sort
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *previous, *current, *nextnode;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;
	nextnode = current->next;
	while (current)
	{
		
		previous = current->prev;
		while (previous && (previous->n > current->n))
		{
			if (!previous->prev)
			{
				previous->prev = current;
				previous->next = current->next;
				if (current->next)
					current->next->prev = previous;
				current->next = previous;
				current->prev = NULL;
				*list = current;
			}
			else
			{
				previous->next = current->next;
				if (current->next)
					current->next->prev = current->prev;
				current->next = previous;
				current->prev = previous->prev;
				previous->prev->next = current;
				previous->prev = current;
			}
			print_list(*list);
			previous = current->prev;
		}
		current = nextnode;
		current ? (nextnode = current->next) : (nextnode = NULL);
	}
}
