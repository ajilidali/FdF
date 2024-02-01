#include "fdf.h"

int main(int argc, char **argv)
{
	t_fdf *fdf;
	int i;
	i = 0;
	fdf = malloc(sizeof(fdf));
	if (argc !=2)
	{
		printf("argc");
		return (0);
	}
	ft_parse(argv[1],fdf);

	printf("%s",fdf->line[0]);
	printf("%s",fdf->line[1]);
	printf("%s",fdf->line[2]);
	printf("%s",fdf->line[3]);
	printf("%s",fdf->line[4]);
	printf("%s",fdf->line[5]);

}