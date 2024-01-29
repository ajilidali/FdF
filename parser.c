#include "fdf.h"

/*void *ft_parse(char *argv[1], t_fdf fdf)
{
	int	fd;
	int	i;

	i = 0;
	if (fd = open(argv[1], O_RDONLY) == -1)
		return (-1);
	while (fdf.line[i] = get_next_line(fd))
	{
		ft_split(fdf.line[i], ' ');
		i++;
	}
}
*/

int	ft_parse(char *argv, t_fdf fdf)
{
	int	fd;
	int	i;
    char **line;
    fd = 0;
	i = 1;
    printf("%s\n",argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (-1);
	}
	fdf.line[0] = *get_next_line(fd);
	while (fdf.line[i] != NULL)
	{
        line[i] = get_next_line(fd);
		fdf.line[i] = *(char *)(malloc(ft_strlen(line[i]) * sizeof(char) - 1));
        fdf.line[i] = *line[i];
		i++;
	}
	close(fd);
	return (0);
}

int ft_get_len()
{
    
}