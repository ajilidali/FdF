/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:50:10 by moajili           #+#    #+#             */
/*   Updated: 2024/03/19 16:20:59 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ishere(char c, char const *s2)
{
	size_t	i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (c == s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	size_t		i;
	char		*str;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ishere(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ishere(s1[end - 1], set))
		end--;
	str = ft_calloc(sizeof(char), end - start + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	return (str);
}
