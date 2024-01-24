#include "sort.h"
#include <stdio.h>


/**
 * merge -  merge sort arrays
 * @array: array to merge
 * @size: size of merge array
 * @lf: left array
 * @rt: right array
 **/
void merge(int *array, int *lf, int *rt, size_t size)
{
	int m = 0, n = 0, p = 0;
	int size_left, size_right;

	size_left = size / 2;
	size_right = size - size_left;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(lf, size_left);
	printf("[right]: ");
	print_array(rt, size_right);

	while (m < size_left && n < size_right)
	{
		if (lf[m] < rt[n])
			array[p++] = lf[m++];
		else
			array[p++] = rt[n++];
	}

	while (m < size_left)
		array[p++] = lf[m++];

	while (n < size_right)
		array[p++] = rt[n++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - array of integers in ascending order
 * @array: input array
 * @size: size of  array
 **/
void merge_sort(int *array, size_t size)
{
	size_t centre = 0, m;
	int left[1000];
	int right[1000];

	if (!array)
		return;

	if (size < 2)
		return;

	centre = size / 2;
	/*left = (int*)malloc(sizeof(int) * mid);*/
	/*right = (int*)malloc(sizeof(int) * (size - mid));*/

	for (m = 0; m < centre; m++)
		left[m] = array[m];

	for (m = centre; m < size; m++)
		right[m - centre] = array[m];

	merge_sort(left, centre);
	merge_sort(right, size - centre);
	merge(array, left, right, size);
}
