#include "sort.h"

/**
* stupify - Sort recursive
* @array: Array of input
* @heap: size of heap
* @idx: index of heap
* @size: array size
*/

void stupify(int *array, int heap, int idx, int size)
{
	int sd = idx, left = 2 * idx + 1, right = 2 * idx + 2, p;

	if (left < heap && array[left] > array[sd])
		sd = left;
	if (right < heap && array[right] > array[sd])
		sd = right;
	if (sd != idx)
	{
		p = array[idx], array[idx] = array[sd], array[sd] = p;
		print_array(array, size);
		stupify(array, heap, sd, size);
	}
}

/**
* heap_sort - array with heap sort algo
* @array: array to input
* @size: size of an array
*/

void heap_sort(int *array, size_t size)
{
	int idx = size / 2 - 1, pmt;

	if (array == NULL || size < 2)
		return;
	for (; idx >= 0; idx--)
		stupify(array, size, idx, size);
	for (idx = size - 1; idx >= 0; idx--)
	{
		pmt = array[0];
		array[0] = array[idx];
		array[idx] = pmt;
		if (idx > 0)
			print_array(array, size);
		stupify(array, idx, 0, size);
	}
}
