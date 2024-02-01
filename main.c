#include "fdf.h"

int main(int argc, char **argv)
{
	t_fdf *fdf;
	fdf = malloc(sizeof(fdf));
	if (argc !=2)
		return (0);
	ft_parse_lines(argv[1],fdf);

	printf("%s\n", fdf->line[0]);
	printf("%s\n", fdf->line[1]);
	printf("%s\n", fdf->line[2]);
	printf("%s\n", fdf->line[3]);
	printf("%s\n", fdf->line[4]);
	printf("%s\n", fdf->line[5]);
	printf("%s\n", fdf->line[6]);
	
/*
	fdf->z = malloc(sizeof(int*) * 7);
	fdf->z = ft_atoi(*ft_split(fdf->line[0], ' '));
	int i = 0;
	while (i!=4)
	{
		printf("%d\n", fdf->z[i]);
		i++;
	}
	*/

}