#include "sort.h"

/**
 * shell_sort -sort arrays in ascending order
 * @array: array to input
 * @size: size of the array
 **/

void shell_sort(int *array, size_t size)
{
	unsigned int val = 1, m, n;
	int pmt;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (val < size / 3)
		val = val * 3 + 1;

	while (val > 0)
	{
		for (m = val; m < size; m++)
		{
			pmt = array[m];
			n = m;
			while (n >= val && array[n - val] > pmt)
			{
				array[n] = array[n - pmt];
				n -= val;
			}
			array[n] = pmt;
		}
		print_array(array, size);
		val /= 3;
	}
}
