

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
    int i;
    int res;
    int sign;

    i = 0;
    res = 0;
    sign = 1;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        if (res > INT_MAX || res < INT_MIN)
            return (-1);
        i++;
    }
    res = res * sign;
    return (res);
}

int     *ft_range(int start, int end)
{
    int *num_arr;
    int i = 0;
    int range_len;

    if (start <= end)
    {
        range_len = (end - start) + 1;
        num_arr = (int *)malloc(sizeof(int) * (range_len + 1));
        if(!num_arr)
            return(0);
        while (start <= end)
        {
            num_arr[i] = start;
            i++;
            start++;
        }
    }
    else
    {
        range_len = (start - end) + 1;
        num_arr = (int *)malloc(sizeof(int) * (range_len + 1));
        if(!num_arr)
            return(0);
        while (end <= start)
        {
            num_arr[i] = start;
            i++;
            start--;
        }
    }
    return (num_arr);
}

int main(int argc, char **argv)
{
    int start = 0;
    int end = 0;
    int *arr;
    int i = 0;
    if (argc == 3)
    {
        start = ft_atoi(argv[1]);
        end = ft_atoi(argv[2]);
        arr = ft_range(start, end);
        while(i < 4)
        {
            printf("%d, ", arr[i]);
            i++;
        }
    }
    write(1, &"\n", 1);
}