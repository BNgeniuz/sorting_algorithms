#include "sort.h"
/**
 * bubble_sort - array sorting from mmin to max val
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{

	size_t l, idx, pmt = 0;

	if (size < 2)
		return;
	for (l = 0; l < size; l++)
		for (idx = 0; idx < size; idx++)
		{
			if (array[idx] > array[idx + 1] && array[idx + 1])
			{
			pmt = array[idx];
			array[idx] = array[idx + 1];
			array[idx + 1] = pmt;
			print_array(array, size);
			}
		}
}
