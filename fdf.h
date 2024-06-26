/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:46:10 by moajili           #+#    #+#             */
/*   Updated: 2024/03/22 12:46:09 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/turbo_libft/turbo.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 2560
# define HEIGHT 1440

typedef struct bres
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	x0;
	int	y0;
	int	e2;
	int	err;
}	t_bres;

typedef struct s_coor
{
	int		x;
	int		y;
	int32_t	color;
}	t_coor;

typedef struct s_angle
{
	float	angle_x;
	float	angle_y;
	int		trans_x;
	int		trans_y;
	float	zoom;
}	t_angle;

typedef struct s_fdf
{
	int			ymax;
	int			xmax;
	int			centre_y;
	int			centre_x;
	int			**pos;
	mlx_t		*mlx;
	t_coor		*coor;
	t_angle		*angle;
	int32_t		**color;
	mlx_image_t	*image;
}	t_fdf;

int		ft_init(t_fdf *map_data, char *filepath);
int		ft_count_point(char *str, char c);
int		ft_get_finals_maps(char ***split_map_content, t_fdf *map_data);
int		ft_count_line_and_point(int fd, t_fdf *map_data);
int		ft_alloc_finals_maps(t_fdf *map_data);
int		ft_check_file_name(char *str);
void	free_split(char ***split_map_content, t_fdf *map_data);
void	freetab(char **str, t_fdf *data);
void	ft_free_finals_maps(t_fdf *map_data);
void	ft_clearimage(mlx_image_t *image);
void	draw_map(t_fdf *map_data);
void	ft_inputs(t_fdf *map_data);
void	ft_stop_process(t_fdf *map, int flag);
void	ft_inputs(t_fdf *data);
int32_t	get_the_color(char *hexa_color);
int32_t	planex(int x, int y, t_fdf *data);
int32_t	planey(int x, int y, t_fdf *data);

#endif