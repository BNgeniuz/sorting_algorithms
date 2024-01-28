#include "sort.h"

/**
*swap_ints - swaps the positions of 2 int
*@x: array element
*@y: array element
Return: 0 (success)
*/
void swap_ints(int *x, int *y)
{
	int pmt;

	pmt = *x;
	*x = *y;
	*y = pmt;
}

/**
 * partition - pivotal array
 * @array: array to input
 * @first: first integer
 * @last: last integer
 * @size: size of array
 * Return: interger for pivot
 */
int partition(int *array, int first, int last, size_t size)
{
	int index = array[last];
	int k = first - 1, m;

	for (m = first; m <= last; m++)
	{
		if (array[m] <= index)
		{
			k++;
			if (k != m)
			{
				swap_ints(&array[k], &array[m]);
				print_array(array, size);
			}
		}
	}
	return (k);
}

/**
 * lomuto_qsort - lomuto sorting schemey
 * @array: Array to input
 * @first: first value of the array
 * @last: last value of the array
 * @size: array size
 * Return: 0 (void)
 */
void lomuto_qsort(int *array, int first, int last, size_t size)
{
	int m;

	if (first < last)
	{
	m = partition(array, first, last, size);
	
	lomuto_qsort(array, first, m - 1, size);
	lomuto_qsort(array, m + 1, last, size);
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

	lomuto_qsort(array, 0, size - 1, size);
}
