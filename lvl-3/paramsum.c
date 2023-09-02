
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

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

int main(int argc, char **argv)
{
    int ar = argc - 1;
    (void)argv;
    if (ar == 0)
        write(1, &"0\n", 2);
    else
    {
        print_num(ar);
        write(1, &"\n", 1);
    }
}