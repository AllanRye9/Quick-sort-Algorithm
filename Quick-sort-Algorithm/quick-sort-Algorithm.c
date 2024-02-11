#include "quick-sort-Algorithm.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int lb, int ub) {
    int point = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (start <= ub && arr[start] <= point)
            start++;
        while (end >= lb && arr[end] > point)
            end--;
        if (start < end)
            swap(&arr[start], &arr[end]);
    }
    swap(&arr[lb], &arr[end]);
    return end;
}

void quicksort(int *arr, int lb, int ub) {
    int loc;

    if (lb < ub) {
        loc = partition(arr, lb, ub);
        quicksort(arr, lb, (loc - 1));
        quicksort(arr, (loc + 1), ub);
    }
}

int main(int argc, char *argv[])
{
    int i = 1;

    if (argc > 1)
    {
        int size = argc - 1;
        int *arr = malloc(sizeof(int) * size);

        while (i < argc)
        {
            arr[i - 1] = ft_atoi(argv[i]);
            i++;
        }

        quicksort(arr, 0, size - 1);
        write(1, "Sorted array:\n", 14);
        
        i = 0;
        char buf[20];
        while (i < size)
        {
            ft_itoa(arr[i], buf);
            write(1, buf, ft_strlen(buf));
            write(1, "\n", 1);
            i++;
        }
        write(1, "\n", 1);
        free(arr);    
    }
    else
        write(1, "\n", 1);
    return 0;
}
