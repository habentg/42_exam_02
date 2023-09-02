
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int inside_str(char *str, char c, int from_index)
{
    while (str[from_index])
    {
        if (str[from_index] == c)
            return (from_index);
        from_index++;
    }
    return (-1);    
}

void    hidenp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int curr_j = 0;

    while (s1[i])
    {
        j = curr_j;
        while (s2[j])
        {
            if (inside_str(s2, s1[i], j) != -1)
            {
                curr_j = inside_str(s2, s1[i], j);
                printf("%c at index j: %d\n", s2[curr_j], curr_j);
                break ;
            }
            else
            {
                write(1, &"0\n", 2);
                exit (0);
            }
            j++;
        }
        i++;
    }
    write(1, &"1\n", 2);
    
}
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        hidenp(argv[1], argv[2]);
    }
    write(1, &"\n", 1);
    return(0);
}