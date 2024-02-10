#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		if (result > __LONG_LONG_MAX__ || i >= 19)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i]!= '\0')
        i++;
    return (i);
}

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
// Function to convert an integer to a string
void ft_itoa(int num, char *str)
{
    int len;
    int tem;
    int i;

    i = 0;
    if (num == -2147483648)
        write (1, "-2147483648", 11);

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }
    // Handle negative numbers
    if (num < 0)
    {
        str[i++] = '-';
        num = -num;
    }

    len = 0;
    tem = num;
    while (tem > 0)
    {
        tem /= 10;
        len++;
    }
    str[len] = '\0';

    while (num > 0)
    {
        str[--len] = num % 10 + '0';
        num /= 10;
    }
}

int main(int argc, char *argv[])
{
    int i = 1;

    if (argc > 1) {
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
    return 0;
}
