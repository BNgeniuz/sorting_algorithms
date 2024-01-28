#include "sort.h"

/**
 * swap_ints - swaps the positions of 2 int
 * @x: array element
 * @y: array element
 * Return: 0 (success)
 */

void swap_ints(int *x, int *y)
{
	int pmt;

	pmt = *x;
	*x = *y;
	*y = pmt;
}

/**
 * lomuto_partition - pivotal array
 * @array: array to input
 * @first: first integer
 * @last: last integer
 * @size: size of array
 * Return: interger for pivot
 */
int lomuto_partition(int *array, size_t size, int first, int last)
{
	int *index, k, m;
	
	index = array + last;
	for (k = m = first; m < last; m++)
	{
		if (array[m] < *index)
		{
			if (k < m)
			{
				swap_ints(array + m, array + k);
				print_array(array, size);
			}
			k++;
		}
	}
	if (array[k] > *index)
	{
		swap_ints(array + k, index);
		print_array(array, size);
	}

	return (k);
}

/**
 * lomuto_sort - lomuto sorting schemey
 * @array: Array to input
 * @first: first value of the array
 * @last: last value of the array
 * @size: array size
 * Return: 0 (void)
 */
void lomuto_sort(int *array, size_t size, int first, int last)
{
	int m;

	if (last - first > 0)
	{
	m = lomuto_partition(array, size, first, last);
	lomuto_sort(array, size, first, m - 1);
	lomuto_sort(array, size, m + 1, last);
	}
}

/**
 * quick_sort - lomuto partition sorting
 * @array: sorting array to input
 * @size: size of an array
 * Return: 0 (void)
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
