#include "sort.h"

/**
 * partition - partition an array
 * by a pivot
 * @array: array to partition
 * @size: size of array
 * @high: higher subarray
 * @low: lower subarray
 *
 * Return: pivot index
 */
int partition(int *array, int size, int high, int low)
{
	int pivot = array[high];
	int i = low, j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quickSort - sort an array
 * using recursion
 * @array: array to sort
 * @size: size of array
 * @high: higher subarray
 * @low: lower subarray
 *
 * Return: void
 */
void quickSort(int *array, int size, int high, int low)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, size, high, low);
		quickSort(array, size, pivot - 1, low);
		quickSort(array, size, high, pivot + 1);
	}
}

/**
 * quick_sort - sort an array
 * using quick sort
 * @array: array to sort
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size > 1 || array != NULL)
	{
		quickSort(array, size, size - 1, 0);
	}
	else
		return;
}
