#include "fdf.h"

/*void free_fdf(t_fdf *fdf) {
    if (fdf == NULL) {
        return;
    }

    free(fdf->map);
    free(fdf->x);
    free(fdf->y);
    free(fdf->z);
    free(fdf);
}

t_fdf *initialize_fdf() 
{
    t_fdf *fdf = (t_fdf *)malloc(sizeof(t_fdf));
    
    if (fdf == NULL) 
        return NULL;
    fdf->line = NULL;
    fdf->map = (int *)malloc(sizeof(int));
    fdf->x = (int *)malloc(sizeof(int));
    fdf->y = (int *)malloc(sizeof(int));
    fdf->z = (int *)malloc(sizeof(int));
    fdf->col = NULL;  
    if (fdf->map == NULL || fdf->x == NULL || fdf->y == NULL || fdf->z == NULL) {
        free_fdf(fdf);  
        return NULL;
    }
    return fdf;
}*/


int ft_parse(char *argv, t_fdf *fdf)
{
    int fd;
    int i;
    char *line;
   // *fdf = initialize_fdf();
    fd = 0;
    i = 0;
    printf("%s\n", argv);
    fd = open(argv, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit (-1);
    }
    fdf->line = malloc(1);
    while ((line = get_next_line(fd)) != NULL)
    {
		fdf->line[i] = (char *)(malloc(ft_strlen(line) * sizeof(char) ));
        fdf->line[i] = line;
        i++;
    }
    close(fd);
    return (0);
}
