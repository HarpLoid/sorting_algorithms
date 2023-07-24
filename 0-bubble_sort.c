#include "sort.h"
#include <unistd.h>

/**
 * bubble_sort - sorts an array of integers
 * in ascending order using the Bubble sort algorithm.
 * @array: array to sort
 * @size: size of array
 *
 * Returns: void
 */
void bubble_sort(int *array, size_t size)
{
	int sorted = 0;
	size_t i;

	if (size < 2)
		return;

	while (!sorted)
	{
		sorted = 1;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				array[i - 1] = array[i - 1] ^ array[i];
				array[i] = array[i - 1] ^ array[i];
				array[i - 1] = array[i] ^ array[i - 1];
				sorted = 0;
				print_array(array, size);
			}
		}
	}
}
