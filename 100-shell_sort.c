#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: Pointer to an integer array.
 * @size: The size of the array.
 *
 * Return: Void
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	int temp;
	size_t current_idx, insert_idx;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = (gap * 3) + 1;

	while (gap > 0)
	{
		for (current_idx = gap; current_idx < size; current_idx++)
		{
			temp = array[current_idx];
			insert_idx = current_idx;

			while (insert_idx >= gap && array[insert_idx - gap] > temp)
			{
				array[insert_idx] = array[insert_idx - gap];
				insert_idx -= gap;
			}
			array[insert_idx] = temp;
		}
		gap /= 3;

		print_array(array, size);
	}
}
