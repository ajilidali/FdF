#include "fdf.h"

int main(int argc, char **argv)
{
	t_fdf *fdf;
	int i;
	i = 0;
	fdf = malloc(sizeof(fdf));
	//printf("%s\n",argv[1]);
	if (argc !=2)
	{
		printf("argc");
		return (0);
	}
	//printf("%s",argv[1]);
	ft_parse(argv[1],*fdf);
	/*while (fdf.line[i])
	{
		printf("%c\n",fdf.line[i]);
		i++;
	}*/
}