
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        if (res > INT_MAX || res < INT_MIN)
            return (-1);
        i++;
    }
    return (res);
}

int is_in_arr(char c, int base)
{
    char arr[17] = "0123456789ABCDEF";
    int arr_index = 0;
    
    while (arr[arr_index] && arr_index < base)
    {
        if (arr[arr_index] == c)
            return (arr_index);
        arr_index++;
    }
    return (-1);
}


int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int num;
    int res;
    int sign;
    
    num = 0;
    res = 0;
    sign = 1;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i])
    {
        num = is_in_arr(str[i], str_base);
        if (num == -1)
            exit(0);
        res = res * str_base + num;
        i++;
    }
    res *= sign;
    return (res);
}

void print_num(int num)
{
    char c;

    c = 0;
    if (num < 0)
    {
        write(1, &"-", 1);
        num *= -1;
    }
    if (num > 9)
    {
        print_num(num / 10);
        print_num(num % 10);
    }
    else
    {
        c = num + '0';
        write(1, &c, 1);
    }
}
int main(int argc, char **argv)
{
    int base = ft_atoi(argv[2]);

    if (argc==3 && base >= 2)
        print_num(ft_atoi_base(argv[1], base));
    write(1, "\n", 1);
}
