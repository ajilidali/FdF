/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:35:06 by moajili           #+#    #+#             */
/*   Updated: 2024/03/19 16:20:59 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	is_backslash(char *buffer)
{
	unsigned int	i;

	i = 0;
	while (buffer[i])
	{
		if ('\n' == buffer[i])
			return (i);
		i++;
	}
	return (-1);
}

void	replace(char **buffer)
{
	int		i;
	char	*new_buffer;

	i = is_backslash(*buffer);
	new_buffer = ft_substr(*buffer, i + 1, ft_strlen(*buffer) - i);
	free(*buffer);
	*buffer = new_buffer;
}

int	read_and_get(int fd, char **buffer)
{
	char	*new_str;
	char	*new_buffer;
	ssize_t	n_read;

	new_buffer = NULL;
	new_str = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!new_str)
		return (-1);
	while (*buffer && is_backslash(*buffer) == -1)
	{
		n_read = read(fd, new_str, BUFFER_SIZE);
		if (n_read == -1)
			return (free(new_str), free(new_buffer), -1);
		else if (n_read == 0)
			return (free(new_str), 1);
		new_buffer = ft_strjoin(*buffer, new_str);
		free(*buffer);
		*buffer = new_buffer;
		if (!*buffer)
			return (free(new_str), -1);
		ft_bzero(new_str, BUFFER_SIZE);
	}
	return (free(new_str), 0);
}

char	*get_next_line_part2(int fd, char **buffer)
{
	char	*return_line;
	int		empty;

	empty = read_and_get(fd, buffer);
	if (empty == -1)
	{
		free(*buffer);
		*buffer = NULL;
		return (*buffer);
	}
	if (empty == 0)
	{
		return_line = ft_substr(*buffer, 0, is_backslash(*buffer) + 1);
		replace(buffer);
		if (!return_line && *buffer)
			return (free(*buffer), *buffer = NULL, NULL);
		return (return_line);
	}
	if (!buffer || *buffer[0] == '\0')
		return_line = NULL;
	else
		return_line = ft_substr(*buffer, 0, ft_strlen(*buffer));
	free(*buffer);
	*buffer = NULL;
	return (return_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];

	if (fd < 0 || BUFFER_SIZE < 0 || fd >= 1024)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer[fd])
		return (NULL);
	return (get_next_line_part2(fd, &buffer[fd]));
}
