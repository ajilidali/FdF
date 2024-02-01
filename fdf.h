#ifndef FDF_H
#define FDF_H

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_fdf
{   
    char **line;
    int     *map;
    int     *x;
    int     *y;
    int     *z;
    char **col;
}				t_fdf;


int ft_parse(char *argv, t_fdf *fdf);
void free_fdf(t_fdf *fdf);
#endif