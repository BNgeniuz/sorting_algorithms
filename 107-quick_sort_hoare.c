#include "sort.h"

/**
*swap - swaps the positions of 2 int
*@x: array element
*@y: array element
Return: 0 (success)
*/
void swap(int *x, int *y)
{
	int pmt;

	pmt = *x;
	*x = *y;
	*y = pmt;
}

/**
 * hoare_partition - subset of an array of integers
 * @array: input of integers.
 * @size: array size
 * @left: index of the subset to order at start
 * @right: index of the subset to order at end
 *
 * Return: 0 on success
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int mid, high, low;

	mid = array[right];
	for (high = left - 1, low = right + 1; high < low;)
	{
		do {
			high++;
		} while (array[high] < mid);
		do {
			low--;
		} while (array[low] > mid);

		if (high < low)
		{
			swap(array + high, array + low);
			print_array(array, size);
		}
	}

	return (high);
}

/**
 * hoare_sort - recursion quicksort algorithm
 * @array: input integers to sort
 * @size: array size
 * @left: index of the array partition to order at start
 * @right: index of the array partition to order at end
 *
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int pmt;

	if (right - left > 0)
	{
		pmt = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, pmt - 1);
		hoare_sort(array, size, pmt, right);
	}
}

/**
 * quick_sort_hoare - array of integers in ascending
 * @array: input array of integers.
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
