#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions an array using the Lomuto scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array (for printing)
 * Return: Partition index
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i = low;
	size_t j;
	int pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap_ints(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursive - Recursively sorts an array using Lomuto scheme
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array (for printing)
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		if (p > 0)
			quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition)
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
