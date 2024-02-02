#include "fdf.h"

void ft_freesplit(char **split_result)
{
    int i;
    i = 0;
    while (split_result[i])
    {
        free(split_result[i]);
        i++;
    }
    free(split_result);
    split_result = NULL;
}