

#ifndef FT_LST_H
# define FT_LST_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list {
    int              value;
    struct s_list    *next;
}   t_list;

#endif