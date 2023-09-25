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
 * @high: Index of the last element.
 *
 * Return: Index of the pivot element after partitioning.
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int left = low - 1;
    int current;

    for (current = low; current <= high; current++)
    {
        if (array[current] <= pivot)
        {
            left++;

	    if (left != current)
	    {
		    swap(&array[left], &array[current]);
		    print_array(array, size);
	    }
        }
    }
    /*swap(&array[left + 1], &array[high]);*/
    /*print_array(array, size);*/

    return (left);
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort.
 * @array: Array to be sorted.
 * @low: Index of the first element.
 * @high: Index of the last element.
 *
 * Return: Void
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_idx - 1, size);
		quick_sort_recursive(array, pivot_idx + 1, high, size);
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
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
