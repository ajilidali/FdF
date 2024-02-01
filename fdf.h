#ifndef FDF_H
#define FDF_H

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_fdf
{   
    char **line;
    int     *x;
    int     *y;
    int     *z;
    char **col;
}				t_fdf;


int ft_parse_lines(char *argv, t_fdf *fdf);
int ft_set_z(char *argv,t_fdf *fdf);
#endif