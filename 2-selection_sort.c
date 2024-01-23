#include "sort.h"
/**
 * selection_sort - sorts array of integers in ascending order
 * @size: size of array to input
 * @array: num of list
 */
void selection_sort(int *array, size_t size)
{
	size_t l, idx;
	int pmt, swagg, flagg = 0;

	if (array == NULL)
		return;
	for (l = 0; l < size; l++)
	{
		pmt = l;
		flagg = 0;
		for (idx = l + 1; idx < size; idx++)
		{
			if (array[pmt] > array[idx])
			{
				pmt = idx;
				flagg += 1;
			}
		}
		swagg = array[l];
		array[l] = array[pmt];
		array[pmt] = swagg;
		if (flagg != 0)
			print_array(array, size);
	}
}
