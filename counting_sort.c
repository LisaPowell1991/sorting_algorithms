#include "sort.h"

void counting_sort(int *array, size_t size)
{
    size_t i;
    int max_element = array[0];
    int *temp_array, *counting_array;

    if (size <= 1)
        return;

    counting_array = (int *)malloc((max_element + 1) * sizeof(int));
    if (counting_array == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (i = 1; i < size; ++i)
    {
        if (array[i] > max_element)
            max_element = array[i];
    }

    for (i = 0; i <= max_element; ++i)
    {
        counting_array[i] = 0;
    }

    for (i = 0; i < size; ++i)
    {
        counting_array[array[i]]++;
    }

    for (i = 1; i <= max_element; ++i)
    {
        counting_array[i] += counting_array[i - 1];
    }

    temp_array = (int *)malloc(size * sizeof(int));
    if (temp_array == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        free(counting_array);
        return;
    }

    for (i = size - 1; i >= 0; --i)
    {
        temp_array[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    for (i = 0; i < size; ++i)
    {
        array[i] = temp_array[i];
    }

    print_array(counting_array, max_element + 1);

    free(counting_array);
    free(temp_array);
}
