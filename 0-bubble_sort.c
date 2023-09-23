#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: Pointer to an integer array.
 * @size: The size of the array.
 *
 * Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	int temp, is_swapped;
	size_t pass, current;

	if (array == NULL || size == 0)
		return;

	for (pass = 0; pass < size - 1; pass++)
	{
		is_swapped = 0;

		for (current = 0; current < size - pass - 1; current++)
		{
			if (array[current] > array[current + 1])
			{
				temp = array[current];
				array[current] = array[current + 1];
				array[current + 1] = temp;
				is_swapped = 1;
				print_array(array, size);
			}
		}
		if (is_swapped == 0)
			break;
	}
}
