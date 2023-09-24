#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 * @array: Pointer to an integer array.
 * @size: The size of the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t current_idx, remaining_idx, min_idx;
	int temp;

	if (array == NULL || size <= 1)
		return;

	for (current_idx = 0; current_idx < size - 1; current_idx++)
	{
		min_idx = current_idx;
		for (remaining_idx = current_idx + 1; remaining_idx < size; remaining_idx++)
		{
			if (array[remaining_idx] < array[min_idx])
				min_idx = remaining_idx;
		}
		if (min_idx != current_idx)
		{
			temp = array[current_idx];
			array[current_idx] = array[min_idx];
			array[min_idx] = temp;

			print_array(array, size);
		}
	}
}
