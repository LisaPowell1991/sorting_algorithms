#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

void quick_sort_recursive(int *array, int low, int high)
{
    int pivot_idx;

    if (low < high)
    {
        pivot_idx = partition(array, low, high);

        quick_sort_recursive(array, low, pivot_idx - 1);
        quick_sort_recursive(array, pivot_idx + 1, high);
    }
}

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quick_sort_recursive(array, 0, size - 1);
}

void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    print_array(array, n);
    printf("\n");
    
    quick_sort(array, n);
    
    printf("\nSorted Array: ");
    print_array(array, n);

    return (0);
}
