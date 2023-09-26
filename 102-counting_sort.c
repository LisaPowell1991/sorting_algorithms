#include "sort.h"

/**
 * counting_sort - a function that sorts an array of integers,
 * in ascending order using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Void
 */

void counting_sort(int *array, size_t size)
{
	int max, min, range;
	int *counting_array;
	size_t current_idx, sorted_idx;

	if (array == NULL || size < 2)
		return;

	max = min = array[0];
	for (current_idx = 1; current_idx < size; current_idx++)
	{
		if (array[current_idx] > max)
			max = array[current_idx];
		if (array[current_idx] < min)
			min = array[current_idx];
	}
	range = max - min + 1;
	counting_array = malloc(range * sizeof(int));

	if (counting_array == NULL)
		return;

	for (current_idx = 0; current_idx < (size_t)range; current_idx++)
		counting_array[current_idx] = 0;

	for (current_idx = 0; current_idx < size; current_idx++)
		counting_array[array[current_idx] - min]++;

	print_array(counting_array, range);
	sorted_idx = 0;

	for (current_idx = 0; current_idx < (size_t)range; current_idx++)
	{
		while (counting_array[current_idx] > 0)
		{
			array[sorted_idx] = current_idx + min;
			sorted_idx++;
			counting_array[current_idx]--;
		}
	}
	free(counting_array);
}
