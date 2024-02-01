#include "fdf.h"

int ft_countln(char *argv)
{
    int fd;
    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit (-1);
    }
    int i;
    while (get_next_line(fd) != NULL)
        i++;
    close(fd);
    return (i);
}

int ft_parse_lines(char *argv, t_fdf *fdf)
{
    int fd;
    int i;
    char *line;
    fd = 0;
    i = 0;
    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit (-1);
    }
    fdf->line = malloc(ft_countln(argv) * sizeof(char *));
    while ((line = get_next_line(fd)) != NULL)
    {
		fdf->line[i] = (char *)(malloc(ft_strlen(line) * sizeof(char)));
        fdf->line[i] = line;
        i++;
    }
    close(fd);
    return (0);
}


