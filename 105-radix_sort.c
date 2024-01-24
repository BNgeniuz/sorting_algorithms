#include "sort.h"

/**
 * get_max - maxi value in an array of integers.
 * @array: integer arrays
 * @size: an array size
 *
 * Return: 0 (maxi array)
 */
int get_max(int *array, int size)
{
	int highest, k;

	for (highest = array[0], k = 1; k < size; k++)
	{
		if (array[k] > highest)
			highest = array[k];
	}

	return (highest);
}

/**
 * radix_counting_sort - significant digits of an array of integers
 * @array: input integers.
 * @size: array size
 * @sig: significant digit to sort
 * @buff: buffer to store array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int read[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t k;

	for (k = 0; k < size; k++)
		read[(array[k] / sig) % 10] += 1;

	for (k = 0; k < 10; k++)
		read[k] += read[k - 1];

	for (k = size - 1; (int)k >= 0; k--)
	{
		buff[read[(array[k] / sig) % 10] - 1] = array[k];
		read[(array[k] / sig) % 10] -= 1;
	}

	for (k = 0; k < size; k++)
		array[k] = buff[k];
}

/**
 * radix_sort - an array of integers in ascending
 * @array: input of integers.
 * @size: array size
 */
void radix_sort(int *array, size_t size)
{
	int highest, imp, *buff_er;

	if (array == NULL || size < 2)
		return;

	buff_er = malloc(sizeof(int) * size);
	if (buff_er == NULL)
		return;

	highest = get_max(array, size);
	for (imp = 1; highest / imp > 0; imp *= 10)
	{
		radix_counting_sort(array, size, imp, buff_er);
		print_array(array, size);
	}

	free(buff_er);
}
