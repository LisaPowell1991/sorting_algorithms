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
	int temp, swapped;
	size_t pass, current;

	for (pass = 0; pass < size - 1; pass++)
	{
		swapped = 0;

		for (current = 0; current < size - pass - 1; current++)
		{
			if (array[current] > array[current + 1])
			{
				temp = array[current];
				array[current] = array[current + 1];
				array[current + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
