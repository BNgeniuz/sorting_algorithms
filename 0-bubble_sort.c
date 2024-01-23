#include "sort.h"
/**
 * bubble_sort - array sorting from mmin to max val
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{

	size_t l, idx;
	int pmt;

	if (array == NULL || size < 2)
		return;
	for (idx = 0; idx < size - 1; idx++)
	{
		for (l = 0; l < size - idx - 1; l++)
		{
			if (array[l] > array[l + 1])
			{
			pmt = array[l];
			array[l] = array[l + 1];
			array[l + 1] = pmt;
			print_array(array, size);
			}
		}
	}
}
