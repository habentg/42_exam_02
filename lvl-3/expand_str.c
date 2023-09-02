#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int str_length(char *str)
{
    int count;

    count = 0;
    while (*str)
    {
        count++;
        str++;
    }
    return (count);
}
void expand_str(char *str)
{
    int i;
    int last_index;

    i = 0;
    last_index = str_length(str) - 1;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    while(str[last_index] == ' ' || str[last_index] == '\t')
        last_index--;
    while (str[i] && i <= last_index)
    {
        if (str[i] == ' ' || str[i] == '\t')
        {
            write(1, &"   ", 3);
            while (str[i] == ' ' || str[i] == '\t')
                i++;
        }
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        expand_str(argv[1]);
    write(1, "\n", 1);
}