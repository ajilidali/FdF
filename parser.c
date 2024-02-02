#include "fdf.h"

int ft_countln(char *argv)
{
    int fd;
    char *line;
    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit (-1);
    }
    int i;
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        free(line);
        i++;
    }
    close(fd);
    return (i);
}

int ft_countz(t_fdf *fdf)
{
    char **split_result;
    int i;
    i = 0;

    split_result = ft_split(fdf->line[0],' ');
    while(split_result[i])    
        i++;
    printf("\n count z : %d \n",i);
    ft_freesplit(split_result);
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
    if (fd == -1 )
    {
        perror("Error opening file");
        exit (-1);
    }
    printf("ft_countln : %d \n", ft_countln(argv));
    fdf->line = malloc(ft_countln(argv) * sizeof(char *));
    while ((line = get_next_line(fd)) != NULL)
    {
		//fdf->line[i] = (char *)(malloc(ft_strlen(line) * sizeof(char)));
        //fdf->line[i] = line;
        //ft_strlcpy(fdf->line[i], line, ft_strlen(line));
        fdf->line[i] = ft_strdup(line);
        free(line);
        i++;
    }
    close(fd);
    return (0);
}

int ft_set_z(char *argv,t_fdf *fdf)
{
    int size_z;
    size_z = ft_countz(fdf);
    printf("ft_countln : %d \n", ft_countln(argv));
    /*fdf->z = (int *)(malloc(ft_countln(argv)*size_z*sizeof(int)));
    fdf->z[0] = 1;
    printf("%d \n", fdf->z[0]);*/
    return 0;
}