#include "sort.h"

/**
 * shell_sort - sorts an array
 * using shell sort Knuth sequence
 * method
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, interval = 1;
	int temp = 0;

	if (size < 2 || array == NULL)
		return;

	while (interval < (size / 3))
		interval = (interval * 3) + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];

			for (j = i; (j > (interval - 1)) && (array[j - interval] >= temp);
					j -= interval)
			{
				array[j] = array[j - interval];
			}

			array[j] = temp;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
