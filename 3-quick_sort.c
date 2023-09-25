#include "sort.h"

/**
 * swap - Swaps 2 integers.
 * @a: First integer.
 * @b: Second integer.
 *
 * Return: Void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions an array around a pivot.
 * @array: Array to be partitioned.
 * @low: Index of the first element.
 * @high: Index of the last element
 *
 * Return: Index of the pivot element after partitioning.
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int left = low - 1;
	int current;

	for (current = low; current <= high - 1; current++)
	{
		if (array[current] < pivot)
		{
			left++;
			swap(&array[left], &array[current]);
		}
	}
	swap(&array[left + 1], &array[high]);
	return (left + 1);
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort.
 * @array: Array to be sorted.
 * @low: Index of the first element.
 * @high: Index of the lst element
 *
 * Return: Void
 */
void quick_sort_recursive(int *array, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = partition(array, low, high);

		print_array(array, high + 1);

		quick_sort_recursive(array, low, pivot_idx - 1);
		quick_sort_recursive(array, pivot_idx + 1, high);
	}
}

/**
 * quick_sort - A function that sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 * @array: Pointer to an integer array.
 * @size: The size of the array.
 *
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1);
	print_array(array, size);
}
