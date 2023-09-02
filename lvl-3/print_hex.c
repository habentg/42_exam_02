

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

void print_hex(int num)
{
    char c;

    c = 0;
    if (num > 15)
    {
        print_hex(num / 16);
        print_hex(num % 16);
    }
    else
    {
        if (num == 10)
            write(1, &"A", 1);
        else if (num == 11)
            write(1, &"B", 1);
        else if (num == 12)
            write(1, &"C", 1);
        else if (num == 13)
            write(1, &"D", 1);
        else if (num == 14)
            write(1, &"E", 1);
        else if (num == 15)
            write(1, &"F", 1);
        else
        {
            c = num + '0';
            write(1, &c, 1);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        print_hex(ft_atoi(argv[1]));
    write(1, &"\n", 1);
}