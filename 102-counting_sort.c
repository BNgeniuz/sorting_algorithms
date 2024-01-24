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
 * counting_sort - array of integers in ascending order
 * @array: input integers.
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int *read, *counted, highest, k;

	if (array == NULL || size < 2)
		return;

	counted = malloc(sizeof(int) * size);
	if (counted == NULL)
		return;
	highest = get_max(array, size);
	read = malloc(sizeof(int) * (highest + 1));
	if (read == NULL)
	{
		free(counted);
		return;
	}

	for (k = 0; k < (highest + 1); k++)
		read[k] = 0;
	for (k = 0; k < (int)size; k++)
		read[array[k]] += 1;
	for (k = 0; k < (highest + 1); k++)
		read[k] += read[k - 1];
	print_array(read, highest + 1);

	for (k = 0; k < (int)size; k++)
	{
		counted[read[array[k]] - 1] = array[k];
		read[array[k]] -= 1;
	}

	for (k = 0; k < (int)size; k++)
		array[k] = counted[k];

	free(counted);
	free(read);
}
