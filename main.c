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
	
	ft_set_z(argv[1],fdf);


	/*char **split_result = ft_split(fdf->line[2], ' ');

    fdf->z = malloc(sizeof(int) * 7); 

    int i = 0;
    while (i != 4 && split_result[i] != NULL)
    {
        fdf->z[i] = ft_atoi(split_result[i]);
        printf("%d\n", fdf->z[i]);
        i++;
    }
	*/

}