
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

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

int is_prime(int num)
{
    int count;
    int i;

    count = 0;
    i = 1;
    while (num >= i)
    {
        if (num % i == 0)
            count++;
        i++;
    }
    if (count == 2)
        return (1);
    return (0);
}

int add_print_sum(char *str)
{
    int num;
    int sum;

    num = ft_atoi(str);
    sum = 0;
    while (num > 1)
    {
        if (is_prime(num))
            sum = sum + num;
        num--;
    }
    return (sum);
}

void print_num(int num)
{
    char c;

    c = 0;
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

int main(int ac, char **argv)
{
    if (ac == 2)
        print_num(add_print_sum(argv[1]));
    else
        print_num(0);
    write(1, "\n", 1);
}