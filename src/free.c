/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:51:22 by moajili           #+#    #+#             */
/*   Updated: 2024/03/22 12:47:52 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/**
 * @brief Frees memory allocated for a 3D array of strings.
 *
 * This function frees the memory allocated for a 3D array
 * of strings used to store split map content.
 * It iterates through each element of
 * the array and frees the
 * allocated memory to prevent memory leaks.
 *
 * @param split_map_content The 3D array of strings to be freed.
 * @param map_data A pointer to the structure containing map data.
 */
void	free_split(char ***split_map, t_fdf *map_data)
{
	int	y_pos;
	int	x_pos;

	y_pos = 0;
	x_pos = 0;
	while (y_pos < map_data->ymax && split_map[y_pos])
	{
		x_pos = 0;
		while (x_pos < map_data->xmax && split_map[y_pos][x_pos])
		{
			free(split_map[y_pos][x_pos]);
			x_pos++;
		}
		free(split_map[y_pos++]);
	}
	free(split_map);
}

/**
 * @brief Frees memory allocated for a 2D array of
 * strings.
 *
 * This function frees the memory allocated for a
 * 2D array of strings. It iterates
 * through each element of the array and frees the
 * allocated memory to prevent memory
 * leaks.
 * It also sets the pointer to NULL after
 * freeing to avoid dangling pointers.
 *
 * @param str The 2D array of strings to be freed.
 */
void	freetab(char **str, t_fdf *data)
{
	int	i;

	i = 0;
	while (str[i] && i < data->ymax)
		free(str[i++]);
	free(str);
	str = NULL;
}
