#include "quick-sort-Algorithm.h"

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

void p(char c)
{
    write(1, &c, 1);
}

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

    if (num < 0 && num != -2147483648)
    {
        p('-');
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