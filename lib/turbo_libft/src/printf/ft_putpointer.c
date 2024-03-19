/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:57:21 by moajili           #+#    #+#             */
/*   Updated: 2024/03/19 16:20:59 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	countdigit(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0 && i != 16)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	ft_putpointer(void *p)
{
	int					i;
	char				*txt;
	char const			*base;
	unsigned long long	adr;

	if (!p)
		return (ft_putstr("(nil)"));
	adr = (unsigned long long)p;
	txt = ft_calloc(sizeof(char), countdigit(adr) + 1);
	if (!txt)
	{
		free(txt);
		return (ft_putstr("0x0"));
	}
	base = "0123456789abcdef";
	i = countdigit(adr) - 1;
	ft_putstr("0x");
	while (adr / 16 != 0 || i >= 0)
	{
		txt[i--] = base[(adr % 16)];
		adr /= 16;
	}
	i = ft_putstr(txt) + 2;
	free(txt);
	return (i);
}
