/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moajili <moajili@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:15:28 by moajili           #+#    #+#             */
/*   Updated: 2024/03/19 16:20:59 by moajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...) \
__attribute__ ((format(printf, 1, 2)));
int		ft_printf_format(char c, va_list ap);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(int nbr);
int		ft_putpointer(void *p);
int		ft_hexadecimal(unsigned int n, char format);
int		ft_putnbr_unsigned(unsigned int nbr);
char	*ft_itoa_unsigned(unsigned int n);

#endif